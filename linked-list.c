#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	char name[60];
	char surname[60];
	int dateOfBirth;
	struct _node *next;
}Node;

void ResetNode(Node*);
void EditNode(Node*);
void Options();

void AddToBegining(Node*);
void AddNodeToEnd(Node*);

void AddElementBehind(Node*);
void AddElementBefore(Node*);

void PrintFileToList(Node*);
void PrintListToFile(Node*);

void Print(Node*);
void Search(Node*);
Node* Delete(Node*);
Node* DeleteNodePermanently(Node*, char, char, int);


int main() {
	Node* myLinkedList = (Node *)malloc(sizeof(Node));
	ResetNode(myLinkedList);
	int loopCounter = 1;

	while (loopCounter != 0) {
		Options();
		printf("Enter wanted option: ");
		scanf("%d", &loopCounter);

		switch (loopCounter) {
		case 0:
			printf("Exiting...\n");
			loopCounter = 0;
			break;
		case 1:
			AddToBegining(myLinkedList);
			break;
		case 2:
			AddNodeToEnd(myLinkedList);
			break;
		case 3:
			AddElementBehind(myLinkedList);
			break; 
		case 4:
			AddElementBefore(myLinkedList);
			break;
		case 5:
			PrintFileToList(myLinkedList);
			break;
		case 6:
			PrintListToFile(myLinkedList);
			break;
		case 7:
			Print(myLinkedList);
			break; 
		case 8:
			Search(myLinkedList);
			break;
		case 9:
			Delete(myLinkedList);
			break;
		case 10:
			Options();
			break;
		default:
			printf("Invalid grade. Exiting...\n");
			loopCounter = 0;
			break;
		}
	}


	return;
}

void ResetNode(Node *linkList) {
	linkList->dateOfBirth = 0;
	strcpy(linkList->name, "");
	strcpy(linkList->surname, "");
	
	linkList->next = NULL;

	return;
}

void EditNode(Node* nodeOfList) {
	printf("Name of new member: ");
	scanf("%s", nodeOfList->name);

	printf("Surname of new member: ");
	scanf("%s", nodeOfList->surname);

	printf("Date of birth of %s %s: ", nodeOfList->name, nodeOfList->surname);
	scanf("%d", &nodeOfList->dateOfBirth);
	nodeOfList->next = NULL;

	printf("\n");
	printf("\n");

	return;
}

void AddNodeToEnd(Node* myLinkedList) {
	if (myLinkedList->dateOfBirth == 0) {
		EditNode(myLinkedList);
		return;
	}

	Node* newNode = (Node *)malloc(sizeof(Node));
	EditNode(newNode);

	while (myLinkedList->next = NULL) {
		myLinkedList = myLinkedList->next;
	}

	myLinkedList->next = newNode;
	newNode->next = NULL;
	
	return;
}

