#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

	struct OgrTipi
	{	int ogrNo; 
	 	char ad[15]; 
	 	char soyad[15]; 
	 	unsigned int vize; 
	 	unsigned int final; 
	 	unsigned int proje; 
	 	unsigned short int devam; 
	 	float bNotu; 
 		char harf[2]; 
	};
	struct OgrTipi ogr[BUFSIZ];
	int N;
	int A1,A2,B1,B2,C1,C2,D1,D2,E,F1,F2= 0;
	FILE *dd;
	void notOku();
	void bNotuHesapla();
	void harfNotu();
	void sapma();
	void yaz();
int main()
{
	int i;
	if(dd == NULL)
		printf("Surucu bulunamadi");
	else
	{
	printf( "OGRENCI#\tAD\tSOYAD\t\tVIZE\tFINAL\tPROJE\tB.NOTU\tHARF NOTU\n");
	printf("====================================================================================\n");
	notOku();
	bNotuHesapla();
	harfNotu();
	for(i=0 ; i<N ; i++)
	printf("%d\t%s\t%s\t\t%d\t%d\t%d\t%3.0f\t%c%c\n",ogr[i].ogrNo, ogr[i].ad, ogr[i].soyad, ogr[i].vize, ogr[i].final, ogr[i].proje, ogr[i].bNotu, ogr[i].harf[0], ogr[i].harf[1]);		
	sapma();
	printf("NOT DAGILIMLARI\n");
    printf("F2=%d\nF1=%d\nE=%d\nD2=%d\nD1=%d\nC2=%d\nC1=%d\nB2=%d\nB1=%d\nA2=%d\nA1=%d\n",F2,F1,E,D2,D1,C2,C1,B2,B1,A2,A1);
    yaz();
	}
}
void notOku()
{
	int i;
	dd = fopen("d:\\odev.txt","r");
	while(!feof(dd))
	{
		fscanf(dd,"%d%s%s%d%d%d%d",&ogr[i].ogrNo,ogr[i].ad,ogr[i].soyad,&ogr[i].vize,&ogr[i].final,&ogr[i].proje,&ogr[i].devam);
		i++;
	}		
		N=i;
		fclose(dd);
}
void bNotuHesapla()
{
	int i;
	for(i=0 ; i<N ; i++)
	{
		ogr[i].bNotu =  (ogr[i].vize) * 0.3 + (ogr[i].final) * 0.4 + (ogr[i].proje) * 0.3;
	}
}
void sapma()
{
	int i;
	float toplam,genelOrt,sapma;
	for(i=0 ; i<N ; i++)
	{
		toplam += ogr[i].bNotu;
		genelOrt = toplam / N;
	}
	for(toplam = 0, i=0; i<N; i++)
       		toplam += pow(ogr[i].bNotu-genelOrt, 2);
   			sapma = sqrt( toplam/(N-1));
   	printf("Ogrenci sayisi = %d\n",N);
   	printf("Notlarin toplami = %5.2f\n",toplam);
   	printf("Genel ortalama = %5.2f\n",genelOrt);
	printf("Basari notlari standart sapmasi = %5.2f\n",sapma);
	
}
void harfNotu()
{
	int i,say;
	for(i=0;i<N;i++)
{
		if(ogr[i].devam == 0 )
	{
		ogr[i].harf[0] = 'F';
		ogr[i].harf[1] = '2';
		F2++;
	}
	if(0<ogr[i].bNotu && ogr[i].bNotu<40)
	{
		ogr[i].harf[0] = 'F';
		ogr[i].harf[1] = '1';
		F1++;
	}
	else if(40<=ogr[i].bNotu && ogr[i].bNotu<50)
	{
		ogr[i].harf[0] = 'E';
		E++;
	}
	else if(50<=ogr[i].bNotu && ogr[i].bNotu<55)
	{
		ogr[i].harf[0] = 'D';
		ogr[i].harf[1] = '2';
		D2++;
	}
	else if(55<=ogr[i].bNotu && ogr[i].bNotu<60)
	{
		ogr[i].harf[0] = 'D';
		ogr[i].harf[1] = '1';
		D1++;
	}
	else if(60<=ogr[i].bNotu && ogr[i].bNotu<65)
	{
		ogr[i].harf[0] = 'C';
		ogr[i].harf[1] = '2';
		C2++;
	}	
	else if(ogr[i].bNotu<70 && 65<=ogr[i].bNotu)
	{
		ogr[i].harf[0] = 'C';
		ogr[i].harf[1] = '1';
		C1++;
	}
	else if(70<=ogr[i].bNotu && ogr[i].bNotu<75)
	{
		ogr[i].harf[0] = 'B';
		ogr[i].harf[1] = '2';
		B2++;
	}
	else if(75<=ogr[i].bNotu && ogr[i].bNotu<80)
	{
		ogr[i].harf[0] = 'B';
		ogr[i].harf[1] = '1';
		B1++;
	}	
	else if(80<=ogr[i].bNotu && ogr[i].bNotu<90)
	{
		ogr[i].harf[0] = 'A';
		ogr[i].harf[1] = '2';
		A2++;
	}	
	else
	{
		ogr[i].harf[0] = 'A';
		ogr[i].harf[1] = '1';
		A1++;
	}	

}
}

void yaz()
{
	FILE *dd1;
	dd1 = fopen("d:/aplOdev.txt","w");
	int i;
	float toplam, genelOrt;
	fprintf(dd1, "OGRENCI#\tAD\tSOYAD\t\tVIZE\tFINAL\tPROJE\tB.NOTU\tHARF NOTU\n");
	fprintf(dd1, "====================================================================================\n");
	for(i=0;i<N;i++)
	{
		fprintf(dd1,"%d\t%s\t%s\t\t%d\t%d\t%d\t%3.0f\t%c%c\n",ogr[i].ogrNo, ogr[i].ad, ogr[i].soyad, ogr[i].vize, ogr[i].final, ogr[i].proje, ogr[i].bNotu, ogr[i].harf[0], ogr[i].harf[1]);
	}
	fclose(dd1);
}

