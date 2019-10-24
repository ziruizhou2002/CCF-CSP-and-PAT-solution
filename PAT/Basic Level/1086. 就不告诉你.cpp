#include<bits/stdc++.h>
using namespace std;
int main(){
    int A,B;
    scanf("%d%d",&A,&B);
    A*=B;
    for(B=0;A!=0;A/=10)
        B=B*10+A%10;
    printf("%d",B);
    return 0;
}