void AddToBegining(Node* myLinkedList) {
	if (myLinkedList->dateOfBirth == 0) {
		printf("\nName of new member:  ");
		scanf("%s", myLinkedList->name);

		printf("Surname of new member: ");
		scanf("%s", myLinkedList->surname);

		printf("Enter date of birth of %s %s: ", myLinkedList->name, myLinkedList->surname);
		scanf("%d", &myLinkedList->dateOfBirth);

		myLinkedList->next = NULL;

		return;
	}
	else if (myLinkedList->next == NULL) {
		Node* newData = (Node *)malloc(sizeof(Node));

		char tempName[50];
		char tempSurname[50];
		strcpy(tempName, myLinkedList->name);
		strcpy(tempSurname, myLinkedList->surname);
		int tempNumber = myLinkedList->dateOfBirth;

		printf("Name of new member: ");
		scanf("%s", myLinkedList->name);

		printf("Surname of new member: ");
		scanf("%s", myLinkedList->surname);

		printf("Enter date of birth: ");
		scanf("%s", myLinkedList->dateOfBirth);

		printf("Enter date of birth of %s %s: ", myLinkedList->name, myLinkedList->surname);
		scanf("%d", &myLinkedList->dateOfBirth);

		myLinkedList->next = newData;
		newData->dateOfBirth = tempNumber;
		strcpy(newData->name, tempName);
		strcpy(newData->surname, tempSurname);

		newData->next = NULL;

		return;
	}
	else {
		Node *tempNode = myLinkedList->next;
		Node* newData = (Node *)malloc(sizeof(Node));

		char tempName[50];
		char tempSurname[50];

		strcpy(tempName, myLinkedList->name);
		strcpy(tempSurname, myLinkedList->surname);
		int tempNumber = myLinkedList->dateOfBirth;


		printf("Name of new member: ");
		scanf("%s", myLinkedList->name);

		printf("Surname of new member: ");
		scanf("%s", myLinkedList->surname);

		printf("Enter date of birth of %s %s: ", myLinkedList->name, myLinkedList->surname);
		scanf("%d", &myLinkedList->dateOfBirth);

		myLinkedList->next = newData;
		newData->dateOfBirth = tempNumber;
		strcpy(newData->name, tempName);
		strcpy(newData->surname, tempSurname);

		newData->next = tempNode;

		return;
	}

	return;
}


void Print(Node* fullList) {
	int counterOfMembers = 1;
	
	printf("\n\nPrinting full list of members...\n");
	while (fullList != NULL)
	{
		printf("%d. member is %s %s, born in %d\n", counterOfMembers++, fullList->name, fullList->surname, fullList->dateOfBirth);
		fullList = fullList->next;
	}

	return;
}

void Search(Node* searchList) {
	char nameToSearch[60];
	printf("\nEnter surname to start the search: ");
	scanf("%s", nameToSearch);

	while (searchList != NULL)
	{
		if (strcmp(searchList->surname, nameToSearch) == 0){
			printf("\n%s is our member!", nameToSearch);
			return;
		}

		searchList = searchList->next;
	}

	return;
}

void AddElementBefore(Node* myLinkedList) {
	char surname[60];
	printf("\nBefore which human do you want it: ");
	scanf("%s", surname);

	if (strcmp(myLinkedList->surname, surname) == 0) {
		AddToBegining(myLinkedList);
		return;
	}
	else {
		while (myLinkedList != NULL && strcmp(myLinkedList->next->surname, surname) != 0)
		{
			myLinkedList = myLinkedList->next;
		}

		Node* newNode = (Node*)malloc(sizeof(Node));
		Node* tempList = myLinkedList->next;

		printf("Name of new member: ");
		scanf("%s", newNode->name);

		printf("Surname of new member: ");
		scanf("%s", newNode->surname);

		printf("Enter date of birth of %s %s: ", newNode->name, newNode->surname);
		scanf("%d", &newNode->dateOfBirth);

		myLinkedList->next = newNode;
		newNode->next = tempList;

		return;
	}

	return;
}

void AddElementBehind(Node* myLinkedList) {
	char surname[60];
	printf("\nBehind which human do you want it: ");
	scanf("%s", surname);

	while (myLinkedList != NULL && strcmp(myLinkedList->surname, surname) != 0)
	{
		myLinkedList = myLinkedList->next;
	}

	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* tempList = myLinkedList->next;

	printf("Name of new member: ");
	scanf("%s", newNode->name);

	printf("Surname of new member: ");
	scanf("%s", newNode->surname);

	printf("Enter date of birth of %s %s: ", newNode->name, newNode->surname);
	scanf("%d", &newNode->dateOfBirth);

	myLinkedList->next = newNode;
	newNode->next = tempList;

	return;		
}


