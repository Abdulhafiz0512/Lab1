#include <iostream>

#include <bits/stdc++.h>
#include "vector"
#include "iterator"
using namespace std;
int main(){
    int a,b,c;
    cin >>a>>b>>c;
    int pic=1;
    while(a%2==0 or b%2==0){
        if(a%2==0 and b%2==1){
            pic=pic*2;
            a=a/2;
        }
        else if(b%2==0 and a%2==1){
            pic=pic*2;
            b=b/2;
        }
        else{
            pic=pic*4;
            b=b/2;
            a=a/2;
        }


    }
    if (pic>c){
        cout<<"YES";

    }
    else{
        cout<<"NO";
    }


}
