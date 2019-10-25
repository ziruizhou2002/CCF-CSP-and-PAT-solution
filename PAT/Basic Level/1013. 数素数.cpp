#include<bits/stdc++.h>
using namespace std;
int M,N;
vector<int>prime;
vector<bool>number(1000000,true);
void findPrime(){//埃氏筛法求解1000000以内的素数表
    vector<bool>number(100005,true);
    for(int i=2;i<number.size();++i)
        if(number[i]){//如果是素数
            prime.push_back(i);//加入prime中
            for(int j=i+i;j<number.size();j+=i)//将数组number中下标凡是i的倍数的均置为false，表示不是素数
                number[j]=false;
        }
}
int main(){
    scanf("%d%d",&M,&N);
    findPrime();
    int j=0;
    for(int i=M-1;i<N;++i){
        printf("%s%d",j>0?" ":"",prime[i]);
        ++j;
        if(j==10){//每输出10个数换一次行 
            printf("\n");
            j=0;
        }
    }
    return 0;
}
