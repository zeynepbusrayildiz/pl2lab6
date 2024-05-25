#include <stdio.h>
#include <stdlib.h>

//finds the number of words in a text

int main(){
	char *metin=(char *)malloc(500*sizeof(char));
	int a=1, n=0;
	printf("Write something:");
	fgets(metin, 500, stdin);
	while(*(metin+n)!='\0'){
		if(*(metin+n)==32) a++;
		n++;
	}
	printf("Number of words in the text: %d",a);
	return 0;
}
