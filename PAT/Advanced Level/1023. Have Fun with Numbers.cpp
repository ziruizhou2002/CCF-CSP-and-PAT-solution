#include<bits/stdc++.h>
using namespace std;
string input,result="";//输入的大整数、2倍后的大整数
int hashTable[10];//辅助数组
void mul(){//大整数乘法
    int num=0;
    for(int i=0;input[i]!='\0';++i){
        int k=2*(input[i]-'0')+num;
        result+=k%10+'0';
        num=k/10;
    }
    if(num!=0)
        result+=num+'0';//如果最终进位不为0，置于result数组末尾
}
int main(){
    cin>>input;
    reverse(input.begin(),input.end());//翻转读取到的数组
    mul();//将原数加倍
    for(int i=0;input[i]!='\0';++i){//遍历新数原数两个数组，在相应的hashTable数组下标下进行递增递减
        ++hashTable[input[i]-'0'];
        --hashTable[result[i]-'0'];
    }
    bool yes=(count(hashTable,hashTable+10,0)==10);//遍历整个hashTable数组，看元素0的个数是否为10
    reverse(result.begin(),result.end());//将result数组翻转
    printf("%s\n%s",yes?"Yes":"No",result.c_str());
    return 0;
}
