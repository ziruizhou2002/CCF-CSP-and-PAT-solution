#include<bits/stdc++.h>
using namespace std;
int startTime=8*60,endTime=17*60;//银行开门时间、关门时间
struct Customer{
    int endTime,customer,window;//结束服务的时间、顾客编号、服务的窗口编号
    Customer(int e,int c,int w):endTime(e),customer(c),window(w){}
    bool operator <(const Customer&c)const{//重载小于运算符，注意优先级队列在定义的小于运算符下以最大的数作为队首
        return this->endTime>c.endTime;
    }
};
struct Window{
    int window=0,personNum=0;//窗口编号、该窗口下的人数
    Window(int w,int p):window(w),personNum(p){}
    bool operator <(const Window&w)const{//重载小于运算符，注意优先级队列在定义的小于运算符下以最大的数作为队首
        if(this->personNum!=w.personNum)
            return this->personNum>w.personNum;
        else
            return this->window>w.window;
    }
};
int main(){
    int N,M,K,Q;
    scanf("%d%d%d%d",&N,&M,&K,&Q);
    int processTime[K+1]={0},doneTime[K+1]={0},tailEndTime[N]={0};//记录顾客的处理时间、顾客业务处理完成的时间、每个窗口排队的最后一个人完成业务的时间，注意窗口从0开始编号
    bool isSever[K+1];//isSever记录那些顾客是在17：00之前接受服务的,true表示是在17:00之前接受服务的，false表示不是
    fill(isSever+1,isSever+K+1,true);//将isSever初始化为true
    priority_queue<Customer>customer;//顾客的优先级队列
    priority_queue<Window>window;//窗口的优先级队列
    for(int i=1;i<K+1;++i)//读取顾客业务的处理时间
        scanf("%d",&processTime[i]);
    for(int i=1;i<K+1;++i)//开始循环找出每位顾客处理完业务的时间
        if(window.size()<N){//如果正在进行服务的窗口数量<N
            customer.push(Customer(startTime+processTime[i],i,window.size()));//向customer压入一个顾客
            tailEndTime[window.size()]=startTime+processTime[i];//更新相应窗口下的最后一个人完成业务的时间
            window.push(Window(window.size(),1));//向window压入一个窗口
            doneTime[i]=startTime+processTime[i];//更新该顾客完成业务的时间
        }else if(window.size()==N){//如果N个窗口都在进行服务
            Window w=window.top();//读取人数最少的窗口
            if(w.personNum<M){//如果该窗口下人数<M
                window.pop();//弹出该窗口
                window.push(Window(w.window,w.personNum+1));//递增该窗口下人数并压入
                if(tailEndTime[w.window]>=endTime)//如果该窗口最后一个人完成业务的时间超过了最晚服务时间
                    isSever[i]=false;//正在处理的人不会得到服务，置isSever为false
                tailEndTime[w.window]+=processTime[i];//更新该窗口最后一个人完成业务的时间
                customer.push(Customer(tailEndTime[w.window],i,w.window));//向customer压入顾客
                doneTime[i]=tailEndTime[w.window];//更新该顾客完成业务的时间
            }else if(w.personNum==M){//如果该窗口下人数==M
                Customer c=customer.top();//读取完成业务时间最早的顾客
                customer.pop();//弹出该顾客
                if(tailEndTime[c.window]>=endTime)//如果该窗口最后一个人完成业务的时间超过了最晚服务时间
                    isSever[i]=false;//正在处理的人不会得到服务，置isSever为false
                tailEndTime[c.window]+=processTime[i];//更新该窗口最后一个人完成业务的时间
                customer.push(Customer(tailEndTime[c.window],i,c.window));//向customer压入顾客
                doneTime[i]=tailEndTime[c.window]; //更新该顾客完成业务的时间
            }
        }
    while(Q--){//进行查询
        int q;
        scanf("%d",&q);
        if(isSever[q])//如果得到了服务输出完成业务时间
            printf("%02d:%02d\n",doneTime[q]/60,doneTime[q]%60);
        else//如果没有得到服务输出Sorry
            printf("Sorry\n");
    }
    return 0;
}
