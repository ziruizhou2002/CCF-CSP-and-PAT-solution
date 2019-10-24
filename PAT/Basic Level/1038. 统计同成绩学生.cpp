#include<bits/stdc++.h>
using namespace std;
int main(){
    int hashTable[105]={0};
    int N,a;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&a);
        ++hashTable[a];
    }
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d",&a);
        printf("%s%d",i>0?" ":"",hashTable[a]);
    }
    return 0;
}
