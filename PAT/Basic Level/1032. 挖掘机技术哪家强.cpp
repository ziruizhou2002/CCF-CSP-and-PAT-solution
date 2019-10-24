#include<bits/stdc++.h>
using namespace std;
int main(){
    int school[100005]={0};
    int N;
    scanf("%d",&N);
    while(N--){
        int a,b;
        scanf("%d%d",&a,&b);
        school[a]+=b;
    }
    int maxIndex=0;
    for(int i=1;i<100005;++i)
        if(school[i]>school[maxIndex])
            maxIndex=i;
    printf("%d %d",maxIndex,school[maxIndex]);
    return 0;
}
