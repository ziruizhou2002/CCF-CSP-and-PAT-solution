#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int teamScore[1005]={0};
    while(n--){
        int a,b,c;
        scanf("%d-%d %d",&a,&b,&c);
        teamScore[a]+=c;
    }
    int maxIndex=max_element(teamScore,teamScore+1005)-teamScore;
    printf("%d %d",maxIndex,teamScore[maxIndex]);
    return 0;
}
