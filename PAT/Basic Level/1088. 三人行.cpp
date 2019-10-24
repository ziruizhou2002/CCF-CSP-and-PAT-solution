#include<bits/stdc++.h>
using namespace std;
string f(double A,int M){
    return A>M*1.0?"Cong":A==M*1.0?"Ping":"Gai";
}
int main(){
    int M,X,Y,A,B;
    double C;
    scanf("%d%d%d",&M,&X,&Y);
    for(A=99;A>=10;--A){
        B=A%10*10+A/10;
        if(abs(A-B)*1.0/X==B*1.0/Y){
            C=B*1.0/Y;
            printf("%d %s %s %s",A,f(A*1.0,M).c_str(),f(B*1.0,M).c_str(),f(C,M).c_str());
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
