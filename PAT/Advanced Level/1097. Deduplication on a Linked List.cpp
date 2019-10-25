#include<bits/stdc++.h>
using namespace std;
int data[(int)(1e5+5)],Next[(int)(1e5+5)];
void output(vector<int>&v){//输出链表
    if(v.empty())//链表为空
        return;//直接返回
    for(int i=0;i<v.size()-1;++i)//输出
        printf("%05d %d %05d\n",v[i],data[v[i]],v[i+1]);
    printf("%05d %d -1\n",v.back(),data[v.back()]);
}
int main(){
    int N,first;
    scanf("%d%d",&first,&N);
    while(N--){
        int a;
        scanf("%d",&a);
        scanf("%d%d",&data[a],&Next[a]);
    }
    unordered_set<int>value;//存储遍历过的链表结点数据域的绝对值
    vector<int>RemainL,RemoveL;
    for(;first!=-1;first=Next[first])
        if(value.find(abs(data[first]))==value.end()){
            value.insert(abs(data[first]));
            RemainL.push_back(first);
        }else
            RemoveL.push_back(first);
    output(RemainL);
    output(RemoveL);
    return 0;
}
