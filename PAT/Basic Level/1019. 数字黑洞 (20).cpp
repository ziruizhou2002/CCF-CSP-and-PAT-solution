#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,n1,n2;
    scanf("%d",&n);
    string num;
    do{
        num=to_string(n);
        while(num.size()<4)//整数不够4位要补0
            num+='0';
        sort(num.begin(),num.end());//按数字从小到大的顺序对字符数组排序
        n2=stoi(num);
        reverse(num.begin(),num.end());//翻转num
        n1=stoi(num);
        n=n1-n2;
        printf("%04d - %04d = %04d\n",n1,n2,n);//确保输出为4位整数，不够在高位补0
    }while(n!=6174&&n!=0);
    return 0;
}
