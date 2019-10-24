#include<bits/stdc++.h>
using namespace std;
int N,pre[30],post[30];
vector<int>in;
bool flag=true;//表示树的形态唯不唯一
void inOrder(int root,int left,int right){//得到中根序列
    if(left>=right){
        if(left==right)//left==right，只有一个结点
            in.push_back(pre[root]);//压入中根序列中
        return;//直接返回
    }
    int i=left;
    while(i<=right-1&&post[i]!=pre[root+1])//查找先根序列中根节点的下一结点在后根序列中的位置
        ++i;
    if(i==right-1)//先根序列中根节点的下一结点在后根序列中的位置正好等于right-1
        flag=false;//树的形态不唯一
    inOrder(root+1,left,i);//递归遍历左子树
    in.push_back(pre[root]);//将根节点压入中根序列
    inOrder(root+i-left+2,i+1,right-1);//递归遍历右子树
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;++i)
        scanf("%d",&pre[i]);
    for(int i=0;i<N;++i)
        scanf("%d",&post[i]);
    inOrder(0,0,N-1);
    printf("%s\n",flag==true?"Yes":"No");
    for(int i=0;i<in.size();++i)
        printf("%s%d",i>0?" ":"",in[i]);
    printf("\n");
    return 0;
}
