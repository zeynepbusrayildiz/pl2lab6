#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kiyas(char *p1, char *p2){
	while(*p1 && *p2 && *p1 == *p2){
		p1++;
		p2++;
	} 
	return *p1-*p2;
}                                                                    //strcmp fonksiyonu

int main(){
	char *cumle, *s1, *arakelime, *son;
	int found=0;
	cumle=(char *)malloc(100*sizeof(char));                          //c�mle i�in pointer tan�mlay�p haf�zada 100 karakterlik yer ay�rd�m
	arakelime=(char *)malloc(20*sizeof(char));                       //aranan kelimenin tan�m�
	printf("Enter your sentence:\n");
	gets(cumle);                                                     //kullan�c�dan c�mle ald�m
	printf("Enter the word you're looking for:\n");
	gets(arakelime);                                                 //arad���m kelimeyi al�yorum
                                                                     //	printf("%s",cumle); //alabildim mi diye kontrol ediyorum
                                                                     //	printf("%s",arakelime); //alabildim mi diye kontrol ediyorum
	son=cumle;
	while(*son!='\0') son++;
	*son=' ';
	son++;
	*son='\0';                                                       // c�mlenin sonuna bo�luk ekledim ��nk� son kelime i�in arama yapt���mda d��taki while �al��mayacak
	s1=cumle;                                                        //cumle pointer�n�n g�sterdi�i yeri g�steren ba�ka bir pointer
	while(*s1!='\0'){
		char str[20];                                                //yeni karakter array olu�tur
		int i=0;
		while(*s1!=' '){                                             //c�mleyi g�steren ptr da kelimeyi bulmaya �al���yoruz
			str[i]=*s1;
			s1++;
			i++;
		}                                                            //bo�luk karakterine kadar, yani kelime al
		str[i]='\0';                                                 //kelimeyi str a kopyalad�ktan sonra null ekliyorum
		if(kiyas(str,arakelime)==0){                                 //compare string fonksiyonu s�f�r d�nd�r�yorsa stringler ayn�d�r
			printf("YES");
			found++;
			break;
		}
		s1++;                                                        //bu en son bo�luk g�stermede kalm��t� o y�zden artt�rd�m
	}
	if(found==0) printf("NO");                                       //kelime yoksa hay�r yaz�yoruz
	free(cumle);
	free(arakelime);                                                 //bellekten sildim
	return 0;
}
