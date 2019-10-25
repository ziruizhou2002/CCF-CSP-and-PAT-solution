#include<bits/stdc++.h>
using namespace std;
struct Person{
    char name[6];
    int year,month,day;
    Person(int y,int m,int d):year(y),month(m),day(d){}
    bool operator <(const Person&person)const{//按照出生日期大小定义<运算符
        if(this->year!=person.year)
            return this->year<person.year;
        else if(this->month!=person.month)
            return this->month<person.month;
        else
            return this->day<person.day;
    }
};
//定义出生日期的下限和上限和临时变量、最年长和最年轻的人
Person minPerson(1814,9,5),maxPerson(2014,9,7),temp(0,0,0),Max(1814,9,5),Min(2014,9,7);
int main(){
    int N,size=0;//size统计有效生日的个数的变量
    scanf("%d",&N);
    while(N--){
        scanf("%s %d/%d/%d",temp.name,&temp.year,&temp.month,&temp.day);
        if(temp<maxPerson&&minPerson<temp){//如果是有效生日，将size加1
            ++size;
            Min=min(Min,temp);
            Max=max(Max,temp);
        }
    }
    printf("%d",size);
    if(size>0)//对size==0的情况不予输出名字
        printf(" %s %s",Min.name,Max.name);
    return 0;
}
