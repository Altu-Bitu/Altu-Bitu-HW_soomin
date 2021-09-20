//
// Created by kirin on 2021-09-19.
//

#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

//연세토토
// 한 과목당 1~ 36 마일리지 가능
// 많이 투자한 사람 순으로 수강인원만큼 자른다 (동일하면 성준이가 우선순위)
// 성준이 : 주어진 마일리지로 최대한 많은 수업 듣길 원함
// in1: 과목 수 = n(1~100), 마일리지 = m(1~100)
// in2: 각 과목 신청한 사람 Pi, 수강인원 Li
// 크기가 Li인 우선순위 큐(by 최소힙) 를 만들고 젤 작은 값보다 내가 크면 되겠지
// 젤 적은 마일리지 필요한 애들 순서대로 들으면 되겠지?
// 고려 1. 수강 미달
// 출력 : 최대로 들을 수 있는 과목의 개수

int main(){
    int subjects_num, mileage, max_number=0; //과목 수, 제공 마일리지, 최대 과목수
    int  students, limit // 각 과목 신청 학생 수, 각 과목 수강인원
    vector<int> mileages; // 각 과목에서 학생의 마일리지
    priority_queue<int, vector<int>, greater<>> pq; // 최소 마일리지 알기 위한 최소힙
    map<int, int> info; // 과목 넘버, 최소 마일리지 (if 인원 미달, 0)
    vector<int> sorted_mileages;

    //입력 시간 단축
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //입력
    cin>>subjects_num>>mileage; // 과목 수, 총 마일리지
    for(int i=0; i<subjects_num; i++){
        cin>>students>>limit; // 각 과목당 학생 수와 수강 정원
        mileages.assign(students,0); // 마일리지스라는 배열을 각 과목당 학생 수 크기로 제작
        for(int i=0;i<students;i++){
            cin>>mileages[i]; // 학생 당 마일리지 값 입력 받음
            if(pq.size()<limit){ // pq가 각 과목 수강 정원보다 작다면
                pq.push(mileages[i]); // push
            }
            else{
                if(pq.top()<mileages[i]){ //pq가 수강 정원보다 크다면
                    pq.pop(); // 젤 작은 값을 pop하고
                    pq.push(mileages[i]); // 이번 값 넣는다.
                }
            }
        }
        if(pq.size()<limit){
            info[i] = 0;
        }
        else{
            info[i] = pq.top();
        }
    }

    //연산
    // info map 에는 각 과목에 대한 정보 있겠지. info map value들 sort해서 max +1 하면 좋은디
    for(auto iter = info.begin(); iter != info.end(); iter++){
        sorted_mileages[i] = info[iter];
    }

    int k=0;
    while(mileage--){
        mileage -= sorted_mileages[k];
        max_number ++;
    }


    //출력
    cout<<max_number;
}