void PrintListToFile(Node* myLinkedList) {
	FILE* file = fopen("C:\\Users\\Mislav\\Desktop\\members.txt", "w");

	while (myLinkedList != NULL) {
		fprintf(file, "%s %s %d\n", myLinkedList->name, myLinkedList->surname, myLinkedList->dateOfBirth);
		myLinkedList = myLinkedList->next;
	}

	return;
}


void PrintFileToList(Node* myLinkedList) {
	FILE* file = fopen("C:\\Users\\Mislav\\Desktop\\membersFull.txt", "r");

	if (file == NULL) {
		printf("File is not opened  correctly.\n");
		return;
	}

	if (myLinkedList->dateOfBirth != 0) {
		while (myLinkedList->next != NULL)
		{
			myLinkedList = myLinkedList->next;
		}
	}

	while (!feof(file))
	{
		if (myLinkedList->dateOfBirth == 0) {
			fscanf(file, "%s %s %d", myLinkedList->name, myLinkedList->surname, &myLinkedList->dateOfBirth);
			myLinkedList->next = NULL;
		}
		else {
			Node* newNode = (Node*)malloc(sizeof(Node));
			myLinkedList->next = newNode;
			newNode->next = NULL;
			fscanf(file, "%s %s %d", newNode->name, newNode->surname, &newNode->dateOfBirth);

			myLinkedList = myLinkedList->next;
		}
	}

	return;
}

Node* Delete(Node* myLinkedList) {
	Node* linkedList = myLinkedList;
	char name[50], surname[50];
	int tempBirth = 0;

	printf("\nEnter name of wannabe former member: ");
	scanf("%s", name);

	printf("Enter surname of wannabe former member: ");
	scanf("%s", surname);

	printf("Enter %s %s date of birth: ", name, surname);
	scanf("%d", &tempBirth);

	while (myLinkedList != NULL)
	{
		if (strcmp(myLinkedList->name, name) == 0 && strcmp(myLinkedList->surname, surname) == 0 && myLinkedList->dateOfBirth == tempBirth) {
			Node* newList = DeleteNodePermanently(linkedList, name, surname, tempBirth);
			return newList;
		}
		else {
			myLinkedList = myLinkedList->next;
		}
	}

	return;

}



Node* DeleteNodePermanently(Node* myLinkedList, char name[60], char surname[60], int tempBirth){
	while (myLinkedList != NULL)
	{
		if (strcmp(myLinkedList->name, name) == 0 && strcmp(myLinkedList->surname, surname) == 0 && myLinkedList->dateOfBirth == tempBirth) {
			return myLinkedList->next;
		}
		else if (strcmp(myLinkedList->next->name, name) == 0 && strcmp(myLinkedList->next->surname, surname) == 0 && myLinkedList->next->dateOfBirth == tempBirth && myLinkedList->next->next == NULL) {
			myLinkedList->next = NULL;
			return myLinkedList;
		}
		else if (strcmp(myLinkedList->next->name, name) == 0 && strcmp(myLinkedList->next->surname, surname) == 0 && myLinkedList->next->dateOfBirth == tempBirth && myLinkedList->next->next != NULL){
			Node *tempList = myLinkedList->next->next;
			myLinkedList->next = tempList;
			return myLinkedList;
		}

		myLinkedList = myLinkedList->next;
	}
	return;
}

void Options() {
	printf("\n");
	printf("***********************************************\n");
	printf("*  1 - Add element to begining                *\n");
	printf("*  2 - Add element to end                     *\n");
	printf("*  3 - Add element behind                     *\n");
	printf("*  4 - Add element before                     *\n");
	printf("*  5 - Print file to linked list              *\n");
	printf("*  6 - Print linked list to file              *\n");
	printf("*  7 - Print linked list                      *\n");
	printf("*  8 - Search linked list                     *\n");
	printf("*  9 - Delete element of linked list          *\n");
	printf("* 10 - Options                                *\n");
	printf("*  0 - Exit from program                      *\n");
	printf("*                                             *\n");
	printf("***********************************************\n");
}