#include<bits/stdc++.h>
using namespace std;
//将输入数据统一转换到最小单位
int transKnut(int G,int S,int K){
    return (G*17+S)*29+K;
}
int main(){
    int G1,S1,K1,G2,S2,K2;
    scanf("%d.%d.%d %d.%d.%d",&G1,&S1,&K1,&G2,&S2,&K2);
    //将输入数据统一转换到最小单位
    K1=transKnut(G1,S1,K1);
    K2=transKnut(G2,S2,K2);
    int K=K2-K1;//作差
    //如果没带够钱，那么输出的应该是负数
    if(K<0){
        printf("-");
        K=abs(K);//将差值转换成正数，否则输出中会形成-3.-2.-1的形式
    }
    printf("%d.%d.%d",K/29/17,K/29%17,K%29);
    return 0;
}
