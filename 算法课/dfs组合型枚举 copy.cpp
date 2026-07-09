#include <iostream>
using namespace std;  
int n,m;
const int N=20;
bool st[N];
void dfs(int u,int start){
    if(u>m){
        for(int i=0;i<=m;i++){
            if(st[i]){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    else{
        for(int i=start;i<n;i++){
            st[i]=true;
            dfs(u+1,start+1);
            st[i]=false;
            dfs(u,start+1);
        }
    }
}
int main(){
    cin>>n>>m;
    dfs(1)
    cout<<a+b;
    return 0;
}