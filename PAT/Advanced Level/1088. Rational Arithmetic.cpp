#include<bits/stdc++.h>
using namespace std;
struct Fraction{
    //虽然题目中说明分子分母都在整型范围内，  
    //但是在四则运算过程中很可能超出int范围，最好用long long存储  
    long long mother;
    long long son;
};
//辗转相除法求最大公约数  
long long gcd(long long a,long long b){
    return b==0?a:gcd(b,a%b);
}
//约分
void simplify(Fraction&f){
    if(f.son==0){
        f.mother=1;
        return;
    }
    if(f.mother<0){
        f.mother=-f.mother;
        f.son=-f.son;
    }
    long long d=gcd(max(abs(f.son),f.mother),min(abs(f.son),f.mother));
    f.son/=d;
    f.mother/=d;
}
//加法  
Fraction add(Fraction&f1,Fraction&f2){
    Fraction f3;
    f3.son=f1.son*f2.mother+f1.mother*f2.son;
    f3.mother=f1.mother*f2.mother;
    simplify(f3);
    return f3;
}
//减法
Fraction sub(Fraction&f1,Fraction&f2){
    Fraction f3;
    f3.son=f1.son*f2.mother-f1.mother*f2.son;
    f3.mother=f1.mother*f2.mother;
    simplify(f3);
    return f3;
}
//乘法
Fraction mul(Fraction&f1,Fraction&f2){
    Fraction f3;
    f3.son=f1.son*f2.son;
    f3.mother=f1.mother*f2.mother;
    simplify(f3);
    return f3;
}
//除法
Fraction div(Fraction&f1,Fraction&f2){
    Fraction f3;
    f3.son=f1.son*f2.mother;
    f3.mother=f1.mother*f2.son;
    simplify(f3);
    return f3;
}
//输出分数
void output(Fraction&f){
    if(f.son<0)
        printf("(");
    if(f.mother==1)
        printf("%lld",f.son);
    else{
        if(abs(f.son)>=f.mother)
            printf("%lld %lld/%lld",f.son/f.mother,abs(f.son)%f.mother,f.mother);  
        else
            printf("%lld/%lld",f.son,f.mother);
    }
    if(f.son<0)
        printf(")");
}

int main(){
    Fraction f1,f2,f3;
    scanf("%lld/%lld %lld/%lld",&f1.son,&f1.mother,&f2.son,&f2.mother);
    simplify(f1);
    simplify(f2);
    for(int i=0;i<4;++i){
        output(f1);
        bool f=true;
        if(i==0){
            printf(" + ");
            f3=add(f1,f2);
        }else if(i==1){
            printf(" - ");
            f3=sub(f1,f2);
        }else if(i==2){
            printf(" * ");
            f3=mul(f1,f2);
        }else if(i==3){
            printf(" / ");
            if(f2.son==0)
                f=false;
            else
                f3=div(f1,f2);
        }
        output(f2);
        printf(" = ");
        if(f)
            output(f3);
        else
            printf("Inf");
        printf("\n");
    }
    return 0;
}
