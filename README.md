# NEU_Algorithm_coursedesign

东北大学算法分析与设计课程设计（2021.06.10）

## 要求

课题任务即不调用算法库的条件下，实现一个小型搜索引擎，分块完成搜集、分析、索引、查询四部分。
其中：
搜集指利用爬虫爬取网页信息；

分析是对网页内容抽取、分词，构建临时索引；

索引是在临时索引的基础上，进行排序与整合，构建倒排索引；

查询是响应用户的请求，根据倒排索引获取相关网页，计算网页排名，返回查询结果给用户。

## 功能

在搜集阶段，将提供的news.csv处理网页文件，以txt形式存储网页；在分析阶段，将搜集的网页文件处理为词频文件，并保存为txt文件；在索引阶段，将词频文件处理为倒排索引文件，并保存为txt文件；在查询阶段，处理用户输入的关键词，并计算相关网页的排名，返回给用户。

## 文件结构

    SearchEngine/
    |--- bin/
    │   |--- Debug/
    │   │   |--- SearchEngine        <-- Debug 模式下的可执行程序
    │   |--- Release/
    │       |--- SearchEngine        <-- Release 模式下的可执行程序
    |--- obj/
    │   |--- Debug/                  <-- Debug 模式下的编译中间文件（.o）
    │   |--- Release/                <-- Release 模式下的编译中间文件（.o）
    |--- .vscode/
    │   |--- tasks.json              <-- VS Code 构建任务配置文件
    |--- Index.cpp                   <-- 索引模块实现文件
    |--- Index.h                     <-- 索引模块头文件（定义索引类或结构）
    |--- Inquire.cpp                 <-- 查询逻辑实现文件
    |--- Inquire.h                   <-- 查询逻辑头文件（可能封装搜索接口）
    |--- Readcsv.cpp                 <-- CSV 文件读取实现文件
    |--- Readcsv.h                   <-- CSV 文件读取头文件（用于加载数据）
    |--- Search.cpp                  <-- 搜索功能实现文件
    |--- Search.h                    <-- 搜索功能头文件（定义搜索类或函数）
    |--- Sort.cpp                    <-- 排序算法实现文件
    |--- Sort.h                      <-- 排序算法头文件（封装排序逻辑）
    |--- Word.cpp                    <-- 单词处理实现文件（如分词、清洗等）
    |--- Word.h                      <-- 单词处理头文件（定义相关结构体或类）
    |--- main.cpp                    <-- 主程序入口，调用其他模块完成流程控制
    |--- SearchEngine.cbp            <-- Code::Blocks 项目配置文件
    |
    |--- 1/                          <-- 网页文件
    |   |--- html1.txt
    |
    |--- 2/                          <-- 词频文件
    |--- 3/                          <-- 索引文件

## 编译和运行

### 使用vscode

创建.vscode/tasks.json文件，内容如下：

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Build (Debug)",
      "type": "shell",
      "command": "g++",
      "args": [
        "-Wall", "-fexceptions", "-g", "-std=c++17",
        "Index.cpp", "Inquire.cpp", "Readcsv.cpp", "Search.cpp", "Sort.cpp", "Word.cpp", "main.cpp",
        "-o", "bin/Debug/SearchEngine.exe"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "problemMatcher": ["$gcc"],
      "options": {
        "cwd": "${workspaceFolder}"
      }
    }
  ]
}
```

运行任务`Ctrl+Shift+B`,如果报错需要创建./bin/Debug目录和./bin/Release目录。

运行`bin/Debug/SearchEngine.exe`

### 使用codeblocks

将SearchEngine.cbp用codeblocks打开，编译运行。

### 使用g++

    g++ -Wall -fexceptions -g -std=c++17 \
        Index.cpp Inquire.cpp Readcsv.cpp Search.cpp Sort.cpp Word.cpp main.cpp \
        -o bin/Debug/SearchEngine

    g++ -Wall -fexceptions -O2 -s -std=c++17 \
    Index.cpp Inquire.cpp Readcsv.cpp Search.cpp Sort.cpp Word.cpp main.cpp \
    -o bin/Release/SearchEngine

## 从头创建

修改Search.cpp中的opserach()，将搜集、分析、索引三部分的函数取消注释，再运行（现在是直接进入查询）。

## 结果

    bin/Debug/SearchEngine.exe
    ********************Welcome to Search********************
    ***********             Searching         **************
    ***********             Analyzing         **************
    ***********         Processing Index      **************
    ***********              Inquire          **************
    *Please input several words to search,Separated by space*
    blue sky
    *------Input accepted, looking for web page now---------*
    *-----Press 0 for end, another for looking for again----*
    0
    site:http://en.people.cn/n3/2022/0524/c90000-10100455.html
    title:Govt takes steps to get economy back on track
    site:http://en.people.cn/n3/2022/0422/c90000-10087584.html
    title:Chinese premier signs decree unveiling revised regulation on place names

## 实现

Word读取的实现[Word](./Word.md)

Index的实现[Index](./Index.md)

Search的实现[Search](./Search.md)

Inquire的实现[Inquire](./Inquire.md)
