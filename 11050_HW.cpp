//
// Created by kirin on 2021-09-22.
//

#include <iostream>

using namespace std;
//이항계수 = 조합(nCk)
// N(1~10) , K(0~N) 주어졌을 때 이항계수 (N,K) 구하기

int factorial(int n){ //조합 구현 위해 factorial 계산해주는 함수
    int result = 1;
    for(int i=2; i<=n; i++){
        result *= i;
    }
    return result;
}

int main(){
    int n,k, binomial_coefficient;

    //입력
    cin>>n>>k;

    //연산
    binomial_coefficient = factorial(n)/ (factorial(k)* factorial(n-k));

    //출력
    cout<< binomial_coefficient;

}