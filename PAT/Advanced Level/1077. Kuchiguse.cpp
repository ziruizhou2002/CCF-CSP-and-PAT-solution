#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,len=300;
    scanf("%d",&N);
    getchar();//吸收后面的换行符
    string input[N],result="";
    for(int i=0;i<N;++i){
        getline(cin,input[i]);//读取字符串
        len=min(len,(int)input[i].size());//求出最小字符串长度
        reverse(input[i].begin(),input[i].end());//进行翻转
    }
    bool flag=true;
    for(int i=0;i<len&&flag;++i){//循环查找公共后缀
        for(int j=1;j<N&&flag;++j)
            if(input[j][i]!=input[j-1][i])
                flag=false;
        if(flag)
            result+=input[0][i];
    }
    reverse(result.begin(),result.end());
    printf("%s\n",result==""?"nai":result.c_str());
    return 0;
}
