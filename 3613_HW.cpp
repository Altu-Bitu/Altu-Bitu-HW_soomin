//
// Created by kirin on 2021-09-19.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

// 자바 : 첫 단어 소문자, 다음 단어부터는 첫 문자만 대문자, 모든 단어 붙여씀
// C++ : 소문자만 사용, 단어랑 단어 구분은 _
// in : 변수명 -> 어떤 언어 형식인지 -> 반대되는 걸로 바꿈
// else 둘 다 아니다 -> 에러 발생
// else: 1. 첫 단어 대문자, 2. _랑 대문자 같이
// 3. 띄어쓰기 존재, 4. 숫자 존재 -> 이건 고려 안해도 될듯 입력 조건에 x
// + 힌트 : 3. 맨 앞에 '_', 맨 뒤에 '_' 4. '_' 연속으로

// 고려 1. name처럼 두 형식 동일한 거 -> 그대로 나옴

// 언어 형식 판별하는 함수
int identifier(string var){
    bool c_identifier = false;
    int count =0; // 예외: '_' 나온 횟수 파악 위해서

    // 예외
    // 1. 첫 단어 대문자, 2. 맨 앞, 맨 뒤에 '_'
    if(isupper(var[0]) || var[0]=='_' || var[var.length()-1]=='_')
        return 0;
    // 3. '_' 연속해서 2번 이상 나올 때
    for(int i=0; i<var.length()-1; i++){
        if(var[i] == '_' && var[i+1] == '_'){
            return 0;
        }
    }
    if(var.find('_') != string::npos){ // 3. '_'와 대문자 동시에 공존하는 경우
        c_identifier = true;
        for(int i=0;i<var.length();i++){
            if(isupper(var[i])){
                return 0;
            }
        }
    }

    //자바 판별
    if(!c_identifier){
        return 1;
    }
    //C++ 판별
    else{
        return 2;
    }

    return 0;
}

// 언어 형식 바꿔주는 함수
// 1. 자바일 때 : 대문자 앞에 '_' 넣고, 대문자->소문자
void javaToC(string var){
    for(int i=0; i<var.length(); i++){
        if(isupper(var[i])){
            var[i] = tolower(var[i]);
            var.insert(i,"_");
        }
    }
}

// 2. C++일 때 : '_' 삭제하고, 뒤의 소문자 -> 대문자
void cToJava(string var){
    for(int i=0; i<var.length(); i++){
        if(var[i] == '_'){
            if(i != var.length()-1)
                var[i+1]=toupper(var[i+1]);
            var.erase(i,1); //i번째부터 1의 길이의 문자열을 자른다
        }
    }
}

string changeVariable(string var){
    int language = identifier(var); // 0: 에러, 1: JAVA, 2: C++
    if(language == 1){
        javaToC(var);
    }
    else if(language == 2){
        cToJava(var);
    }
    else{
        return "Error!";
    }

    return var;
}

int main(){
    string var, change_var;

    //입력 시간 단축
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //입력
    cin>>var;

    //연산
    change_var = changeVariable(var);

    //출력
    cout<<change_var;
}
