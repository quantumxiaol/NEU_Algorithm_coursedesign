#ifndef _WORD_H_
#define _WORD_H_

class WordDictionary;
//extern WordDictionary WordList;

extern std::vector<std::string> wordTP;

int mainTPfunction();
bool isletter(char str);
bool isdigit(char str);
int subscript(char ch);

int readsitestory_TP(long long int id,std::vector<std::string> &input);
int analyseHtml(int num);
int generate_temp_index(std::vector<std::pair<int,int>> input);
int tempindex(long long int id,std::vector<std::string> htmlword,std::vector<std::string>&wordlist,WordDictionary &WD,std::vector<std::pair<int,int>>&index1);
int tempindexwithfrequency(long long int id,std::vector<std::string> htmlword,WordDictionary &WD,std::vector<std::pair<int,std::pair<int,int>>>&index1);
void PrintVector(std::vector<std::string> v,std::string information);
void PrintVector(std::vector<int> v,std::string information);
void PrintVector(std::vector<std::pair<int,int>> v,std::string information);
void PrintVector(std::vector<std::pair<int,std::pair<int,int>>> v,std::string information);
#endif
