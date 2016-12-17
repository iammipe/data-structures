#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _node {
	int broj; //4 bajta
	struct _node *next; // 4bajta
}Node;


void Print(Node* , Node* , Node* );
void AddToList(Node*);
Node* ResetData(Node*);
void Presjek(Node*, Node*, Node*);
void PutInNewList(int []);
void PrintOne(Node *);

int main() {
	srand(time(NULL));

	Node* myLinkedListOne = (Node*)malloc(sizeof(Node));
	myLinkedListOne = ResetData(myLinkedListOne);
	AddToList(myLinkedListOne);

	Node* myLinkedListTwo = (Node*)malloc(sizeof(Node));
	myLinkedListTwo = ResetData(myLinkedListTwo);
	AddToList(myLinkedListTwo);

	Node* myLinkedListThree = (Node*)malloc(sizeof(Node));
	myLinkedListThree = ResetData(myLinkedListThree);
	AddToList(myLinkedListThree);


	Print(myLinkedListOne, myLinkedListTwo, myLinkedListThree);
	Presjek(myLinkedListOne, myLinkedListTwo, myLinkedListThree);

}


Node* ResetData(Node* myLinkedList) {
	myLinkedList->broj = 0;
	myLinkedList->next = NULL;

	return myLinkedList;
}

void AddToList(Node* myLinkedList) {
	for (int i = 0; i < 10; i++) {
		if (myLinkedList->broj == 0) {
			myLinkedList->broj = rand() % 21 + 100;
			myLinkedList->next = NULL;
		}
		else
		{
			Node *newNode = (Node*)malloc(sizeof(Node));
			newNode->broj = rand() % 21 + 100;
			newNode->next = NULL;
			myLinkedList->next = newNode;
			myLinkedList = myLinkedList->next;
		}
	}
}

void Print(Node* myLinkedListOne, Node* myLinkedListTwo, Node* myLinkedListThree) {
	printf(" 1   2   3  \n");
	while (myLinkedListOne != NULL && myLinkedListTwo != NULL && myLinkedListThree != NULL) {
		printf("%d %d %d\n", myLinkedListOne->broj, myLinkedListTwo->broj, myLinkedListThree->broj);
		myLinkedListOne = myLinkedListOne->next;
		myLinkedListTwo = myLinkedListTwo->next;
		myLinkedListThree = myLinkedListThree->next;
	}

	printf("\n\n");
}

void Presjek(Node* listOne, Node* listTwo, Node* listThree) {
	int temp = -1;
	int arrayOne[10];
	int arrayTwo[10];
	int arrayThree[10];

	int presjekArray[21];

	for (int i = 0; i < 21; i++) {
		presjekArray[i] = 0;
	}

	for (int i = 0; i < 10; i++) {
		arrayOne[i] = listOne->broj;
		arrayTwo[i] = listTwo->broj;
		arrayThree[i] = listThree->broj;

		listOne = listOne->next;
		listTwo = listTwo->next;
		listThree = listThree->next;
	}

	for (int i = 0; i < 10; i++) {
		temp = arrayOne[i]-100;
		if (presjekArray[temp] == 0) {
			presjekArray[temp] = 1;
		}
		else {
			presjekArray[temp] = 0;
		}
	}

	// drugi algoritam
	for (int i = 0; i < 10; i++) {
		temp = arrayTwo[i] - 100;
		if (presjekArray[temp] == 1) {
			presjekArray[temp] = 2;
		}
		else {
			continue;
		}
	}

	// treci algoritam
	for (int i = 0; i < 10; i++) {
		temp = arrayThree[i] - 100;
		if (presjekArray[temp] == 2) {
			presjekArray[temp] = 3;
		}
		else {
			continue;
		}
	}

	
	PutInNewList(presjekArray);
	
}

void PutInNewList(int presjekArray[21]) {
	Node* finalList = (Node*)malloc(sizeof(Node));
	finalList = ResetData(finalList);

	for (int i = 0; i < 21; i++) {
		if (presjekArray[i] == 3) {
			if (finalList->broj == 0) {
				finalList->broj = i + 100;
			}
			else {
				Node* newNode = (Node*)malloc(sizeof(Node));
				newNode->broj = i + 100;
				finalList->next = newNode;
				newNode->next = NULL;
				finalList = finalList->next;
			}
		}

	}

	PrintOne(finalList);
	
}

void PrintOne(Node *finalList) {
	while (finalList != NULL) {
		printf("%d\n", finalList->broj);
		finalList = finalList->next;
	}
}