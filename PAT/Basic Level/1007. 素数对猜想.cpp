#include<bits/stdc++.h>
using namespace std;
vector<int>prime;
void findPrime(){//埃氏筛法求解100005以内的素数表
    vector<bool>number(100005,true);
    for(int i=2;i<number.size();++i)
        if(number[i]){//如果是素数
            prime.push_back(i);//加入prime中
            for(int j=i+i;j<number.size();j+=i)//将数组number中下标凡是i的倍数的均置为false，表示不是素数
                number[j]=false;
        }
}
int main(){
    int N,count=0;
    scanf("%d",&N);
    findPrime();
    for(int i=1;prime[i]<=N;++i)
        if(prime[i]-prime[i-1]==2)
            ++count;
    printf("%d",count);
    return 0;
}
