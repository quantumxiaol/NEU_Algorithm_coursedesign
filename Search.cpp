#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Readcsv.h"
#include "Search.h"
#include "Word.h"
#include "Index.h"
#include "Inquire.h"

using namespace std;

int runsearch(){
vector<string> keywordlist;
std::vector<std::pair<std::string,int>> wordlistfile;
std::vector<std::pair<int,int>> tempindexfile;
std::vector<std::pair<int,std::pair<int,int>>> tempindexfrefile;

cout<<"********************Welcome to Search********************"<<endl;


int state=-1;
/*
//读取网页文件
//Readcsv();

//读取k个查询词
cout<<"*Please input several words to search,Separated by space*"<<endl;
do{
state=keyword_search(keywordlist);
if(0==state)
cout<<"*------Input accepted, looking for web page now---------*"<<endl;

//analyseHtml();
//debugtext_analyseHtml();

}
while(isContinue());

getchar();
*/
//analyseHtml(4717);

//readwordlist(wordlistfile);
//readtempindex(tempindexfile);
//readtempindexfrequency(tempindexfrefile);

//indexProcressTest();
indexProcressTest0();
debugtest();

return 0;
}


int keyword_search(vector<string> &inputlist){
string str;
string lineStr;
getline(cin,lineStr,'\n');
stringstream sstream(lineStr);
while(getline(sstream,str,' ')){
    inputlist.push_back(str);
}
return 0;
}

int isContinue(){
cout<<"*-----Press 0 for end, another for looking for again----*"<<endl;
char ch=getchar();
if('0'==ch)return 0;
else return 1;
}

int preProcess(){
Readcsv();

}

int readwordlist(vector<pair<string,int>> &input){
fstream test;
test.open("2\\wordlist.txt",ios::in);
//
if(!test)return -1;
string str;
int i=0;
int a;
string line;
while(getline(test,line,'\n')){
    stringstream ss(line);
    ss>>str>>a;
    input.push_back(make_pair(str,i++));
    str.clear();
}
test.close();
return 0;
}

int inputwordlist(vector<string> input){
fstream test;
test.open("2\\wordlist.txt",ios::out|ios::app);
//
if(!test)return -1;
for(int i=0;i<input.size();i++){
    test<<input[i]<<"\t"<<i<<"\n";
}
test.close();
return 0;
}

int inputtempindex(vector<pair<int,int>> &input){
fstream test;
test.open("2\\tempindex.txt",ios::out);
//
if(!test)return -1;
for(int i=0;i<input.size();i++){
    test<<input[i].first<<"\t"<<input[i].second<<"\r\n";
}
test.close();
return 0;
}

int readtempindex(vector<pair<int,int>> &input){
fstream test;
test.open("2\\tempindex.txt",ios::in);
//
int word_id,doc_id;
if(!test)return -1;
while(test>>word_id>>doc_id){
    input.push_back(make_pair(word_id,doc_id));
}
test.close();
return 0;
}

int inputtempindexfrequency(vector<pair<int,pair<int,int>>> &input){
fstream test;
test.open("2\\tempindexwithfrequency.txt",ios::out);
//
if(!test)return -1;
for(int i=0;i<input.size();i++){
    test<<input[i].first<<"\t"<<input[i].second.first<<" "<<input[i].second.second<<"\r\n";
}
test.close();
return 0;
}

int readtempindexfrequency(vector<pair<int,pair<int,int>>> &input){
fstream test;
test.open("2\\tempindexwithfrequency.txt",ios::in);
//
int word_id,doc_id,fre;
if(!test)return -1;

while(test>>word_id>>doc_id>>fre){
    //cout<<":"<<word_id<<"\t"<<doc_id<<"\t"<<fre<<"\n";

    input.push_back(make_pair(word_id,make_pair(doc_id,fre)));
}
test.close();
return 0;
}

int inputtempindexsort(vector<pair<int,int>> &input){
fstream test;
test.open("2\\tempindexsort.txt",ios::out);
//
if(!test)return -1;
for(int i=0;i<input.size();i++){
    test<<input[i].first<<"\t"<<input[i].second<<"\r\n";
}
test.close();
return 0;
}

