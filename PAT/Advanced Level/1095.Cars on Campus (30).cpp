#include<bits/stdc++.h>
using namespace std;
struct Record{
    string plateNum;//车名
    int time=0;//时间
    bool in=false;//停入还是开出
    Record(const string&s,int t,bool i):time(t),in(i){//构造函数
        plateNum=s;
    }
};
bool cmp(const Record&r1,const Record&r2){//比较函数
    return r1.time<r2.time;
}
int main(){
    int N,K;
    scanf("%d%d",&N,&K);
    unordered_map<string,vector<Record>>allCar;//存储车名与其对应的所有记录信息
    int h,m,s;
    while(N--){//读取数据
        string in,plate;
        cin>>plate;
        scanf("%d:%d:%d",&h,&m,&s);
        cin>>in;
        allCar[string(plate)].push_back(Record(plate,h*3600+m*60+s,in=="in"));
    }
    vector<Record>validCar;//存储合法的记录信息
    set<string>maxPlate;//存储停放时间最长的车名，set可直接按字典序排序
    int maxTime=0;//存储停放的最长时间
    for(auto i=allCar.begin();i!=allCar.end();++i){//遍历allCar
        sort((i->second).begin(),(i->second).end(),cmp);//排序
        int t=0;//记录当前遍历到的车的停放时间
        for(int j=0;j<(i->second).size()-1;++j)//遍历记录信息
            if((i->second)[j].in&&!(i->second)[j+1].in){//如果当前记录与下一记录是匹配的
                validCar.push_back((i->second)[j]);//加入合法记录
                validCar.push_back((i->second)[j+1]);//加入合法记录
                t+=(i->second)[j+1].time-(i->second)[j].time;//累加停放时间
            }
        if(t>maxTime){//比较当前车辆停放时间与停放的最长时间，更新相关信息
            maxPlate.clear();
            maxPlate.insert(i->first);
            maxTime=t;
        }else if(t==maxTime)
            maxPlate.insert(i->first);
    }
    sort(validCar.begin(),validCar.end(),cmp);//对合法记录排序
    int parkCar=0,index=0;//当前停车场内的车辆数，索引位置
    while(K--){
        scanf("%d:%d:%d",&h,&m,&s);
        int t=(h*60+m)*60+s;//查询时间
        for(;index<validCar.size()&&validCar[index].time<=t;++index)//遍历合法记录
            parkCar+=validCar[index].in?1:-1;//统计停车场内车辆数
        printf("%d\n",parkCar);//输出
    }
    for(auto i=maxPlate.cbegin();i!=maxPlate.cend();++i)
        cout<<*i<<" ";
    printf("%02d:%02d:%02d",maxTime/3600,maxTime%3600/60,maxTime%60);
    return 0;
}
