#include<bits/stdc++.h>
using namespace std;
struct Applicant{//入学申请的结构体
    int id,GE,GI,finalGrade,school[6];
};
bool cmp(const Applicant&a1,const Applicant&a2){//比较函数
    return a1.finalGrade!=a2.finalGrade?a1.finalGrade>a2.finalGrade:a1.GE>a2.GE;
}
Applicant applicant[40005];
int N,M,K,quota[105],Rank[40005];
vector<int>admission[105];
int main(){
    scanf("%d%d%d",&N,&M,&K);
    for(int i=0;i<M;++i)
        scanf("%d","a[i]);
    for(int i=0;i<N;++i){//读取数据
        scanf("%d%d",&applicant[i].GE,&applicant[i].GI);
        for(int j=0;j<K;++j)
            scanf("%d",&applicant[i].school[j]);
        applicant[i].id=i;
        applicant[i].finalGrade=applicant[i].GE+applicant[i].GI;
    }
    sort(applicant,applicant+N,cmp);//排序
    Rank[applicant[0].id]=1;
    for(int i=1;i<N;++i)//求出排名
        Rank[applicant[i].id]=applicant[i].finalGrade==applicant[i-1].finalGrade&&applicant[i].GE==applicant[i-1].GE?Rank[applicant[i-1].id]:i+1;
    for(int i=0;i<N;++i)//进行录取
        for(int j=0;j<K;++j){//遍历志愿学校
            int temp=applicant[i].school[j];
            if(quota[temp]>0||Rank[admission[temp].back()]==Rank[applicant[i].id]){//志愿学校还有录取名额或者最后录取的和当前学生的排名相同
                admission[temp].push_back(applicant[i].id);//志愿学校接受该申请
                --quota[temp];//递减录取名额
                break;
            }
        }
    for(int i=0;i<M;++i){//输出
        sort(admission[i].begin(),admission[i].end());
        for(int j=0;j<admission[i].size();++j)
            printf("%s%d",j>0?" ":"",admission[i][j]);
        printf("\n");
    }
    return 0;
}
