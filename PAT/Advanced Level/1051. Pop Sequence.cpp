#include<bits/stdc++.h>
using namespace std;
int main(){
    int M,N,K;
    scanf("%d%d%d",&M,&N,&K);
    while(K--){
        int A[N],t=0;//数组A存储出栈顺序，t存储下一次压栈时的首元素-1
        stack<int>s;
        bool f=true;//判断输出YES或者NO
        for(int i=0;i<N;++i)
            scanf("%d",&A[i]);
        for(int i=0;i<N&&f;++i){//遍历数组A
            if(s.empty()||s.top()<A[i]){//栈为空或者栈顶元素小于A[i]
                for(int k=t+1;k<=A[i]&&s.size()<M;++k)//将t+1~A[i]这些数按从小到大顺序压入栈中，并保证栈的当前容量不超过M
                    s.push(k);
                t=s.empty()?0:s.top();//更新t
                if(t==A[i])//栈顶元素与A[i]相等
                    s.pop();//弹出
                else//栈顶元素与A[i]不等
                    f=false;//置f为false
            }else if(s.top()==A[i])//栈不为空且栈顶元素等于A[i]
                s.pop();//弹出栈顶元素
            else//栈不为空且栈顶元素大于A[i]
                f=false;//置f为false
        }
        printf("%s\n",f?"YES":"NO");//输出
    }
    return 0;
}
