#include <bits/stdc++.h>
using namespace std;
int main() {
	int num,k=1;
	queue<int> q;
	stack<int> a;
	queue<char> result;
	cin>>num;
	for(int i=0;i<num;i++){
		int tmp;
		cin>>tmp;
		q.push(tmp);
	}
	while(!q.empty()){
		if(!a.empty() && q.front()==a.top()){
			q.pop();
			a.pop();
			result.push('-');	
		}
		else if(k<=q.front()){
            result.push('+');
			a.push(k++);
		}else{
			cout<<"NO";
			return 0;
		}
	}
	while(!result.empty()){
		char tmp=result.front(); //result를 string으로 쓰면 틀림. 
		cout<<tmp<<"\n";
		result.pop();
	}
	return 0;
}