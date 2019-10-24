#include<bits/stdc++.h>
using namespace std;
string name[40005];//存储名字
int main(){
    int N,K;
    scanf("%d%d",&N,&K);
    vector<int>course[K+1];//其数组下标存储课程号，数组元素存储选修该课程的学生的名字在name中的下标
    for(int i=0;i<N;++i){
        int C,a;
        cin>>name[i]>>C;
        while(C--){
            scanf("%d",&a);
            course[a].push_back(i);
        }
    }
    for(int i=1;i<=K;++i){
        printf("%d %d\n",i,course[i].size());
        sort(course[i].begin(),course[i].end(),[](const int a,const int b){
            return name[a]<name[b];
        });//排序
        for(int j=0;j<course[i].size();++j)
            puts(name[course[i][j]].c_str());
    }
    return 0;
}
