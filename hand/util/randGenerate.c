#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand((unsigned)time(NULL));
	//int number;
	//printf("please input the number you want to generate\n");
	//scanf("%d", &number);

	for(int i = 0; i < 1000; i++) {
		if(i % 10 == 0 && i != 0)
		{
			printf("\n");
		}
		printf("%d\t", rand() % 1000);
	}
	printf("\n");

	return 0;

}
