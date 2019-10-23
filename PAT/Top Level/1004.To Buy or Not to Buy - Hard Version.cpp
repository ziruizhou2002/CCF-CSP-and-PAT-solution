#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int>trans;
vector<vector<int>>strings;
int Extra=INT_MAX,Remain=INT_MAX;//匹配成功时最少的多余字符的数量、匹配失败时还有多少个字符没有匹配成功
void DFS(int index,vector<int>need,int extra,int&loop){
    if(extra>=Extra||loop>=200)//当当前多余字符数量大于等于最小多余字符数量或者搜索次数达到200次时结束搜索
        return;
    ++loop;//进行一次搜索递增一次loop
    int use=0;//当前字符串匹配成功的字符数量
    for(int i=0;i<need.size()-1;++i)//遍历出现的字符
        if(strings[index][i]>0)//当前字符串也出现了相应字符，更新相关变量
            if(strings[index][i]>need[i]){
                use+=need[i];
                need[i]=0;
            }else{
                use+=strings[index][i];
                need[i]-=strings[index][i];
            }
    extra+=strings[index].back()-use;//多余字符等于字符串字符总数-匹配成功的字符数量
    need.back()-=use;//更新没有匹配成功的字符数量
    if(need.back()==0){//所有字符均匹配成功
        Extra=min(Extra,extra);//更新最小多余字符数量
        Remain=0;//所有字符均匹配成功
        return;
    }
    if(index==strings.size()-1){//到达最后一个字符串
        Remain=min(need.back(),Remain);//更新Remain
        return;
    }
    for(int i=index+1;i<strings.size();++i)//继续进行搜索
        DFS(i,need,extra,loop);
}
int main(){
    string s;
    int n;
    cin>>s>>n;
    vector<int>need;//储存需要进行匹配的字符串的字符出现次数
    for(char c:s){//遍历字符串
        if(trans.find(c)==trans.end()){//该字符没出现过
            trans.insert({c,trans.size()});//插入trans中
            need.push_back(0);//插入need中
        }
        ++need[trans[c]];//递增该字符出现次数
    }
    need.push_back(s.size());//在need末尾插入该字符串的字符总数
    while(n--){
        cin>>s;
        vector<int>v(need.size(),0);//每个字符串维护一个与进行匹配的字符串相同长度的数组
        for(char c:s)//遍历字符串
            if(trans.find(c)!=trans.end())//只统计在进行匹配的字符串中出现的字符出现次数
                ++v[trans[c]];
        v.push_back(s.size());//在末尾插入该字符串的字符总数
        strings.push_back(v);//放入strings中
    }
    sort(strings.begin(),strings.end(),[](const vector<int>&b1,const vector<int>&b2){
        return b1.back()<b2.back();
    });//按字符串长度从短到长排序
    int loop=0;//结束搜索的变量
    for(int i=0;i<strings.size()&&loop<200;++i)//遍历所有的字符串，当搜索次数达到200次跳出循环
        DFS(i,need,0,loop);//进行搜索
    if(Remain==0)
        printf("Yes %d\n",Extra);
    else
        printf("No %d\n",Remain);
    return 0;
}
