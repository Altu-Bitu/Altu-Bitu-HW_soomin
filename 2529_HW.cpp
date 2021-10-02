//
// Created by kirin on 2021-09-30.
//

#include <iostream>
#include<string>
using namespace std;

//부등호

string maxx;
string minn;
bool check[10];

void put(char* src, char* des, int k) {
    for(int i = 0 ; i <= k ; i ++)
        des[i] = src[i];
}
bool possible(char* target, int n, int index) {
    for(int i = 0 ; i <= index; i++) {
        if(target[i] == n + '0')
            return false;
    }
    return true;
}

void f(char* ine, char* num, int k, int index) {
    if(index == k){ // after final position, finish
        //cout<< "TEST: "<<num<<", "<<maxx<<", "<<minn<<"\n";
        if(minn.size() == 0) {
            minn = num;
        }
        else{
            maxx = num;
        }
        return;
    }
    //if(num[index] < maxx[index] && num[index] > minn[index])
    //    return;
    if(ine[index] == '>') {
        for(int i = 0;  i <= num[index] - 1-'0'; i++) {
            if(check[i])
                continue;
            check[i] = true;
            num[index+1] = i + '0';
            f(ine,num,k,index+1);
            check[i] = false;
        }
    }
    else {
        for(int i = num[index] + 1-'0'; i <= 9 ; i++) {
            if(check[i])
                continue;
            check[i] = true;
            num[index+1] = i + '0';
            //cout<<"NEW INDEX " <<index+1<<","<<i+'0'<<"\n";
            f(ine,num,k,index+1);
            check[i] = false;
        }
    }
}

int main() {
    int k;
    int i;
    char ine[9];
    char num[10];
    cin >> k;

    for(i = 0 ; i < k ; i++)
        cin >> ine[i];

    num[k+1] = '\0';

    for(i = 0 ; i <= 9; i++) {
        num[0] = i+'0';
        check[i] = true;
        f(ine, num, k,0);
        check[i] = false;

    }

    cout << maxx<<"\n";
    cout << minn;
}