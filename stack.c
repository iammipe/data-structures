#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// DODAJ NA RAJ SKIDAJ SA KRAJA

typedef struct _stack {
	char  command[50];
	int numberOfCommand;
	struct _stack* next;
}Stack;


void Print(Stack* );
void Push(Stack*);
void Pop(Stack*);
void Options();

int main() {
	Stack *myStack = (Stack *)malloc(sizeof(Stack));
	int loopCounter = 1;

	myStack->numberOfCommand = 0;
	strcpy(myStack->command, "");
	myStack->next = NULL;

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
			Push(myStack);
			break;
		case 2:
			Pop(myStack);
			break;
		case 3:
			Print(myStack);
			break;
		default:
			printf("Invalid grade. Exiting...\n");
			loopCounter = 0;
			break;
		}
	}

	return;
}

void Push(Stack* myStack) {
	if (myStack->numberOfCommand == 0) {
		printf("Enter number in stack: ");
		scanf("%d", &myStack->numberOfCommand);

		printf("Enter command: ");
		scanf("%s", myStack->command);

		myStack->next = NULL;

		return;
	}
	else{
		Stack *newNode = (Stack*)malloc(sizeof(Stack));

		while (myStack->next != NULL) {
			myStack = myStack->next;
		}

		printf("Enter value to stack: ");
		scanf("%d", &newNode->numberOfCommand);
		printf("Enter command: ");
		scanf("%s", newNode->command);
		newNode->next = NULL;

		myStack->next = newNode;

		return;
	}
}

void Pop(Stack* myStack) {
	while (myStack->next->next != NULL)
	{
		myStack = myStack->next;
	}

	free(myStack->next);
	myStack->next = NULL;

	return;
}

void Print(Stack* myStack) {
	while (myStack != NULL) {
		printf("\n %d %s ", myStack->numberOfCommand, myStack->command);
		myStack = myStack->next;
	}
	printf("\n");
}



void Options() {
	printf("\n");
	printf("***********************************************\n");
	printf("*  1 - Push command to Stack                  *\n");
	printf("*  2 - Pop command of Stack                   *\n");
	printf("*  3 - Print commands of Stack                *\n");
	printf("*  0 - Exit from program                      *\n");
	printf("*                                             *\n");
	printf("***********************************************\n");
}