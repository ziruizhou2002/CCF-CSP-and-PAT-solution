#include<bits/stdc++.h>
using namespace std;
int main(){
    string input="",s="PATest";//s负责将数组下标映射到PATest这6个字符
    getline(cin,input);
    unordered_map<char,int>m;//记录字符及其出现次数
    for(char c:input)//统计字符出现的次数
        ++m[c];
    bool f=true;//跳出循环的标志
    while(f){//不断遍历输出
        f=false;
        for(int i=0;i<6;++i)
            if(m[s[i]]-->0){//如果有元素不为0
                printf("%c",s[i]);//输出一次对应字符
                f=true;//有元素不为0置f为true，表示不允许跳出循环
            }
    }
    return 0;
}
