
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include<string.h>
#include <ctype.h>
#include <utility>
#include <algorithm>
#include "Readcsv.h"
#include "Search.h"
#include "Word.h"


using namespace std;
int triesearchnum=0;
struct TrieNode{
    vector<TrieNode *> child;
    bool isEnd;
    int wordid;
    TrieNode() {
        this->child = vector<TrieNode *>(67,nullptr);
        this->isEnd = false;
        //不存在的单词的id
        wordid=-114514;
    }
};
int subscript(char ch){
switch(ch){

case 'a': return 0;
case 'b': return 1;
case 'c': return 2;
case 'd': return 3;
case 'e': return 4;
case 'f': return 5;
case 'g': return 6;
case 'h': return 7;
case 'i': return 8;
case 'j': return 9;
case 'k': return 10;
case 'l': return 11;
case 'm': return 12;
case 'n': return 13;
case 'o': return 14;
case 'p': return 15;
case 'q': return 16;
case 'r': return 17;
case 's': return 18;
case 't': return 19;
case 'u': return 20;
case 'v': return 21;
case 'w': return 22;
case 'x': return 23;
case 'y': return 24;
case 'z': return 25;

case 'A': return 26;
case 'B': return 27;
case 'C': return 28;
case 'D': return 29;
case 'E': return 30;
case 'F': return 31;
case 'G': return 32;
case 'H': return 33;
case 'I': return 34;
case 'J': return 35;
case 'K': return 36;
case 'L': return 37;
case 'M': return 38;
case 'N': return 39;
case 'O': return 40;
case 'P': return 41;
case 'Q': return 42;
case 'R': return 43;
case 'S': return 44;
case 'T': return 45;
case 'U': return 46;
case 'V': return 47;
case 'W': return 48;
case 'X': return 49;
case 'Y': return 50;
case 'Z': return 51;

case '-': return 52;
case '.': return 53;

case '0': return 54;
case '1': return 55;
case '2': return 56;
case '3': return 57;
case '4': return 58;
case '5': return 59;
case '6': return 60;
case '7': return 61;
case '8': return 62;
case '9': return 63;

case ',':return 64;
case '&':return 65;

default:return 66;
}
return -1;
}

void insert(TrieNode * root, const string & word,int id) {
    TrieNode * node = root;
    for (auto c : word) {
        if (node->child[subscript(c)] == nullptr) {
            node->child[subscript(c)] = new TrieNode();
        }
        node = node->child[subscript(c)];
    }
    node->isEnd = true;
    node->wordid=id;
}

class WordDictionary {
public:
    WordDictionary() {
        trie = new TrieNode();
    }
    ~WordDictionary(){
    release(trie);
    }
    void release(TrieNode* r){
        if(!r)return;
        TrieNode* tmp = r;
        for(int i=0;i<67;i++){
        release(tmp->child[i]);
        }
        delete tmp;//cout<<"releaseCalled\n";
    }
    void addWord(string word,int id) {
        //string str=word;
        //for(auto it=str.begin();it!=str.end();it++)if(*it=='-'||*it=='.')str.erase(it);
        //transform (str.begin (), str.end (), str.begin (), ::tolower);
        insert(trie,word,id);
    }

    int searchwordid(string word){
        int a;
        dfsid(word, 0, trie,a);
        return a;
    }

    bool search(string word) {
        //string str=word;
        //cout<<"searchcalled"<<triesearchnum++<<"\n";
        //for(auto it=str.begin();it!=str.end();it++)if(*it=='-'||*it=='.')str.erase(it);
        //transform (str.begin (), str.end (), str.begin (), ::tolower);
        return dfs(word, 0, trie);
    }

    bool dfsid(const string & word,int index,TrieNode * node,int &id) {
    if(index==word.size()){
            id=node->wordid;
            return node->isEnd;
        }
        char ch = word[index];
        //if (ch >= 'a' && ch <= 'z')
            {
            TrieNode * child = node->child[subscript(ch)];
            if (child != nullptr && dfsid(word, index + 1, child,id)) {
                //id=child->wordid;
                return true;
            }
        }

        /*
        //模糊匹配
        else if (ch == '*') {
            for (int i = 0; i < 26; i++) {
                TrieNode * child = node->child[i];
                if (child != nullptr && dfs(word, index + 1, child)) {
                    return true;
                }
            }
        }
        */
        return false;
    }

