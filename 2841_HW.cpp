//
// Created by kirin on 2021-09-22.
//

#include <iostream>
#include <queue>

using namespace std;

// 외계인의 기타연주
// 멜로디 주어졌을 때 손가락 가장 적게 움직이는 횟수 구하기
// 여러 개 누르고 있다면 제일 높은 프렛의 음이 발생한다.
// 연주하려는 프렛이 높으면 기존 손 안떼도 됨 (push)
// 연주하려는 프렛이 낮으면 기존 손 떼고 -> 다시 누르기 (pop , push)
// 모든 연산의 횟수 더하기
// 줄이 같다면? 기존 손 떼야지. 다르다면? 안떼도 되지
// 이미 눌러져 있다면? 연산 없지

// 등장한 줄의 개수만큼 우선순위 큐를 제작해.
priority_queue<int, vector<int>> s1;
priority_queue<int, vector<int>> s2;
priority_queue<int, vector<int>> s3;
priority_queue<int, vector<int>> s4;
priority_queue<int, vector<int>> s5;
priority_queue<int, vector<int>> s6;


int main(){
    int n,p; // 음의 수 n, 프렛의 수 p
    int string, fret; // 줄의 번호, 프렛 번호
    int cnt=0;// 손가락 움직임 횟수

    //입력
    cin>> n>>p;

    //연산
    for(int i=0; i<n;i++){
        cin>>string>>fret; //입력으로 주어진 음의 순서대로 기타를 연주해야함

        switch(string){
            case 1:
                if(s1.empty()){
                    s1.push(fret);
                    cnt++;
                    //cout << "push empty" << fret <<" cnt:"<<cnt <<'\n';
                    break;
                }

                while (s1.top() > fret) { // 누르고 싶은 게 제일 큰 수일 때 까지
                    //cout << "pop " << s2.top() <<" cnt:"<<cnt<< '\n';
                    s1.pop(); // 손가락 뗴어준다
                    cnt++;
                    if (s1.empty())
                        break;
                }

                if(s1.top() == fret){ //이미 누르고 있는 프렛이라면 그냥 패스
                    break;
                }

                s1.push(fret); //손가락 눌러준다
                cnt++;
                //cout << "push " << fret <<" cnt:"<<cnt<< '\n'; //디버깅용
                break;
            case 2:
                if(s2.empty()){
                    s2.push(fret);
                    cnt++;
                    //cout << "push empty" << fret <<" cnt:"<<cnt <<'\n';
                    break;
                }

                while (s2.top() > fret) { // 누르고 싶은 게 제일 큰 수일 때 까지
                    //cout << "pop " << s2.top() <<" cnt:"<<cnt<< '\n';
                    s2.pop(); // 손가락 뗴어준다
                    cnt++;
                    if (s2.empty())
                        break;
                }

                if(s2.top() == fret){ //이미 누르고 있는 프렛이라면 그냥 패스
                    break;
                }

                s2.push(fret); //손가락 눌러준다
                cnt++;
                //cout << "push " << fret <<" cnt:"<<cnt<< '\n'; //디버깅용
                break;

            case 3:
                if(s3.empty()){
                    s3.push(fret);
                    cnt++;
                    //cout << "push empty" << fret <<" cnt:"<<cnt <<'\n';
                    break;
                }

                while (s3.top() > fret) { // 누르고 싶은 게 제일 큰 수일 때 까지
                    //cout << "pop " << s2.top() <<" cnt:"<<cnt<< '\n';
                    s3.pop(); // 손가락 뗴어준다
                    cnt++;
                    if (s3.empty())
                        break;
                }

                if(s3.top() == fret){ //이미 누르고 있는 프렛이라면 그냥 패스
                    break;
                }

                s3.push(fret); //손가락 눌러준다
                cnt++;
                //cout << "push " << fret <<" cnt:"<<cnt<< '\n'; //디버깅용
                break;
            case 4:
                if(s4.empty()){
                    s4.push(fret);
                    cnt++;
                    //cout << "push empty" << fret <<" cnt:"<<cnt <<'\n';
                    break;
                }

                while (s4.top() > fret) { // 누르고 싶은 게 제일 큰 수일 때 까지
                    //cout << "pop " << s2.top() <<" cnt:"<<cnt<< '\n';
                    s4.pop(); // 손가락 뗴어준다
                    cnt++;
                    if (s4.empty())
                        break;
                }

                if(s4.top() == fret){ //이미 누르고 있는 프렛이라면 그냥 패스
                    break;
                }

                s4.push(fret); //손가락 눌러준다
                cnt++;
                //cout << "push " << fret <<" cnt:"<<cnt<< '\n'; //디버깅용
                break;
            case 5:
                if(s5.empty()){
                    s5.push(fret);
                    cnt++;
                    //cout << "push empty" << fret <<" cnt:"<<cnt <<'\n';
                    break;
                }

                while (s5.top() > fret) { // 누르고 싶은 게 제일 큰 수일 때 까지
                    //cout << "pop " << s2.top() <<" cnt:"<<cnt<< '\n';
                    s5.pop(); // 손가락 뗴어준다
                    cnt++;
                    if (s5.empty())
                        break;
                }

                if(s5.top() == fret){ //이미 누르고 있는 프렛이라면 그냥 패스
                    break;
                }

                s5.push(fret); //손가락 눌러준다
                cnt++;
                //cout << "push " << fret <<" cnt:"<<cnt<< '\n'; //디버깅용
                break;
            case 6:
                if(s6.empty()){
                    s6.push(fret);
                    cnt++;
                    //cout << "push empty" << fret <<" cnt:"<<cnt <<'\n';
                    break;
                }

                while (s6.top() > fret) { // 누르고 싶은 게 제일 큰 수일 때 까지
                    //cout << "pop " << s2.top() <<" cnt:"<<cnt<< '\n';
                    s6.pop(); // 손가락 뗴어준다
                    cnt++;
                    if (s6.empty())
                        break;
                }

                if(s6.top() == fret){ //이미 누르고 있는 프렛이라면 그냥 패스
                    break;
                }

                s6.push(fret); //손가락 눌러준다
                cnt++;
                //cout << "push " << fret <<" cnt:"<<cnt<< '\n'; //디버깅용
                break;
        }

    }

    //출력
    cout<<cnt;

}