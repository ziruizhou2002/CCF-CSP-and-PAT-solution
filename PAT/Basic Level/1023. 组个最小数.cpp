#include<bits/stdc++.h>
using namespace std;
int main(){
    int input[10];
    for(int i=0;i<10;++i)
        scanf("%d",&input[i]);
    for(int i=1;i<10;++i)
        if(input[i]>0){
            printf("%d",i);
            --input[i];
            break;
        }
    for(int i=0;i<10;++i)
        while(input[i]--)
            printf("%d",i);
    return 0;
}
