#include<bits/stdc++.h>
using namespace std;
struct student{
    string num;//准考证号
    int site_number,test_date,score;//考场编号、考试日期、分数
    student(string str,int sn,int td,int s):num(str),site_number(sn),test_date(td),score(s){}
};
struct site{
    int site_number,presonNum=0;//考场编号、人数
    site(int s,int p):site_number(s),presonNum(p){}
};
int main(){
    int N,M,a,b;
    scanf("%d%d",&N,&M);
    vector<student>students;
    while(N--){//读取信息
        string s;
        cin>>s>>a;
        students.push_back(student(s,stoi(s.substr(1,3)),stoi(s.substr(4,6)),a));
    }
    for(int ii=1;ii<=M;++ii){
        scanf("%d",&b);
        vector<student>v;
        if(b==1){
            char c=getchar();//读取空格
            c=getchar();//读取级别符号
            printf("Case %d: %d %c\n",ii,b,c);
            for(auto&i:students)//遍历所有学生信息
                if(i.num[0]==c)//符合级别要求
                    v.push_back(i);//放入到v中
            sort(v.begin(),v.end(),[](const student&s1,const student&s2){//排序
                if(s1.score!=s2.score)
                    return s1.score>s2.score;
                return s1.num<s2.num;
            });
            if(v.empty())//查询结构为空
                puts("NA");//输出NA
            for(auto&i:v)//输出
                printf("%s %d\n",i.num.c_str(),i.score);
        }else if(b==2){
            scanf("%d",&a);
            printf("Case %d: %d %03d\n",ii,b,a);
            int presonNum=0,allScore=0;//考场人数和总分数
            for(auto&i:students)//遍历所有学生信息
                if(i.site_number==a){//符合级别要求
                    ++presonNum;
                    allScore+=i.score;
                }
            if(presonNum==0)//查询结构为空
                puts("NA");//输出NA
            else
                printf("%d %d\n",presonNum,allScore);//输出
        }else{
            scanf("%d",&a);
            printf("Case %d: %d %06d\n",ii,b,a);
            vector<site>sites;
            map<int,int>m;
            for(auto&i:students)//遍历所有学生信息
                if(i.test_date==a)//符合级别要求
                    ++m[i.site_number];//递增对应考场人数
            for(auto&i:m)//遍历所有考场
                sites.push_back(site(i.first,i.second));//放入到sites中
            sort(sites.begin(),sites.end(),[](const site&s1,const site&s2){//排序
                if(s1.presonNum!=s2.presonNum)
                    return s1.presonNum>s2.presonNum;
                return s1.site_number<s2.site_number;
            });
            if(sites.empty())//查询结构为空
                puts("NA");//输出NA
            for(auto&i:sites)//输出
                printf("%d %d\n",i.site_number,i.presonNum);
        }
    }
    return 0;
}
