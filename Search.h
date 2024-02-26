#ifndef _SEARCH_H_
#define _SEARCH_H_

int runsearch();
int opserach();
int keyword_search(std::vector<std::string> &inputlist);
int isContinue();
int preProcess();

int debugtest();
int test(int num);


int inputwordlist(std::vector<std::string>input);
int readwordlist(std::vector<std::pair<std::string,int>> &input);
int inputtempindex(std::vector<std::pair<int,int>> &input);
int readtempindex(std::vector<std::pair<int,int>> &input);
int inputindex(std::vector<std::pair<int,std::vector<int>>> &input);
int readindex(std::vector<std::pair<int,std::vector<int>>> &input);
int inputtempindexfrequency(std::vector<std::pair<int,std::pair<int,int>>> &input);
int readtempindexfrequency(std::vector<std::pair<int,std::pair<int,int>>> &input);

int inputtempindexsort(std::vector<std::pair<int,int>> &input);
int readtempindexsort(std::vector<std::pair<int,int>> &input);
int inputtempindexfrequencysort(std::vector<std::pair<int,std::pair<int,int>>> &input);
int readtempindexfrequencysort(std::vector<std::pair<int,std::pair<int,int>>> &input);

int inputindexfrequency(std::vector<std::pair<int,std::vector<std::pair<int,int>>>> &input);
int readindexfrequency(std::vector<std::pair<int,std::vector<std::pair<int,int>>>> &input);
#endif

