#include<bits/stdc++.h>
using namespace std;
int main(){
    string low[13]={//数字到火星文低位的映射
         "tret","jan","feb","mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string high[13]={//数字到火星文高位的映射
         "tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    unordered_map<string,int>temp;//火星文到数字的映射
    for(int i=0;i<13;++i){
        temp[low[i]]=i;
        temp[high[i]]=i*13;
    }
    int n;
    scanf("%d%*c",&n);
    string digit="";
    while(n--){
        getline(cin,digit);
        if(isdigit(digit[0])){//如果是数字
            int k=stoi(digit);
            if(k/13!=0)//高位不为0，输出高位
                printf("%s",high[k/13].c_str());
            if(k/13!=0&&k%13!=0)//高位低位均不为0，输出空格
                printf(" ");
            if(k/13==0||k%13!=0)//高位为0或者高位不为0但低位为0时，输出低位
                printf("%s",low[k%13].c_str());
            puts("");//换行
        }else{//是火星文
            int k=0;
            stringstream stream(digit);
            while(stream>>digit)//按空格键分割字符串
                k+=temp[digit];
            printf("%d\n",k);
        }
    }
    return 0;
}
