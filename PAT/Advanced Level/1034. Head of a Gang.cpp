#include<bits/stdc++.h>
using namespace std;
struct Set{//作为辅助求解的集合类
    int head=-1;//头目
    int weight=0;//集合的总权值
    int num=0;//集合的人数
};
const int MAXV=2005;
int weight[MAXV]={0};//点权
bool visit[MAXV]={false};//结点是否已被访问
Set gang[MAXV];//辅助的计算Gang的数组
vector<vector<int>>graph(MAXV);
void DFS(int v,int start){
    visit[v]=true;//将该节点设置为已访问
    ++gang[start].num;//递增该集合人数
    gang[start].weight+=weight[v];//增加该集合总权值
    if(gang[start].head==-1)//更新该集合头目
        gang[start].head=v;
    else if(weight[v]>weight[gang[start].head])
        gang[start].head=v;
    for(int i:graph[v])
        if(!visit[i])
            DFS(i,start);
}
int main(){
    int N,K;
    scanf("%d%d",&N,&K);
    unordered_map<string,int>STOI;//将名字映射到一个整数
    vector<string>ITOS;//将整数映射到名字
    for(int i=0;i<N;++i){//读入数据
        getchar();
        string s1,s2;
        cin>>s1>>s2;
        int w;
        scanf("%d",&w);
        if(STOI.find(s1)==STOI.cend()){//如果STOI中没有改名字，将名字加入STOI，并同步更新ITOS
            STOI[s1]=ITOS.size();
            ITOS.push_back(s1);
        }if(STOI.find(s2)==STOI.cend()){
            STOI[s2]=ITOS.size();
            ITOS.push_back(s2);
        }
        weight[STOI[s1]]+=w;//更新点权
        weight[STOI[s2]]+=w;//更新点权
        graph[STOI[s1]].push_back(STOI[s2]);//向图中增加无向边
        graph[STOI[s2]].push_back(STOI[s1]);//向图中增加无向边
    }
    for(int i=0;i<2*N;++i)//深度优先遍历
        if(!visit[i])
            DFS(i,i);
    map<string,int>result;//存储最终输出结果，利用map自动按头目名字排序
    for(int i=0;i<N;++i)//遍历找到符合条件的Gang
        if(gang[i].num>2&&gang[i].weight/2>K)
            result.insert({ITOS[gang[i].head],gang[i].num});
    printf("%d\n",result.size());
    for(auto i=result.cbegin();i!=result.cend();++i)
        printf("%s %d\n",(i->first).c_str(),i->second);
    return 0;
}
