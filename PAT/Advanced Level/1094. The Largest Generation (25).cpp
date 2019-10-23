#include<bits/stdc++.h>
using namespace std;
vector<int>tree[105];
int levelNum[105];//存储每层下结点个数
void DFS(int v,int level){//level表示顶点v所处的层数
    ++levelNum[level];//递增相应层数的结点个数
    for(int i:tree[v])//递归遍历其能到达的结点
        DFS(i,level+1);
}
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    while(M--){
        int id,K,a;
        scanf("%d%d",&id,&K);
        while(K--){
            scanf("%d",&a);
            tree[id].push_back(a);
        }
    }
    DFS(1,1);
    int i=max_element(levelNum+1,levelNum+N)-levelNum;//c++标准库自带的求一个序列中最大元素的函数，并返回一个迭代器
    printf("%d %d",levelNum[i],i);
    return 0;
}
