#include <bits/stdc++.h>
using namespace std;
const int MAX=1005;
bool isPalindromic(const string&s){//判断是否回文
    for(int i=0,j=s.size()-1; i<j; ++i,--j)//定义两个指针从数组两端同时向中间遍历，检测指向的字符是否一致，不一致，则返回false
        if(s[i]!=s[j])
            return false;
    return true;//都一致，返回true
}
void add(string&n1,string&n2){//大整数加法，从索引为0的位置开始进行逐位加法，如果有最终进位可以放在数组末尾
    int jinwei=0;//进位
    for(int i=0; i<n1.size(); ++i){
        int k=n1[i]+n2[i]-'0'-'0'+jinwei;
        jinwei=k/10;
        n1[i]=k%10+'0';
    }
    if(jinwei>0)//有最终进位放在数组末尾
        n1+=jinwei+'0';
}
int main(){
    string n1,n2;
    cin>>n1;
    for(int k=0;k<10&&!isPalindromic(n1);++k){//如果不是回文数且未超过指定步数，继续循环
        n2=n1;
        reverse(n2.begin(),n2.end());//翻转n2字符串
        printf("%s + %s = ",n1.c_str(),n2.c_str());
        add(n1,n2);//进行加法
        reverse(n1.begin(),n1.end());//翻转n1字符串（因为n1是从字符串首位向字符串末位进行逐位加法的）
        printf("%s\n",n1.c_str());
    }
    if(isPalindromic(n1))
        printf("%s is a palindromic number.",n1.c_str());
    else
        printf("Not found in 10 iterations.");
    return 0;
}
