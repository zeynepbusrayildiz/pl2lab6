#include <stdio.h>
#include <stdlib.h>

//compares 2 words

int main(){
	int l1=0, l2=0, n=0;
	char*k1, *k2;
	k1=(char *)malloc(20*sizeof(char));
	k2=(char *)malloc(20*sizeof(char));
	printf("Enter a word:");
	scanf("%s",k1);
	printf("Enter a word:");
	scanf("%s",k2);
	while(*(k1+n)!='\0')
	{
		l1++;
		n++;
	}
	n=0;
	while(*(k2+n)!='\0')
	{
		l2++;
		n++;
	}
	n=0;
//	printf("l1=%d l2=%d",l1,l2);
	if(l1!=l2){
		printf("These words are not the same.");
		if(l1>l2) printf(" %s is a longer word.",k1);
		else printf("%s is a longer word.",k2);
	}
	else{
		while(*(k1+n)!=0){
			if(*(k1+n)!=*(k2+n)){
				printf("These are different words.");
				return 0;
			}
			n++;
		}
		printf("These are the same words.");
	}
	return 0;
}
