#include<bits/stdc++.h>
using namespace std;
//计算a和b的最大公约数
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main() {
    int a,b,c,d,e;
    scanf("%d/%d %d/%d %d",&a,&b,&c,&d,&e);
    double k1=(double)a*e/b,k2=(double)c*e/d;//获取将两个分数化为以给定整数位分母后的分子
    //令k1表示小的分子，k2表示大的分子
    if(k1>k2)
        swap(k1,k2);
    a=(int)floor(k1+1);//获取小的整数分子，对k1+1进行向下取整
    c=(int)ceil(k2-1);//获取大的整数分子，对k2-1进行向上取整
    bool output=false;
    for(int i=a;i<=c;++i){//在[a,c]范围内进行查找
        if(gcd(i,e)==1){//最大公约数为1，进行输出
            if(output)
                printf(" ");
            printf("%d/%d",i,e);
            output=true;
        }
    }
    return 0;
}
