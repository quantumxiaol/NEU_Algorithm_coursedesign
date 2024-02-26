#ifndef _INQUIRE_H_
#define _INQUIRE_H_

int find_number(std::vector<std::string> searchkey,std::vector<int>&answer);
int rantwordlist_webfre(std::vector<std::pair<std::pair<int,int>,int>> &input);
int rantwordlist_web(std::vector<std::pair<int,int>> &input);
void maxHeapify(std::vector<std::pair<std::string,int>> &input, int start, int end);
void maxHeapify_web(std::vector<std::pair<int,int>> &input, int start, int end);
void maxHeapify_webfre(std::vector<std::pair<std::pair<int/*次数*/,int/*频数*/>,int>> &input, int start, int end);
int rantwordlist_webfre( std::vector<std::pair<std::pair<int/*次数*/,int/*频数*/>,int>>&input);
int InquireKeywordFre(std::vector<std::string> keywordlist,std::vector<int> &htmlidfre);
int InquireKeyword(std::vector<std::string> keywordlist,std::vector<int> &htmlid);
int lookksite(std::vector<std::string> sitelist,std::vector<std::string> titlelist,std::vector<int> id);
int visitksite(std::vector<std::string> sitelist,std::vector<std::string> titlelist,std::vector<int> id);



#endif
