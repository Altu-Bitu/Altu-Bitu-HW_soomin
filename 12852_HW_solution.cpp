//
// Created by kirin on 2021-11-16.
//

#include <iostream>
#include <vector>

using namespace std;


/**
* 1로 만들기
 *
 * 정수 X에 사용할 수 있는 연산 세 가지
 * 1. X가 3으로 나누어 떨어지면, 3으로 나눔
 * 2. 2로 나누어 떨어지면 2로 나눔
 * 3. 1을 뻄
 *
 * N이 주어졌을 때 3개 사용해서 1로 만드려하는데, 연산의 최소 실행 횟수 구하기
 *
 * [점화식]
 * dp[i] = (i에 가능한 연산을 적용한 수 중 최소 연산 횟수)+1
 * dp[i] = min(dp[i/3], dp[i/2], dp[i-1]) +1
 *
 * [역추적]
 * path : 인덱스가 정수를 나타냄, 해당 수에서 연산을 적용한 다음 수를 저장
 * n부터 역추적 시작
*/
//역추적
vector<int> back(int x, vector<int> &path) { //x = n부터 역추적 시작
    vector<int> result(0);
    while (x != 0) {
        result.push_back(x); //경로에 x 추가하고
        x = path[x]; //그 다음 수 추적 준비
    }
    return result;
}

//1로 만드는 최소 연산 횟수 리턴
int makeOne(int n, vector<int> &path) {
    vector<int> dp(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        int min_value = dp[i - 1]; //우선 i - 1 연산 적용한 것으로 저장
        path[i] = i - 1; //나눗셈 안되면 -1 이므로
        if (!(i % 3) && min_value > dp[i / 3]) { //3으로 나눠지고 최솟값이라면
            min_value = dp[i / 3]; //최솟값 대체
            path[i] = i / 3; //path에 결과 값 넣음
        }
        if (!(i % 2) && min_value > dp[i / 2]) { //2로 나눠지고 최솟값이라면
            min_value = dp[i / 2]; //최솟값 대체
            path[i] = i / 2; //path에 결과값 넣음
        }
        dp[i] = min_value + 1; //최소연산 횟수 +1
    }
    return dp[n]; //최종 최솟값
}


int main() {
    int n;

    //입력
    cin >> n;
    vector<int> path(n + 1, 0); //경로 저장

    //연산
    int ans = makeOne(n, path); //횟수
    vector<int> result = back(n, path); //역추적 경로

    //출력
    cout << ans << '\n';
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';
    return 0;
}