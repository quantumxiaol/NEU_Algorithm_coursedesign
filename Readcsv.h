#ifndef _READCSV_H_
#define _READCSV_H_

#include <ctime>


void Readcsv();
bool isHttp(std::string str);
void inputsitestory(long long int htmlnum,std::string str);
void readstory();
void debugtest_read();
int readsitestory(long long int id,std::vector<std::string> &input);
int readsitestory_state(long long int id,std::vector<std::string> &input);
void debugtext_readhtml(int num);
int analyseHtml();
void debugtext_analyseHtml();

int inputsite(std::vector<std::string> &input);
int inputtitle(std::vector<std::string> &input);
int readsite(std::vector<std::string> &input);
int readtitle(std::vector<std::string> &input);

bool is_Char(char c);
bool is_Dig(char c);

extern std::vector<std::string>siteArray;
extern std::vector<std::string>titleArray;
extern std::vector<std::string>storyArray;
extern std::vector<std::string> WORDLIST;
extern int WORDCOUNTER;
extern int HTMLNUM;

#endif
