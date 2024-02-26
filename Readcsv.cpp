
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Readcsv.h"

using namespace std;

vector<string>siteArray;
vector<string>titleArray;
vector<string>storyArray;
int HTMLNUM=0;

/*
读取"news.csv"，得到网址、标题、文章内容4717篇，
其中网址标题分别置于siteArray和titleArray容器之中
文章内容放置于工程文件下为"1"的子文件夹
特别说明，文章内容从1计数，网址标题从0计数
*/
void Readcsv()//读取"news.csv"
{
    clock_t Readcsvstart, Readcsvfinish;
    double ReadcsvTime;
    int html=0;
    int countnum=0;
    int flag=0;
    //0=site,1=title,2=story
	// 读文件
	ifstream inFile("news.csv", ios::in);
	string lineStr;
	vector<vector<string>> strArray;
	Readcsvstart=clock();
	while (getline(inFile, lineStr))
	{
	    char in;

		string str;
		string str1;
		// 打印整行字符串
		//cout << lineStr << endl;
		// 存成二维表结构
		stringstream ss(lineStr);

		//测试读取的csv文件
		//cout<<countnum++<<":\n"<<lineStr<<endl<<endl;

		if(3==flag){
            if(lineStr.size()==0){flag=3;}
            if(isHttp(lineStr)){flag=0;}
            //网页内容写入txt文件，位于子文件夹1下
            else;
                //inputsitestory(html,lineStr);
        }
		if(0==flag){int flagtitle=0;
            getline(ss, str, ',');
            siteArray.push_back(str);

            //cout<<"site:\n"<<str<<endl;
            //leep:
            while(in=ss.get()){
                //cout<<in;

                if(0==flagtitle){
                if(','==in){
                    flagtitle=1;
                    continue;
                    }

                }
                else if(1==flagtitle){
                    flagtitle=0;
                    if('\"'==in||','==in){;break;}
                    else {
                        //str1=str1+',';
                        continue;
                    }
                }
                str1=str1+in;

                //cout<<"flag:"<<flagtitle;
            };

            titleArray.push_back(str1);
            str1.clear();
            flag=3;
            //cout<<"html:\n"<<html<<endl;
            html++;
		}
	}
	Readcsvfinish=clock();
	ReadcsvTime=(double)(Readcsvfinish-Readcsvstart);
	cout<<"写入网页文件的时间为"<<ReadcsvTime<<"ms\n";
	//inputsite(siteArray);
	//inputtitle(titleArray);

	//cout<<"htmlsize:"<<siteArray.size()<<endl;
    //cout<<"titlesize:"<<titleArray.size()<<endl;
    //debugtest_read();
    //debugtext_readhtml(500);
    HTMLNUM=html;
	//getchar();
}


bool isHttp(string str){
if(str.size()<5)return false;
if('h'==str[0]&&'t'==str[1]&&'t'==str[2]&&'p'==str[3])return true;
return false;
}


void inputsitestory(long long int htmlnum,string str){
string filenamenum="";
filenamenum=to_string(static_cast<long long>(htmlnum));
string filename="html"+filenamenum+".txt";
fstream test;
test.open("1\\"+filename,ios::out|ios::app);
test<<str;
//cout<<endl<<endl<<"called"<<endl<<endl;
}


void readstory(){
}

void debugtest_read(){
	cout<<"htmlsize:"<<siteArray.size()<<endl;
    cout<<"titlesize:"<<titleArray.size()<<endl;
    for(int i=0;i<siteArray.size();i++){
        cout<<"id::"<<i<<"site:"<<siteArray[i]<<"_ _ _ _"<<"title:"<<titleArray[i]<<endl;
    }
    cout<<"htmlsize:"<<siteArray.size()<<endl;
    cout<<"titlesize:"<<titleArray.size()<<endl;
}

