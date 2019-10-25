#include <bits/stdc++.h>
using namespace std;
struct Student{//学生结构体，把成绩均初始化为-1，以便输出
    string id;
    int Gp=-1,Gmid=-1,Gfinal=-1,G=0;
};
int main(){
    unordered_map<string,Student>m;//学生id到学生结构体的映射
    int P,M,N,score;
    scanf("%d%d%d",&P,&M,&N);
    string temp;
    for(int i=0; i<P; ++i){
        cin>>temp>>score;
        m[temp].Gp=score;
    }
    for(int i=0; i<M; ++i){
        cin>>temp>>score;
        m[temp].Gmid=score;
    }
    for(int i=0; i<N; ++i){
        cin>>temp>>score;
        auto&j=m[temp];
        j.Gfinal=score;
        if(j.Gmid>j.Gfinal)//计算最终成绩
            j.G=(int)round(j.Gmid*0.4+j.Gfinal*0.6);
        else
            j.G=j.Gfinal;
    }
    vector<Student>v;//存储合格学生的数组
    for(auto&i:m)//将合格学生加入数组v中
        if((i.second).Gp>=200&&(i.second).G>=60){
            i.second.id=i.first;
            v.push_back(i.second);
        }
    sort(v.begin(),v.end(),[](const Student&s1,const Student&s2){//比较函数
        if(s1.G!=s2.G)
            return s1.G>s2.G;
        else
            return s1.id<s2.id;
    });
    for(auto&i:v)
        printf("%s %d %d %d %d\n",i.id.c_str(),i.Gp,i.Gmid,i.Gfinal,i.G);
    return 0;
}
