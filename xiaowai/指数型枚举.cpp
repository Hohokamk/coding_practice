#include <iostream>
using namespace std;
const int N=20;
int n;
bool st[N];
void dfs(int u){
    if(u>n){
        for(int i=1;i<u;i++){
         if(st[i]){
             cout<<i<<" ";}
        }
        cout<<endl;
        return;
    }
    st[u]= true;
    dfs(u+1);
    st[u]=false;
    dfs(u+1);
}

int main(){
    cin>>n;
    dfs(1);
    return 0;
}