#include<bits/stdc++.h>
using namespace std;
unordered_set<string>set_centers;//存储已选中的边的center
struct Edge{//边类
    int c1,c2,fee;
    string center;
    Edge(int cc1,int cc2,string cen,int f):c1(cc1),c2(cc2),center(cen),fee(f) {}
    bool operator <(const Edge&e)const{//重载小于运算符，注意优先级队列是大根堆
        return this->fee>e.fee||(this->fee==e.fee&&set_centers.find(this->center)==set_centers.end());
    }
};
vector<Edge>ans;//存储最终结果
int n,m,father[10005],sumFee;
int findFather(int x){//寻找根结点并进行路径压缩
    if(x==father[x])
        return x;
    int temp=findFather(father[x]);
    father[x]=temp;
    return temp;
}
int main(){
    scanf("%d%d",&n,&m);
    iota(father,father+n,0);
    priority_queue<Edge>edges;
    while(m--){
        int c1,c2,fee;
        string center;
        cin>>c1>>c2>>center>>fee;
        edges.push(Edge(c1,c2,center,fee));
    }
    while(!edges.empty()){
        Edge e=edges.top();
        edges.pop();
        int ua=findFather(e.c1),ub=findFather(e.c2);
        if(ua!=ub){
            father[ua]=ub;
            ans.push_back(e);
            sumFee+=e.fee;
            set_centers.insert(e.center);
        }
    }
    sort(ans.begin(),ans.end(),[](const Edge&e1,const Edge&e2){
        return e1.center<e2.center||(e1.center==e2.center&&e1.fee<e2.fee);
    });
    printf("%d %d\n",set_centers.size(),sumFee);
    for(Edge&e:ans)
        printf("%d %d %s %d\n",e.c1,e.c2,e.center.c_str(),e.fee);
    return 0;
}
