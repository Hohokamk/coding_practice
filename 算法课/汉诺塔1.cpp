#include <iostream>
using namespace std;


void hanoi(int n,char src ,char mid,char dst){
    if(n==1){
        cout<<src<<"->"<<dst<<endl;
        return;
    }
    hanoi(n-1,src,dst,mid);
    cout<<src<<"->"<<dst<<endl;
    hanoi(n-1,mid,src,dst);
}

int main(){
    int n;
    cin>>n;
    hanoi(n,'A','B','C');
    return 0;
}