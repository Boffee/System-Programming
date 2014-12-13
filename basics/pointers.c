#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* f1() {
    char* p = "Hello";
    return p;
} // OK

char* f2() {
	// static vars exists until application exits
	// non-static array gets removed when function ends
	// permanently stored in the stack
    static char p[] = "Hello";
    return p;
} // OK

void mystrcpy(char*dest, char* src) { 
  	// while( *src ) { *dest = *src; src ++; dest++; }
  	// *dest = *src;
	while((*dest++ = *src++)) {};
}

char *mystrdup(char*src) {
	char* p = malloc(sizeof(char)*(strlen(src)+1));
	mystrcpy(p,"hello");
	mystrcpy(p,src);
	return p;
}

int main() {

	// ptrs stored in heap
	char *ptr = "hello world";
	char *ptr2 = ptr;
	char *ptr3; 
	char arr[19]; // stored on the stack
	ptr2 += 4; // moves 4x1=4 bytes (char = 1 byte)
	int *move = (int *)ptr;
	move+=2; // moves 2x4=8 bytes (int = 4 bytes)
	ptr3 = (char *)move;
	mystrcpy(arr, ptr);
	ptr = mystrdup("booya");
	printf("%p, %s\n", ptr, ptr);
	printf("%p, %s\n", ptr2, ptr2);
	printf("%p, %s\n", ptr3, ptr3);
	printf("%p, %d\n", move, *move);
	printf("%p, %s\n", arr, arr);

	printf("\nfunction tests\n");

	int *space = (int*) malloc(sizeof(int)*10); //
	char *r2 = f2(); // stored in the stack
	strcpy(r2, "tada");
	printf("%s\n",f1());
	printf("%s\n",f2());
	printf("%s\n",r2);
	// printf("%s\n",r4);
	return 0;
}