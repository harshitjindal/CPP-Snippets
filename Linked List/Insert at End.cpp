#include <iostream>
using namespace std;

class Node {
public:
	int Data;
	Node* Next;
	
	Node(int data) {
		Data = data;
		Next = NULL;
	}
};

void insertNodeAtEnd(Node** HEAD, int data) {
	Node* it = *HEAD;
	if (*HEAD == NULL) { *HEAD = new Node(data); }
	else {
		while (it->Next != NULL) { it = it -> Next; }
		it -> Next = new Node(data);
	}
}

void printLinkedList(Node** HEAD) {
	Node* it = *HEAD;
	while (it != NULL) {
		cout << it->Data << endl;
		it = it -> Next;
	}
}

int main() {
	Node* HEAD = NULL;
	insertNodeAtEnd(&HEAD, 1);
	insertNodeAtEnd(&HEAD, 2);
	insertNodeAtEnd(&HEAD, 7);
	
	printLinkedList(&HEAD);
	return 0;
}

