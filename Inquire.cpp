#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Readcsv.h"
#include "Search.h"

#include "windows.h "
#include "shellapi.h "
using namespace std;
void maxHeapify(std::vector<pair<string,int>> &input, int start, int end) {
    // 求出左右子结点下标
    int left=2*start+1;
    int right=left+1;

    // 求出{vi[start], vi[left], vi[right]}三者中的最大值下标
    int maxIndex=start;
    if (left<=end&&input[left].first>input[maxIndex].first) {
        maxIndex=left;
    }
    if (right<=end&&input[right].first>input[maxIndex].first) {
        maxIndex=right;
    }

    // 如果根结点不是最大的, 交换父子结点后则继续递归调整下一层
    if (maxIndex!=start) {
        {

        std::swap(input[maxIndex], input[start]);}
        maxHeapify(input, maxIndex, end);
    }
}

int rantwordlist(vector<pair<string,int>> &input)
{
    // 初始化建堆: 从最后一个叶子结点开始, 从右到左从下到上调整二叉树成大根堆
    for (int i=input.size()/2-1;i>=0;--i) {
        maxHeapify(input,i,input.size()-1);
    }

    // 堆排序: 交换首尾元素后调整根节点使其符合大根堆特性
    for (int i=input.size()-1;i>=1;--i) {
       std::swap(input[0],input[i]);

        maxHeapify(input,0,i-1);
    }
}
int find_number(vector<string> searchkey,vector<int>&answer)
{    vector<pair<string,int>> input;
     readwordlist(input);
     rantwordlist(input);

     for(int i=0;i<searchkey.size();i++)
     {int sz=input.size();
     int mid=0;
     int left=0;
     int right=sz-1;
     while(left<=right)
         {
             mid=(left+right)/2;//计算中间元素的下标
	//判断mid和看大小，重新精确k所在范围
		if (input[mid].first<searchkey[i])
		{
			left=mid+1;
		}
		else if (input[mid].first>searchkey[i])
		{
			right=mid-1;
		}
		else
		{
			break;
		}
	}
	if (left>right)
		printf("ERROR\n");
	else
	{
     answer.push_back(input[mid].second);
	}

         }
     }

void maxHeapify_web(std::vector<pair<int,int>> &input, int start, int end) {
    // 求出左右子结点下标
    int left=2*start+1;
    int right=left+1;
    // 求出{vi[start], vi[left], vi[right]}三者中的最大值下标
    int maxIndex=start;

    if (left<=end&&input[left].first>input[maxIndex].first) {
        maxIndex=left;
    }
    if (right<=end&&input[right].first>input[maxIndex].first) {
        maxIndex=right;
    }

    // 如果根结点不是最大的, 交换父子结点后则继续递归调整下一层
    if (maxIndex!=start) {
        {
        std::swap(input[maxIndex], input[start]);}
        maxHeapify_web(input, maxIndex, end);
    }
}

void maxHeapify_webfre(std::vector<pair<pair<int/*次数*/,int/*频数*/>,int>> &input, int start, int end) {
    // 求出左右子结点下标

    int left=2*start+1;
    int right=left+1;

    // 求出{vi[start], vi[left], vi[right]}三者中的最大值下标
    int maxIndex=start;

    if (left<=end&&input[left].first.first>input[maxIndex].first.first) {
        maxIndex=left;
    }
    if (left<=end&&input[left].first.first==input[maxIndex].first.first)
    {
        if(input[left].first.second>input[maxIndex].first.second)
             maxIndex=left;
    }
    if (right<=end&&input[right].first.first>input[maxIndex].first.first) {
        maxIndex=right;
    }
     if (right<=end&&input[right].first.first==input[maxIndex].first.first)
    {
        if(input[right].first.second>input[maxIndex].first.second)
             maxIndex=right;
    }
    // 如果根结点不是最大的, 交换父子结点后则继续递归调整下一层
    if (maxIndex!=start) {
        {
        std::swap(input[maxIndex], input[start]);}
        maxHeapify_webfre(input, maxIndex, end);
    }
}

int rantwordlist_web(vector<pair<int,int>> &input)
{
    // 初始化建堆: 从最后一个叶子结点开始, 从右到左从下到上调整二叉树成大根堆
    for (int i=input.size()/2 -1;i>=0;--i) {
        maxHeapify_web(input,i,input.size()-1);
    }

    // 堆排序: 交换首尾元素后调整根节点使其符合大根堆特性
    for (int i=input.size()-1;i>=1;--i) {
       std::swap(input[0],input[i]);

        maxHeapify_web(input,0,i-1);
    }
}

int rantwordlist_webfre( vector<pair<pair<int/*次数*/,int/*频数*/>,int>>&input)
{
    // 初始化建堆: 从最后一个叶子结点开始, 从右到左从下到上调整二叉树成大根堆
    for (int i=input.size()/2 -1;i>=0;--i) {
        maxHeapify_webfre(input,i,input.size()-1);
    }

    // 堆排序: 交换首尾元素后调整根节点使其符合大根堆特性
    for (int i=input.size()-1;i>=1;--i) {
       std::swap(input[0],input[i]);

        maxHeapify_webfre(input,0,i-1);
    }
}


