#include<bits/stdc++.h>
using namespace std;
struct Student{
    string name="",number="";
    int score;
    Student(int s=0):score(s){}
};
int main(){
    int N;
    scanf("%d",&N);
    Student Max(-1),Min(101),temp;
    for(int i=0;i<N;++i){
        cin>>temp.name>>temp.number>>temp.score;
        if(Max.score<temp.score)
            Max=temp;
        if(Min.score>temp.score)
            Min=temp;
    }
    printf("%s %s\n%s %s",Max.name.c_str(),Max.number.c_str(),Min.name.c_str(),Min.number.c_str());
    return 0;
}
