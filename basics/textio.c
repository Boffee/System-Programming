#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 int main() {

	FILE * fp = fopen ("textio.txt", "r+");

 	char buffer[100];
 	scanf("%s", buffer);
 	fscanf(fp, "%s", buffer);
 	printf("%s\n",buffer);

 	int* data = (int*) malloc(sizeof(int));
	char* line = "dadata 10";
	char type[100];
	int ok = (2 == sscanf(line,"%s %d", type, data)); // pointer error

	char result[200];
	int len = snprintf(result, sizeof(result), "%s %d", type, *data);

	fprintf(fp, "test write text: \n%s\n", result);
	printf("%s %d\n", type ,*data);
	printf("%s\n", result);
	printf("%d\n", ok);
	fclose(fp);
 }