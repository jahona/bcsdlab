#include <iostream>

using namespace std;

/*
링크드 리스트의 각 노드를 나타내는 클래스
data는 노드가 가지고 있는 데이터
prevNode는 현재 노드가 이전 노드의 주소를 가리키는 포인터(중요)
*/
class Node {
    public:
        int data;
        Node* prevNode;

        Node(int data);
        ~Node();
};

// 생성자 : 객체가 생성될 때 호출
Node::Node(int data) {
    this->data = data;
    this->prevNode = NULL;
}

// 소멸자 : 객체에 할당된 메모리가 해제 될 때 호출
Node::~Node() {
    cout << "deleting node (" << this->data << ")" << endl;
}

/*
topNode 는 스택의 맨 위쪽의 노드를 가리키는 포인터이다.
[[ node node node <- topNode
위 경우 length는 3이다.
*/

class Stack {
    public:
        Node* topNode;
        int length;

        Stack();
        ~Stack();

        void push(int data);
        int pop();
		int top();

		bool empty();
        int getLength();
};

// 생성자 : 처음에는 topNode는 첫번째 노드가 없으므로 NULL을 가리킨다. 
Stack::Stack() {
    this->topNode = NULL;
    this->length = 0;
}

// 예시를 위해 스택이 소멸될 때 스택의 맨 위의 노드부터 빼면서 할당된 메모리를 해제해준다.
Stack::~Stack() {
    Node* top = this->topNode;
    while(top) {
        Node* old = top;
        top = top->prevNode;
        delete old;
    }
}

void Stack::push(int data){
	// 첫번째 노드가 추가되면
    if(this->topNode == NULL) {
        this->topNode = new Node(data);
    } 
	// 새 노드가 스택의 맨 위에 쌓이게 되므로 새 노드는 이전 노드를 가리켜야 한다.
	else {
        Node* old = this->topNode;
        this->topNode = new Node(data);
        this->topNode->prevNode = old;
    }
    length++;

    cout << "push: " << data << endl;
}

int Stack::pop() {
	// 스택의 맨위의 데이터를 빼고 메모리 해제
    int data = this->topNode->data;
    delete this->topNode;

	// 다음 노드를 topNode로 설정
    this->topNode = this->topNode->prevNode;

    length--;

    cout << "pop: " << data << endl;
    return data;
}

int Stack::top() {
	return this->topNode->data;
}

int Stack::getLength() {
    return length;
}

bool Stack::empty() {
	return this->topNode == NULL;
}

int main(){
	// 스택 생성
	Stack s;

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
	}
	
	return 0;
}