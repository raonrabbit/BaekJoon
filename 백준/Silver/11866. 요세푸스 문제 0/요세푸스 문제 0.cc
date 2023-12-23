#include<iostream>
#include<vector>

using namespace std;

struct Node {
	int number;
	Node* next;
};

class LinkedList {
public:
	Node* head;
	Node* tail;
	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	void insertNode(int n);
	int deleteNode(Node* node);
};

void LinkedList::insertNode(int n) {
	Node* temp = new Node();
	temp->number = n;
	if (head == NULL) {
		head = temp;
		tail = temp;
		temp->next = head;
		return;
	}
	tail->next = temp;
	tail = temp;
	tail->next = head;
}

int LinkedList::deleteNode(Node* node) {
	if (node->next == node) {
		head = NULL;
		tail = NULL;
		return(node->number);
	}
	if (node == head) {
		head = node->next;
	}

	Node* p = head;
	Node* q;
	while (p != node) {
		q = p;
		p = p->next;
	}
	q->next = p->next;

	if (node == tail) {
		tail = q;
	}
	return(node->number);
}

int main() {
	int N;
	int K;
	vector<int> yosepus;

	scanf("%d %d", &N, &K);

	LinkedList linkedList;

	for (int i = 1; i <= N; i++) {
		linkedList.insertNode(i);
	}
	
	int i = 1;
	Node* currentNode = linkedList.head;
	while (linkedList.head != NULL) {
		if (i % K == 0) {
			yosepus.push_back(linkedList.deleteNode(currentNode));
		}
		currentNode = currentNode->next;
		i++;
	}

	printf("<");
	for (int i = 0; i < N - 1; i++) {
		printf("%d, ", yosepus[i]);
	}
	printf("%d>", yosepus[N - 1]);
}