#include <iostream>
using namespace std;
int main(){
    int a;
    cin >>a;
    for(int i=0; a > i; i++){
        for (int j = 0; j < a-i; ++j) {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int u=0; u<a; u++){
        for (int h = 0; h < a; ++h) {
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<a*a;
    return 0;



}
