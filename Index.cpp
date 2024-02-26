#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include<string.h>
#include <ctype.h>
#include <utility>
#include <algorithm>
#include <iterator>
#include "Readcsv.h"
#include "Search.h"
#include "Word.h"
#include "Index.h"
#include "Sort.h"
//仅用于生成测试样例让王怡正先使用，实际实现由季晔实现
#include <algorithm>


using namespace std;

bool cmp0(const pair<int, int>& a, const pair<int, int>& b){
	// 以pair对的第1个数的大小从大往小排序
	return a.first < b.first;
}
bool cmp1(const pair<int, int>& a, const pair<int, int>& b){
	// 以pair对的第2个数的大小从大往小排序
	return a.second < b.second;
}
bool cmp2(const pair<int,pair<int,int>>& a, const pair<int,pair<int,int>>& b){
	// 以pair对的第1个数的大小从大往小排序
	return a.first < b.first;
}


int indexProcressTest(){
clock_t sortstart,sortfinish;
clock_t indexstart,indexfinish;
clock_t indexfrestart,indexfrefinish;
double indexTime,sortTime,indexfreTime;
cout<<"index called\n";
vector<pair<string,int>>wordlist;
readwordlist(wordlist);

//*********单词id**网页id
vector<pair<int,int>> temindex;
//*********单词id********网页id**词频
vector<pair<int,pair<int,int>>> temindexfre;

//*********单词id**网页id
vector<pair<int,vector<int>>> indextest;
//*********单词id********网页id**词频
vector<pair<int,vector<pair<int,int>>>> indexfretest;

readtempindex(temindex);
readtempindexfrequency(temindexfre);
cout<<"read called\n";


sortstart=clock();

//sort(temindex.begin(), temindex.end(), cmp0);
//sort(temindexfre.begin(), temindexfre.end(), cmp2);

/*
int l=temindex.size()-1;
merge_sort(temindex,0,l);
int lfre=temindexfre.size()-1;
merge_sortFre(temindexfre,0,l);
*/
shellSort(temindex);
shellSortFre(temindexfre);
sortfinish=clock();
cout<<"sort called\n";
sortTime=(double)(sortfinish-sortstart);
indexstart=clock();


inputtempindexsort(temindex);
inputtempindexfrequencysort(temindexfre);
cout<<"input called\n";


vector<int> small;
vector<pair<int,int>> smallfre;
cout<<"temindex size"<<temindex.size()<<"  "<<"temindexfre size"<<temindexfre.size()<<endl;
int i=0;


for(auto it=temindex.begin();it!=temindex.end();){
    //cout<<"for called";
    if(it==temindex.begin()){it++;continue;}
    int wordid=(*(it-1)).first;
    //cout<<"wordid called\n";
    if((*it).first==(*(it-1)).first){
        small.push_back( (*(it-1)).second );
        it=temindex.erase(it-1);
        it++;
        continue;
        //cout<<"1919810\n";
    }
    else{
        small.push_back((*(it-1)).second);
        indextest.push_back(make_pair(wordid,small));
        //PrintVector(small,"small");
        inputindextemp(indextest[indextest.size()-1]);
        small.clear();
        vector<int>().swap(small);
        it++;
        //cout<<"-1919810\n";
    }
    //cout<<temindex.size()<<endl;

}
indexfinish=clock();
indexfrestart=clock();
for(auto it=temindexfre.begin();it!=temindexfre.end();){
    if(it==temindexfre.begin()){it++;continue;}
    int wordid=(*(it-1)).first;
    if((*it).first==((*(it-1))).first){
        smallfre.push_back(make_pair((*(it-1)).second.first,(*(it-1)).second.second));
        it=temindexfre.erase(it-1);
        it++;
        continue;
    }
    else{
        smallfre.push_back(make_pair((*(it-1)).second.first,(*(it-1)).second.second));
        indexfretest.push_back(make_pair(wordid,smallfre));
        inputindexfrequencytemp(indexfretest[indexfretest.size()-1]);
        smallfre.clear();
        vector<pair<int,int>>().swap(smallfre);
        it++;
    }
}
indexfrefinish=clock();
cout<<"generate called\n";

inputindex(indextest);
inputindexfrequency(indexfretest);
cout<<"input called\n";

indexTime=(double)(indexfinish-indexstart);
indexfreTime=(double)(indexfrefinish-indexfrestart);
cout<<"排序索引文件的时间为"<<sortTime<<"ms\n";
cout<<"写入倒排索引文件的时间为"<<indexTime<<"ms\n";
cout<<"写入(频率)倒排索引文件的时间为"<<indexfreTime<<"ms\n";
return 0;
}