int readtempindexsort(vector<pair<int,int>> &input){
fstream test;
test.open("2\\tempindexsort.txt",ios::in);
//
int word_id,doc_id;
if(!test)return -1;
while(test>>word_id>>doc_id){
    input.push_back(make_pair(word_id,doc_id));
}
test.close();
return 0;
}

int inputtempindexfrequencysort(vector<pair<int,pair<int,int>>> &input){
fstream test;
test.open("2\\tempindexwithfrequencysort.txt",ios::out);
//
if(!test)return -1;
for(int i=0;i<input.size();i++){
    test<<input[i].first<<"\t"<<input[i].second.first<<" "<<input[i].second.second<<"\r\n";
}
test.close();
return 0;
}

int readtempindexfrequencysort(vector<pair<int,pair<int,int>>> &input){
fstream test;
test.open("2\\tempindexwithfrequencysort.txt",ios::in);
//
int word_id,doc_id,fre;
if(!test)return -1;

while(test>>word_id>>doc_id>>fre){
    //cout<<":"<<word_id<<"\t"<<doc_id<<"\t"<<fre<<"\n";

    input.push_back(make_pair(word_id,make_pair(doc_id,fre)));
}
test.close();
return 0;
}

int inputindex(vector<pair<int,vector<int>>> &input){
fstream test;
test.open("3\\index.txt",ios::out|ios::app);
//
if(!test)return -1;
for(int i=0;i<input.size();i++){
    test<<input[i].first<<"\t";
    for(int j=0;j<input[i].second.size();j++)
        test<<input[i].second[j]<<" ";
        test<<"\r\n";
}
test.close();
return 0;
}

int readindex(vector<pair<int,vector<int>>> &input){
fstream test;

string line;
test.open("3\\index.txt",ios::in);
int word_id,doc_id;
int a;
char ch;
if(!test)return -1;
while(getline(test,line,'\n')){
    vector<int> doclist;
    stringstream ss(line);
    //cout<<line<<endl;
    ss>>word_id;
    string str;
    /*
    while(ch=ss.get()){
            if(','==ch){
                istringstream is(str);
                str.clear();
                is>>doc_id;
                doclist.push_back(doc_id);
            }
            else if(is_Dig(ch)) str=str+ch;
            else break;
    }
    */
    while(ss>>doc_id){
        doclist.push_back(doc_id);
    }
    input.push_back(make_pair(word_id,doclist));
}
test.close();
return 0;
}

int inputindexfrequency(vector<pair<int,vector<pair<int,int>>>> &input){
fstream test;
test.open("3\\indexfrequency.txt",ios::out);
//
if(!test)return -1;
for(int i=0;i<input.size();i++){
    test<<input[i].first<<"\t";
    for(int j=0;j<input[i].second.size();j++)
        test<<input[i].second[j].first<<" "<<input[i].second[j].second<<" ";
        test<<"\r\n";
}
test.close();
return 0;
}

int readindexfrequency(vector<pair<int,vector<pair<int,int>>>> &input){
fstream test;

string line;
test.open("3\\indexfrequency.txt",ios::in);
int word_id,doc_id,fre;
int a;
char ch;
if(!test)return -1;
while(getline(test,line,'\n')){
    vector<pair<int,int>> doclist;
    stringstream ss(line);
    //cout<<line<<endl;
    ss>>word_id;
    string str;
    /*
    while(ch=ss.get()){
            if(','==ch){
                istringstream is(str);
                str.clear();
                is>>doc_id;
                doclist.push_back(doc_id);
            }
            else if(is_Dig(ch)) str=str+ch;
            else break;
    }
    */
    while(ss>>doc_id>>fre){
        doclist.push_back(make_pair(doc_id,fre));
    }
    input.push_back(make_pair(word_id,doclist));
}
test.close();
return 0;
}


