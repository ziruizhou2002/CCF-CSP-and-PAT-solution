#include<bits/stdc++.h>
using namespace std;
struct Person{
    string name;//名字
    int height;//身高
};
Person person[10005];//存储数据的数组
void output(int left,int right){//输出某一排名字的函数,输出范围为person数组中的[left,right)区间
    vector<int>v(right-left);//按排队规则存储person数组相应下标
    int mid=v.size()/2;//中间位置
    for(int i=left;i<right;++i){
        int k=i-left;
        if(k%2==1)//该向中间人右边排（数组v的左边是中间人的右边）
            v[mid-(k+1)/2]=i;
        else//该向中间人左边排（数组v的右边是中间人的左边）
            v[mid+k/2]=i;
    }
    for(int i=0;i<v.size();++i)//输出
        printf("%s%s",i>0?" ":"",person[v[i]].name.c_str());
    puts("");
}
int main(){
    int N,K;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;++i)
        cin>>person[i].name>>person[i].height;
    sort(person,person+N,[](const Person&p1,const Person&p2){//比较函数
        return p1.height!=p2.height?p1.height>p2.height:p1.name<p2.name;
    });//排序
    for(int i=0;i<N;i+=N/K)//按排输出
        if(i==0){
            output(i,i+N%K+N/K);
            i+=N%K;
        }else
            output(i,i+N/K);
    return 0;
}
