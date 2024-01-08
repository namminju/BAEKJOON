#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    int n=0, k=0;//입력 받을 변수

    cin >> n; // N 입력받기
    vector<int> N;
    for (int i = 0; i < n; i++) {
        N.push_back(i + 1); //N개 만큼 수를 차례대로 넣기
    }
    cin >> k;//K 입력받기
    int temp = k-1;//현재 제거 대상의 번호
    cout << "<";//출력 형식 맞추기
    while(N.size()!=0){//N 벡터가 0이 아닐때만(즉, 사람이 존재하지 않으면 멈춤)
        n--;//n의 크기를 줄이기(원형이기 때문에 범위를 넘어가면 n으로 나눈 나머지가 현재 제거 대상의 번호이므로)
        if (n != 0) {//마지막 사람이 아니면
            cout << N.at(temp) << ", ";//현재 제거 대상 번호를 출력
            N.erase(N.begin() + temp);//대상 제거
            temp += k - 1;//제거 대상 번호 업데이트
            temp %= n;//범위가 넘어갈 때를 대비하여 제거 대상 번호 업데이트(원형이므로!!)
        }
        else {//마지막 사람에 대해(',' 제거)
            cout << N.at(temp);//현재 제거 대상 번호를 출력
            N.erase(N.begin() + temp);//대상 제거
        }
    }
    cout << ">";//출력 형식 맞추기
    return 0;//종료
}
