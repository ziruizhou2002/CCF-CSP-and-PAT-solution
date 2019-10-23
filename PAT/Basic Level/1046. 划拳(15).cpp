#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sumA=0,sumB=0;
    scanf("%d",&n);
    int a1,a2,b1,b2;
    while(n--){
        scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
        int temp=a1+b1;
        if(a2==temp&&b2!=temp)
            ++sumB;
        else if(a2!=temp&&b2==temp)
            ++sumA;
    }
    printf("%d %d",sumA,sumB);
    return 0;
}
