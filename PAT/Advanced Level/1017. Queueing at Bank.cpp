#include<bits/stdc++.h>
using namespace std;
struct Customer{
    int arriveTime,processTime;//顾客到达时间、顾客处理业务时间
};
bool cmp(const Customer&c1,const Customer&c2){//比较函数，用来对customer进行排序
    return c1.arriveTime<c2.arriveTime;
}
int openTime=8*60*60,closeTime=17*60*60;//银行开门时间，关门时间
int main(){
    int N,K;
    scanf("%d%d",&N,&K);
    priority_queue<int,vector<int>,greater<int>>window;//定义窗口的优先级队列，将时间小的放在队首
    vector<Customer>customer;//顾客的vector
    double waitTime=0.0;//等待时间
    while(N--){
        int h,m,s;
        Customer c;
        scanf("%d:%d:%d %d",&h,&m,&s,&c.processTime);
        c.arriveTime=(h*60+m)*60+s;//将到达时间转换成秒为单位
        c.processTime*=60;//处理时间变为秒
        if(c.arriveTime<=closeTime)//如果到达时间早于关门时间，加入顾客的vector中
            customer.push_back(c);
    }
    sort(customer.begin(),customer.end(),cmp);//排序
    for(int i=0;i<customer.size();++i){//遍历所有顾客
        if(customer[i].arriveTime<openTime){//如果顾客到达时间早于开门时间，更新等待时间，并向到达时间赋值为开门时间
            waitTime+=openTime-customer[i].arriveTime;
            customer[i].arriveTime=openTime;
        }
        if(window.size()==0)//如果窗口都没有进行服务，直接将处理完业务的时间加入优先级队列
            window.push(customer[i].arriveTime+customer[i].processTime);
        else{
            int time=window.top();//获取最早处理完业务的窗口的时间
            while(time<=customer[i].arriveTime){//如果最早处理完业务的窗口的时间<=当前顾客到达时间，释放该窗口
                window.pop();
                if(!window.empty())
                    time=window.top();
                else
                    time=INT_MAX;
            }
            if(window.size()<K)//如果正在服务的窗口数小于K,直接将处理完业务的时间加入优先级队列
                window.push(customer[i].arriveTime+customer[i].processTime);
            else{//如果正在服务的窗口数等于K,释放一个窗口，更新等待时间，将处理完业务的时间加入优先级队列
                time=window.top();
                window.pop();
                waitTime+=time-customer[i].arriveTime;
                window.push(time+customer[i].processTime);
            }
        }
    }
    waitTime/=customer.size()*60.0;//将等待时间变为秒并求平均时间
    printf("%.1f",waitTime);
    return 0;
}
