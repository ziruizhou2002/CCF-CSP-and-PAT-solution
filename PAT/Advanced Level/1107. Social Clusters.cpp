#include<bits/stdc++.h>
using namespace std;
int hobby[1005],father[1005];
int findFather(int x){//查找父亲结点并进行路径压缩
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
    int N;
    scanf("%d",&N);
    iota(father,father+N+1,0);//c++标准库自带函数，将第三个参数赋值给father每一个元素，每赋值一次，第三个参数递增一次，最后赋值完成时，father[i]=i
    for(int i=1;i<=N;++i){//读取数据
        int K,a;
        scanf("%d:",&K);
        while(K--){
            scanf("%d",&a);
            if(hobby[a]==0)//没有人有当前这个爱好
                hobby[a]=i;//i作为第一个有该爱好的人
            else//有人喜欢该爱好
                unionSet(hobby[a],i);//将有同样爱好的两个人合并为一个集合
        }
    }
    int result[N+1]={0};//储存每个集合的人数
    for(int i=1;i<N+1;++i)
        ++result[findFather(i)];
    sort(result,result+N+1,[](const int a,const int b){//从大到小排序
        return a>b;
    });
    int cnt=N+1-count(result,result+N+1,0);//储存集合不为0的集合个数，c++标准库自带的count函数计算result中0的个数
    printf("%d\n",cnt);//输出
    for(int i=0;i<cnt;++i)//输出result前cnt个元素(result已经从大到小排序，输出的都是集合个数不为0的)
        printf("%s%d",i>0?" ":"",result[i]);
    return 0;
}
