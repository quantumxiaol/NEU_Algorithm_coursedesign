#include "Sort.h"
#include <string>
#include <iostream>
#include <vector>

#include "Readcsv.h"
#include "Search.h"
#include "Word.h"

bool cmppairG(std::pair<int,int> a,std::pair<int,int> b){
    if(a.first>b.first)
        return true;
    else
        return false;
    }

bool cmppairL(std::pair<int,int> a,std::pair<int,int> b){
    if(a.first<b.first)
        return true;
    else
        return false;
    }

bool cmppairGFre(std::pair<int,std::pair<int,int>>a,std::pair<int,std::pair<int,int>> b){
    if(a.first>b.first)
        return true;
    else
        return false;
    }

bool cmppairLFre(std::pair<int,std::pair<int,int>> a,std::pair<int,std::pair<int,int>> b){
    if(a.first<b.first)
        return true;
    else
        return false;
    }

void shellSort(vector<pair<int,int>>&vi){
    int len = vi.size();
    if (len <= 1) {
        return;
    }

    // 声明一个参数gap, 一般初始值设置为len/2, 然后缩小方式为gap/2, 直到gap等于1转化为插入排序
    int gap = len / 2;
    while (gap >= 1) {
        // 将数据分成gap组, 然后每组内进行插入排序
        for (int i = gap; i < len; ++i) {
            pair<int,int> insert_value = vi[i];
            int j = i - gap;
            while (j >= 0 && cmppairG(vi[j],insert_value)) {
                vi[j + gap] = vi[j];
                j -= gap;
            }
            vi[j + gap] = insert_value;
        }

        gap /= 2;
    }
}

void shellSortFre(vector<pair<int,pair<int,int>>>&vi){
    int len = vi.size();
    if (len <= 1) {
        return;
    }

    // 声明一个参数gap, 一般初始值设置为len/2, 然后缩小方式为gap/2, 直到gap等于1转化为插入排序
    int gap = len / 2;
    while (gap >= 1) {
        // 将数据分成gap组, 然后每组内进行插入排序
        for (int i = gap; i < len; ++i) {
            pair<int,pair<int,int>> insert_value = vi[i];
            int j = i - gap;
            while (j >= 0 && cmppairGFre(vi[j],insert_value)) {
                vi[j + gap] = vi[j];
                j -= gap;
            }
            vi[j + gap] = insert_value;
        }

        gap /= 2;
    }
}


int disperseVector(vector<pair<int,int>>input,vector<vector<pair<int,int>>>&output){
int i=0;
int j=0;
vector<pair<int,int>>line;
for(i=0;i<input.size();i++){
    if(i%100==0){
        output.push_back(line);
        vector<pair<int,int>>L;
        line.swap(L);
    }
    line.push_back(input[i]);

}
return 0;
}

/*
int Adjust(LoserTree &ls,int s,External &b){
int t=(s+5)/2;
while(t>0){
    if(cmpExNodeG(b[s],b[ls[t]])){//s指向新的胜者，而ls[t]指向败者
        int tem=s;
        s=ls[t];
        ls[t]=tem;
    }
    t/=2;//向上继续比较
}
ls[0]=s;
}


void Create_losertree(LoserTree &ls,External &b){
for(int i=0;i!=5;++i){//设置ls败者的初值都为5， k位置的关键字已经设置为了-1，
    ls[i]=5;
}
for(int i=0;i!=5;++i){//一次从存储点第一个关键词开始进行调整
    Adjust(ls,i,b);
}
}



void k_merge(Losertree &ls,External &b,vector<vector<pair<int,int>>> r){
    for(int i=0;i!=k;++i){//先将个归并段的第一个关键字，放入存储数组
        b[i].key=r[i][0];
    }
    b[k].key=-1;//设置一个最小值，作为建立败者树时用，
    Create_losertree(ls,b);
    int next0=1,next1=1,next2=1,next3=1,next4=1,next5=1,next6=1,next7=1;
    while(b[ls[0]].key!=1000){//当1000出来的时候，说明归并已经完成
        int q=ls[0];
        cout<<b[q].key<<"  ";//输出一个被选出来的关键字
    switch (q){ //q记录的最小关键词所在的归并段，然后从这个归并段中读入下一个关键字，
    case 0:
        b[q].key=r[q][next0];
        ++next0;
        break;
    case 1:
        b[q].key=r[q][next1];
        ++next1;
        break;
    case 2:
        b[q].key=r[q][next2];
        ++next2;
        break;
    case 3:
        b[q].key=r[q][next3];
        ++next3;
         break;
    case 4:
        b[q].key=r[q][next4];
        ++next4;
        break;
    case 5:
        b[q].key=r[q][next5];
        ++next5;
        break;
    case 6:
        b[q].key=r[q][next6];
        ++next6;
        break;
    case 7:
        b[q].key=r[q][next7];
        ++next7;
        break;

    }
    Adjust(ls,q,b);//再进行调整，




    }



}

*/



void merge_sort(vector<pair<int,int>>&q, int l, int r){
    if (l >= r) return;

    int mid = (l + r) >> 1;

    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    vector<pair<int,int>> tmp(q.size());

    while (i <= mid && j <= r){
        if (q[i].first <= q[j].first) {
            tmp[k++] = q[i++];
            }
        else tmp[k++] = q[j++];
    }
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];

    for (int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}
void merge_sortFre(vector<pair<int,pair<int,int>>>&q, int l, int r){
    if (l >= r) return;

    int mid = (l + r) >> 1;

    merge_sortFre(q, l, mid);
    merge_sortFre(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    vector<pair<int,pair<int,int>>> tmp(q.size());

    while (i <= mid && j <= r){
        if (q[i].first <= q[j].first) {
            tmp[k++] = q[i++];
            }
        else tmp[k++] = q[j++];
    }
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];

    for (int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}

