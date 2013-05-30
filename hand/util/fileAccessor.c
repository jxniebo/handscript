#include <stdio.h>

int main() {
	FILE* fileSrc = fopen("./out0.txt", "r");
	FILE* fileTar = fopen("./out1.txt", "a");
	char line[10];
	
	while(fgets(line, 8, fileSrc)) {
		printf("a new line---------\n");
		printf("%s\n", line);	
		fputs(line, fileTar);
	}


}
