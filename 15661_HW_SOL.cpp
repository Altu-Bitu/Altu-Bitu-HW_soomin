//
// Created by kirin on 2021-10-01.
//

#include <iostream>
#include <algorithm>

using namespace std;

//링크와 스타트
/*
 * [문제]
 * 1. N명의 축구 선수 두 팀으로 나눔 (1<=N<=20). 각 팀 선수 인원 달라도 됨
 * 2. Sij = i+j번 사람 같은 팀 속했을 때 팀에 더해지는 능력치, Sji랑 다르고 팀에는 두 능력치 더해짐
 * 3. 두 팀 능력치 차이 최소화인 값은?
 *
 * [백트래킹 풀이]
 * 오름차순 수열을 만드는 것을 활용하여 팀 조합
 * 오름차순 수열을 만들어가는 과정에서 길이가 1 이상이 되면 팀배정 완료된 것
 * 스타트 팀 꾸려나가는 거 기준으로 풀이. 나머지는 링크팀에 수동 배정
 * ex. n = 4
 * 1 -> 1번 사람이 스타트
 * 1 2 -> 1, 2번 사람이 스타트
 * (생략)
 * 2 3 4 -> 2, 3, 4번 사람이 스타트
 *
 * 팀 배정 모두 끝낸 후 능력치 차이 계산
*/

const int SIZE = 20; // n 최댓값
const int INF = 10e8; //

int n; //인원 수
int answer = INF; //
int power[SIZE][SIZE]; // 각 시너지
bool is_start[SIZE]; // 스타트 팀인지
int start[SIZE], link[SIZE]; //스타트와 링크 팀에 속하는 사람

 //각 팀의 능력치 계산 함수
 int calcPower(int arr[], int size){
     int result = 0; // 총 Sij 합

     //모든 Sij의 합
     for(int i=0; i<size; i++){ //Sij != Sji이므로 둘 다 더해준다.
         for(int j= i+1; j<size; j++){
             result += power[arr[i]][arr[j]] + power[arr[j]][arr[i]]
         }
     }

     return result; // 팀 능력치 총합 return
 }

 void backtracking(int cnt, int st){
     if(cnt == n)//n이면 팀 더 이상 꾸릴 수 없음. 기저조건
         return;
     if(cnt >0){ // 최소 1명이 팀에 있어야 함
         int idx = 0; // cnt는 start팀 명 수, idx는 link 팀 명 수
         for(int i=0; i<n; i++){
             if(!is_start[i]) // 스타트팀 아니라면 -> 링크팀
                 link[idx++] = i; //i를 링크팀에 넣는다.
         }
         int diff_value = abs(calcPower(link, idx)-calcPower(start,cnt)); // 각 팀의 능력 차이
         answer = min(answer, diff_value); //차이의 최솟값을 저장
     }
     for(int i=st; i<n; i++){
         is_start[i] = true;//링크 팀에 속하는 사람 추리기 위해 스타트 팀원 체크
         start[cnt] = i; //스타트 팀에 배치
         backtracking(cnt+1, i+1);
         if(i==0) // 1번 사람이 링크 팀이 됨 -> 어차피 스타트 팀이었던 경우와 값 같음
             return;
         is_start[i] = false; //다음 돌 것을 위해 false로 만들어 놓아야함.
     }
 }

 int main(){
     //입력
     cin >> n;
     for(int i=0; i<n; i++){
         for(int j=0; j<n; j++){
             cin>>power[i][j]; // 사람 사이의 능력치 관계
         }
     }

     //연산
     backtracking(0,0);
     // 연산 수 많은 거 걱정해서 min 값이 0 된다면 (abs 값이므로 0이 최소) break 해야 하나 싶었는데그럴 필요 없었음

     //출력
     cout << answer << '\n';

     return 0;
 }