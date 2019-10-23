#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    int next;
};
const int INF=1e5;
Node List[INF];
int main(){
    int first,N,K;
    scanf("%d%d%d",&first,&N,&K);
    while(N--){
        int address;
        scanf("%d",&address);
        scanf("%d%d",&List[address].data,&List[address].next);
    }
    vector<int>order1,order2,order3;
    while(first!=-1){
        if(List[first].data<0)
            order1.push_back(first);
        else if(List[first].data>=0&&List[first].data<=K)
            order2.push_back(first);
        else if(List[first].data>K)
            order3.push_back(first);
        first=List[first].next;
    }
    order1.insert(order1.end(),order2.begin(),order2.end());
    order1.insert(order1.end(),order3.begin(),order3.end());
    for(int i=0;i<order1.size();++i){
        printf("%05d %d ",order1[i],List[order1[i]].data);
        if(i<order1.size()-1)
            printf("%05d\n",order1[i+1]);
        else
            printf("-1\n");
    }
    return 0;
}
