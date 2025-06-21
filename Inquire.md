# Inquire

## 函数

|函数名|功能|
|-|-|
|maxHeapify, rantwordlist|堆排序字符串-整数对（按字符串升序）|
|maxHeapify_web, rantwordlist_web|堆排序整数-整数对（按第一个整数降序）|
|maxHeapify_webfre, rantwordlist_webfre|堆排序复杂结构（次数、频数、文档ID）|
|find_number|从词表中查找关键词对应的编号|
|InquireKeywordFre|查询多个关键词在哪些文档中出现，以及总频次，排序后输出|
|InquireKeyword|查询关键词匹配的文档ID列表，并统计文档命中次数，排序后输出|
|lookksite / visitsite|显示或打开匹配的网页链接|
|runserachWang / runserachWangFre|测试函数，模拟完整搜索流程|

## 数据结构说明

|类型|描述|
|-|-|
|pair<string, int>|词表项：单词 + 编号|
|pair<int, int>|文档ID + 关键词命中次数|
|pair<pair<int, int>, int>|(次数, 频数), 文档ID|
|vector<pair<int,vector<int> > >|最终索引结构：词ID → 文档列表|
|vector<pair<int,vector<pair<int,int> > > >|带频率的最终索引结构：词ID → (文档ID, 频率) 列表|
