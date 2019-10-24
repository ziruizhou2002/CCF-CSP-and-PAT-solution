#include<bits/stdc++.h>
using namespace std;
vector<int>pre,in,post;//先根、中根、后根遍历序列
void postOrder(int root,int left,int right){//得出后根遍历序列
    if(left>right)
        return;
    int i=left;
    while(in[i]!=pre[root])//找到根节点在中根遍历序列中的位置
        ++i;
    postOrder(root+1,left,i-1);//递归遍历左子树
    postOrder(root+1+i-left,i+1,right);//递归遍历右子树
    post.push_back(pre[root]);//将根节点加入后根遍历序列
}
int main(){
    int N;
    scanf("%d",&N);
    stack<int>s;
    char temp[5];
    for(int i=0;i<2*N;++i){
        scanf("\n%s",temp);//读取字符串
        if(strcmp(temp,"Push")==0){//是压栈
            int a;
            scanf("%d",&a);
            pre.push_back(a);//当前数字是先根遍历序列
            s.push(a);//压栈
        }else{
            in.push_back(s.top());//栈首元素是中根遍历序列
            s.pop();//出栈
        }
    }
    postOrder(0,0,in.size()-1);//得出后根遍历序列
    for(int i=0;i<post.size();++i)//输出
        printf("%s%d",i>0?" ":"",post[i]);
    return 0;
}
