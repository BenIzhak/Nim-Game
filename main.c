#include <stdio.h>
#include "SPBufferset.h"
#include "main_aux.h"
#include "sp_nim.h"

int main(){
	int numOfHeaps = 0, turnCounter = 0;
	SP_BUFF_SET();
	numOfHeaps	= getNumOfHeaps();/*gets data from user about the heaps*/
	getHeapsSizes(numOfHeaps);


	while(1){
		turnCounter++;
		printHeapsStat(numOfHeaps, turnCounter);
		userTurn(numOfHeaps);
		isGameOver(numOfHeaps, 0);

		turnCounter++;
		printHeapsStat(numOfHeaps, turnCounter);
		bixbyTurn(numOfHeaps);
		isGameOver(numOfHeaps, 1);
	}

	return 0;
}
