#include<bits/stdc++.h>
using namespace std;
//判断数组是否是回文数组
bool isPalindromic(int*t,int size){
    for(int i=0,j=size-1;i<=j;++i,--j)
        if(t[i]!=t[j])
            return false;
    return true;
}
int main(){
    int trans[30]={0},size=0;//定义数组及其有效长度
    int N,B;
    scanf("%d%d",&N,&B);
    //将10进制数转换成B进制并储存在数组trans中
    do{
        trans[size++]=N%B;
        N/=B;
    }while(N!=0);
    //判断是否回文并输出
    if(!isPalindromic(trans,size))
        printf("No\n");
    else
        printf("Yes\n");
    for(int i=size-1;i>=0;--i){
        if(i<size-1)
            printf(" ");
        printf("%d",trans[i]);
    }
    return 0;
}
