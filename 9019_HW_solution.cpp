//
// Created by kirin on 2021-11-16.
//
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * DSLR : 네 명령어 이용한 간단한 계산기. 이 계산기에는 레지스터가 들어있다.
 * 레지스터 : 0이상 10,000미만의 십진수 저장 가능함.
 * 각 명령어는 이 레지스터에 저장된 n을 다음과 같이 변환한다.
 * 1. D: D는 n을 두 배로 바꾼다. 결과값이 9999보다 크면 10000으로 나눈 나머지 취함.
 * (2n mod 10000)
 * 2. S: S는 n에서 1을 뺸 결과 n-1을 레지스터에 저장. n이 0이면 9999가 저장됨
 * 3. L: 각 자리수를 왼편으로 회전시켜 저장. d2,d3,d4,d1
 * 4. R: 오른편 회전 d4,d1,d2,d3
 *
 * A를 B로 바꾸는 최소한의 명렁어 생성.
 *
 * [solution]
 * path: 경로와 수행한 명령어(D, S, L, R)를 저장
 *
 * 각 명령어의 수행 결과를 사칙연산으로 나타낼 수 있음 (cur: 현재 수, SIZE = 10,000)
 * D: cur * 2 % SIZE
 * S: (cur - 1 + SIZE) % SIZE (cur이 0일 경우를 처리하기 위해)
 * L: (cur * 10 % SIZE) + (cur / 1000)
 * R: (cur % 10 * 1000) + (cur / 10)
 *
 * 따라서 위의 연산을 적용한 값들을 자식노드로 하여 bfs 탐색 진행
 * 앞서 구한 path값을 따라 B인덱스부터 역추적 시작
 */
const int SIZE =10000;
typedef pair<int, char> ci;

//역추적
string back(int x, vector<ci> &path) { //x = B부터 역추적 시작
    string ans = "";
    while (path[x].first != -1) { //path 없을 때 까지
        ans += path[x].second; //어떤 명령 수행했는지
        x = path[x].first;
    }
    reverse(ans.begin(), ans.end()); //첨부터 나타내야 하니까
    return ans;
}


//bfs
void bfs(int a, int b, vector<ci> &path) {
    vector<bool> visited(SIZE, false); //방문 여부를 나타낸 bool vector
    queue<int> q; //bfs니까 queue가 필요함

    q.push(a); //시작 노드 초기화
    visited[a] = true; //방문한거니까 true로 변경
    while (!q.empty()) { //탐색해야하는 queue 텅 빌때까지
        int cur = q.front(); //현재 수
        q.pop();

        if (cur == b) //B를 만들었다면 즉시 탐색 종료
            break;

        //각 연산을 적용한 수를 자식노드로 두어 bfs 진행하기 위해 연산,명령어 vector 만듦
        vector<ci> child = {{cur * 2 % SIZE,                   'D'},
                            {(cur - 1 + SIZE) % SIZE,          'S'},
                            {(cur * 10 % SIZE) + (cur / 1000), 'L'},
                            {(cur % 10 * 1000) + (cur / 10),   'R'}};
        for (int i = 0; i < 4; i++) { //4개의 연산에 대해!
            int next = child[i].first; //4개 연산을 수행한 결과 값
            if (!visited[next]) { //방문하지 않은 숫자였다면
                q.push(next); //queue에 넣어서 bfs
                visited[next] = true; //방문했으니 true로 변경해줌
                path[next] = ci(cur, child[i].second); //자식 노드에 부모 노드(경로)와 명령어 저장
            }
        }
    }
}

int main() {
    int t, a, b;

    //입력 & 연산 & 출력
    cin >> t; //test case 개수
    while (t--) {
        cin >> a >> b;
        vector<ci> path(SIZE, {-1, ' '}); //first: 경로, second: 명령어
        bfs(a, b, path);
        cout << back(b, path) << '\n';
    }
    return 0;
}