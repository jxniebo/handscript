#include <stdio.h>

#define MONEY 100
#define BIG_PRICE 5
#define MEDIUM_PRICE 3
#define SMALL_PRICE 1 
#define OUT_PUT_FILE "./chichenBought.txt"
void record(int big, int medium, int small) {
	FILE* file = fopen(OUT_PUT_FILE, "a");
	fprintf(file, "%d\t%d\t%d\n", big, medium, small);
	fclose(file);
}

void clearOutput() {
	FILE* file = fopen(OUT_PUT_FILE, "w");
	fputs("", file);
	fclose(file);
}

int main() {
	clearOutput();
	int bigNum = MONEY / BIG_PRICE;

	for(int i = 0; i <= bigNum; i++) {
		int leftForMedium = MONEY - i * BIG_PRICE;
		int mediumNum = leftForMedium / MEDIUM_PRICE;	

		for(int j = 0; j <= mediumNum; j++){
			int leftForSmall = leftForMedium - j * MEDIUM_PRICE;		
			int smallNum = leftForSmall;
			record(i, j, smallNum);
		}
	}
}
