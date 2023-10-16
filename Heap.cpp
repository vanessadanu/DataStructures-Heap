#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int size = 0;

struct heap{
	char order[30];
	int time;
	int tableNum;
};

heap data[100];

//to swap the key variable(s)
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//to swap the string variable(s)
void swapChar(char *a, char *b){
	char *temp = (char *)malloc((strlen(a) + 1) * sizeof(char));
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
	free(temp);
}

//to sort data
//sort if the newnode value is smaller than the parent
void upheap(int i){
	if(i == 1) return;
	
	int parent = i/2;
	if(data[parent].time > data[i].time){
		swap(&data[parent].time, &data[i].time);
		swapChar(data[parent].order, data[i].order);
		swap(&data[parent].tableNum, &data[i].tableNum);
		upheap(parent);
	}
}

//to insert new data
void insert(heap data[], int num, char order[30], int time){
	size++;
	strcpy(data[size].order, order);
	data[size].tableNum = num;
	data[size].time = time;
	
	upheap(size);
}

//to delete the root node from heap
void delRoot(){
	if(size == 0) printf("--- Heap is empty. ---\n");
	else{
		for(int i=1; i<=size; i++){
			data[i].time = data[i+1].time;
			strcpy(data[i].order, data[i+1].order);
			data[i].tableNum = data[i+1].tableNum;
		}
		
		size--;
		upheap(size);
		
		printf("--- Root successfully deleted. ---\n\n");
	}
}

//to display the root and its child(ren)
void display(){
	for(int i=1; i<=size; i++){
		if(i == 1) printf("Root: %d\n", data[i].time);
		else{
			printf("Child of %d: %d\n", data[(i)/2].time, data[i].time);
		}
	}
	puts("");
}

//to display data in table form
void displayTable(){
	if(size == 0){
		printf("--- Data doesn't exist. ---\n\n");
		printf("");
	}
	else{
    	printf("PRIORITY QUEUE\n");
		printf("+=====+============+==============================+================+\n");
		printf("| No. |  Table No  |             Order            |    Est. Time   |\n");
		printf("+=====+============+==============================+================+\n");
		for(int i=1; i<=size; i++){
			if(i == 1) printf("|  %d. | %6d     | %-28s | %7d m      | --> root\n", i, data[i].tableNum, data[i].order, data[i].time);
			else printf("|  %d. | %6d     | %-28s | %7d m      |\n", i, data[i].tableNum, data[i].order, data[i].time);
		}
		printf("+=====+============+==============================+================+\n");
	}
}

//to bubble sort element by time
void bubbleSort(){
    int i, j;
    for (i = 1; i <= size; i++)
 
        // Last i elements are already in place
        for (j = 1; j <= size-i; j++)
            if (data[j].time > data[j + 1].time){
                swap(&data[j].time, &data[j + 1].time);
                swapChar(data[j].order, data[j+1].order);
				swap(&data[j].tableNum, &data[j+1].tableNum);
			}
}

//to display bubblesort data in table form
void displaySort(){
	if(size == 0)
		printf("--- Data doesn't exist. ---\n\n");
	else{
	bubbleSort();
		printf("+=====+============+==============================+================+\n");
		printf("| No. |  Table No  |             Order            |    Est. Time   |\n");
		printf("+=====+============+==============================+================+\n");
		for(int i=1; i<=size; i++){
			printf("|  %d. | %6d     | %-28s | %7d m      |\n", i, data[i].tableNum, data[i].order, data[i].time);
		}
		printf("+=====+============+==============================+================+\n");
	}
}

//to display heap in tree visualization
//sideways tree
void displayTree(int space, int index){
	if(size == 0){
		printf("--- Data doesn't exist. ---\n\n");
		printf("");
	}
	else{
		int COUNT = 10;
		if(data[index].time== 0 || index>100){
			return;
	}
	space += COUNT;
	
	displayTree(space,index*2 + 1);
	printf("\n");
	
	for(int i=COUNT; i<space; i++){
		printf(" ");
	}
	
	if(data[index].time != 999999)
		printf("%d\n", data[index].time);
	displayTree(space, index*2);
	
	puts("");
	}
}

//to display minimum heap flow
void displayTime(){
	if(size == 0) printf("--- Data doesn't exist. ---\n");
	else{
		for(int i=1; i<=size; ++i){
		if(i == 1) printf("%d ", data[i].time);
		else printf("-> %d ", data[i].time);
		}  
	} 
}

int main(){
	int menu, num;
	
	char newOrder[30];
	int newNum, est;
	
	do{
		system("cls");
		printf("PRIORITY LIST USING HEAP\n");
		printf("========================\n");
		display();
		printf("Menu:\n");
		printf("1. Insert element(s)\n");
		printf("2. Delete root\n");
		printf("3. Display table\n");
   		printf("4. Display sorted table\n")-
    	printf("5. Display minimum heap flow\n");
		printf("6. Display heap tree\n");
		printf("0. Exit\n\n");
		printf("Choice: "); scanf("%d", &menu);
		
		switch(menu){
			case 1:{
				//insert
				int n;
				system("cls");
				printf("INSERT\n");
				printf("======\n");
				printf("How many elements do you want to insert? "); scanf("%d", &n);
				puts("");
				for(int i=1; i<=n; i++){
					printf("Element #%d\n", i);
					printf("Table Number: "); scanf("%d", &newNum);
					printf("Order: "); getchar(); scanf("%[^\n]s", newOrder);
					printf("Estimated Time: "); scanf("%d", &est);
					insert(data, newNum, newOrder, est);
					printf("--- Element successfully added. ---\n\n");
				}
				system("pause");
				break;
			}
			
			case 2:{
				//delete root
				delRoot();
				system("pause");
				break;
			}
			
			case 3:{
				//display table
        		system("cls");
        		printf("TABLE BY MIN HEAP TRANSVERSAL\n");
				printf("=============================\n");
				displayTable();
				system("pause");
				break;
			}

		    case 4:{
			    //display sorted table
			    system("cls");
			    printf("TABLE BY TIME\n");
				printf("=============\n");
			    displaySort();
			    system("pause");
			    break;
		    }
		
		    case 5:{
			    //display the minimum heap flow (est time)
			    system("cls");
			    printf("MINIMUM HEAP\n");
			    printf("============\n");
			    displayTime();
			    printf("\n");
			    system("pause");
			    break;
		    }
      
			case 6:{
				//display tree
	        	system("cls");
	        	printf("TREE VISUALIZATION\n");
    				printf("==================\n");
    				displayTree(0, 1);
    				system("pause");
    				break;
    		}
			
			case 0:{
				printf("\n--- Thank you. ---\n");
				break;
			}
			
			default:{
				printf("\n--- Invalid input. Please try again. ---\n\n");
				system("pause");
				break;
			}
		}
	} while(menu != 0);
	return 0;
}
