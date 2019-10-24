#include<bits/stdc++.h>
using namespace std;
int father[10005],birdNum=0,treeNum=0;
int findFather(int x){//查找父亲结点
    if(x==father[x])
        return x;
    int temp=findFather(father[x]);
    father[x]=temp;
    return temp;
}
void unionSet(int a,int b){//合并两个集合
    int ua=findFather(a),ub=findFather(b);
    if(ua!=ub)
        father[ua]=ub;
}
int main(){
    iota(father,father+10005,0);//c++标准库自带函数，将第三个参数赋值给father每一个元素，每赋值一次，第三个参数递增一次，最后赋值完成时，father[i]=i  
    int N;
    scanf("%d",&N);
    while(N--){//读取数据，合并集合并更新birdNum
        int K,a,b;
        scanf("%d",&K);
        if(K--){
            scanf("%d",&a);
            birdNum=max(birdNum,a);
        }
        while(K--){
            scanf("%d",&b);
            unionSet(a,b);
            birdNum=max(birdNum,b);
        }
    }
    for(int i=1;i<=birdNum;++i)//遍历并查集数组，找出其中findFather(i)==i的元素数量
        if(findFather(i)==i)
            ++treeNum;
    printf("%d %d\n",treeNum,birdNum);
    scanf("%d",&N);
    while(N--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%s\n",findFather(a)==findFather(b)?"Yes":"No");//检测两只鸟是否在同一集合
    }
    return 0;
}
