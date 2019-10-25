#include<bits/stdc++.h>
using namespace std;
string str1[4]={"Qian","Bai","Shi",""};//存储个十百千
string str2[3]={"","Wan","Yi"};//存储万亿
string digit[10]={//存储数字
                  "ling","yi","er","san","si","wu","liu","qi","ba","jiu"
                 };
bool ling=false;//指示是否有积累的0还没有输出
bool output(const string&s,int left,int right,bool space){//按要求输出字符串s的[left,right)区间内的数字，space指示处理字符串s前是否需要输出空格
    bool f=false;//指示处理字符串s的[left,right)区间的过程中是否有输出
    for(int i=left;i<right;++i)//遍历字符串s的[left,right)区间
        if(s[i]=='0'){//当前字符为'0'
            ling=true;//有0积累未被输出
        }else if(s[i]!='0'){//当前字符不为'0'
            if(ling){//该字符前有0积累未被输出
                cout<<" ling "<<digit[s[i]-'0'];//输出0与该数字
                ling=false;//积累的0被处理过，没有0积累
            }else if(!f)//该字符前没有0积累且还未输出过
                printf("%s%s",space?" ":"",digit[s[i]-'0'].c_str());//输出数字,如果需要输出空格，先输出数字之前先输出一个空格
            else
                cout<<" "<<digit[s[i]-'0'];//输出空格和数字
            if(i<right-1)//当前字符不是处理区间内最后一个字符
                cout<<" "<<str1[4+i-right];//输出空格和个十百千位级
            f=true;//已有输出
        }
    if(f)//有输出
        ling=false;//积累的0清空
    return f;//返回f
}
int main(){
    string s;
    cin>>s;
    if(s[0]=='-'){//如果是负数先输出“Fu”,然后将该字符从字符串s中删掉
        s.erase(s.begin());
        cout<<"Fu ";
    }
    if(s=="0")//对字符串s为0的情况进行特殊处理
        cout<<"ling";
    int group=s.size()%4==0?s.size()/4-1:s.size()/4;//表示字符串s如果每4个字符一组可以分成几组(如果字符串长度能整除4，要减去1组)
    int extra=s.size()%4==0?4:s.size()%4;//表示字符串每4个字符一组剩下的字符(如果恰好分完，剩下字符为4)
    for(int i=0;i<s.size();){//遍历字符串s
        bool f=i==0?output(s,0,extra,false):output(s,i,i+4,true);//处理每4个一组的字符，注意除第一组被处理的字符外，其余组字符处理前均需先输出一个空格
        i+=(i==0)?extra:4;//如果是第一组处理的字符，i递增extra；否则i递增4
        if(group!=0&&f)//当前处理的组不是最后一组且当前组有输出
            cout<<" "<<str2[group];//输出万亿位级
        --group;//组数递减
    }
    return 0;
}
