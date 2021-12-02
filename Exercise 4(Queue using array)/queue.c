// implement queue using array
#include<stdio.h>
#define MAX 100
int front = -1, rear = -1, queue[MAX];

void enqueue(){
	if(rear >= (MAX - 1)){
		printf("\nOver Flow...!\n");
	}else{
		rear++;
		int data;
		printf("\nEnter data : ");
		scanf("%d", &data);
		queue[rear] = data;
		printf("\n%d added to queue.\n", data);
		
		if(rear == 0){
		// if first element added set front and rear = 0
			front = rear;
		}
	}
}

void dequeue(){
	if(front <= -1 || front > rear){
		printf("\nUnder flow...!\n");
	}else{
		printf("\n%d removed from queue\n", queue[front]);
		front++;
	}
}

void display(){
	if(front <= -1 || front > rear){
		printf("\nQueue is empty...!\n");
	}else{
		printf("\nPrinting queue\n--------------------------\n");
		for(int i = front; i <= rear; i++){
			printf("%d\t", queue[i]);
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
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			default:
				printf("Invalid choice...!");
		}
	}
}
