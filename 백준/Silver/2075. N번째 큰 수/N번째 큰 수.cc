#include <iostream>
#include <string>
#include <vector>
#include <climits>//INT_MIN 사용을 위해
#include <queue>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);//시간 단축을 위한 코드
    ios_base::sync_with_stdio(false);//시간 단축을 위한 코드
    
    int n;//N 입력 변수
    cin >> n;//n 입력 받기
    vector<vector<int>> table(n, vector<int>(n));//N*N 2차원 벡터 생성
    for (int i = 0; i < n * n; i++) {//N*N개의 수를 2차원 벡터에 넣기
        int temp = 0;//임시 변수
        cin >> temp;//값 입력받아
        table[i/n][i%n] = temp;//N*N개의 수를 2차원 벡터에 순서대로 입력
    }
    int* last = new int[n];//각 줄의 가장 큰 숫자의 위치를 나타내는 배열
    for (int i = 0; i < n; i++) {//n개의 줄이 있으므로
        last[i] = n - 1;//각 줄을 n-1의 위치로 설정
    }

    int result = 0;//결과 변수
    
    for (int i = 0; i < n; i++) {//n번빼 큰 변수 찾는 부분
        int max = INT_MIN;//가장 작은 값으로 우선 초기화
        int now = 0;//가장 큰 수가 있는 줄 번호
        for (int j = 0; j < n; j++) {//각 줄의 모든 수 비교
            if (table[last[j]][j] > max) {//현재 max 값보다 다음 줄의 값이 크면
                max = table[last[j]][j];//값 업데이트
                now = j;//줄 번호도 업데이트
            }
        }
        last[now] -= 1;//해당 줄의 다음 큰 수를 가르키도록 변경
        result = max;//i번째 큰 수
    }
    cout << result;//n번째 큰 수 출력
    delete[] last;//동적 할당 제거
    return 0;//종료
}
