#include <iostream>
#include <string>
#include <stack>
#include <iomanip>//소수점 제한을 위해

using namespace std;

int main() {
    int n = 0;//피연산자 개수 입력받을 변수
    cin >> n;//피연산자 개수 입력받기
    string str = "";//후위표기식 입력받을 변수
    stack<double> num;//피연산자 저장 stack
    int* number_array = new int[n];//피연산자 대응하는 값 저장할 정수 배열
    cin >> str;//후의 표기식 입력받기

    for (int i = 0; i < n; i++) {//피연산자 대응하는 값 정수 배열에 저장
        int temp;//임시 변수
        cin >> temp;//피연산자 대응 값 입력받기
        number_array[i] = temp;//정수 배열에 저장
    }

    for (int i = 0; i < str.length(); i++) {//입력받은 후위 표기식 길이만큼 반복
        if (str[i] >= 'A' && str[i] <= 'Z') {//피연산자일 경우(알파벳 대문자인 경우)
            double temp = number_array[str[i] - 'A'];//해당 피연산자에 해당하는 정수 배열의 값 가져오기
            num.push(temp);//해당 값 stack에 넣기
        }
        else {//피연산자 아니면(즉, 연산자이면)
            double o1, o2;//연산할 피연산자 2개의 임시 변수
            if (num.size() == 0) { return 0; }// stack에 피연산자 2개 미만이면 종료
            o1 = num.top();// stack에서 피연산자1 가져오기
            num.pop();// 가져온 값 stack에서 제거
            o2 = num.top();// stack에서 피연산자2 가져오기
            num.pop();// 가져온 값 stack에서 제거

            switch (str[i]) {//연산자 종류에 따라
            case '*'://'*' 이면
                num.push(o2 * o1);//피연산자 2개 곱해서 stack에 넣기
                break;
            case '+'://'+' 이면
                num.push(o2 + o1);//피연산자 2개 더해서 stack에 넣기
                break;
            case '/'://'/' 이면
                num.push(o2 / o1);//피연산자 2개 나눠서 stack에 넣기
                break;
            case '-'://'-' 이면
                num.push(o2 - o1);//피연산자 2개 빼서 stack에 넣기
                break;

            }
        }
    }

    cout << fixed << setprecision(2) << num.top() << "\n";//결과 출력

    delete[] number_array;//동적할당 해제
    return 0;//종료
}
