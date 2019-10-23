#include<bits/stdc++.h>
using namespace std;
int main(){
    string input="";
    getline(cin,input);//读取字符串
    int n1=(input.size()+2)/3,n2=input.size()+2-2*n1;//获取n1,n2
    //进行输出
    for(int i=0;i<n1-1;++i){//前n1-1行，需要输出首尾两个字符，且每行字符数为n2
        printf("%c",input[i]);
        for(int j=0;j<n2-2;++j)
            printf(" ");
        printf("%c\n",input[input.size()-i-1]);
    }
    //最后一行将没有输出的n2个字符一次性输出
    for(int i=0;i<n2;++i)
        printf("%c",input[n1-1+i]);
    return 0;
}
