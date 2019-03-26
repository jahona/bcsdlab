#include <iostream>
#include <queue>

using namespace std;

class Node {
    public:
        int data;
        Node* nextNode;

        Node(int data);
        ~Node();
};

// 생성자 : 객체가 생성될 때 호출
Node::Node(int data) {
    this->data = data;
    this->nextNode = NULL;
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

class Queue {
    public:
        Node* head;
		Node* tail;
        int length;

        Queue();
        ~Queue();

        void push(int data);
        int pop();
		int front();

		bool empty();
        int getLength();
};

// 생성자 : 처음에는 topNode는 첫번째 노드가 없으므로 NULL을 가리킨다. 
Queue::Queue() {
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;
}

// 예시를 위해 스택이 소멸될 때 스택의 맨 위의 노드부터 빼면서 할당된 메모리를 해제해준다.
Queue::~Queue() {
    Node* front = this->head;
    while(front) {
        Node* old = front;
        front = front->nextNode;
        delete old;
    }
}

void Queue::push(int data){
	// 첫번째 노드가 추가되면
    if(this->head == NULL) {
        this->head = new Node(data);
        this->tail = this->head;
    } 
	// 새 노드가 스택의 맨 위에 쌓이게 되므로 새 노드는 이전 노드를 가리켜야 한다.
	else {
        Node* newNode = new Node(data);
        
        this->tail->nextNode = newNode;

        this->tail = newNode;
    }
    length++;

    cout << "push: " << data << endl;
}

int Queue::pop() {
	// 스택의 맨위의 데이터를 빼고 메모리 해제
    int data = this->head->data;
    Node* tmp = this->head;

	// 다음 노드를 topNode로 설정
    this->head = this->head->nextNode;

    delete tmp;

    length--;
    cout << "pop: " << data << endl;
    return data;
}

int Queue::front() {
	return this->head->data;
}

int Queue::getLength() {
    return length;
}

bool Queue::empty() {
	return this->head == NULL;
}

int main(){
	// 스택 생성
	Queue q;

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