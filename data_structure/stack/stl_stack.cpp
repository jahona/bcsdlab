#include <iostream>
#include <stack>

using namespace std;

/*
STL 버전
*/
int main(){
	// 스택 생성
	stack<int> s;

	// push
	s.push(3);
	s.push(2);
	s.push(1);

	/*
	현재 스택 상황
	front << 3 2 1 << back
	스택은 back에서 부터 pop한다.

	출력 결과:
	1
	2
	3
	*/
	while(!s.empty())
	{
		int n = s.top();
		s.pop();
	
		cout << n << endl;
	}
	
	return 0;
}