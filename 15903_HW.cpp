//
// Created by kirin on 2021-09-20.
//

#include <iostream>
#include <queue>

using namespace std;

// 카드 합체 놀이
// n(2~1000) 장의 카드 : i번 카드에 ai가 쓰여있음. (1~1,000,000)
// x번 카드, y번 카드 (x != y) 두 값 더해서 각 카드에 덮어쓴다
// 총 m번(0~15xn) 반복한 후 n개의 카드에 쓰여있는 수 모두 더하면 됨. 최소가 되게 하는 게 목표

priority_queue<int, vector<int>, greater<>> min_heap; // 최소 힙

void sum_cards(){
    int a, b, ab; // 카드 합체 연산에 사용될 a,b, a+b

    a= min_heap.top(); //제일 작은 수
    min_heap.pop();
    b= min_heap.top(); //두 번째로 작은 수
    min_heap.pop();

    ab = a+b; // 두 개 더한 수
    min_heap.push(ab); // 더한 수를 다시 a, b에 넣어준다
    min_heap.push(ab);
}

int main(){
    int n,m;
    int card; // ai
    int min_sum=0; // 최소 합

    //입력 시간 단축
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //입력
    cin>>n>>m; //카드 총 개수, 카드 합체 수행 횟수 입력
    for(int i=0; i<n; i++){ // 각 카드의 값 ai 입력
        cin>>card;
        min_heap.push(card);
    }

    //연산

    // 1. m번의 합체
    for(int i=0; i<m; i++){
        sum_cards();
    }

    // 2. n장 모두 더하기
    while(!min_heap.empty()){
        min_sum += min_heap.top();
        min_heap.pop();
    }

    //출력
    cout<<min_sum;
}