#include<bits/stdc++.h>
using namespace std;
vector<int>post,pre(1005);
bool mirror=false;//是否是镜像树
void postOrder(int left,int right){
    if(left>right)
        return;
    int i=left+1,j=right;//i指示右子树的第一个数在先根遍历序列中的索引，j指示左子树的最后一个数在先根遍历序列中的索引
    if(!mirror) {
        while(i<=right&&pre[left]>pre[i]) 
            ++i;
        while(j>left&&pre[left]<=pre[j]) 
            --j;
    }else{
        while(i<=right&&pre[left]<=pre[i]) 
            ++i;
        while(j>left&&pre[left]>pre[j]) 
            --j;
    }
    if(i-j!=1) return ;//i-j!=1，说明不能构成二叉查找树或镜像树，提前返回
    postOrder(left+1,i-1);//处理左子树
    postOrder(i,right);//处理右子树
    post.push_back(pre[left]);//将根节点加入后根遍历序列中
}
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;++i)
        scanf("%d",&pre[i]);
    if(N>2&&pre[1]>pre[0])//判断是否是镜像树
        mirror=true;
    postOrder(0,N-1);//得出后根遍历序列
    if(post.size()==N){//得出的后根遍历序列中元素个数与给定的元素总数相等，说明能构成二叉查找树或镜像树
        printf("YES\n");
        for(int i=0;i<post.size();++i)
            printf("%s%d",i>0?" ":"",post[i]);
    }else//得出的后根遍历序列中元素个数与给定的元素总数相等，说明不能构成二叉查找树或镜像树
        printf("NO");
    return 0;
}
