#include<bits/stdc++.h>
using namespace std;
struct Problem{
    double score=0.0;//该题分数
    int num=0;//选项个数、正确选项个数
    bool answer[5]={false};//正确答案
};
int main(){
    int N,M,n;
    char c;
    scanf("%d%d",&N,&M);
    Problem p[M];
    map<pair<int,char>,int>wrong;//存储错误选项错误次数，map会按键排序,pair类型自定义的<运算符先比较first元素，如果相等再比较second元素
    for(int i=0;i<M;++i){//读取题目数据
        scanf("%lf%d%d",&p[i].score,&p[i].num,&n);
        while(n--){
            scanf(" %c",&c);
            p[i].answer[c-'a']=true;
        }
    }
    for(int i=0;i<N;++i){//读取学生选项
        double score=0.0;
        for(int j=0;j<M;++j){
            while(getchar()!='(');//读取字符直至遇到(字符
            scanf("%d",&n);
            bool correct=true,less=false,option[5]={false};
            for(int ii=0;ii<n;++ii){
                scanf(" %c",&c);
                option[c-'a']=true;
            }
            for(int i=0;i<5;++i)//比较学生选的选项和正确选项
                if(option[i]!=p[j].answer[i]){//学生选的当前选项和正确选项不同
                    ++wrong[pair<int,char>(j+1,i+'a')];//这个选项选错了，递增对应的错误次数
                    if(option[i]&&!p[j].answer[i])//学生选了不是正确答案的选项
                        correct=false;//这道题错误，将correct置false
                    else if(!option[i]&&p[j].answer[i])//学生少选了正确选项
                        less=true;//将less置true
                }
            while(getchar()!=')');//读取字符直至遇到)字符
            if(correct&&!less)//选择了全部的正确选项
                score+=p[j].score;//得到全部分数
            else if(correct&&less)//漏选了正确选项
                score+=p[j].score/2;//得到一半分数
        }
        printf("%.1f\n",score);//输出该学生分数
    }
    int maxWrong=0;//错得最多的选项的错误次数
    vector<pair<int,char>>wrongIndex;//错得最多的选项的题目编号、选项编号
    for(auto i=wrong.cbegin();i!=wrong.cend();++i)
        if(i->second>maxWrong){//选项错误次数大于maxWrong
            maxWrong=i->second;//更新maxWrong
            wrongIndex.clear();//清空vector
            wrongIndex.push_back(i->first);//将当前选项信息加入vector中
        }else if(i->second==maxWrong)//选项错误次数等于maxWrong
            wrongIndex.push_back(i->first);//将当前选项信息加入vector中
    if(maxWrong==0)//不能以wrongIndex是否为空为判断条件
        printf("Too simple");
    else
        for(pair<int,char>& i:wrongIndex)
            printf("%d %d-%c\n",maxWrong,i.first,i.second);
    return 0;
}
