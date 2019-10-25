#include<bits/stdc++.h>
using namespace std;
int main(){
    char A[11],B[11];
    int Da,Db;
    int a=0,b=0;
    scanf("%s%d%s%d",A,&Da,B,&Db);
    for(int i=0;A[i]!='\0';++i)
        if(A[i]-'0'==Da)
            a=a*10+Da;
    for(int i=0;B[i]!='\0';++i)
        if(B[i]-'0'==Db)
            b=b*10+Db;
    printf("%d",a+b);
    return 0;
}
