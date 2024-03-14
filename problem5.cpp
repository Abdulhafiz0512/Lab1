#include <iostream>

#include <bits/stdc++.h>
#include "vector"
#include "iterator"
using namespace std;
int main(){
    int a;
    int in;
    cin >>a;
    vector <int> v;
    for (int i = 0; i < a; ++i) {
        int y;
        cin>>y;
        v.push_back(y);
    }
    int item;
    cin>>item;
    bool con=false;
int il=0;
    for(int i :v){
        il++;
        if (item==i){
            con= true;
            cout<<il;
            break;
        }
    }
if (con==false){
    cout<<-1;
}



}
