#include <bits/stdc++.h>
using namespace std;
const int MAX=5*1e4+5;
int pre[MAX],in[MAX];//存储先根序列，中根序列
//寻找后根遍历第一个数
void findNode(int root,int left,int right){
    if(left==right){//如果是叶节点
        printf("%d",pre[root]);//这个数就是我们要找的数，输出这个数
        return ;
    }
    //在中根序列中寻找与根节点的位置
    int i=left;
    while(in[i]!=pre[root])
        ++i;
    if(i==left)//如果没有左子树
        findNode(root+1,i+1,right);//向右子树中寻找
    else//如果有左子树
        findNode(root+1,left,i-1);//向左子树中寻找
}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d",&pre[i]);
    }
    for(int i=0;i<N;++i){
        scanf("%d",&in[i]);
    }
    findNode(0,0,N-1);
    return 0;
}
