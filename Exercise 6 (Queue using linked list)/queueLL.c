// implement queue using Linked list
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enQueue(){
	int data;
	printf("\nEnter data to be added : ");
	scanf("%d", &data);
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	
	if(front == NULL){
		newNode->data = data;
		newNode->next = NULL;
		front = newNode;	
		rear = newNode;
	}else{
		newNode->data = data;
		newNode->next = NULL;
		rear->next = newNode;
		rear = newNode;	
	}
}

void deQueue(){
	if(front == NULL){
		printf("\nUnder flow...!");
	}else{
		struct Node *ptr = front;
		front = front->next;
		printf("\n%d Removed from queue.", ptr->data);
		free(ptr);
	}
}

void display(){
	if(front == NULL){
		printf("\nQueue is empty...!");
	}else{
		printf("\nDisplaying Queue\n==========================\n");
		struct Node *temp = front;
		while(temp != NULL){
			printf("%d->", temp->data);
			temp = temp->next;
		}
	}
}

void main(){
	int choice = 0;
	
	while(choice != 4){
		printf("\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.exit \nEnter ur choice : ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				enQueue();
				break;
			case 2:
				deQueue();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\nSee u again.\n");
				break;
			default:
				printf("Invalid choice...!");
		}
	}
}
