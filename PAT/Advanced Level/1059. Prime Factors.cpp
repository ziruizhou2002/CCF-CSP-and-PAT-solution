#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5;
vector<int>prime;
vector<bool>f(MAX,false);
void findPrime(){
    for(int i=2;i<MAX;++i)
        if(!f[i]){
            prime.push_back(i);
            for(int j=i+i;j<MAX;j+=i)
                f[j]=true;
        }
}

int main(){
    int N;
    scanf("%d",&N);
    findPrime();
    printf("%d=",N);
    if(N==1){
        printf("1");
        return 0;
    }
    map<int,int>factor;
    for(int i=0;i<prime.size();++i){
        while(N%prime[i]==0){
            ++factor[prime[i]];
            N/=prime[i];
        }
        if(N==1)
            break;
    }
    for(auto i=factor.cbegin();i!=factor.cend();++i){
        if(i!=factor.cbegin())
            printf("*");
        printf("%d",i->first);
        if(i->second>1)
            printf("^%d",i->second);
    }
    return 0;
}
