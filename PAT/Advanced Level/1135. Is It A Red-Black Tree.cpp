#include<bits/stdc++.h>
using namespace std;
struct Node{//二叉树结点定义
    int data,leftNum,rightNum;
    Node*left,*right;
    Node(int d):data(d),left(nullptr),right(nullptr),leftNum(0),rightNum(0){}
};
void insertTree(Node*&root,int data){//二叉查找树的插入节点算法
    if(root==nullptr){
        root=new Node(data);
        return;
    }
    if(abs(root->data)>abs(data))
        insertTree(root->left,data);
    else
        insertTree(root->right,data);
}
int getBlackNum(Node*root){//计算左右子树中黑色结点个数
    if(root==nullptr)
        return 1;
    root->leftNum=getBlackNum(root->left);//计算左子树中黑色结点个数
    root->rightNum=getBlackNum(root->right);//计算右子树中黑色结点个数
    return root->data<0?root->leftNum:root->leftNum+1;
}
bool judge(Node*root){//判断给定的树是否满足4、5条性质
    if(root==nullptr)
        return true;
    bool leftBlack=root->left==nullptr||root->left->data>0;
    bool rightBlack=root->right==nullptr||root->right->data>0;
    bool f1=root->data>0?true:leftBlack&&rightBlack;//是否满足性质4
    bool f2=root->leftNum==root->rightNum;//是否满足性质5
    return f1&&f2&&judge(root->left)&&judge(root->right);//递归判断左右子树
}
int main(){
    int K,N,a;
    scanf("%d",&K);
    while(K--){
        scanf("%d",&N);
        Node*root=nullptr;
        for(int i=0;i<N;++i){
            scanf("%d",&a);
            insertTree(root,a);
        }
        getBlackNum(root);
        bool isRBT=root->data>0&&judge(root);
        printf("%s\n",isRBT?"Yes":"No");
    }
    return 0;
}
