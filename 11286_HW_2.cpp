//
// Created by kirin on 2021-09-20.
//

//
// Created by kirin on 2021-09-20.
//

#include <iostream>
#include <queue>

using namespace std;

// 절댓값 힙 : 연산 개수 N (1~100,000)
// x!=0이면 배열에 정수 x를 넣는다
// x=0이면 배열 중 절댓값 제일 작은 수 출력, 그 값 배열에서 제거
// 배열 비었는데 x=0이면 0 출력

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)){
            return a>b;
        }
        
        return abs(a)>abs(b);  // 수정 : 기존에 else문 썼었는데 else 사용할 필요 없음 
       
    }
};

priority_queue<int, vector<int>, cmp> abs_min_heap;

int main(){
    int n, x;

    //입력
    cin>>n;

    while(n--){
        cin>>x;
        if(x == 0){
            if(abs_min_heap.empty()){
                cout<<0<<'\n';
            }
            else{
                cout<<abs_min_heap.top()<<'\n';
                abs_min_heap.pop();
            }
        }
        else
            abs_min_heap.push(x);
    }
    //연산, 출력

    // vector에 넣는다면 for loop 돌리면서 num값
}