    bool dfs(const string & word,int index,TrieNode * node) {
    if(index==word.size()){
            return node->isEnd;
        }
        char ch = word[index];
        //if (ch >= 'a' && ch <= 'z')
            {
            TrieNode * child = node->child[subscript(ch)];
            if (child != nullptr && dfs(word, index + 1, child)) {
                return true;
            }
        }
    {
        /*
        //模糊匹配
        else if (ch == '*') {
            for (int i = 0; i < 26; i++) {
                TrieNode * child = node->child[i];
                if (child != nullptr && dfs(word, index + 1, child)) {
                    return true;
                }
            }
        }
        */
    }
        return false;
    }
private:
    TrieNode *trie;
};
//WordDictionary WordList;

//对单个网页的单词统计词频用
//字典树的结点
struct trie {
    int n;
    bool isRecord;
    trie* son[67];
    trie (): n(0) {
        isRecord=false;
        for (int i = 0; i < 67; ++i) {
            son[i] = nullptr;
        }
    }
};

class WordsFrequency {
private:
    trie* root;
public:
    WordsFrequency(vector<string>& book) {
        root = new trie();
        trie* tmp = root;
        for (auto& i : book) {
            tmp = root;
            for (auto& ch : i) {
                int next = subscript(ch);
                if (!tmp->son[next]) {
                    tmp->son[next] = new trie();
                }
                tmp = tmp->son[next];
            }
            // 到达底部后, 叶子结点++,说明单词出现一次
            ++(tmp->n);
        }
    }
    ~WordsFrequency(){
        release(root);
        //delete root;
    }
    void release(trie* r){
        if(!r)return;
        trie* tmp = r;
        for(int i=0;i<67;i++){
        release(tmp->son[i]);
        }
        delete tmp;//cout<<"releaseCalled\n";
    }
    int get(string word) {
        trie* find = root;
        for (auto& i : word) {
            int next = subscript(i);
            if (find->son[next]) find = find->son[next];
            else return 0;
        }
        find->isRecord=true;
        return find->n;
    }
    bool isRecordword(string word){
        trie* find = root;
        for (auto& i : word) {
            int next = subscript(i);
            if (find->son[next]) find = find->son[next];
            else return 0;
        }
        return find->isRecord;
    }
};


void debugWordDictionary(){

cout<<"*debugWordDictionary is working*"<<endl;
}

vector<string> wordTP;
bool isletter(char str)
{
    if((str>='A'&&str<='Z')||(str>='a'&&str<='z'))
        return true;
    else
        return false;
}
bool isdigit(char str)
{
    if(str>='0'&&str<='9')
        return true;
    else
        return false;
}


int mainTPfunction()
{
int doc_id=1;
int term_id=1;

while(doc_id<3)
{
    pair<int,string > p;
    string filenamenum="";
    filenamenum=to_string(static_cast<long long>(doc_id));
    string filename="html"+filenamenum+".txt";
    fstream test;
    test.open("1\\"+filenamenum,ios::in);

    if(!test)
        return -1;
    string str;
    int statech=0;
    while(test>>str)
    {

        for(int i=0;i<str.size();i++)
            while(str[i]==','||str[i]=='\t'||str[i]=='，'||str[i]==' '||str[i]=='('||str[i]==')'||
                  (str[i]=='-'&&!isletter(str[i-1])&&!isletter(str[i+1]))
                  ||str[i]=='\''||str[i]=='\"'||(str[i]=='.'&&str!="a.m."&&str!="p.m.")
                  ||str[i]=='_'||str[i]=='?'||str[i]=='!'||str[i]=='&'||str[i]=='/'||str[i]==';')
                {
                    int pos = str.find(str[i]);
                    str = str.erase(pos,1);
                }
        if(str.size()==0)
            continue;
        else
        {
                 wordTP.push_back(str);
                 p.first=term_id;
                 p.second=filenamenum;
                 cout<<p.first<<"\t"<<p.second<<"\r\n";
                 term_id++;
        }
    }
    str.clear();
    test.close();
    doc_id++;
    p = make_pair(term_id,filenamenum);
}
	return 0;
}


