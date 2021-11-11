//array operations

#include <stdio.h>

void insert(int size, int array[]);
void delete(int size, int array[]);
int search(int size, int array[]);
void display(int size, int array[]);


void main(){

	int array[100], size, choice = 0;

	printf("\nEnter size of the array : ");
	scanf("%d", &size);

	for(int i=0; i<size; i++){
		printf("Enter number %d : ", i+1);
		scanf("%d", &array[i]);
	}

	while(choice != 5){
		printf("\n\nEnter your choice : \n1.Display Array\n2.Insert an item to a position\n3.Delete an item\n4.Search an Element\n5.Exit\nYour choice : ");
		scanf("%d", &choice);

		switch(choice){
			case 1: display(size, array);
				  break;
			case 2: insert(size, array);
				  size++;
				  break;
			case 3: delete(size, array);
				  size--;
				  break;
			case 4: search(size, array);
				  break;
			case 5: printf("\n See you again :)");
				  break;

			default: printf("\nEnter a valid choice!");
		}
	}


}

void insert(int size, int *array){
	int num, index;
	printf("\nEnter a number to insert : ");
	scanf("%d", &num);
	printf("\nIn what index do you want to insert : ");
	scanf("%d", &index);

	if(size >= 100){
		printf("\nArray is full...!");
	}else{
		//temp = array[size-1];
		for(int i=size; i>=index; i--){
			*(array + i) = *(array + i - 1);
		}
		*(array + index) = num;
	}


}

void display(int size, int *array){

	printf("\n\nDisplay array\n----------------------\n");
	for(int i=0; i<size; i++){
		printf("%d   ", *(array + i));
	}
}

void delete(int size, int *array){
    //int *arr = array;
	int index;
	printf("\nEnter index of the item to delete : ");
	scanf("%d", &index);
    int deleted_item = *(array + index); // stores the item we are going to delete
	for(int i=index; i<=size; i++){
		*(array + i) = *(array + i+1);
	}

	printf("%d is deleted from index %d", deleted_item, index);

}

int search(int size, int *array){
	int num;
	int index = -1;
	printf("\nEnter a number to search : ");
	scanf("%d", &num);

	for(int i=0;i<size;i++){

		if(*(array + i) == num){
			index = i;
			break;
		}
	}

	if(index == -1){
		printf("Oops...Item Not Found...!!!");
	}else{
		printf("\nnumber %d found at index %d", num, index);
	}

	return (index);
}
