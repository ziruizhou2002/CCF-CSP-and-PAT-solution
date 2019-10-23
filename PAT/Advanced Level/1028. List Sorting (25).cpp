#include <bits/stdc++.h>
using namespace std;
struct Student{
    int id,grade;
    string name;
};
int main(){
    int N,C;
    scanf("%d%d",&N,&C);
    vector<Student>stu(N);
    for(int i=0;i<N;++i)
        cin>>stu[i].id>>stu[i].name>>stu[i].grade;
    if(C==1)
        sort(stu.begin(),stu.end(),[](const Student&s1,const Student&s2){
            return s1.id<s2.id;
        });
    else if(C==2)
        sort(stu.begin(),stu.end(),[](const Student&s1,const Student&s2){
            return s1.name!=s2.name?s1.name<s2.name:s1.id<s2.id;
        });
    else if(C==3)
        sort(stu.begin(),stu.end(),[](const Student&s1,const Student&s2){
            return s1.grade!=s2.grade?s1.grade<s2.grade:s1.id<s2.id;
        });
    for(int i=0;i<N;++i)
        printf("%06d %s %d\n",stu[i].id,stu[i].name.c_str(),stu[i].grade);
    return 0;
}
