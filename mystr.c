#include <stdio.h>
#include <string.h>

#include "mystr.h"

int mylen(char *s){
	int count = 0;
	while(*s++){
		count++;
	}
	return count;
}

char * mycat(char *dest, char *source){
	int i,j;
	for(i = 0; dest[i] != 0; i++);
	for(j = 0; source[j] != 0; j++)
		dest[i+j] = source[j];
	dest[i+j] = 0;
	return dest;
}

int mycmp(char *s1, char *s2){
	while((*s1 && *s2) && (*s1 == *s2)){
		s1++;
		s2++;
	}
	if(*s1 == *s2)
		return 0;
	else
		return *s1 - *s2;
}



int main(){
	char s[50] = "hello";
	printf("orginal string: %s \n \n", s);

	printf("strlen: \nstrlen of %s: %ld \n", s, strlen(s));
	printf("mylen of %s: %d \n \n", s, mylen(s));

	printf("strcat: \nstrcat with %s: %s \n", "!", strcat(s, "!"));
	printf("mycat with %s: %s \n \n", "!", mycat(s, "!"));

	printf("strcmp: \nequal to %s \n  strcmp: %d \n", "hello!!", strcmp(s, "hello!!"));
	printf("  mycmp: %d \n", mycmp(s, "hello!!"));
	printf("less than %s \n  strcmp: %d \n", "HELLO", strcmp(s, "HELLO"));
	printf("  mycmp: %d \n", mycmp(s, "HELLO"));
	printf("greater than %s \n  strcmp: %d \n", "zebra", strcmp(s, "zebra"));
	printf("  mycmp: %d \n", mycmp(s, "zebra"));

	return 0;
}
