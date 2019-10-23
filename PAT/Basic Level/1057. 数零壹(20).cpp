#include<bits/stdc++.h>
using namespace std;
int main(){
    string input;
    getline(cin,input);//读取输入数据
    int sum=0;//求英文字母序号之和
    for(char c:input)
        if(isalpha(c))
            sum+=tolower(c)-'a'+1;
    if(sum==0){//如果sum为0，输出"0 0"
        printf("0 0");
        return 0;
    }
    int a=0,b=0;
    do{//转化成2进制字符串存储在input中
        if(sum%2==0)
            ++a;
        else
            ++b;
        sum/=2;
    }while(sum!=0);
    printf("%d %d",a,b);//输出
    return 0;
}
