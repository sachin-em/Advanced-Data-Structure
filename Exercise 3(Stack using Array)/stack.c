// implemet stack using array

#include<stdio.h>
#define MAX 100
int stack[MAX], top = -1;

void push(int data){
	if(top >= (MAX - 1)){
		printf("\nOver Flow...!\n");
	}else{
		top++;
		stack[top] = data;
	}
}

int pop(){
	if(top <= -1){
		printf("\nUnder flow...!\n");
	}else{
		int data = stack[top];
		top--;
		printf("\n%d deleted from stack", data);
		return data;
	}
	
}

void display(){
	int pos = top;
	if(pos >=0){
		printf("\nPrinting stack elements\n");
		while(pos > -1){
			printf("\n%d", stack[pos]);
			pos--;
		}
	}else{
		printf("\nStack is empty ...!");
	}
	
}

void main(){
	int choice = 0, data;
	
	while(choice != 4){
		printf("\n\n1.push\n2.pop\n3.display\n4.exit \nenter ur choice : ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter data : ");
				scanf("%d", &data);
				push(data);
				break;
			case 2:
				pop();
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
