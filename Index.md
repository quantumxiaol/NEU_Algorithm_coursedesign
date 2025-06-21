# Index

主要负责处理索引数据的排序、合并以及写入磁盘文件。

但是我记得是存在一些性能问题没有解决的，好像是因为vector特别大，还涉及到频繁的删除操作。

## 函数

### int indexProcressTest()

功能：
测试索引处理流程，包括读取临时索引、排序、合并相同单词ID对应的文档ID列表或词频信息，并最终将结果写入磁盘文件。

流程：
读取索引：从磁盘文件中读取临时索引和带词频的索引。
排序：使用自定义排序算法（如希尔排序）对索引数据进行排序。
合并：合并相同单词ID下的文档ID列表或词频信息。
写入磁盘：将处理后的索引数据写入磁盘文件。

性能分析：

时间复杂度：

排序：取决于使用的排序算法。希尔排序的时间复杂度为 $O(n^1.5)$，而标准库 sort() 的平均时间复杂度为 $O(n log(n))$。
合并：遍历整个索引数据，时间复杂度为 $O(n)$。

空间复杂度：主要受输入数据大小的影响，额外的空间开销主要用于存储中间结果。

改进建议：

使用更高效的排序算法（如快速排序或归并排序）。

减少不必要的内存分配和释放操作。

### int inputindextemp(pair<int,vector<int>> &input)

功能：
将单个倒排索引条目写入文件 "3\indextemp.txt" 中。

性能分析：
时间复杂度：$O(m)$，其中 $m$ 是文档ID列表的长度。

I/O 操作：每次调用都会打开文件并追加数据，频繁的文件操作可能成为性能瓶颈。

改进建议：
批量写入数据，减少文件打开和关闭的次数。
使用缓冲区提高写入效率。

### int inputindexfrequencytemp(pair<int,vector<pair<int,int>>> &input)

功能：
将单个带词频的倒排索引条目写入文件 "3\indexfrequencytemp.txt" 中。

## 数据结构说明

vector<pair<int,int>> temindex

用途：存储基础索引 <word_id, doc_id>

特点：每个元素表示一个单词ID及其对应的文档ID

vector<pair<int,pair<int,int>>> temindexfre

用途：存储带词频的索引 <word_id, <doc_id, frequency>>

特点：每个元素表示一个单词ID及其对应文档ID和出现频率

vector<pair<int,vector<int>>> indextest

用途：存储合并后的基础索引 <word_id, [doc_ids]>

特点：每个元素表示一个单词ID及其对应的文档ID列表

vector<pair<int,vector<pair<int,int>>>> indexfretest

用途：存储合并后的带词频索引 <word_id, [(doc_id, frequency)]>

特点：每个元素表示一个单词ID及其对应的文档ID和词频列表

## 性能问题

在 Index.cpp 的 indexProcressTest() 函数中表现得尤为明显。

```cpp
for(auto it=temindex.begin(); it!=temindex.end();){
    if(it == temindex.begin()) {
        it++;
        continue;
    }

    int wordid = (*(it-1)).first;

    if((*it).first == (*(it-1)).first) {
        small.push_back( (*(it-1)).second );
        it = temindex.erase(it - 1);   // 👈 这里是性能瓶颈！
        it++;
    } else {
        small.push_back((*(it-1)).second);
        indextest.push_back(make_pair(wordid, small));
        inputindextemp(indextest[indextest.size()-1]);
        small.clear();
        vector<int>().swap(small);
        it++;
    }
}

```

1. 频繁使用 vector::erase()
每次调用 temindex.erase(it - 1) 会导致：
整个 vector 后面的所有元素都要前移一位。
时间复杂度为 $O(n)$，如果循环执行了 $m$ 次，整体复杂度会变成 $O(n^2)$。
对于一个非常大的 temindex 来说，这会导致程序严重卡顿甚至崩溃。

2. 迭代器失效问题
每次 erase() 之后，原来的迭代器可能会失效，虽然用了 it = erase(...) 来更新迭代器，但这种写法本身就不适合频繁操作。

3. 内存碎片 & 内存拷贝开销
vector 是连续内存结构，频繁插入/删除会导致大量数据复制和内存重新分配。
尤其是在中间位置频繁删除时，性能急剧下降。

### 解决方案与优化建议

#### 方案一：先排序后合并

既然已经对 temindex 做了排序（按 word_id），那就可以利用这个特性，避免使用 erase()。

实现思路如下：
```cpp
sort(temindex.begin(), temindex.end(), cmp0);

int current_word_id = -1;
vector<int> doc_ids;

for (const auto& p : temindex) {
    if (p.first != current_word_id) {
        if (current_word_id != -1) {
            indextest.push_back(make_pair(current_word_id, doc_ids));
            doc_ids.clear();
        }
        current_word_id = p.first;
    }
    doc_ids.push_back(p.second);
}

// 最后一组也加入结果
if (!doc_ids.empty()) {
    indextest.push_back(make_pair(current_word_id, doc_ids));
}
```

优点：
完全避免了 erase()，时间复杂度从 $O(n^2)$ 降低到 $O(n)$；
更简洁、更安全，没有迭代器失效风险；
内存占用更低，没有频繁复制；

#### 方案二：使用 std::map<int, vector<int>> 替代手动合并

由于最终是要把相同 word_id 的所有 doc_id 放在一起，可以直接使用 map：

（问题在于完成项目是要求不使用algorithm的函数，只能自己实现，我又没能搓出来一个map，但我确实尝试写了一个Hashmap.cpp）

```cpp
map<int, vector<int>> index_map;

for (const auto& p : temindex) {
    index_map[p.first].push_back(p.second);
}

// 转换回 vector<pair<int, vector<int>>> 格式
for (const auto& kv : index_map) {
    indextest.push_back({kv.first, kv.second});
}
```

优点：
简洁明了，逻辑清晰；
自动去重；
可扩展性强（例如支持词频统计）
