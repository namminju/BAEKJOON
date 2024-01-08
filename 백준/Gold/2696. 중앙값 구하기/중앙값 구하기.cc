#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;//테스트 케이스 개수 변수
    cin >> n;//테스트 케이스 개수 입력

    for (int i = 0; i < n; i++) {//테스트 케이스 개수만큼 반복 
        int num = 0;//수열의 크기 변수
        cin >> num;//수열의 크기 입력받기
        cout << num / 2 + 1 << "\n";//출력하는 중앙값의 개수(홀수일 때마다 출력하므로)

        vector<int> test;//수를 입력받아 저장해놓을 벡터
        for (int j = 0; j < num; j++) {//수열의 크기만큼 반복
            int temp;//임시변수
            cin >> temp;//입력받아서
            test.push_back(temp);//벡터에 넣기

            if ((j + 1) % 2 == 1) {//홀수이면
                sort(test.begin(), test.end());//정렬
                cout << test[j / 2] << " ";//중앙값 출력
                if ((j + 2) % 20 == 0) { cout << "\n"; }//한 줄에 10개 채우면 다음 줄로
            }
        }
        cout << "\n";//다음 테스트 케이스로 넘어가기
    }

    return 0;//종료
}