int InquireKeywordFre(vector<string> keywordlist,vector<int> &htmlidfre){
int web[2][10000];
vector<pair<pair<int/*次数*/,int/*频数*/>,int>>webb;

//初始化
for(int v=0;v<2;v++)
    for(int w=0;w<10000;w++)
        web[v][w]=0;

vector<int> answer;

vector<pair<int,vector<pair<int/*编号*/,int/*频数*/>>>> inputfre;

readindexfrequency(inputfre);

find_number(keywordlist,answer);

for(int p=0;p<answer.size();p++)
{
    for(int q=0;q<inputfre[answer[p]].second.size();q++)
    //cout<<input3[answer[p]].second[q]<<' ';
    //cout<<endl;
    {
     web[0][inputfre[answer[p]].second[q].first]++;

     web[1][inputfre[answer[p]].second[q].first]=web[1][inputfre[answer[p]].second[q].first]+inputfre[answer[p]].second[q].second;}
}
for(int w=0;w<10000;w++)
{
    webb.push_back(make_pair(make_pair(web[0][w],web[1][w]),w));
}

rantwordlist_webfre(webb);

for (int w=9999;w>=0;w--)
    if((webb[w].first.first)!=0){
        htmlidfre.push_back(webb[w].second);
        //cout<<webb[w].second<<endl;
    }
}

int InquireKeyword(vector<string> keywordlist,vector<int> &htmlid){
    int web[5000];
    vector<pair<int,int>>webb;
    for(int w=0;w<5000;w++)
        web[w]=0;

vector<int> answer;
vector<pair<int,vector<int>>> input;
readindex(input);

find_number(keywordlist,answer);

for(int p=0;p<answer.size();p++){
    for(int q=0;q<input[answer[p]].second.size();q++)
    //cout<<input3[answer[p]].second[q]<<' ';
    //cout<<endl;
    web[input[answer[p]].second[q]]++;
    }

for(int w=0;w<5000;w++){
    webb.push_back(make_pair(web[w],w));
}

rantwordlist_web(webb);


for (int w=4999;w>=0;w--){
    if(webb[w].first!=0)
        htmlid.push_back(webb[w].second);
}

}

int lookksite(vector<string> sitelist,vector<string> titlelist,vector<int> id){
for(int i=0;i<id.size();i++){
    cout<<"site:"<<sitelist[i]<<endl;
    cout<<"title:"<<titlelist[i]<<endl;
}
return 0;
}

int visitksite(vector<string> sitelist,vector<string> titlelist,vector<int> id){
for(int i=0;i<id.size();i++){
    ShellExecute(NULL,"open",sitelist[i].c_str(),NULL,NULL,SW_HIDE);
    cout<<"site:"<<sitelist[i]<<endl;
    cout<<"title:"<<titlelist[i]<<endl;
}

return 0;
}

int runserachWang(){
    int web[5000];
    vector<pair<int,int>>webb;
    for(int w=0;w<5000;w++)
        web[w]=0;
vector<int> answer;
//vector<pair<int,vector<pair<int,int>>>> input3;
vector<pair<int,vector<int>>> input3;
vector<string> keywordlist;
cout<<"********************Welcome to Search********************"<<endl;
cout<<"*Please input several words to search,Separated by space*"<<endl;
int state=-1;

//Readcsv();
do{
state=keyword_search(keywordlist);
if(0==state)
cout<<"*------Input accepted, looking for web page now---------*"<<endl;

//analyseHtml();
//debugtext_analyseHtml();

}
while(isContinue());

getchar();
readindex(input3);
find_number(keywordlist,answer);
for(int p=0;p<answer.size();p++)
    {for(int q=0;q<input3[answer[p]].second.size();q++)
    //cout<<input3[answer[p]].second[q]<<' ';
    //cout<<endl;
    web[input3[answer[p]].second[q]]++;
    }
       for(int w=0;w<5000;w++)
    {webb.push_back(make_pair(web[w],w));


}
rantwordlist_web(webb);
for (int w=4999;w>=0;w--)
    cout<<webb[w].second<<endl;
debugtest();

return 0;
}

int runserachWangFre(){
    int web[2][10000];

    vector<pair<pair<int/*次数*/,int/*频数*/>,int>>webb;
   for(int v=0;v<2;v++)
    for(int w=0;w<10000;w++)
        web[v][w]=0;
vector<int> answer;
vector<pair<int,vector<pair<int/*编号*/,int/*频数*/>>>> input4;
//vector<pair<int,vector<int>>> input3;
vector<string> keywordlist;
cout<<"********************Welcome to Search********************"<<endl;
cout<<"*Please input several words to search,Separated by space*"<<endl;
int state=-1;

//Readcsv();
do{
state=keyword_search(keywordlist);
if(0==state)
cout<<"*------Input accepted, looking for web page now---------*"<<endl;

//analyseHtml();
//debugtext_analyseHtml();

}
while(isContinue());

getchar();

readindexfrequency(input4);

find_number(keywordlist,answer);

for(int p=0;p<answer.size();p++)

    {for(int q=0;q<input4[answer[p]].second.size();q++)
    //cout<<input3[answer[p]].second[q]<<' ';
    //cout<<endl;
    {
     web[0][input4[answer[p]].second[q].first]++;

     web[1][input4[answer[p]].second[q].first]=web[1][input4[answer[p]].second[q].first]+input4[answer[p]].second[q].second;}
    }

       for(int w=0;w<10000;w++)
    {webb.push_back(make_pair(make_pair(web[0][w],web[1][w]),w));


}
rantwordlist_webfre(webb);
for (int w=9999;w>=0;w--)
    if((webb[w].first.first)!=0)
    cout<<webb[w].second<<endl;
debugtest();

return 0;
}

