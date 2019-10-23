#include<bits/stdc++.h>
using namespace std;
int main(){
    string input;
    char flag;
    //读取数据
    scanf("%c",&flag);
    getchar();
    getline(cin,input);
    if(flag=='C'){//压缩字符串
        int num=1;//开始字符个数为1
        for(int i=0;i<input.size();++i){
            if(input[i]!=input[i+1]){//当前字符与其后一个字符不同
                if(num>1)
                    cout<<num;//字符数不为1输出字符数
                cout<<input[i];//输出字符
                num=1;//当前字符数仍为1
            }else//当前字符与其后一个字符相同
                ++num;//递增字符数
        }
    }else if(flag=='D'){//解压缩字符串
        int num=0;//记录输出字符数量，初始化为0
        for(int i=0;i<input.size();++i){
            if(isdigit(input[i]))//如果是数字，将其转换为整数累加
                num=num*10+input[i]-'0';
            else if(num==0)//字符数量为0，只需输出一个字符
                cout<<input[i];
            else{//输出num个字符
                for(int j=0;j<num;++j)
                    cout<<input[i];
                num=0;
            }
        }
    }
    return 0;
}
