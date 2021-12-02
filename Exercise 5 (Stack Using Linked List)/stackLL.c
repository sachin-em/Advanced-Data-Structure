// stack using linked list

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
};

struct Node *top = NULL;

void push(){
	int data;
	printf("\nEnter data to insert : "); 
	scanf("%d", &data); // reading data to insert
	
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); // allocating memory for newNode
	if(top == NULL){
		// inserting first node
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		top = newNode;
	}else{
		// atleat one node exists
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = top;
		top->next = newNode;
		top = newNode;
	}
}

void pop(){
	if(top == NULL){
		printf("\nUnder Flow ...!");
	}else{
		struct Node *ptr = top;
		printf("\n%d popped.", top->data);
		top = top->prev;
		free(ptr);
	}
}

void display(){
	if(top == NULL){
		printf("\nStack is empty...!");
	}else{
		printf("\nDisplaying stack elements\n=================================\n");
		struct Node *temp = top;
		while(temp != NULL){
			printf("%d\n", temp->data);
			temp = temp->prev;
		}
	}
}

void main(){
	int choice = 0;
	
	while(choice != 4){
		printf("\n\n1.Push\n2.Pop\n3.Display\n4.exit \nEnter ur choice : ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				push();
				break;
			case 2:
				pop();
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
