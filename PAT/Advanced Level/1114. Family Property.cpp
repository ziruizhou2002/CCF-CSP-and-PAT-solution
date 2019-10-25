#include<bits/stdc++.h>
using namespace std;
struct Estate{//存储集合最小id、集合结点个数num、集合总sets、集合总area
    int id,num=0;
    double sets=0.0,area=0.0;
};
bool cmp(const Estate&e1,const Estate&e2){//比较函数
    return e1.area!=e2.area?e1.area>e2.area:e1.id<e2.id;
}
int father[10005];//并查集底层数组
int findFather(int x){//查找根节点
    if(x==father[x])
        return x;
    int temp=findFather(father[x]);
    father[x]=temp;
    return temp;
}
void unionSet(int a,int b){//合并两个集合
    int ua=findFather(a),ub=findFather(b);
    if(ua!=ub)
        father[max(ua,ub)]=min(ua,ub);//以小的id作为根节点
}
unordered_map<int,pair<double,double>>idEstate;
unordered_map<int,Estate>familyEstate;
int main(){
    int N;
    scanf("%d",&N);
    iota(father,father+10005,0);
    while(N--){//读取数据并合并相关集合
        int id,f,m,k,a;
        scanf("%d%d%d%d",&id,&f,&m,&k);
        if(f!=-1)
            unionSet(id,f);
        if(m!=-1)
            unionSet(id,m);
        while(k--){
            scanf("%d",&a);
            unionSet(id,a);
        }
        scanf("%lf%lf",&idEstate[id].first,&idEstate[id].second);//记录id和对应的sets、area
    }
    for(int i=0;i<10005;++i){//遍历并查集数组
        int temp=findFather(i);
        if(temp!=i)//根节点不等于本身
            ++familyEstate[temp].num;//递增根节点下集合的结点个数
        if(idEstate.find(i)!=idEstate.cend()){//累加集合的总sets、总area
            familyEstate[temp].sets+=idEstate[i].first;
            familyEstate[temp].area+=idEstate[i].second;
        }
    }
    vector<Estate>v;
    for(auto i=familyEstate.begin();i!=familyEstate.end();++i){//将familyEstate中的值搬迁到vector中,并更新相关信息
        (i->second).id=i->first;
        ++(i->second).num;//集合下结点个数没有统计根节点，所以要+1
        (i->second).sets/=(i->second).num;
        (i->second).area/=(i->second).num;
        v.push_back(i->second);
    }
    sort(v.begin(),v.end(),cmp);//排序
    printf("%d\n",v.size());
    for(int i=0;i<v.size();++i)
        printf("%04d %d %.3f %.3f\n",v[i].id,v[i].num,v[i].sets,v[i].area);
    return 0;
}