int readsitestory_TP(long long int id,vector<string> &input){

pair<int,int > p;

//词频（未实现）
int frequency;

//网页文件读取
if(id<0)return -1;
string filenamenum="";
filenamenum=to_string(static_cast<long long>(id));
string filename="html"+filenamenum+".txt";
fstream test;
test.open("1\\"+filename,ios::in);

if(!test)return -1;


int term_id=1;
string str;
char ch;
int statech=0;
    while(test>>str)
    {

        for(int i=0;i<str.size();i++)
            while((str[i]==','||str[i]=='\t'||str[i]==' '||str[i]=='('||str[i]==')'||
                  (str[i]=='-'&&!isletter(str[i-1])&&!isletter(str[i+1]))
                  ||str[i]=='\''||str[i]=='\"'||(str[i]=='.'&&str!="a.m."&&str!="p.m.")
                  ||str[i]=='_'||str[i]=='?'||str[i]=='!'||str[i]=='&'))
                {
                    int pos = str.find(str[i]);
                    str = str.erase(pos,1);
                }
        if(str.size()==0)
            continue;
        else
        {   {
                    input.push_back(str);
                    p.first=term_id;
                    p.second=id;
                    term_id++;
                }
                 //cout<<p.first<<"\t"<<p.second<<"\r\n";
        }
    }
    str.clear();
    test.close();
    //p = make_pair(term_id,filenamenum);

return 0;
}

int tempindex(long long int id,vector<string> htmlword,vector<string>&wordlist,WordDictionary &WD,vector<pair<int,int>>&index1){
    //,vector<pair<int,int>>index1,vector<pair<int,pair<int,int>>>index2

    //单词id，<网页id，词频>
    pair<int,pair<int,int>> triplepair;
    //<单词id，网页id>
    pair<int,int> wordpair;
    int wdid;
    WordsFrequency WDFre(htmlword);
    int i=0;

    for(i=0;i<htmlword.size();i++){
    //if(is_Dig(htmlword[i][0])||('$'==htmlword[i][0]))continue;

    //已经在全篇中出现过力
    if(WD.search(htmlword[i])){
        //frequency++;
        //cout<<"word id:"<<htmlword[i]<<endl;
    }
    else{
        WD.addWord(htmlword[i],wordlist.size());
        //cout<<"addword"<<"\t"<<htmlword[i]<<"\t"<<wordlist.size()<<endl;
        //cout<<"addwordid"<<"\t"<<htmlword[i]<<"\t"<<WD.searchwordid(htmlword[i])<<endl;
        //index1.push_back(make_pair(wordlist.size(),id));
        wordlist.push_back(htmlword[i]);
    }

    if(WDFre.isRecordword(htmlword[i])){
                //cout<<htmlword[i]<<"interup\n";
                //continue;
    }
        else{
        //标记单词被访问
        WDFre.get(htmlword[i]);
        wdid=WD.searchwordid(htmlword[i]);
        //调试输出
        //cout<<"word id:"<<htmlword[i]<<"\t"<<wdid<<"\t"<<id<<endl;
        //int fre=WDFre.get(htmlword[i]);
        index1.push_back(make_pair(wdid,id));
        }


    /*
    if(WDFre.isRecordword(htmlword[i]))continue;
    else{
        wdid=WD.searchwordid(htmlword[i]);
        //cout<<"word id:"<<htmlword[i]<<endl;
        int fre=WDFre.get(htmlword[i]);
        index1.push_back(make_pair(wdid,id));
        }
    */



//    wordlist.push_back(htmlword[i]);

    }
    return 0;

}