//单词列表放在input中，读指定id的文件，id从0开始
int readsitestory_state(long long int id,vector<string> &input){

if(id<0)return -1;
string filenamenum="";
filenamenum=to_string(static_cast<long long>(id));
string filename="html"+filenamenum+".txt";
fstream test;
test.open("1\\"+filename,ios::in);
//
if(!test)return -1;
string str;
char ch;
int statech=0;
while(test.get(ch)){
    if(0==statech){
        if(is_Char(ch)){
            statech=1;
            str=str+ch;
            }
        else if(is_Dig(ch)){
            statech=2;
            str=str+ch;
            }
        else if(' '==ch){
            statech=10;
        }
        else if(','==ch){
            statech=11;
        }
        else if('.'==ch||'!'==ch||'?'==ch){
            statech=12;
        }
        else statech=13;
    }
    else if(1==statech){
        if(ch=='\'')statech=5;
        else if(is_Char(ch)){
                statech=1;
                str=str+ch;
                }
        else statech=13;
        }
    else if(2==statech){
        if(is_Dig(ch)){
            statech=2;
            str=str+ch;
            }
        else if(ch==',')statech=3;
        else if(ch=='.')statech=4;
        else statech=13;
        }
    else if(3==statech){
        if(is_Dig(ch))str=str+','+ch;
        else statech=13;
        }
    else if(4==statech){
        if(is_Dig(ch))str=str+'.'+ch;
        else statech=13;
        }
    else if(5==statech){
        if(is_Dig(ch))
        str=str+'\''+ch;
        }

    else {
    input.push_back(str);
    str.clear();
    if(11==statech)input.push_back(",");
    if(12==statech)input.push_back(".");
        if(is_Char(ch)){
            statech=1;
            str=str+ch;
            }
        else if(is_Dig(ch)){
            statech=2;
            str=str+ch;
            }
        else if(' '==ch){
            statech=10;
        }
        else if(','==ch){
            statech=11;
        }
        else if('.'==ch||'!'==ch||'?'==ch){
            statech=12;
        }
        else statech=13;

    }
}

test.close();

return 0;
}

int readsitestory(long long int id,vector<string> &input){

if(id<0)return -1;
string filenamenum="";
filenamenum=to_string(static_cast<long long>(id));
string filename="html"+filenamenum+".txt";
fstream test;
test.open("1\\"+filename,ios::in);
//
if(!test)return -1;
string str;
char ch;
int statech=0;
while(test>>str){
    input.push_back(str);
    str.clear();
}

test.close();
return 0;
}


void debugtext_readhtml(int num){

vector<string> test;
int flag=0;
flag=readsitestory(num,test);
if(-1==flag)cout<<"Error!\n";
else{
    cout<<"success!\n";
    for(int i=0;i<test.size();i++){
        cout<<test[i]<<" ";
    }
}

}

int WORDCOUNTER=0;
vector<string> WORDLIST;

void generate_word_list(vector<string> &input){

int i=0;
int j=0;
/*
    for(int i=0;i<input.size();i++){
        cout<<input[i]<<" ";
    }
*/

for(i=0;i<input.size();i++){
   string str=input[i];
    int flag=0;
    for(j=0;j<WORDLIST.size();j++){
        if(input[i]==WORDLIST[j]){flag=1;break;}
    }
    if(1==flag);
    else{
        WORDLIST.push_back(str);
        WORDCOUNTER++;
        //cout<<"push:"<<str<<endl;
    }
}
//cout<<"generate_word_list called!!"<<endl;
}

void input_wordlist(){
fstream test;
test.open("2\\wordlist.txt",ios::out|ios::app);
    for(int j=0;j<WORDCOUNTER;j++){
        test<<WORDLIST[j]<<"\n";
    }
test.close();
}

/*
int analyseHtml(){
int num=HTMLNUM;
int id=0;
for(id=0;id<6;id++){
    vector<string> input;
    readsitestory(id,input);
        //cout<<"Inputsize:"<<input.size()<<endl;
        //cout<<"id:"<<id<<endl;
    for(int i=0;i<input.size();i++){
        cout<<input[i]<<" ";
    }

    generate_word_list(input);
}
//debugtext_analyseHtml();

return 0;
}
*/

int inputsite(vector<string> &input){
    fstream test;
    test.open("2\\site.txt",ios::out|ios::app);
    for(int i=0;i<input.size();i++){
    test<<input[i]<<"\n";
}
return 0;
}

int inputtitle(vector<string> &input){
    fstream test;
    test.open("2\\title.txt",ios::out|ios::app);
    for(int i=0;i<input.size();i++){
    test<<input[i]<<"\n";
}
return 0;
}

int readsite(vector<string> &input){
fstream test;
test.open("2\\site.txt",ios::in);
//
if(!test)return -1;
string str;
int i=0;
int a;
string line;
while(getline(test,line,'\n')){
    input.push_back(line);
}
test.close();
return 0;
}

int readtitle(vector<string> &input){
fstream test;
test.open("2\\title.txt",ios::in);
//
if(!test)return -1;
string str;
int i=0;
int a;
string line;
while(getline(test,line,'\n')){
    input.push_back(line);
}
test.close();
return 0;
}

void debugtext_analyseHtml(){
    cout<<"WORDLISTsize:"<<WORDLIST.size()<<endl;
    for(int i=0;i<WORDLIST.size();i++){
        cout<<WORDLIST[i]<<"\t\t";
}
cout<<endl;
}

bool is_Char(char c) //判断字符
{
	if((c>='A' && c<='Z') || (c>='a' && c<='z'))return true;
	else
		return false;
}

bool is_Dig(char c) //判断数字
{
	if(c>='0' && c<='9')return true;
	else
		return false;
}



