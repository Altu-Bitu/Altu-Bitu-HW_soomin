//
// Created by kirin on 2021-11-16.
//

#include <iostream>
#include <vector>

using namespace std;
/**
 * [오목]
 * 같은 색 바둑알이 연속적으로 5개 놓인 경우 이긴거.
 * 하지만 6알 이상이 연속적으로 놓인 거는 안이긴거.
 *
 * in: 바둑판 상태
 * out: 누가 이겼는지, 아직 승부 판단되지 않았는지 판별
 * 검 win :1, 흰 win :2, not yet: 0
 * 다섯 바둑알 중 가장 왼쪽에 있는 바둑알의 가로줄 번호, 세로줄 번호
 *
 * 1. 특정 좌표(r,c)를 가장 왼쪽으로 하는 가능한 모든 오목 배치에 대해 오목 여부 확인
 *    가능한 모든 배치 : 오른쪽, 아래, 우하향, 우상향
 * 2. 육목 이상이 되는 경우 : (r,c) 왼쪽에 같은 돌이 있는 경우
 */

const int SIZE = 19;

//범위와 돌의 종류가 유효한지 확인
bool promising(int r, int c, int stone, vector<vector<int>> &board){
    return r>=0 && r<SIZE && c>=0 && c<SIZE && board[r][c] ==stone;
}

bool validDir(int r, int c, int d, int stone, vector<vector<int>> &board){
    //가로, 세로, 우하향 대각선, 우상향 대각선
    int dr[4] ={0,1,1,-1};
    int dc[4] ={1,0,1,1};

    //(r,c) 이전에 위치한 이어지는 돌이 있나?
    bool is_six = promising(r-dr[d],c-dc[d],stone, board);

    int cnt = 0;
    while(cnt <6 && promising(r,c,stone,board)){//(r, c)를 가장 왼쪽으로 하는 이어지는 바둑알의 개수
        cnt++; //해당 방향으로 이어질 수 있으면 cnt++
        r += dr[d]; //d 방향으로 계속 나아간다
        c += dc[d];
    }
    return cnt == 5 && !is_six; //cnt 5개이고, 육목이 아니라면 true return

}

bool isEnd(int r, int c, vector<vector<int>> &board){
    for(int i=0; i<4; i++){ //가로, 세로, 우하향 대각선, 우상향 대각선
        if(validDir(r,c,i,board[r][c], board)) //오목이 완성됐다면
            return true; //true return
    }
    return false; //아니라면 false
}

int main(){
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0)); //최대 19x19인 바둑판

    //입력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            cin >> board[i][j];
    }

    //연산 & 출력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j]) //돌이 없음
                continue;
            if (isEnd(i, j, board)) { //누군가 이겼나?
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1;
                return 0;
            }
        }
    }
    cout << 0;

    return 0;
}