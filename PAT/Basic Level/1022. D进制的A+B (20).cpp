#include<bits/stdc++.h>
using namespace std;
int main(){
    int A,B,D;
    scanf("%d%d%d",&A,&B,&D);
    A+=B;
    if(A==0)
        printf("0");
    string result="";
    while(A!=0){
        result+=A%D+'0';
        A/=D;
    }
    reverse(result.begin(),result.end());
    printf("%s",result.c_str());
    return 0;
}
