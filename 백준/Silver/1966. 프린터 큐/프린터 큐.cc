#include <iostream>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

struct Document {//문서 구조
    int pri = 0;//우선순위
    int seq = 0;//놓여진 순서
};

bool compare(const int& d1, const int& d2) {//내림차순 정렬하기 위해 정의한 함수
    return d1 > d2;  // 큰 것부터 정렬
}

int main() {
    int n = 0;//테스트 케이스 개수 변수
    cin >> n;//테스트 케이스 개수 입력

    for (int i = 0; i < n; i++) {//테스트 케이스만큼 반복
        int doc = 0;//문서 개수 변수
        int que = 0;//궁금한 문서 위치 변수
        
        cin >> doc;//문서 개수 입력
        cin >> que;//궁금한 문서 위치 입력

        queue<Document> test;//문서 인쇄 대기열
        vector<int> big;//우선순위 비교를 위한 벡터

        for (int j = 0; j < doc; j++) {//문서의 수만큼 입력받기
            int input = 0;//임시 변수
            cin >> input;//문서의 우선수위 입력받기
            big.push_back(input);//벡터에 넣기

            Document t;//임시 변수
            t.pri = input;//우선순위 지정
            t.seq = j;//문서의 위치 지정
            test.push(t);//문서 인쇄 대기열에 넣기
        }

        sort(big.begin(), big.end(), compare);//내림차순으로 정렬

        int now = 0;//현재 출력중인 문서의 순서

        while (test.size()>0) {//대기열에 문서가 있는 경우 반복
            if (big[now] != test.front().pri) {//맨 앞의 문서의 우선순위가 가장 높은 우선순위가 아니면
                Document in = test.front();//맨 앞의 문서를 임시저장
                test.pop();//맨 앞 문서 제거
                test.push(in);//맨 뒤에 다시 넣기
            }
            else { //맨 앞의 문서의 우선순위가 가장 높은 우선순위인 경우
                if (que == test.front().seq) {//해당 문서가 궁금한 문서인 경우
                    cout << now+1 << endl;//현재 출력중인 문서의 순서를 출력
                }
                now++; //순서 증가
                test.pop();//현재의 문서 제거
            }
        }
    }

    return 0;//종료
}
