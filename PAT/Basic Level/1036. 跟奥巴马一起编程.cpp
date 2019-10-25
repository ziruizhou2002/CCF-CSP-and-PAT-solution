#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    char c;
    scanf("%d %c",&n,&c);
    for(int i=0;i<n;++i)
        printf("%c",c);
    printf("\n");
    int row=(n+1)/2;
    for(int i=0;i<row-2;++i){
        printf("%c",c);
        for(int j=0;j<n-2;++j)
            printf(" ");
        printf("%c",c);
        printf("\n");
    }
    for(int i=0;i<n;++i)
        printf("%c",c);
    return 0;
}
