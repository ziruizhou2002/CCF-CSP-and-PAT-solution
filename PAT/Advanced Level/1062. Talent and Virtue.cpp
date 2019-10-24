#include<bits/stdc++.h>  
using namespace std;  
struct Student{  
    int id,de,cai,sum;//学生id、德分、才分、总分
    int leibie;//定义类别信息  
};  
bool cmp(const Student&s1,const Student&s2){  //比较函数 
    if(s1.leibie!=s2.leibie)  
        return s1.leibie<s2.leibie;  
    else if(s1.sum!=s2.sum)  
        return s1.sum>s2.sum;  
    else if(s1.de!=s2.de)  
        return s1.de>s2.de;  
    else  
        return s1.id<s2.id;  
}  
int main(){
    int N,L,H,size=0;
    scanf("%d%d%d",&N,&L,&H);  
    Student student[N];  
    for(int i=0;i<N;++i){  
        scanf("%d%d%d",&student[size].id,&student[size].de,&student[size].cai);  
        if(student[size].de>=L&&student[size].cai>=L){  
            student[size].sum=student[size].de+student[size].cai;   
            if(student[size].de>=H&&student[size].cai>=H)//分类 
                student[size].leibie=1;  
            else if(student[size].de>=H&&student[size].cai<H)  
                student[size].leibie=2;  
            else if(student[size].de<H&&student[size].cai<H  
                    &&student[size].de>=student[size].cai)  
                student[size].leibie=3;  
            else  
                student[size].leibie=4;  
            ++size;  
        }  
    }  
    sort(student,student+size,cmp);//排序
    printf("%d\n",size);  
    for(int i=0;i<size;++i)
        printf("%d %d %d\n",student[i].id,student[i].de,student[i].cai);  
    return 0;  
}  
