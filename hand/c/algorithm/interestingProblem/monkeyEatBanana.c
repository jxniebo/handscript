#include <stdio.h>

#define DAY 10
#define LEFT 1

int main() {
	int amount = LEFT;
	for(int i = 0; i < DAY; i++){
		amount = (amount + 1) * 2;
		printf("on %d day monkey actually have: %d bananas\n", DAY - i, amount); 
	}
}	
