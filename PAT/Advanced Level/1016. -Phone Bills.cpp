#include<bits/stdc++.h>
using namespace std;
struct Time{//定义时间类
    int month,day,hour,minute,time,online=0;//月日时分信息、距0日0时0分的分钟数、指明这一时间是online还是offline
    bool operator <(const Time&t)const{//重载<运算符
        return this->time<t.time;
    }
};
double price[25];//存储一天内各个小时段的话费单位是美元/分钟
double compute(Time t,int day){//计算当前时间到day日0时0分所用话费
    double bill=0.0;
    for(int i=0;i<t.hour;++i)
        bill+=60*price[i];
    return bill+t.minute*price[t.hour]+price[24]*60*(t.day-day);
}
int main(){
    for(int i=0;i<24;++i){//读取一天内各个小时段的话费
        scanf("%lf",&price[i]);
        price[i]/=100.0;//化为美元
        price[24]+=price[i];
    }
    int N;
    scanf("%d",&N);
    map<string,set<Time>>bill;//存储每个人的名字和对应的话费时间
    for(int i=0;i<N;++i){//读取账单
        string s1,s2;
        Time t;
        cin>>s1;
        scanf("%d:%d:%d:%d",&t.month,&t.day,&t.hour,&t.minute);
        t.time=(t.day*24+t.hour)*60+t.minute;
        cin>>s2;
        if(s2=="on-line")
            t.online=1;
        bill[s1].insert(t);
    }
    for(auto i=bill.cbegin();i!=bill.cend();++i){//查找有效的话费记录并就算用时与话费并输出
        bool output=false;//该人的话费记录是否需要输出/是否有有效的话费记录
        double sumBill=0.0;//该人的话费总额
        for(auto j=(i->second).cbegin();j!=(i->second).cend();++j){//定义set的迭代器j
            auto jnext=j;//定义指向j指向的下一个对象的迭代器
            ++jnext;
            for(;jnext!=(i->second).cend()&&!(j->online&&!jnext->online);++j,++jnext);//查找有效的话费记录
            if(jnext!=(i->second).cend()){//如果查找到了
                if(!output){//还没有输出过姓名的月份进行输出，并通过修改output变量标明该人的话费记录需要输出
                    output=true;
                    printf("%s %02d\n",(i->first).c_str(),j->month);
                }
                printf("%02d:%02d:%02d %02d:%02d:%02d ",j->day,j->hour,j->minute,jnext->day,jnext->hour,jnext->minute);//输出话费账单起止时间
                int t=jnext->time-j->time;//计算话费
                double bill=compute(*jnext,j->day)-compute(*j,j->day);//计算话费账单用时
                sumBill+=bill;//加到话费总额上
                printf("%d $%.2f\n",t,bill);//输出
            }
        }
        if(output)//如果该人的话费记录需要输出，输出话费总额
            printf("Total amount: $%.2f\n",sumBill);
    }
    return 0;
}
