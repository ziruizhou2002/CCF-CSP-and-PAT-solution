#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*left=nullptr,*right=nullptr;
    Node(int d):data(d){}
};
int levelNum[1000],maxLevel=-1;//每层结点个数、最大层数
void insert(Node*&root,int data){//向二叉查找树插入节点
    if(root==nullptr){//节点为空
        root=new Node(data);//新建结点
        return;//直接返回
    }
    if(data<=root->data)//data值比结点值小或相等
        insert(root->left,data);//向左子树插入
    else//data值比结点值大
        insert(root->right,data);//向右子树插入
}
void DFS(Node*r,int level){//DFS遍历
    if(r==nullptr){//r为空
        maxLevel=max(level,maxLevel);//更新最大层数
        return;//直接返回
    }
    ++levelNum[level];//递增该层结点个数
    DFS(r->left,level+1);//遍历左子树
    DFS(r->right,level+1);//遍历右子树
}
int main(){
    int N,a;
    scanf("%d",&N);
    Node*root=nullptr;
    while(N--){
        scanf("%d",&a);
        insert(root,a);
    }
    DFS(root,0);
    printf("%d + %d = %d",levelNum[maxLevel-1],levelNum[maxLevel-2],levelNum[maxLevel-1]+levelNum[maxLevel-2]);
    return 0;
}
