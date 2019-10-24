#include<bits/stdc++.h>  
using namespace std;  
int main(){  
    int n,num=0;  
    scanf("%d",&n);   
    while(n!=1){  
        if(n%2!=0)  
            n=3*n+1;  
        n/=2;
        ++num;  
    }  
    printf("%d",num);  
    return 0;  
} 
