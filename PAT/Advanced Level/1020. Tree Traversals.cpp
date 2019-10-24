#include<bits/stdc++.h>
using namespace std;
struct Node{//定义树结点
    int data=-1,left=-1,right=-1;
};
int postOrder[30];//存储后根遍历序列、
Node inOrder[30];//用中根遍历序列顺序存储整棵树
int createTree(int root,int left,int right){//重建一棵树
    if(left>right)//如果left>right，返回nullptr
        return -1;
    int index=left;//查找在中根序列中根节点的位置
    while(inOrder[index].data!=postOrder[root])
        ++index;
    inOrder[index].left=createTree(root-1-right+index,left,index-1);//递归重建左子树
    inOrder[index].right=createTree(root-1,index+1,right);//递归重建右子树
    return index;//返回根节点在数组中的索引
}
void levelOrder(int root){//层次遍历
    queue<int>q;
    q.push(root);
    bool output=false;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        if(output)
            printf(" ");
        printf("%d",inOrder[t].data);
        output=true;
        if(inOrder[t].left!=-1)
            q.push(inOrder[t].left);
        if(inOrder[t].right!=-1)
            q.push(inOrder[t].right);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&postOrder[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&inOrder[i].data);
    int root=createTree(n-1,0,n-1);
    levelOrder(root);
    return 0;
}
