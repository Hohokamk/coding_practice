#include <iostream>
using namespace std;
void hanoi(int n,char src ,char mid,char dst){
    if(n==1){
        cout<<n<<":"<<src<<"->"<<dst<<endl;
        return;
    }
    hanoi(n-1,src,dst,mid);
    cout<<n<<":"<<src<<"->"<<dst<<endl;
    hanoi(n-1,mid,src,dst);
}

int main(){
    int n;
    char a,b,c;
    cin>>n>>a>>b>>c;
    hanoi(n,a,b,c);
    return 0;
}