int tempindexwithfrequency(long long int id,vector<string> htmlword,WordDictionary &WD,vector<pair<int,pair<int,int>>>&index1){
    //,vector<pair<int,int>>index1,vector<pair<int,pair<int,int>>>index2

    //单词id，<网页id，词频>
    pair<int,pair<int,int>> triplepair;
    //<单词id，网页id>
    pair<int,int> wordpair;
    int i=0;
    int wdid;
    WordsFrequency WDFre(htmlword);
    for(i=0;i<htmlword.size();i++){
        if(WDFre.isRecordword(htmlword[i])){
                //cout<<htmlword[i]<<"interup\n";
                continue;
        }
        else{
        wdid=WD.searchwordid(htmlword[i]);
        //cout<<"word id:"<<htmlword[i]<<"\t"<<wdid<<endl;
        int fre=WDFre.get(htmlword[i]);
        index1.push_back(make_pair(wdid,make_pair(id,fre)));
        }
    }
    return 0;

}

int analyseHtml(int num=HTMLNUM){

    int term_id=0;
    WordDictionary WordList;
    WordDictionary WordListFre;
    vector<pair<int,int>> index;
    vector<pair<int,pair<int,int>>>indexfre;
    clock_t analysestart, analysefinish;
    clock_t a1,a2,b1,b2,c1,c2;
    double analyseTime;
    double Ta,Tb,Tc;
    analysestart=clock();
    for(int i=1;i<num;i++){
        vector<string> HtmlWordTemp;
        readsitestory_TP(i,HtmlWordTemp);
        //cout<<"di"<<i<<"pian:"<<endl;
        //PrintVector(HtmlWordTemp,"wangyeneirongdanci");
        tempindex(i,HtmlWordTemp,WORDLIST,WordList,index);
        tempindexwithfrequency(i,HtmlWordTemp,WordList,indexfre);
    }
    analysefinish=clock();
    analyseTime=(double)(analysefinish-analysestart);
    cout<<"计算临时索引文件的时间为"<<analyseTime<<"ms\n";
    //写入临时索引
    a1=clock();
    inputtempindex(index);
    a2=clock();
    Ta=(double)(a2-a1);
    cout<<"写入临时索引文件的时间为"<<Ta<<"ms\n";

    //写入带词频的索引
    b1=clock();
    inputtempindexfrequency(indexfre);
    b2=clock();
    Tb=(double)(b2-b1);
    cout<<"写入带词频临时索引文件的时间为"<<Tb<<"ms\n";

    //写入单词编码表
    c1=clock();
    inputwordlist(WORDLIST);
    c2=clock();
    Tc=(double)(c2-c1);
    cout<<"写入单词编码表的时间为"<<Tc<<"ms\n";
    //cout<<"WORDLIST :"<<WORDLIST.size()<<endl;
    //PrintVector(WORDLIST,"WORDLIST");
    //cout<<"WORDLIST :"<<WORDLIST.size()<<endl;

    return 0;
}




int generate_temp_index(vector<pair<int,int>> input){
    fstream indextemp;
    indextemp.open("2\\tempindex.txt",ios::in);
    return 0;
}

void PrintVector(vector<string> v,string information){
for(int i=0;i<v.size();i++)cout<<""<<i<<": "<<v[i]<<endl;
cout<<endl<<endl<<information<<endl<<endl;
}

void PrintVector(vector<int> v,string information){
cout<<"size:"<<v.size()<<endl;
for(int i=0;i<v.size();i++)cout<<""<<i<<": "<<v[i]<<endl;
cout<<endl<<endl<<information<<endl<<endl;
}

void PrintVector(vector<pair<int,int>> v,string information){
cout<<"size:"<<v.size()<<endl;
for(int i=0;i<v.size();i++)cout<<""<<i<<": "<<v[i].first<<" "<<v[i].second<<endl;
cout<<endl<<endl<<information<<endl<<endl;
}

void PrintVector(vector<pair<int,pair<int,int>>> v,string information){
cout<<"size:"<<v.size()<<endl;
for(int i=0;i<v.size();i++)cout<<""<<i<<": "<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
cout<<endl<<endl<<information<<endl<<endl;
}



