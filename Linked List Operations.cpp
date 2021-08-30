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

void insertNodeAtBeginning(Node** HEAD, int data) {
	if (*HEAD == NULL) { *HEAD = new Node(data); return; }
	Node* temp = new Node(data);
	temp->Next = *HEAD;
	*HEAD = temp;
}

void insertNodeAtIndex(Node** HEAD, int idx, int data) {
	// TODO
}

void insertNodeAtEnd(Node** HEAD, int data) {
	Node* it = *HEAD;
	if (*HEAD == NULL) { *HEAD = new Node(data); }
	else {
		while (it->Next != NULL) { it = it->Next; }
		it->Next = new Node(data);
	}
}

void deleteNodeAtIndex(Node** HEAD, int idx) {
	if (*HEAD == NULL) return;
	Node* it = *HEAD;
	Node* forward = it->Next;
	if (idx == 0) { *HEAD = it->Next; return; }
	for (int i = 0; i < idx-1; ++i) {
		if (forward == NULL) { it->Next = NULL; return; }
		it = it->Next;
		forward = forward->Next;
	}
	if (forward == NULL) { it->Next = NULL; return; }
	it->Next = forward->Next;
	forward->Next = NULL;
}

void deleteLastNode(Node** HEAD) {
	if (*HEAD == NULL) return;
	Node* it = *HEAD;
	Node* forward = it->Next;
	if (forward == NULL) { *HEAD = NULL; return; }
	while(forward->Next != NULL) { it = it->Next; forward = forward->Next; }
	it-> Next = NULL;
}

Node* reverseLinkedList(Node** HEAD) {
	Node* it = *HEAD;
	Node* prev = NULL;
	while(it!=NULL) {
		Node* nextNode = it->Next;
		it->Next = prev;
		prev = it;
		it = nextNode;
	}
	return prev;
}

void printLinkedList(Node** HEAD) {
	Node* it = *HEAD;
	while (it != NULL) {
		cout << it->Data << " -> ";
		it = it->Next;
	}
	cout << "NULL" << endl;
}

int main() {
	
	Node* HEAD = NULL;
	
	insertNodeAtEnd(&HEAD, 1);
	insertNodeAtEnd(&HEAD, 2);
	insertNodeAtEnd(&HEAD, 7);
	printLinkedList(&HEAD);

	deleteLastNode(&HEAD);
	printLinkedList(&HEAD);

	insertNodeAtBeginning(&HEAD, 100);
	printLinkedList(&HEAD);

	deleteLastNode(&HEAD);
	deleteLastNode(&HEAD);
	printLinkedList(&HEAD);

	deleteLastNode(&HEAD);
	printLinkedList(&HEAD);

	insertNodeAtBeginning(&HEAD, 25);
	printLinkedList(&HEAD);

	cout << "----------" << endl;
	insertNodeAtBeginning(&HEAD, 100);
	insertNodeAtBeginning(&HEAD, 50);
	insertNodeAtEnd(&HEAD, 700);
	insertNodeAtEnd(&HEAD, 750);
	printLinkedList(&HEAD);

	deleteNodeAtIndex(&HEAD, 2);
	printLinkedList(&HEAD);
	
	insertNodeAtBeginning(&HEAD, 100);
	insertNodeAtBeginning(&HEAD, 200);
	insertNodeAtBeginning(&HEAD, 300);
	printLinkedList(&HEAD);
	HEAD = reverseLinkedList(&HEAD);
	printLinkedList(&HEAD);
	
	return 0;
}
