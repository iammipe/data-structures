#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ADDING ELEMENT ON BEGINING, REMOVING FROM END

typedef struct _queue {
	char  command[50];
	int numberOfCommand;
	struct _queue* next;
}Queue;


void Print(Queue* );
void Push(Queue*);
void Pop(Queue*);
void Options();

int main() {
	Queue *myQueue = (Queue *)malloc(sizeof(Queue));
	int loopCounter = 1;

	myQueue->numberOfCommand = 0;
	strcpy(myQueue->command, "");
	myQueue->next = NULL;
	

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
			Push(myQueue);
			break;
		case 2:
			Pop(myQueue);
			break;
		case 3:
			Print(myQueue);
			break;
		default:
			printf("Invalid enter. Exiting...\n");
			loopCounter = 0;
			break;
		}
	}

	return;
}

void Push(Queue* myQueue) {
	if (myQueue->numberOfCommand == 0) {
		printf("Enter number in queue: ");
		scanf("%d", &myQueue->numberOfCommand);

		printf("Enter command: ");
		scanf("%s", myQueue->command);

		myQueue->next = NULL;

		return;
	}
	else if (myQueue->next == NULL) {
		Queue* newData = (Queue *)malloc(sizeof(Queue));

		char tempCommand[50];
		strcpy(tempCommand, myQueue->command);
		int tempNumber = myQueue->numberOfCommand;

		printf("Enter number: ");
		scanf("%d", &myQueue->numberOfCommand);
		
		printf("Enter command: ");
		scanf("%s", myQueue->command);

		myQueue->next = newData;
		newData->numberOfCommand = tempNumber;
		strcpy(newData->command, tempCommand);
		
		newData->next = NULL;

		return;
	}
	else {
		Queue *tempQueue = myQueue->next;
		Queue* newData = (Queue *)malloc(sizeof(Queue));

		char tempDescription[50];
		strcpy(tempDescription, myQueue->command);
		int tempNumber = myQueue->numberOfCommand;

		printf("Enter number: ");
		scanf("%d", &myQueue->numberOfCommand);

		printf("Enter description: ");
		scanf("%s", myQueue->command);

		myQueue->next = newData;
		newData->numberOfCommand = tempNumber;
		strcpy(newData->command, tempDescription);

		newData->next = tempQueue;

		return;
	}

	return;
}

void Print(Queue* myQueue) {
	while (myQueue != NULL) {
		printf("\n %d %s ", myQueue->numberOfCommand, myQueue->command);
		myQueue = myQueue->next;
	}
	printf("\n");
}

void Pop(Queue* myQueue) {
	// izbaci zadnjeg sa liste
	if (myQueue->numberOfCommand == 0) {
		printf("Stog is empty. Push something.\n");
		Push(myQueue);

		return;
	}
	while (myQueue->next->next != NULL) {
		myQueue = myQueue->next;
	}

	Queue* nodeToDelete = myQueue->next;
	myQueue->next = NULL;
	free(nodeToDelete);

	return;
}

void Options() {
	printf("\n");
	printf("***********************************************\n");
	printf("*  1 - Push command to Queue                  *\n");
	printf("*  2 - Pop command of Queue                   *\n");
	printf("*  3 - Print commands of Queue                *\n");
	printf("*  0 - Exit from program                      *\n");
	printf("*                                             *\n");
	printf("***********************************************\n");
}