#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    bool broken[128]={false};//true表示该键坏了，false表示该键完好
    for(char c:s1)
        broken[c]=true;//在数组broken中把坏掉的键置true
    for(char c:s2)
        if(!broken[toupper(c)]&&(!isupper(c)||!broken['+']))//如果对应的键没有坏且不是大写字母或上档键没有坏则输出
            printf("%c",c);
    printf("\n");//如果没有一个字符能被打出，则输出空行。(测试点并未检测)
    return 0;
}
