#include <bits/stdc++.h>
using namespace std;
vector<int>graph[10005];//图
bool boy[10005];//下标为ID，元素表示该ID是否是男
int N,M,K,vstart,vend;
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;++i){//读取边的数据
        string a,b;
        cin>>a>>b;
        int ia=abs(stoi(a)),ib=abs(stoi(b));//将字符串化为正整数
        graph[ia].push_back(ib);//向图中加入边
        graph[ib].push_back(ia);//向图中加入边
        boy[ia]=(a[0]!='-');//表示该人性别
        boy[ib]=(b[0]!='-');//表示该人性别
    }
    scanf("%d",&K);
    while(K--){
        scanf("%d%d",&vstart,&vend);//读取首尾结点
        vector<pair<int,int>>result;//存储符合题目要求的两个结点
        for(int i:graph[abs(vstart)])//遍历首节点的朋友
            if(i!=abs(vend)&&i!=abs(vstart)&&boy[i]==boy[abs(vstart)])//找到非首尾结点且与首节点性别相同的朋友作为第一个节点
                for(int j:graph[i])//遍历第一个节点的朋友
                    if(j!=abs(vend)&&j!=abs(vstart)&&boy[j]==boy[abs(vend)])//找到非首尾结点且与尾节点性别相同的朋友作为第二个节点
                        for(int k:graph[j])//遍历第二个节点的朋友
                            if(k==abs(vend))//尾结点是第二个节点的朋友
                                result.push_back({i,j});//i,j两个节点符合要求
        printf("%d\n",result.size());
        sort(result.begin(),result.end());//排序
        for(auto&i:result)//输出
            printf("%04d %04d\n",i.first,i.second);
    }
    return 0;
}
