#include<bits/stdc++.h>    
using namespace std;    
int main(){    
    int e,c;  
    scanf("%d%d",&e,&c);    
    if(c!=0){    
        printf("%d %d",e*c,c-1);    
        while(scanf("%d%d",&e,&c)!=EOF)   
            if(c!=0)    
                printf(" %d %d",e*c,c-1);    
    }    
    else   
        printf("0 0");    
    return 0;    
}   
