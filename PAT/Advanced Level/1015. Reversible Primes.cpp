#include<bits/stdc++.h>
using namespace std;
const int INF=1e5;
bool prime[INF];//记录某个数是否为素数
//埃氏筛法求素数表
void findPrime(){
    fill(prime+2,prime+INF,true);
    for(int i=2;i<INF;++i)
        if(prime[i])
            for(int j=i+i;j<INF;j+=i)
                prime[j]=false;
}
//将给定的数在给定进制下翻转之后按十进制数返回
int f(int n,int d){
    int k=0;//翻转转换后得到的数
    do{
        k=k*d+n%d;
        n/=d;
    }while(n!=0);
    return k;
}
int main(){
    findPrime();//获取素数表
    int n,d;
    scanf("%d",&n);//读取n
    while(n>=0){//如果n不是负数继续循环
        scanf("%d",&d);//读取进制d
        int k=f(n,d);//获取n在进制d下翻转之后的数
        if(prime[n]&&prime[k])//如果n,k均是素数输出Yes
            printf("Yes\n");
        else//否则输出No
            printf("No\n");
        scanf("%d",&n);
    }
    return 0;
}
