#ifndef _SORT_H_
#define _SORT_H_
#include "utility"
#include <vector>
using namespace std;
struct ExNode{
   std::pair<int,int> key;
};
typedef ExNode External[6];
typedef int LoserTree[5];//表示非终端结点，由于是完全二叉树，所以可以使用一维数组来表示

/*
bool cmpExNodeG(ExNode a,ExNode b){
    if(a.key.first>b.key.first)
        return true;
    else
        return false;
    }

bool cmpExNodeL(ExNode a,ExNode b){
    if(a.key.first<b.key.first)
        return true;
    else
        return false;
    }

bool cmpExNodeE(ExNode a,ExNode b){
    if(a.key.first==b.key.first)
        return true;
    else
        return false;
    }
*/
bool cmppairG(std::pair<int,int> a,std::pair<int,int> b);
bool cmppairL(std::pair<int,int> a,std::pair<int,int> b);
bool cmppairGFre(std::pair<int,std::pair<int,int>>a,std::pair<int,std::pair<int,int>> b);
bool cmppairLFre(std::pair<int,std::pair<int,int>> a,std::pair<int,std::pair<int,int>> b);

void shellSort(vector<pair<int,int>>&vi);
void shellSortFre(vector<pair<int,pair<int,int>>>&vi);
void merge_sort(vector<pair<int,int>>&q, int l, int r);
void merge_sortFre(vector<pair<int,pair<int,int>>>&q, int l, int r);

#endif
