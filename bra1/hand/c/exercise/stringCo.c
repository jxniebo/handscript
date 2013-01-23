#include <stdio.h>

void compare(char* string1, char* string2) {
	int i = 0;
	while(string1[i] != '\0') {
		if(string1[i] != string2[i]) {
			break;		
		}
		i++;
	}
	if(string1[i] != string2[i]) {
		printf("false\n");		
	}
	else printf("true\n");
}

int main() {
	char string1[100];
	char string2[100];

	printf("input compare string\n");
	scanf("%s", string1);
	scanf("%s", string2);
	printf("%s\n", string1);
	printf("%s\n", string2);

	compare(string1, string2);

//	  while ((*destbak++ = *src++)) != '\0');
 
	return 0;
}

