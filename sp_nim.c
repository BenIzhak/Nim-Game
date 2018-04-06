#include <stdio.h>
#include <stdlib.h>
#include "SPBufferset.h"

int heaps[32];


void removeFromHeap(int heapIndex, int amountOfObj){
	heaps[heapIndex] = heaps[heapIndex] - amountOfObj;
}

void userTurn(int numOfHeaps){
	int heapIndex = 0, amountOfObj = 0, validInputFlag = 0;
	printf("%s","Your turn: please enter the heap index and the number of removed objects.\n");
	while(validInputFlag == 0){/*asking for input as long as the input is invalid*/
		scanf("%d",&heapIndex);
		scanf("%d",&amountOfObj);
		if(heapIndex <= numOfHeaps && heapIndex > 0){/*checks if input is valid*/
			if(amountOfObj <= heaps[heapIndex - 1] && amountOfObj > 0){
				validInputFlag = 1;
			}
		}
		if(validInputFlag == 0){
			printf("%s","Error: Invalid input.\nPlease enter again the heap index and the number of removed objects.\n");
		}
	}
	removeFromHeap(heapIndex - 1, amountOfObj);
	printf("You take %d objects from heap %d.\n", amountOfObj, heapIndex);
}

int findWinningHeap(int numOfHeaps, int nimSum){
	int i, minIndex = 0;
	for(i = 0; i < numOfHeaps; i++){
		if(((heaps[i] ^ nimSum) < heaps[i])){
			minIndex = i;
			break;
		}
	}
	return minIndex;
}

int findLosingHeap(int numOfHeaps){
	int i;
	for(i = 0; i < numOfHeaps; i++){
		if(heaps[i] > 0){
			return i;
		}
	}
	return 0;
}

void bixbyTurn(int numOfHeaps){
	int i, nimSum, winnerHeap = 0, losingHeap = 0, amountToRemove = 0;
	nimSum = heaps[0];
	for(i = 1; i < numOfHeaps; i++){
		nimSum ^= heaps[i];
	}
	if(nimSum != 0){
		winnerHeap = findWinningHeap(numOfHeaps, nimSum);
		amountToRemove = (heaps[winnerHeap] - (heaps[winnerHeap] ^ nimSum));
		removeFromHeap(winnerHeap, amountToRemove);
		printf("Computer takes %d objects from heap %d.\n", amountToRemove, winnerHeap + 1);
	}else{
		losingHeap = findLosingHeap(numOfHeaps);
		removeFromHeap(losingHeap, 1);
		printf("Computer takes 1 objects from heap %d.\n", losingHeap + 1);
	}
}



void isGameOver(int numOfHeaps, int currentPlayer){/*checks if heaps are empty*/
	int i, flag = 0;
	for (i = 0; i < numOfHeaps; i++){
		if(heaps[i] > 0){
			flag++;
		}
	}
	if(flag == 0){
		if(currentPlayer == 0){/*player is user*/
			printf("%s","You win!\n");
		}else{
			printf("%s","Computer wins!\n");
		}
		exit(0);
	}
}
