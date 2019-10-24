#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_set<int>record;//存储被覆盖的数
    vector<int>v;//存储输入的数
    int K,n;
    scanf("%d",&K);
    while(K--){
        scanf("%d",&n);
        v.push_back(n);
        while(n!=1){//n不为1，按要求进行操作
            if(n%2==1)
                n=3*n+1;
            n/=2;
            record.insert(n);//n被覆盖
        }
    }
    sort(v.begin(),v.end());//排序
    bool output=false;//是否需要输出空格
    for(int i=v.size()-1;i>=0;--i)//从大到小遍历
        if(record.find(v[i])==record.cend()){//按要求输出
            printf("%s%d",output?" ":"",v[i]);
            output=true;
        }
    return 0;
}
