#include <iostream>
using namespace std;
int f(int x,int y){
    if(y>x){
        return f(x,x);
    }
    if(x==0){
        return 1;
    }
    if(y<=0){
        return 0;
    }
    return f(x,y-1)+f(x-y,y);
}
int main(){
    int t,M,N;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>M>>N;
        cout<<f(M,N)<<endl;
    }
    return 0;
}