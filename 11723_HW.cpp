//
// Created by kirin on 2021-09-15.
//

// 집합

#include <iostream>
#include <vector>
//#include <map> // 0923 시간초과 나서 용량 줄여야하는데, S 원소 x의 범위가 1~20이므로 vector 사용해도 됨

using namespace std;

//map<int,bool> S;
vector<bool> S; // S map -> vector로 수정

const int SIZE = 21; // arr 0부터 시작하지만 우린 idx: 1~20만 사용할 것

int main(){
    string calc;
    int n,x;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //S 생성
    S.assign(SIZE,false);
    //for(int i=0; i<20;i++){
    //    S[i+1] = false;
    //}

    cin>>n;
    while(n--){
        cin>>calc; //초기 cin>>calc>>x의 경우 'all', 'empty'의 경우 x가 안들어감. 따라서 x 입력은 case문에서 받아주었음. 
        if(calc == "add"){
            calc = "plus";
        }
        switch (calc[0]) {
            case 'p': //add
                cin>>x;
                S[x] = true;
                break;
                
            case 'r': //remove
                cin>>x;
                S[x] = false;
                break;
                
            case 'c': //check
                cin>>x;

                if(S[x]){
                    cout<<1<<'\n';
                }
                else{
                    cout<<0<<'\n';
                }
                break;
                
            case 't': { //toggle
                cin>>x;
                bool tmp = S[x]; // case 문 안에서 새로운 변수 지정할 경우, {} 해줘야함
                S[x] = !tmp;
                break;
            }
                
            case 'a': { //all
                S.assign(SIZE,true); //for문 대신 assign으로 수정
                break;
            }
            case 'e': { //empty
                S.assign(SIZE,false);
                break;
            }
        }
    }

}
