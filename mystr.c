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

char * mystrchr(char *s, char c){
  if (*s == c){
    return s;
  }
  if (*s == 0){
    return 0;
  }
  return mystrchr(s+=1, c);
}

char * mystrncpy(char *dest, char *source, int n){
  char * retval = dest;
  while(n != 0 && *source){
    *dest = *source;
    dest += 1;
    source += 1;
    n -= 1;
  }
  //since the destination was incremented to the next character, I want to make sure I add in null
  *dest = 0;
  return retval;
}



int main(){
	printf("\nTesting strlen \n \n");
	char s[50] = "hello";
	printf("original string: %s \n \n", s);

	printf("strlen: \nstrlen of %s: %ld \n", s, strlen(s));
	printf("mylen of %s: %d \n \n", s, mylen(s));

	printf("\nTesting strcat \n \n");

	printf("strcat: \nstrcat with %s: %s \n", "!", strcat(s, "!"));
	printf("mycat with %s: %s \n \n", "!", mycat(s, "!"));

	printf("\nTesting strcmp \n \n");

	printf("strcmp: \nequal to %s \n  strcmp: %d \n", "hello!!", strcmp(s, "hello!!"));
	printf("  mycmp: %d \n", mycmp(s, "hello!!"));
	printf("less than %s \n  strcmp: %d \n", "HELLO", strcmp(s, "HELLO"));
	printf("  mycmp: %d \n", mycmp(s, "HELLO"));
	printf("greater than %s \n  strcmp: %d \n", "zebra", strcmp(s, "zebra"));
	printf("  mycmp: %d \n", mycmp(s, "zebra"));

	char z[10] = "pizza";
  printf("\nTesting strchr \n \n");
  printf("original string:%s \n \n", z);
  printf("Searching for char p that is in the string \n");
  printf("strchr: \n strchr of %s: %p \n",z,strchr(z,'p'));
  printf(" mystrchr of %s: %p \n \n",z,mystrchr(z,'p'));

  printf("\n Searching for a char that is not in the string \n");
  printf(" strchr of %s: %p \n",z,strchr(z,'t'));
  printf(" mystrchr of %s: %p \n \n",z,mystrchr(z,'t'));

  printf("\n Searching for a char in the middle of string \n");
  printf(" strchr of %s: %p \n",z,strchr(z,'z'));
  printf(" mystrchr of %s: %p \n \n",z,mystrchr(z,'z'));

  char i[10];
  char a[10];
  char w[] = "hello";
  printf("Testing strncpy \n \n");
  printf("original string:%s \n \n",w);
  printf("Copying hello to a container such that (i,w,3) and (a,w,3) for parameters \n");
  printf("strncpy:\n");
  strncpy(i,w,3);
  mystrncpy(a,w,3);
  printf("After effects on containters \n");
  printf(" strncpy: %s \n", i);
  printf(" mystrncpy: %s \n", a);

	return 0;
}
