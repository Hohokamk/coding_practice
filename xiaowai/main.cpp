#include <iostream>
using namespace std;
int main(){
    int T;
    int a[1000000];
    for(int i=0;i<T;i++){
        int num=0;
        int j=0;
        while(cin>>num){
            a[j++]=num;
        }
        for(int k=0;k<j-1;k++){
            for(int l=0;l<j-k-1;l++){
                if(a[l]>a[l+1]){
                    int temp=a[i];
                    a[i+1]=a[i];
                    a[i]=temp;
                }
            }
        }
        for(int k=0;k<j;k++){
            cout<<a[k]<<" ";
        }
    }
    return 0;
}
