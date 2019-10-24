#include<bits/stdc++.h>
using namespace std;
int main(){
    double bet[3][3];//存储给定的9个数
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            scanf("%lf",&bet[i][j]);
    int index[3]={0};//存储3场比赛中每场比赛最大的那个数对应的索引
    string trans="WTL";//存储指向相应字符的索引
    for(int i=0;i<3;++i)//找出3场比赛中每场比赛最大的那个数对应的索引
        for(int j=1;j<3;++j)
            if(bet[i][j]>bet[i][index[i]])
                index[i]=j;
    for(int i=0;i<3;++i)//输出3场比赛中每场比赛最大的那个数对应的索引对应的WTL字符
        printf("%c ",trans[index[i]]);
    double result=1.0;
    for(int i=0;i<3;++i)//计算收益
        result*=bet[i][index[i]];
    result=(result*0.65-1)*2;
    printf("%.2f",result); //输出收益
    return 0;
}
