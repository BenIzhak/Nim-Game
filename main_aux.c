#include <stdio.h>
#include <stdlib.h>
#include "SPBufferset.h"

extern int heaps[];

void getHeapsSizes(int numOfHeaps){
	int i;

	printf("%s","Enter the heap sizes:\n");

	for(i = 0; i < numOfHeaps ; i++){
		scanf("%d", &heaps[i]);
		if(heaps[i] <= 0){
			printf("Error: the size of heap %d should be positive.\n",i+1);
			exit(0);
		}
	}
}

int getNumOfHeaps(){
	int numOfHeaps = 0;

	printf("%s", "Enter the number of heaps:\n");
	scanf("%d",&numOfHeaps);

	if(!((numOfHeaps >= 1 )&& (numOfHeaps <=32))){
		printf("%s", "Error: the number of heaps must be between 1 and 32.\n");
		exit(0);
	}
	return numOfHeaps;
}

void printHeapsStat(int numOfHeaps, int turnCounter){
	int i;
	printf("In turn %d heap sizes are:", turnCounter);
	for( i = 0 ; i < numOfHeaps ; i++ ){
		printf(" h%d=%d", i + 1, heaps[i]);
	}
	printf("%s",".\n");
}


