#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        char c1,c2;
        for(int i=0;i<4;++i){
            scanf("%*c%c-%c",&c1,&c2);
            if(c2=='T')
                printf("%d",(int)(c1-'A'+1));
        }
    }
    return 0;
}
