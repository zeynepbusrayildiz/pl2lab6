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
	cumle=(char *)malloc(100*sizeof(char));                          //cümle için pointer tanýmlayýp hafýzada 100 karakterlik yer ayýrdým
	arakelime=(char *)malloc(20*sizeof(char));                       //aranan kelimenin tanýmý
	printf("Enter your sentence:\n");
	gets(cumle);                                                     //kullanýcýdan cümle aldým
	printf("Enter the word you're looking for:\n");
	gets(arakelime);                                                 //aradýðým kelimeyi alýyorum
                                                                     //	printf("%s",cumle); //alabildim mi diye kontrol ediyorum
                                                                     //	printf("%s",arakelime); //alabildim mi diye kontrol ediyorum
	son=cumle;
	while(*son!='\0') son++;
	*son=' ';
	son++;
	*son='\0';                                                       // cümlenin sonuna boþluk ekledim çünkü son kelime için arama yaptýðýmda dýþtaki while çalýþmayacak
	s1=cumle;                                                        //cumle pointerýnýn gösterdiði yeri gösteren baþka bir pointer
	while(*s1!='\0'){
		char str[20];                                                //yeni karakter array oluþtur
		int i=0;
		while(*s1!=' '){                                             //cümleyi gösteren ptr da kelimeyi bulmaya çalýþýyoruz
			str[i]=*s1;
			s1++;
			i++;
		}                                                            //boþluk karakterine kadar, yani kelime al
		str[i]='\0';                                                 //kelimeyi str a kopyaladýktan sonra null ekliyorum
		if(kiyas(str,arakelime)==0){                                 //compare string fonksiyonu sýfýr döndürüyorsa stringler aynýdýr
			printf("YES");
			found++;
			break;
		}
		s1++;                                                        //bu en son boþluk göstermede kalmýþtý o yüzden arttýrdým
	}
	if(found==0) printf("NO");                                       //kelime yoksa hayýr yazýyoruz
	free(cumle);
	free(arakelime);                                                 //bellekten sildim
	return 0;
}
