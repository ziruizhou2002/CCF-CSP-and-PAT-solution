#include<bits/stdc++.h>
using namespace std;
struct Mouse{//存储老鼠重量、排名的结构体
    int weight,rank;
};
int main(){
    int Np,Ng;
    scanf("%d%d",&Np,&Ng);
    Mouse mouse[Np];//维度为Np的Mouse类型数组，数组下标存储老鼠编号
    for(int i=0;i<Np;++i)
        scanf("%d",&mouse[i].weight);
    queue<int>q;//队列
    for(int i=0;i<Np;++i){//将初始顺序放入队列中
        int a;
        scanf("%d",&a);
        q.push(a);
    }
    while(q.size()>1){//在队列元素个数大于1，即进行比较的老鼠多于1只时继续循环
        int extra=q.size()%Ng==0?Ng:q.size()%Ng,group=(q.size()-1)/Ng;//extra存储最后一组老鼠数量，group存储当前比较的老鼠分的组数-1
        for(int i=0;i<group+1;++i){//对这group+1组老鼠进行比较，选出晋级的老鼠
            int temp=i==group?extra:Ng,index=q.front();//存储当前组的老鼠数量
            for(int j=0;j<temp;++j){//处理当前组的老鼠
                mouse[q.front()].rank=group+2;//将当前组的老鼠的排名置为group+2，即组数+1
                if(mouse[q.front()].weight>mouse[index].weight)//找出体重最大的老鼠在数组中的索引
                    index=q.front();
                q.pop();//弹出当前队首元素
            }
            q.push(index);//将体重最大的老鼠在数组中的索引放入队列中
        }
    }
    mouse[q.front()].rank=1;//将剩余的唯一一只老鼠的排名置为1
    for(int i=0;i<Np;++i)//输出
        printf("%s%d",i>0?" ":"",mouse[i].rank);
    return 0;
}
