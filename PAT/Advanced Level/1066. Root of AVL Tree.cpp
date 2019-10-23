#include<bits/stdc++.h>
using namespace std;
struct AVLTreeNode{
    int data,height;//关键字、高度
    AVLTreeNode *left,*right;
    AVLTreeNode(int value, AVLTreeNode *l=nullptr, AVLTreeNode *r=nullptr):data(value), height(0),left(l),right(r) {}
};
int getHeight(AVLTreeNode*r){
    return r==nullptr?0:r->height;
}
AVLTreeNode*findAVL(AVLTreeNode*root,int data){
    if (root==nullptr || root->data==data)
        return root;
    if (data < root->data)
        return findAVL(root->left, data);
    else
        return findAVL(root->right, data);
}
//LL：左左对应的情况(左单旋转),返回旋转后的根节点
AVLTreeNode* leftLeftRotation(AVLTreeNode* k2){
    AVLTreeNode* k1= k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
    k1->height = max(getHeight(k1->left), k2->height) + 1;
    return k1;
}
//RR：右右对应的情况(右单旋转),返回旋转后的根节点
AVLTreeNode* rightRightRotation(AVLTreeNode* k1){
    AVLTreeNode* k2= k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max( getHeight(k1->left), getHeight(k1->right)) + 1;
    k2->height = max( getHeight(k2->right), k1->height) + 1;
    return k2;
}
//LR：左右对应的情况(左双旋转),返回旋转后的根节点
AVLTreeNode* leftRightRotation(AVLTreeNode* k3){
    k3->left = rightRightRotation(k3->left);
    return leftLeftRotation(k3);
}
//RL：右左对应的情况(右双旋转),返回旋转后的根节点
AVLTreeNode* rightLeftRotation(AVLTreeNode* k1){
    k1->right = leftLeftRotation(k1->right);
    return rightRightRotation(k1);
}
//将结点插入到AVL树中，并返回根节点
AVLTreeNode* insertNode(AVLTreeNode* &root, int data){
    if (root == nullptr)
        root = new AVLTreeNode(data);
    else if (data < root->data){
        root->left = insertNode(root->left, data);
        // 插入节点后，若AVL树失去平衡，则进行相应的调节。
        if (getHeight(root->left) - getHeight(root->right) == 2){
            if (data < root->left->data)
                root = leftLeftRotation(root);
            else
                root = leftRightRotation(root);
        }
    }else if (data > root->data){ // 应该将data插入到"root的右子树"的情况
        root->right = insertNode(root->right, data);
        // 插入节点后，若AVL树失去平衡，则进行相应的调节。
        if (getHeight(root->right) - getHeight(root->left) == 2){
            if (data > root->right->data)
                root = rightRightRotation(root);
            else
                root = rightLeftRotation(root);
        }
    }else
        cout << "添加失败：不允许添加相同的节点！" << endl;
    root->height = max( getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}
int main(){
    int N,a;
    scanf("%d",&N);
    AVLTreeNode*root=nullptr;
    for (int i=0;i<N;++i) {
        scanf("%d",&a);
        root=insertNode(root,a);
    }
    printf("%d",root->data);
    return 0;
}
