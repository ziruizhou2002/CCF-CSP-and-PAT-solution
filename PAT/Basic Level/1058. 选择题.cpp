#include<bits/stdc++.h>
using namespace std;
struct Problem{
    int score=0,num=0,wrongNum=0;//该题分数、选项个数、错误次数
    string answer="";//正确答案
};
int main(){
    int N,M,n;
    scanf("%d%d",&N,&M);
    Problem p[M];
    for(int i=0;i<M;++i){//读取题目数据
        scanf("%d%d%d",&p[i].score,&p[i].num,&n);
        while(n--){
            char c;
            scanf(" %c",&c);
            p[i].answer+=c;
        }
    }
    for(int i=0;i<N;++i){//读取学生选项
        int score=0;
        for(int j=0;j<M;++j){
            while(getchar()!='(');//读取字符直至遇到(字符
            scanf("%d",&n);
            string s="";
            while(n--){
                char c;
                scanf(" %c",&c);
                s+=c;
            }
            while(getchar()!=')');//读取字符直至遇到)字符
            if(s==p[j].answer)//与正确答案相同
                score+=p[j].score;//得分
            else//与正确答案不同
                ++p[j].wrongNum;//增加该题错误次数
        }
        printf("%d\n",score);//输出该学生分数
    }
    int maxWrong=0;//错得最多的题目的错误次数
    vector<int>wrongIndex;//错得最多的题目编号
    for(int i=0;i<M;++i){
        if(p[i].wrongNum>maxWrong){//题目错误次数大于maxWrong
            maxWrong=p[i].wrongNum;//更新maxWrong
            wrongIndex.clear();//清空vector
            wrongIndex.push_back(i+1);//将当前题目编号加入vector中
        }else if(p[i].wrongNum==maxWrong)//题目错误次数等于maxWrong
            wrongIndex.push_back(i+1);//将当前题目编号加入vector中
    }
    if(maxWrong==0)//不能以wrongIndex是否为空为判断条件
        printf("Too simple");
    else{
        printf("%d",maxWrong);
        for(int i=0;i<wrongIndex.size();++i)
            printf(" %d",wrongIndex[i]);
    }
    return 0;
}
