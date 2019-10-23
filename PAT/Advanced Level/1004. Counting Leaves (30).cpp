#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>tree(100);//下标存储结点编号，元素内容存储儿子结点编号
int leaveNumOfLevel[100],maxLevel=-1;//每层叶子节点数、最大层数
int N,M;
void DFS(int v,int level){//深度优先遍历
    maxLevel=max(level,maxLevel);//更新最大层数
    if(tree[v].empty())//如果没有儿子结点，则为叶节点
        ++leaveNumOfLevel[level];//递增该节点所处层数下的叶节点数目
    for(int i:tree[v])//不是叶节点
        DFS(i,level+1);//递归遍历儿子结点
}
int main(){
    scanf("%d%d",&N,&M);
    while(M--){
        int id,k;
        scanf("%d%d",&id,&k);
        while(k--){
            int iid;
            scanf("%d",&iid);
            tree[id].push_back(iid);
        }
    }
    DFS(1,0);
    for(int i=0;i<=maxLevel;++i)//输出每层叶子节点数
        printf("%s%d",i==0?"":" ",leaveNumOfLevel[i]);
    return 0;
}
