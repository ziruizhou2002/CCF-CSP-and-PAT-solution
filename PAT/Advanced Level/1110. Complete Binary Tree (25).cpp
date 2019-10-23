#include<bits/stdc++.h>
using namespace std;
struct Node{
    int left=-1,right=-1;
};
Node tree[20];
int N;
bool levelOrder(int root,int&last){//层次遍历,last表示最后一个结点
    queue<int>q;
    q.push(root);
    int num=0;//从0开始给结点编号
    while(!q.empty()){
        int t=q.front();
        q.pop();
        if(t!=-1){//当前结点不是空节点
            ++num;//编号递增
            last=t;//更新最后一个结点
        }else//当前结点是空节点
            return num==N;//返回其编号是否等于N
        q.push(tree[t].left);//将左孩子压入队列
        q.push(tree[t].right);//将右孩子压入队列
    }
}
int main(){
    scanf("%d",&N);
    bool child[N]={false};//表示一个结点是否是孩子节点
    for(int i=0;i<N;++i){
        string a,b;//不能用char，因为结点数可以是两位数
        cin>>a>>b;
        if(a!="-"){
            tree[i].left=stoi(a);
            child[tree[i].left]=true;
        }
        if(b!="-"){
            tree[i].right=stoi(b);
            child[tree[i].right]=true;
        }
    }
    int last=-1,root=find(child,child+N,false)-child;//找到child中仍为true的即为根结点
    bool f=levelOrder(root,last);
    printf("%s %d",f?"YES":"NO",f?last:root);//输出
    return 0;
}
