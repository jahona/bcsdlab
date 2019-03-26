#include <iostream>
#include <queue>

using namespace std;

/*
STL 버전
*/
int main(){
	// 스택 생성
	queue<int> q;

	// push
	q.push(3);
	q.push(2);
	q.push(1);

	/*
	현재 스택 상황
	front << 3 2 1 << bac

	출력 결과:
	3
    2
    1
	*/
	while(!q.empty())
	{
		int n = q.front();
		q.pop();
	
		cout << n << endl;
	}
	
	return 0;
}