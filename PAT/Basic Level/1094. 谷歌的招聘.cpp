#include<bits/stdc++.h>
using namespace std;
bool isprime(int n){//判断一个数字是否是素数
    for(int i=2;i<(int)sqrt(n*1.0)+1;++i)//遍历2~根号N
        if(n%i==0)//能整除
            return false;//不是素数
    return true;//是素数
}
int main(){
    int L,K;
    scanf("%d%d",&L,&K);
    string s;
    cin>>s;//读取数字字符串
    for(int i=0;i<s.size()-K+1;++i){//遍历[0,s.size()-K]这些下标
        int ans=stoi(s.substr(i,K));//将以i开始的K个字符转换为int型变量
        if(isprime(ans)){//是素数
            printf("%0*d",K,ans);//输出该素数，注意不够K位数字，高位补0
            return 0;//终止程序
        }
    }
    printf("404");//没有这样的素数，输出404
    return 0;
}
