#ifndef _INDEX_H_
#define _INDEX_H_

bool cmp0(const std::pair<int, int>& a, const std::pair<int, int>& b);
bool cmp1(const std::pair<int, int>& a, const std::pair<int, int>& b);
bool cmp2(const std::pair<int,std::pair<int,int>>& a, const std::pair<int,std::pair<int,int>>& b);

int indexProcressTest();
int indexProcressTest0();
int inputindextemp(std::pair<int,std::vector<int>> &input);
int inputindexfrequencytemp(std::pair<int,std::vector<std::pair<int,int>>> &input);
#endif
