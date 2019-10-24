#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data,left=-1,right=-1;
};
Node tree[105];
int data[105],N;
void inOrder(int root,int&index){//中根遍历
    if(root==-1)//root==-1,直接返回
        return;
    inOrder(tree[root].left,index);//递归遍历左子树
    tree[root].data=data[index++];//将数据填入根部结点
    inOrder(tree[root].right,index);//递归遍历右子树
}
void levelOrder(){//层次遍历
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        printf("%s%d",t==0?"":" ",tree[t].data);
        if(tree[t].left!=-1)
            q.push(tree[t].left);
        if(tree[t].right!=-1)
            q.push(tree[t].right);
    }
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;++i)
        scanf("%d%d",&tree[i].left,&tree[i].right);
    for(int i=0;i<N;++i)
        scanf("%d",&data[i]);
    sort(data,data+N);//排序
    int index=0;
    inOrder(0,index);
    levelOrder();
    return 0;
}
