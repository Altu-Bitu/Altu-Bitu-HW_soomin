//
// Created by kirin on 2021-09-30.
//

#include <iostream>
#include <math.h>


using namespace std;

//링크와 스타트
/*
 * [문제]
 * 1. N명의 축구 선수 두 팀으로 나눔 (1<=N<=20). 각 팀 선수 인원 달라도 됨
 * 2. Sij = i+j번 사람 같은 팀 속했을 때 팀에 더해지는 능력치, Sji랑 다르고 팀에는 두 능력치 더해짐
 * 3. 두 팀 능력치 차이 최소화인 값은?
 *
 * [SOL]
 * 1. 팀을 어떻게 나눌 것인가 -> 한 팀에 배치하는 경우로 생각?
 *
 */
const int SIZE = 20; // n의 최댓값
int n; // 총 팀원 n명
int min=100; // 최솟값 min
int s[SIZE][SIZE]; // 능력치 담긴 array
int start[SIZE]; // start 팀원
int link[SIZE]; // link 팀원
bool check_start[SIZE+1]; // 해당 번호 사람이 start 팀에 속하면 true, link 팀이면 false

void calcS(int start){
    int link = n-start;
    int sum_start=0;
    int sum_link=0;

    // 각 팀원 중 두 명 뽑아서 둘의 s 값 sum_start/sum_link 값에 더함
    for(int i=0; i<start-1; i++){
        for(int j=i+1; j<start; j++){
            sum_start += s[i][j]+s[j][i];
        }
    }

    for(int i=0; i<link-1; i++){
        for(int j=i+1; j<link; j++){
            sum_link += s[i][j]+s[j][i];
        }
    }

    // 두 능력치 차이가 min 값 보다 작다면 update
    if(min > abs(sum_start-sum_link)){
        min = abs(sum_start - sum_link);
    }

}

void backtracking(int cnt, int start){
    if(cnt == start){ //기저조건. cnt가 start 팀의 수 만큼 채웠다면 끝
        //start 팀 꽉 찬 것이므로, n명중 그 외의 인원은 link 팀
        for(int i=0; i<n; i++){
            if(!check_start[i])
                link[i] = i;
        }
        calcS(start);
        if(min ==0)
            break;
        return;
    }

    for(int i=1; i<=n; i++){ // n까지 돌아보고
        if(!check_start[i]){ // start 팀에 속하지 않았다면
            start[i] = i;
            check_start[i] = true; // start 팀에 넣는다.
            backtracking(cnt+1,start);
            check_start[i] = false;
        }
    }
}

int main(){
    int start; // start팀 인원수

    //입력
    cin>>n;
    //int s[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>s[i][j]; // Sij 입력 받음
        }
    }

    //연산
    for(int i=2; i<=n/2; i++){ // 각 팀원 인원수 분배
        start = i; // start 팀이 i 명이면 link = n-i
        backtracking(0,start);
    }

    //출력
    cout<<min;



}