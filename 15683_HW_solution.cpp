//
// Created by kirin on 2021-11-16.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 * 감시 : 5종류의 cctv, 한 공간에서 사각지대 최소로 나오는 사각지대 개수
 * 0: 빈칸, 1~5: cctv 종류, 6:벽
 *
 * [solution]
 * cctv가 설치될 수 있는 모든 경우를 고려하는 완전탐색 문제
 *
 * 1. 각 cctv에 대해 가능한 모든 방향을 고려하여 설치
 *  1, 3, 4번 cctv : 4방향
 *  2 : 2방향
 *  5: 1방향
 * 2. install 함수에서 각 cctv의 빛이 뻗어나갈 방향을 잡음
 * 3. ray 함수에서 cctv의 감시 가능 범위 표시
 * 4. 모든 위치를 확인했으면 blindSpot 함수를 통해 사각지대 계산
 */

int n, m, ans = 65; //1<=가로,세로<=8
vector<vector<int>> board;

//cctv 범위 표시
void ray(int row, int col, int dir){
    //우상좌하 방향
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};

    // row, col이 board 안에서 범위 안에 있고, 벽 만나기 전 까지 반복하기.
    while(row>=0 && row<n && col>=0 && col<m && board[row][col] !=6){ //dir 방향으로 뻗어나가며 방향표시
        if(board[row][col]==0){ //다른 cctv를 지우지 않기 위해 빈 공간일 때만 표시
            board[row][col]=7; //감시 가능한 부분은 7로 표시
        }
        row += dr[dir]; //dir 방향으로 쭉쭉 뻗어 나간다.
        col += dc[dir];
    }
}

//cctv 방향 지정
void install(int cctv, int row, int col, int dir){
    if(cctv>=1) {//1,2,3,4,5번 cctv
        ray(row, col, dir); //1이상인 cctv에 대해 우선 한 방향으로 감시
    }
    if(cctv>=2 && cctv !=3) { //2,4,5번 cctv
        ray(row, col, (dir + 2) % 4); //앞 if문과 반대 방향 감시
    }
    if(cctv >=3){ //3,4,5번 cctv
        ray(row, col, (dir+1)%4); //90도 방향 감시
    }
    if(cctv ==5){ //5번 cctv
        ray(row,col,(dir+3)%4); //반대쪽 90도 방향도 감시
    }



}

//사각지대 계산
int blindSpot(){
    int cnt= 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!board[i][j]) //0이면 cctv 없고,벽아니고, cctv로 볼 수 없는 곳이니까(사각지대니까) cnt 개수 높임
                cnt++;
        }
    }
    return cnt;
}

void backtracking(int idx){
    if(idx == n*m){ //기저조건 : 사무실의 모든 위치 확인
        ans = min(ans, blindSpot()); //사각지대 계산 후 최솟값 갱신
        return;
    }
    //row, col을 ci로 들고다니는 것이 아니라 idx에다가 +1을 하며
    int row = idx/m; //m으로 나눈 몫은 row,
    int col = idx%m; //m으로 나눈 나머지는 col인 것을 이용하였음.
    int cur = board[row][col]; //현재 점의 상태 (몇 번째 cctv, 벽, 이미 cctv가 검색중인 곳, 빈 공간 중 하나)
    if(cur ==0 || cur ==6 || cur ==7){ //cctv가 없는 곳
        return backtracking(idx+1); //다음 idx로 넘어가서 계속 탐색
    }
    vector<vector<int>> save = board; //unvisited 처리용 board상태 저장
    for(int i=0; i<4; i++){ //4개의 방향에 대해 cctv 설치
        install(cur, row, col, i); // 현재 지점의 cctv 종류, (row,col) 정보, 상하좌우 중 한 가지 direction
        backtracking(idx+1); //다음 점으로 가서 탐색한다.
        board = save; //한 가지 경우에 대해 모든 점 backtracking 완료하고, save에 저장한다.

        //2번 cctv의 방향 종류는 2개, 5번 cctv의 방향 종류는 1개. 따라서 반복해도 똑같으니까 미리 종료
        if((cur==2 && i==1) || (cur==5 && i==0))
            break;
    }

}

int main(){
    //입력
    cin>>n>>m;
    board.assign(n,vector<int>(m)); //보드 크기 nxm
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          cin>>board[i][j];//보드의 정보 입력 받음
        }
    }

    //연산
    backtracking(0);

    //출력
    cout<<ans;
}