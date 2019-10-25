#include<bits/stdc++.h>
using namespace std;
struct Person{
    string name="",id="";
    int score;
    Person(int s=0):score(s){}
};
int main(){
    int N;
    scanf("%d",&N);
    Person female(-1),male(101),temp;
    char gender;
    for(int i=0;i<N;++i){
        cin>>temp.name>>gender>>temp.id>>temp.score;
        if(gender=='F'&&temp.score>female.score)
                female=temp;
        else if(gender=='M'&&temp.score<male.score)
                male=temp;
    }
    if(female.score==-1)
        printf("Absent\n");
    else
        printf("%s %s\n",female.name.c_str(),female.id.c_str());
    if(male.score==101)
        printf("Absent\n");
    else
        printf("%s %s\n",male.name.c_str(),male.id.c_str());
    if(female.score!=-1&&male.score!=101)
        printf("%d",female.score-male.score);
    else
        printf("NA");
    return 0;
}
