//
// Created by kirin on 2021-09-15.
//

// 집합

#include <iostream>
#include <vector>
#include <map>


using namespace std;

map<int,bool> S;

int main(){
    string calc;
    int n,x;

    //S 생성
    for(int i=0; i<20;i++){
        S[i+1] = false;
    }

    cin>>n;
    while(n--){
        cin>>calc>>x;
        if(calc == "add"){
            S[x] = true;
        }
        else if(calc == "remove"){
            S[x] = false;
        }
        else if(calc == "check"){
            if(S[x]){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
        else if(calc == "toggle"){
            if(S[x]){
                S[x] = false;
            }
            else{
                S[x] = true;
            }
        }
        else if(calc == "all"){
            for(int i=0; i<20;i++){
                S[i] = true;
            }
        }
        else if(calc == "empty"){
            for(int i=0; i<20; i++){
                S[i] = false;
            }
        }
    }


}