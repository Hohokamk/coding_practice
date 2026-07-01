#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    int num=0;
    while(cin>>a>>b>>c>>d&&a!=-1){
        num++;
        for(int i=d;i<23*28*33+d;i++){
            if(!((i-a)%23)&&!((i-b)%28)&&!((i-c)%33)){
               cout<<"Case "<<num<<": the next triple peak occurs in "<<i-d<<" days." <<endl;
               break;
            }
        }//优化：步长选择23或28或33的倍数
    }
}