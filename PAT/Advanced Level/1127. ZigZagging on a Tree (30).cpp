#include<bits/stdc++.h>
using namespace std;
struct Node{//树的结点类
    int data,left=-1,right=-1;
};
Node tree[35];//树，存储后根遍历序列
int N,in[35],maxLevel=-1;//maxLevel表示最大层数
vector<int>levelElement[30];//存储每一层的元素
int createTree(int root,int left,int right){//重建一棵树
    if(left>right)
        return -1;
    int i=left;
    while(in[i]!=tree[root].data)//在中根遍历序列中查找根节点位置
        ++i;
    tree[root].left=createTree(root-1+i-right,left,i-1);//递归重建左子树
    tree[root].right=createTree(root-1,i+1,right);//递归重建右子树
    return root;//返回根节点位置
}
void DFS(int v,int level){//深度优先搜索
    if(v==-1)
        return;
    maxLevel=max(level,maxLevel);//更新最大层数
    levelElement[level].push_back(tree[v].data);//将当前结点压入对应层数下
    DFS(tree[v].left,level+1);//递归遍历左子树
    DFS(tree[v].right,level+1);//递归遍历右子树
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;++i)
        scanf("%d",&in[i]);
    for(int i=0;i<N;++i)
        scanf("%d",&tree[i].data);
    int root=createTree(N-1,0,N-1);
    DFS(root,0);
    for(int i=0;i<maxLevel+1;++i)//输出
        if(i%2==1)
            for(int j=0;j<levelElement[i].size();++j)
                printf("%s%d",i>0?" ":"",levelElement[i][j]);
        else
            for(int j=levelElement[i].size()-1;j>=0;--j)
                printf("%s%d",i>0?" ":"",levelElement[i][j]);
    return 0;
}
