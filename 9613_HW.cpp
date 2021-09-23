//
// Created by kirin on 2021-09-22.
//

#include <iostream>
#include <vector>

using namespace std;

// GCD 합
// in1: 테스트 케이스 개수 t(1~100)
// in2: 각 테스트 케이스의 수 n(1~100) + n개의 수(<=1,000,000)

// 고려 사항 1. 중복되는 숫자가 들어왔다면! -> array의 중복 없애줌 xxxxx
// 2. n = 100 -> 100개 중 2개 조합 = 50*99 x gcd로 최댓값 1,000,000 = 49억. 따라서 long long 사용!

//GCD recursive
int gcdRecursion(int a, int b){
    if(b==0){
        return a;
    }
    return gcdRecursion(b, a%b);
}

//array 받아서 GCD 합 구하는 함수
long long gcdSum(vector<int> x){
    long long gcd_sum =0;
    for(int i=0; i<x.size()-1; i++){
        for(int j=i+1; j<x.size(); j++){
            int a = x[i];
            int b = x[j];
            gcd_sum += gcdRecursion(max(a,b),min(a,b));
        }
    }
    return gcd_sum;
}

int main(){
    int t, n; // 테스트 케이스 개수, 각 테스트 케이스 수
    vector<int> x; // n개의 test case 담는 array

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //입력
    cin>>t;

    while(t--){
        //입력
        cin >> n;
        x.assign(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        // x 내 중복되는 값 해결하기
        //sort(x.begin(),x.end()); //정렬을 하고
        //x.erase(unique(x.begin(),x.end()), x.end()); //unique: 중복원소를 vector의 제일 뒷부분(쓰레기 값으로 보냄)
        // 쓰레기 값~ 맨 끝까지를 지우면 중복되는 값 사라질 것임
        // -> 처음엔 얘 떄매 오류 나는줄. (고려1) 근데 이거는 고려사항 아니었음

        //연산 + 출력
        cout<< gcdSum(x)<<'\n';
    }

}