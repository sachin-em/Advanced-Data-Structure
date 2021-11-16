// Implement singly linked list and it's operations 

#include<stdio.h>
#include<stdlib.h>

struct Node{
		int data;
		struct Node* next;		
	     };

struct Node *head, *tail = NULL;

int nodes = 0;

void display(){
	struct Node *temp = head;
	
	if(temp == NULL){
		printf("\nList is empty\n");
	}else{
		printf("\nPrinting Linked List\n------------------------------\n");
		while(temp != NULL){
			printf("%d -> ", temp->data);
			temp = temp->next;
		}
		
		printf("\n------------------------------\n");
	
	}
	
}

void addNode(int data){
	
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}else{
		tail->next = newNode;
		tail = newNode;
	}
	
}





void insert(int position, int value){
	int i;
	if(position >= 0 && position <= nodes){
		struct Node *temp = head;
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		for(i=0;i<position-1;i++){
		
			if(temp == NULL){
				break;
			}
			temp = temp->next;
		
		}
		if(position == 0){
			newNode->data = value;
			newNode->next = head;
			head = newNode;
			nodes++;
			display();
		}else{
			newNode->data = value;
			newNode->next = temp->next;
			temp->next = newNode;
			nodes++;
			display();
		}
	}else{
		printf("\nInvalid position...!\n");
	}
	
			
}


void delete(){
	int position, i;
	printf("Enter the position where you want to delete(start from 0) : ");
	scanf("%d", &position);
	if(position < nodes && position >= 0){
		struct Node *temp = head;
		for(i=0;i<position-1;i++){
		
			if(temp == NULL){
				printf("\nCan't delete...!");
				break;
			}
			temp = temp->next;		
		}
		
		if(position == 0){
			struct Node* ptr = head;
			head = head->next;
			free(ptr);
			nodes--;
			display();
		}else{
			struct Node* ptr = temp->next;
			temp->next = temp->next->next;
			free(ptr);
			nodes--;
			printf("\nNode at position %d deleted successfully..!\n", position);
			display();
		}
		}else{
			if(nodes > 0){
				printf("\nPlease enter a valid position from 0 to %d\n", nodes-1);
			}else{
				printf("\nList is empty...!\n");
			}
			
			
		}
}



void main(){
	int value, position, choice =  0;
	printf("\nHow many nodes do you want to create : ");
	scanf("%d", &nodes);
	
	for(int i=0;i<nodes;i++){
		printf("\nEnter value for node %d : ", i+1);
		scanf("%d", &value);
		addNode(value);
	}
	display();
	
	printf("Linked List Operations");
	while(choice != 5){
		printf("\n===================\n       MENU\n===================");
		printf("\n1.Insert at Beginning\n2.Insert at end\n3.Insert at a specific location\n4.Delete\n5.Exit\nEnter your choice : ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("\nEnter data to insert : ");
				scanf("%d",&value);
				insert(0, value);
				break;
			case 2:
				printf("\nEnter data to insert : ");
				scanf("%d",&value);
				insert(nodes, value);
				break;
			case 3:
				printf("\nEnter data to insert : ");
				scanf("%d",&value);
	
				printf("\nEnter position where you want to insert(from 0 to %d) : ", nodes);
				scanf("%d",&position);
				insert(position,value);
				break;
			case 4:
				delete();
				break;
			case 5:
				printf("\nProgram terminated !\n");
				break;
			default:
				printf("Please enter a valid choice...!");
				break;
		}
	}
	
}

























