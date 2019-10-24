#include<bits/stdc++.h>
using namespace std;
int main(){
    int M,N;
    scanf("%d%d",&M,&N);
    unordered_map<int,int>m;
    for(int i=0;i<M*N;++i){
        int a;
        scanf("%d",&a);
        ++m[a];
    }
    for(auto i=m.cbegin();i!=m.cend();++i)
        if(i->second*2>M*N){
            printf("%d",i->first);
            return 0;
        }
    return 0;
}