int debugtest(){
cout<<"*Press 0 for word list, 1 for temp index,2 for index with frequency, 3 for index, another for end*"<<endl;
char ch;
while(1){
    ch=getchar();getchar();
    if('0'==ch)test(0);
    else if('1'==ch)test(1);
    else if('2'==ch)test(2);
    else if('3'==ch)test(3);
    else break;

}
return 0;
}

int test(int num){
vector<pair<string,int>> input1;
vector<pair<int,int>> input2;
vector<pair<int,pair<int,int>>>input3;
vector<pair<int,vector<int>>> input4;

if(0==num){
    readwordlist(input1);
    for(int i=0;i<input1.size();i++){
    //      单词                  单词编号
    cout<<input1[i].first<<" "<<input1[i].second<<"\n";
    }
}

if(1==num){
    readtempindex(input2);
    for(int i=0;i<input2.size();i++){
    //      单词编号            网页编号
    cout<<input2[i].first<<"\t"<<input2[i].second<<"\n";
    }
}

if(2==num){
    readtempindexfrequency(input3);
    for(int i=0;i<input3.size();i++){
    //      单词编号            网页编号                        词频
    cout<<input3[i].first<<"\t"<<input3[i].second.first<<"\t"<<input3[i].second.second<<"\n";
    }
}

if(3==num){
    readindex(input4);
    for(int i=0;i<input4.size();i++){
            //单词编号
    cout<<input4[i].first<<"\t";
    for(int j=0;j<input4[i].second.size();j++)
        cout<<input4[i].second[j]<<" ";
        cout<<"\n";
}
}
return 0;
}


//堆排序模板
// 递归方式调整完全二叉树的根节点, 使其符合大根堆特性
// start和end描述了堆点在数组vi中的下标
void maxHeapify(std::vector<int> &vi, int start, int end) {
    // 求出左右子结点下标
    int left = 2 * start + 1;
    int right = left + 1;

    // 求出{vi[start], vi[left], vi[right]}三者中的最大值下标
    int maxIndex = start;
    if (left <= end && vi[left] > vi[maxIndex]) {
        maxIndex = left;
    }
    if (right <= end && vi[right] > vi[maxIndex]) {
        maxIndex = right;
    }

    // 如果根结点不是最大的, 交换父子结点后则继续递归调整下一层
    if (maxIndex != start) {
        std::swap(vi[maxIndex], vi[start]);
        maxHeapify(vi, maxIndex, end);
    }
}

// 堆排序
void heapSort(std::vector<int> &vi) {
    // 初始化建堆: 从最后一个叶子结点开始, 从右到左从下到上调整二叉树成大根堆
    for (int i = vi.size() / 2 - 1; i >= 0; --i) {
        maxHeapify(vi, i, vi.size() - 1);
    }

    // 堆排序: 交换首尾元素后调整根节点使其符合大根堆特性
    for (int i = vi.size() - 1; i >= 1; --i) {
        std::swap(vi[0], vi[i]);
        maxHeapify(vi, 0, i - 1);
    }
}

int kkeyword(vector<string> &keyword){
//读取k个查询词
int state;
cout<<"*Please input several words to search,Separated by space*"<<endl;
do{
state=keyword_search(keyword);
if(0==state)
cout<<"*------Input accepted, looking for web page now---------*"<<endl;

//analyseHtml();
//debugtext_analyseHtml();

}
while(isContinue());
}

int opserach(){
cout<<"********************Welcome to Search********************"<<endl;

vector<string> keyword;
vector<string> site;
vector<string> title;
//搜集
cout<<"***********             Searching         **************"<<endl;

//Readcsv();
int htmln=HTMLNUM;

//分析
cout<<"***********             Analyzing         **************"<<endl;

//analyseHtml(htmln+1);

//索引
cout<<"***********         Processing Index      **************"<<endl;

//indexProcressTest();

//查询
cout<<"***********              Inquire          **************"<<endl;

kkeyword(keyword);

vector<int>answer;
InquireKeywordFre(keyword,answer);
InquireKeyword(keyword,answer);
readsite(site);
readtitle(title);
lookksite(site,title,answer);
//visitksite(site,title,answer);

return 0;
}