int indexProcressTest0(){
cout<<"index called\n";
vector<pair<string,int>>wordlist;
readwordlist(wordlist);

//*********单词id**网页id
vector<pair<int,int>> temindex;
//*********单词id********网页id**词频
vector<pair<int,pair<int,int>>> temindexfre;

//*********单词id**网页id
vector<pair<int,vector<int>>> indextest;
//*********单词id********网页id**词频
vector<pair<int,vector<pair<int,int>>>> indexfretest;

readtempindex(temindex);
readtempindexfrequency(temindexfre);
cout<<"read called\n";

sort(temindex.begin(), temindex.end(), cmp0);
sort(temindexfre.begin(), temindexfre.end(), cmp2);

cout<<"sort called\n";

inputtempindexsort(temindex);
inputtempindexfrequencysort(temindexfre);
cout<<"input called\n";


vector<int> small;
vector<pair<int,int>> smallfre;
cout<<"temindex size"<<temindex.size()<<"  "<<"temindexfre size"<<temindexfre.size()<<endl;
int i=0;
for(auto it=temindex.begin();it!=temindex.end();){
    //cout<<"for called";
    if(it==temindex.begin()){it++;continue;}
    int wordid=(*(it-1)).first;
    //cout<<"wordid called\n";
    if((*it).first==(*(it-1)).first){
        small.push_back( (*(it-1)).second );
        it=temindex.erase(it-1);
        it++;
        continue;
        //cout<<"1919810\n";
    }
    else{
        small.push_back((*(it-1)).second);
        indextest.push_back(make_pair(wordid,small));
        //PrintVector(small,"small");
        inputindextemp(indextest[indextest.size()-1]);
        small.clear();
        vector<int>().swap(small);
        it++;
        //cout<<"-1919810\n";
    }
    //cout<<temindex.size()<<endl;

}

for(int i=0;i<temindex.size();i++){
    //cout<<"for called";
    if(i==0){continue;}
    int wordid=temindex[i-1].first;
    //cout<<"wordid called\n";
    if(temindex[i].first==temindex[i-1].first){
        small.push_back( temindex[i-1].second );


        continue;
        //cout<<"1919810\n";
    }
    else{
        small.push_back(temindex[i-1].second);
        indextest.push_back(make_pair(wordid,small));
        //PrintVector(small,"small");
        inputindextemp(indextest[indextest.size()-1]);
        small.clear();
        vector<int>().swap(small);

        //cout<<"-1919810\n";
    }
    //cout<<temindex.size()<<endl;

}


/*
for(auto it=temindexfre.begin();it!=temindexfre.end();){
    if(it==temindexfre.begin()){it++;continue;}
    int wordid=(*(it-1)).first;
    if((*it).first==((*(it-1))).first){
        smallfre.push_back(make_pair((*(it-1)).second.first,(*(it-1)).second.second));
        //it=temindexfre.erase(it-1);
        it++;
        continue;
    }
    else{
        smallfre.push_back(make_pair((*(it-1)).second.first,(*(it-1)).second.second));
        indexfretest.push_back(make_pair(wordid,smallfre));
        inputindexfrequencytemp(indexfretest[indexfretest.size()-1]);
        smallfre.clear();
        vector<pair<int,int>>().swap(smallfre);
        it++;
    }
}
*/
cout<<"generate called\n";

//inputindex(indextest);
//inputindexfrequency(indexfretest);
cout<<"input called\n";

return 0;
}

int inputindextemp(pair<int,vector<int>> &input){
fstream test;
test.open("3\\indextemp.txt",ios::out|ios::app);
//
if(!test)return -1;

    test<<input.first<<"\t";
    for(int j=0;j<input.second.size();j++)
        test<<input.second[j]<<" ";
        test<<"\r\n";

test.close();
return 0;
}


int inputindexfrequencytemp(pair<int,vector<pair<int,int>>> &input){
fstream test;
test.open("3\\indexfrequencytemp.txt",ios::out);
//
if(!test)return -1;

    test<<input.first<<"\t";
    for(int j=0;j<input.second.size();j++)
        test<<input.second[j].first<<" "<<input.second[j].second<<" ";
        test<<"\r\n";

test.close();
return 0;
}


pair<int,int> readunsortindex(fstream &test,pair<int,int> &input){

//test.open("2\\title.txt",ios::in);

//if(!test)return -1;
string str;
int i=0;
int a,b;
string line;
getline(test,line,'\n');
stringstream ss(line);
ss>>a>>b;
//input.push_back(line);
input=make_pair(a,b);

return input;
}


int inputunsortindex(fstream &test,pair<int,int> &input){
//test.open("2\\title.txt",ios::in);

if(!test)return -1;
string str;
int i=0;

test<<input.first<<" "<<input.second<<"\n";
//input.push_back(line);

return 1;
}


