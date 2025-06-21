# Search

实现了一个简易搜索引擎的基础架构，包含：

关键词输入解析
词表构建与管理
临时索引与最终索引的建立
支持频率统计与排序
支持多关键词匹配查询

## 文件读取（硬编码）

|文件路径|用途|
|-|-|
|2\wordlist.txt|存储原始词表|
|2\tempindex.txt|临时索引（word_id + doc_id）|
|2\tempindexwithfrequency.txt|带频率的临时索引|
|2\tempindexsort.txt|排序后的临时索引|
|2\tempindexwithfrequencysort.txt|排序后带频率的索引|
|3\index.txt|最终索引|
|3\indexfrequency.txt|最终索引（带频率）|

## 存在的问题

编码问题（已修复 GB 2312->UTF-8）

路径依赖

所有文件路径都硬编码为 2\ 和 3\，应考虑改为相对路径或可配置项。

异常处理

目前仅简单判断文件是否打开成功，建议增加更完整的错误日志和恢复机制。

性能优化

频繁地进行文件读写可能影响效率，可以考虑引入内存缓存机制。
