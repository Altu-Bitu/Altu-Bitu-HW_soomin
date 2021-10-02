//
// Created by kirin on 2021-09-29.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int SIZE = 7;

int n,m;
set<int> input_set; // 입력 set으로 받을 예정
vector<int> input;
//int input[SIZE]; //입력 배열
int num[SIZE]; //수열 (output)

// N과 M (11)
/*
 * N개의 자연수 중에서 M개를 고른 수열
 * 같은 수를 여러 번 골라도 된다.
 *
 * [in]
 * 첫째 줄: N, M 주어짐 (1<= M <= N <= 7)
 * 둘째 줄: N개의 수 주어짐 (<=10,000)
 *
 * [out]
 * 한 줄에 하나씩 문제의 조건 만족하는 수열 출력
 * 중복되는 수열 여러 번 출력하면 안됌
 * 사전 순으로 증가하는 순서로 출력
 *
 */

void backtracking(int cnt, int start){ //오름차순 구현을 위한 시작 인덱스
    if(cnt == m){ // 기저조건
        for(int i=0; i< cnt; i++){
            cout<< num[i] << ' ';
        }
        cout<<'\n';
        return;
    }
    for(int i= 0; i<n; i++){
        num[cnt] = input[i]; //수열 저장
        backtracking(cnt+1, i); //호출
    }
}
int main(){
    int tmp;

    //입력
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>> tmp;
        input_set.insert(tmp); // 중복 방지를 위해 set으로 값을 넣어준다
    }
    n = input_set.size(); // input의 중복 없앴으므로 n 값 변경

    // 임의 인덱스 접근을 위해 set을 vector로 옮긴다
    input.assign(input_set.size(),0);

    int cnt=0;
    for(auto iter= input_set.begin(); iter != input_set.end(); iter++){
        input[cnt] = *iter;
        cnt++;
    }


    //연산 + 출력
    backtracking(0,0);

    return 0;
}