#include<bits/stdc++.h>
using namespace std;
int main(){
    int T,K;
    scanf("%d%d",&T,&K);
    while(K--){
        int n1,b,t,n2;
        scanf("%d%d%d%d",&n1,&b,&t,&n2);
        if(T<=0){
            printf("Game Over.\n");
            break;
        }
        if(t>T){
            printf("Not enough tokens.  Total = %d.\n",T);
            continue;
        }
        if((b==0&&n2<n1)||(b==1&&n2>n1)){
            T+=t;
            printf("Win %d!  Total = %d.\n",t,T);
        }else{
            T-=t;
            printf("Lose %d.  Total = %d.\n",t,T);
        }
    }
    return 0;
}
