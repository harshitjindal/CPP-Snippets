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

void insertNodeAtEnd(Node** HEAD, int data) {
	Node* it = *HEAD;
	if (*HEAD == NULL) { *HEAD = new Node(data); }
	else {
		while (it->Next != NULL) { it = it->Next; }
		it->Next = new Node(data);
	}
}

void deleteLastNode(Node** HEAD) {
	if (*HEAD == NULL) return;
	Node* it = *HEAD;
	Node* forward = it->Next;
	if (forward == NULL) { *HEAD = NULL; return; }
	while(forward->Next != NULL) { it = it->Next; forward = forward->Next; }
	it-> Next = NULL;
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
	
	return 0;
}
