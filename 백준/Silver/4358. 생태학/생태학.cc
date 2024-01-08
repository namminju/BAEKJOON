#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string name;//
    map<string,int> tree;//문자열(tree 이름; key), 정수(개수; value)
    int whole = 0;//전체 입력의 개수
    while (getline(cin, name) && !name.empty()) {//더 이상의 입력이 없으면
        whole++;//전체 개수 증가
        if (!tree[name]) { tree[name] = 0; }//처음 들어오는 입력값이면 0으로 설정
        tree[name]++;//해당 value 증가
    }

    for (auto iter : tree) {//tree가 더 이상 없을 때까지
        cout.precision(4);//소수점 제한
        //해당 tree 이름 비율(=개수/전체*100) 순으로 출력
        cout << fixed << iter.first << " " << ((double)iter.second / whole) * 100 << "\n";
    }
    return 0;
}
