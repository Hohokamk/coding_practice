#include <iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    for(int i=2;i<=N;i++){
        for(int j=1;j<=i-1;j++){
            for(int k=j;k<=i-1;k++){
                for(int l=k;l<=i-1;l++){
                    if(i*i*i==l*l*l+j*j*j+k*k*k){
                        cout<<"Cube = "<<i<<", "<<"Triple = "<<"("<<j<<","<<k<<","<<l<<")"<<endl;
                    }
                }
            }
        }
    }
    return 0;
}