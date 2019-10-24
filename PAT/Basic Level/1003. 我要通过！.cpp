#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d%*c",&n);
    string num;
    while(n--){
        getline(cin,num);
        int pindex=-1,tindex=-1;
        for(int i=0;i<num.size();++i)
            if(num[i]=='P'&&pindex==-1)//当前字符是P字符且P字符没有出现过
                pindex=i;//更新P字符在字符串中位置
            else if(num[i]=='T'&&tindex==-1)//当前字符是T字符且T字符没有出现过
                tindex=i;//更新T字符在字符串中位置
            else if(num[i]!='A'){//当前字符不是A字符
                pindex=-2;//置pindex为-2，确保能输出NO
                break;//跳出循环
            }
        if(pindex>-1&&tindex>-1&&pindex<tindex-1&&pindex*(tindex-pindex-1)==num.size()-1-tindex)
            printf("YES\n");//满足所有条件输出YES
        else
            printf("NO\n");
    }
    return 0;
}
