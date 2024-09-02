#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#define MAX_YATIRILABILIR_PARA (250000)
#define MAX_CEKILEBILIR_PARA   (10000)
#define MAX_TRANSFER_PARA      (500000)

void paracekme_log(int hesapno, int cekilen_para_miktari)
{
	printf("[S�STEM - PARA �EKME LOG]: %d hesap numaras�ndan %d miktar�nda para �ekildi!\n", hesapno, cekilen_para_miktari);
}

void parayatirma_log(int yatir_hNo, int yatirilan_hno, int yatirilan_para_miktari)
{
	printf("[S�STEM - PARA YATIRMA LOG]: %d hesap numaras�ndan %d hesap numaras�na %d miktar�nda para yat�r�ld�!\n", yatir_hNo, yatirilan_hno, yatirilan_para_miktari);
}

void paratransfer_log(int transfer_eden_hNo, int transfer_edilen_hNo, int transfer_edilen_para)
{
	printf("[S�STEM - PARA TRANSFER LOG]: %d hesap numaras�ndan %d hesap numaras�na %d miktar�nda para transfer edildi!\n", transfer_eden_hNo, transfer_edilen_hNo, transfer_edilen_para);
}

void Sistem_Cikis()
{
	printf("[S�STEM]: Sistemden ��k�� yap�l�yor...\n");
	printf("[S�STEM - B�LG�]: Hazneden kart�n�z� almay� unutmay�n�z!\n");
	printf("[S�STEM]: ��k�� yap�ld�, kart�n�z haznede!");
}

void Islemler(int hesapno, int islem)
{
	switch(islem)
	{
		case 1:
		{
			int cekmek_istenilen_para = 0, farkli_islem_istek = -1, farkli_hesap_no_istek = 0, yeni_islem = 0, yeni_hesapno = 0;
			printf("[S�STEM]: �ekmek istedi�iniz para miktar�n� giriniz: ");
			scanf("%d", &cekmek_istenilen_para);
			if(cekmek_istenilen_para < 0)
			{
				printf("[S�STEM - HATA]: �ekmek istedi�iniz miktar 0'�n alt�nda olmamal�d�r!\n");
				printf("[S�STEM]: �ekmek istedi�iniz para miktar�n� giriniz: ");
				scanf("%d", &cekmek_istenilen_para);
			}
			while(cekmek_istenilen_para > MAX_CEKILEBILIR_PARA)
			{
				printf("[S�STEM - HATA]: �ekmek istedi�iniz miktar �ekilebilir limitin �st�nde!\n");
				printf("[S�STEM - B�LG�]: Maksimum �ekilebilir para miktar�: %d\n", MAX_CEKILEBILIR_PARA);
				printf("[S�STEM]: �ekmek istedi�iniz para miktar�n� giriniz: ");
				scanf("%d", &cekmek_istenilen_para);
			}
			paracekme_log(hesapno, cekmek_istenilen_para);
			printf("[S�STEM]: Farkl� bir i�lem yapmak ister misiniz? ");
			scanf("%d", &farkli_islem_istek);
			while(farkli_islem_istek < 0 || farkli_islem_istek  > 1)
			{
				printf("[S�STEM - HATA]: Hatal� istek ID girdiniz!\n");
				printf("[S�STEM - B�LG�]: 0 veya 1 olarak de�er girmelisiniz!\n");
				printf("[S�STEM]: Farkl� bir i�lem yapmak ister misiniz? ");
				scanf("%d", &farkli_islem_istek);
			}
			if(farkli_islem_istek == 0)
			{
				Sistem_Cikis();
			}
			else
			{
				printf("[S�STEM]: ��lem yapaca��n�z hesap numaras�n� de�i�tirmek ister misiniz? ");
				scanf("%d", &farkli_hesap_no_istek);
				while(farkli_hesap_no_istek < 0 || farkli_hesap_no_istek > 1)
				{
					printf("[S�STEM - HATA]: Hatal� hesap no istek ID girdiniz!\n");
					printf("[S�STEM - B�LG�]: 0 veya 1 olarak de�er girmelisiniz!\n");
					printf("[S�STEM]: ��lem yapaca��n�z hesap numaras�n� de�i�tirmek ister misiniz? ");
					scanf("%d", &farkli_hesap_no_istek);
				}
				if(farkli_hesap_no_istek == 0)
				{
					printf("1 - Para �ekme\n");
					printf("2 - Para Yat�rma\n");
					printf("3 - Para Transferi\n");
					printf("4 - Sistemden ��k��\n");
					printf("[S�STEM]: Yap�lacak i�lemi se�iniz: ");
					scanf("%d", &yeni_islem);
					while(yeni_islem < 1 || yeni_islem > 4)
					{
						printf("[S�STEM - HATA]: Hatal� i�lem ID girdiniz!\n");
						printf("[S�STEM - B�LG�]: ��lem ID'leri 1-4 aras�ndad�r!\n");
						printf("[S�STEM]: Yap�lacak i�lemi se�iniz: ");
						scanf("%d", &yeni_islem);
					}
					Islemler(hesapno, yeni_islem);
				}
				else
				{
					printf("[S�STEM]: Yeni i�lem yapmak istedi�iniz hesap numaras�n� giriniz: ");
					scanf("%d", &yeni_hesapno);
					while(yeni_hesapno < 10000 || yeni_hesapno > 99999)
					{
						printf("[S�STEM - HATA]: Bankam�za ait olmayan bir hesap numaras� girdiniz!\n");
						printf("[S�STEM - B�LG�]: Bankam�za ait hesap numaralar� 10000-99999 aras�ndad�r!");
						printf("[S�STEM]: Yeni i�lem yapmak istedi�iniz hesap numaras�n� giriniz: ");
						scanf("%d", &yeni_hesapno);
					}
					printf("1 - Para �ekme\n");
					printf("2 - Para Yat�rma\n");
					printf("3 - Para Transferi\n");
					printf("4 - Sistemden ��k��\n");
					printf("[S�STEM]: Yap�lacak i�lemi se�iniz: ");
					scanf("%d", &yeni_islem);
					while(yeni_islem < 1 || yeni_islem > 4)
					{
						printf("[S�STEM - HATA]: Hatal� i�lem ID girdiniz!\n");
						printf("[S�STEM - B�LG�]: ��lem ID'leri 1-4 aras�ndad�r!\n");
						printf("[S�STEM]: Yap�lacak i�lemi se�iniz: ");
						scanf("%d", &yeni_islem);
					}
					Islemler(yeni_hesapno, yeni_islem);
				}
			}
			break;
		}
		case 2:
		{
			int yatirilmak_istenilen_para = 0, yatirilan_hesapno = 0, farkli_islem_istek = -1, farkli_hesap_no_istek = 0, yeni_islem = 0, yeni_hesapno = 0;
			printf("[S�STEM]: Yat�rmak istedi�iniz para miktar�n� giriniz: ");
			scanf("%d", &yatirilmak_istenilen_para);
			if(yatirilmak_istenilen_para < 0)
			{
				printf("[S�STEM - HATA] Yat�rmak istedi�iniz miktar 0'�n alt�nda olmamal�d�r!\n");
				printf("[S�STEM]: Yat�rmak istedi�iniz para miktar�n� giriniz: ");
				scanf("%d", &yatirilmak_istenilen_para);
			}
			while(yatirilmak_istenilen_para > MAX_YATIRILABILIR_PARA)
			{
				printf("[S�STEM - HATA] Yat�rmak istedi�iniz miktar yat�r�labilir limitin �st�nde!\n");
				printf("[S�STEM - B�LG�]: Maksimum yat�r�labilir para miktar�: %d\n", MAX_YATIRILABILIR_PARA);
				printf("[S�STEM]: Yat�rmak istedi�iniz para miktar�n� giriniz: ");
				scanf("%d", &yatirilmak_istenilen_para);
			}
			printf("[S�STEM]: Yat�rmak istedi�iniz hesap numaras�n� giriniz: ");
			scanf("%d", &yatirilan_hesapno);
			while(yatirilan_hesapno < 10000 || yatirilan_hesapno > 99999)
			{
				printf("[S�STEM - HATA]: Hesap numaran�z bankam�za ait de�il!\n");
				printf("[S�STEM - B�LG�]: Bankam�za ait hesap numaralar� 10000-99999 aras�ndad�r!\n");
				printf("[S�STEM]: Yat�rmak istedi�iniz hesap numaras�n� giriniz: ");
				scanf("%d", &yatirilan_hesapno);
			}
			parayatirma_log(hesapno, yatirilan_hesapno, yatirilmak_istenilen_para);
			printf("[S�STEM]: Farkl� bir i�lem yapmak ister misiniz? ");
			scanf("%d", &farkli_islem_istek);
			while(farkli_islem_istek < 0 || farkli_islem_istek  > 1)
			{
				printf("[S�STEM - HATA]: Hatal� istek ID girdiniz!\n");
				printf("[S�STEM - B�LG�]: 0 veya 1 olarak de�er girmelisiniz!\n");
				printf("[S�STEM]: Farkl� bir i�lem yapmak ister misiniz? ");
				scanf("%d", &farkli_islem_istek);
			}
			if(farkli_islem_istek == 0)
			{
				Sistem_Cikis();
			}
			else
			{
				printf("[S�STEM]: ��lem yapaca��n�z hesap numaras�n� de�i�tirmek ister misiniz? ");
				scanf("%d", &farkli_hesap_no_istek);
				while(farkli_hesap_no_istek < 0 || farkli_hesap_no_istek > 1)
				{
					printf("[S�STEM - HATA]: Hatal� hesap no istek ID girdiniz!\n");
					printf("[S�STEM - B�LG�]: 0 veya 1 olarak de�er girmelisiniz!\n");
					printf("[S�STEM]: ��lem yapaca��n�z hesap numaras�n� de�i�tirmek ister misiniz? ");
					scanf("%d", &farkli_hesap_no_istek);
				}
				if(farkli_hesap_no_istek == 0)
				{
					printf("1 - Para �ekme\n");
					printf("2 - Para Yat�rma\n");
					printf("3 - Para Transferi\n");
					printf("4 - Sistemden ��k��\n");
					printf("[S�STEM]: Yap�lacak i�lemi se�iniz: ");
					scanf("%d", &yeni_islem);
					while(yeni_islem < 1 || yeni_islem > 4)
					{
						printf("[S�STEM - HATA]: Hatal� i�lem ID girdiniz!\n");
						printf("[S�STEM - B�LG�]: ��lem ID'leri 1-4 aras�ndad�r!\n");
						printf("[S�STEM]: Yap�lacak i�lemi se�iniz: ");
						scanf("%d", &yeni_islem);
					}
					Islemler(hesapno, yeni_islem);
				}
				else
				{
					printf("[S�STEM]: Yeni i�lem yapmak istedi�iniz hesap numaras�n� giriniz: ");
					scanf("%d", &yeni_hesapno);
					while(yeni_hesapno < 10000 || yeni_hesapno > 99999)
					{
						printf("[S�STEM - HATA]: Bankam�za ait olmayan bir hesap numaras� girdiniz!\n");
						printf("[S�STEM - B�LG�]: Bankam�za ait hesap numaralar� 10000-99999 aras�ndad�r!");
						printf("[S�STEM]: Yeni i�lem yapmak istedi�iniz hesap numaras�n� giriniz: ");
						scanf("%d", &yeni_hesapno);
					}
					printf("1 - Para �ekme\n");
					printf("2 - Para Yat�rma\n");
					printf("3 - Para Transferi\n");
					printf("4 - Sistemden ��k��\n");
					printf("[S�STEM]: Yap�lacak i�lemi se�iniz: ");
					scanf("%d", &yeni_islem);
					while(yeni_islem < 1 || yeni_islem > 4)
					{
						printf("[S�STEM - HATA]: Hatal� i�lem ID girdiniz!\n");
						printf("[S�STEM - B�LG�]: ��lem ID'leri 1-4 aras�ndad�r!\n");
						printf("[S�STEM]: Yap�lacak i�lemi se�iniz: ");
						scanf("%d", &yeni_islem);
					}
					Islemler(yeni_hesapno, yeni_islem);
				}
			}
			break;
		}
		case 3:
		{
			int transfer_hesapno = 0, transfer_para = 0, farkli_islem_istek = -1, farkli_hesap_no_istek = 0, yeni_islem = 0, yeni_hesapno = 0;
			printf("[S�STEM]: Transfer edilecek hesap numaras�n� giriniz: ");
			scanf("%d", &transfer_hesapno);
			while(transfer_hesapno < 10000 || transfer_hesapno > 99999)
			{
				printf("[S�STEM - HATA]: Hesap numaran�z bankam�za ait de�il!\n");
				printf("[S�STEM - B�LG�]: Bankam�za ait hesap numaralar� 10000-99999 aras�ndad�r!\n");
				printf("[S�STEM]: Transfer edilecek hesap numaras�n� giriniz: ");
				scanf("%d", &transfer_hesapno);
			}
			printf("[S�STEM]: Transfer edilecek para miktar�n� giriniz: ");
			scanf("%d", &transfer_para);
			while(transfer_para > MAX_TRANSFER_PARA)
			{
				printf("[S�STEM - HATA]: Transfer edilebilir para miktar�n�n �st�nde de�er girdiniz!\n");
				printf("[S�STEM - B�LG�]: Maksimum transfer edilebilir para miktar�: %d\n", MAX_TRANSFER_PARA);
				printf("[S�STEM]: Transfer edilecek para miktar�n� giriniz: ");
				scanf("%d", &transfer_para);
			}
			paratransfer_log(hesapno, transfer_hesapno, transfer_para);
			printf("[S�STEM]: Farkl� bir i�lem yapmak ister misiniz? ");
			scanf("%d", &farkli_islem_istek);
			while(farkli_islem_istek < 0 || farkli_islem_istek  > 1)
			{
				printf("[S�STEM - HATA]: Hatal� istek ID girdiniz!\n");
				printf("[S�STEM - B�LG�]: 0 veya 1 olarak de�er girmelisiniz!\n");
				printf("[S�STEM]: Farkl� bir i�lem yapmak ister misiniz? ");
				scanf("%d", &farkli_islem_istek);
			}
			if(farkli_islem_istek == 0)
			{
				Sistem_Cikis();
			}
			else
			{
				printf("[S�STEM]: ��lem yapaca��n�z hesap numaras�n� de�i�tirmek ister misiniz? ");
				scanf("%d", &farkli_hesap_no_istek);
				while(farkli_hesap_no_istek < 0 || farkli_hesap_no_istek > 1)
				{
					printf("[S�STEM - HATA]: Hatal� hesap no istek ID girdiniz!\n");
					printf("[S�STEM - B�LG�]: 0 veya 1 olarak de�er girmelisiniz!\n");
					printf("[S�STEM]: ��lem yapaca��n�z hesap numaras�n� de�i�tirmek ister misiniz? ");
					scanf("%d", &farkli_hesap_no_istek);
				}
				if(farkli_hesap_no_istek == 0)
				{
					printf("1 - Para �ekme\n");
					printf("2 - Para Yat�rma\n");
					printf("3 - Para Transferi\n");
					printf("4 - Sistemden ��k��\n");
					printf("[S�STEM]: Yap�lacak i�lemi se�iniz: ");
					scanf("%d", &yeni_islem);
					while(yeni_islem < 1 || yeni_islem > 4)
					{
						printf("[S�STEM - HATA]: Hatal� i�lem ID girdiniz!\n");
						printf("[S�STEM - B�LG�]: ��lem ID'leri 1-4 aras�ndad�r!\n");
						printf("[S�STEM]: Yap�lacak i�lemi se�iniz: ");
						scanf("%d", &yeni_islem);
					}
					Islemler(hesapno, yeni_islem);
				}
				else
				{
					printf("[S�STEM]: Yeni i�lem yapmak istedi�iniz hesap numaras�n� giriniz: ");
					scanf("%d", &yeni_hesapno);
					while(yeni_hesapno < 10000 || yeni_hesapno > 99999)
					{
						printf("[S�STEM - HATA]: Bankam�za ait olmayan bir hesap numaras� girdiniz!\n");
						printf("[S�STEM - B�LG�]: Bankam�za ait hesap numaralar� 10000-99999 aras�ndad�r!");
						printf("[S�STEM]: Yeni i�lem yapmak istedi�iniz hesap numaras�n� giriniz: ");
						scanf("%d", &yeni_hesapno);
					}
					printf("1 - Para �ekme\n");
					printf("2 - Para Yat�rma\n");
					printf("3 - Para Transferi\n");
					printf("4 - Sistemden ��k��\n");
					printf("[S�STEM]: Yap�lacak i�lemi se�iniz: ");
					scanf("%d", &yeni_islem);
					while(yeni_islem < 1 || yeni_islem > 4)
					{
						printf("[S�STEM - HATA]: Hatal� i�lem ID girdiniz!\n");
						printf("[S�STEM - B�LG�]: ��lem ID'leri 1-4 aras�ndad�r!\n");
						printf("[S�STEM]: Yap�lacak i�lemi se�iniz: ");
						scanf("%d", &yeni_islem);
					}
					Islemler(yeni_hesapno, yeni_islem);
				}
			}
			break;
		}
		case 4:
		{
			Sistem_Cikis();
			break;
		}
	}
}

int main(int argc, char *argv[]) 
{
	system("cls");
	system("color 4F");
	setlocale(LC_ALL, "Turkish");
	int islem = 0, hesapno = 0;
	printf("Hesap numaran�z� giriniz: ");
	scanf("%d", &hesapno);
	while(hesapno < 10000 || hesapno > 99999)
	{
		printf("[S�STEM - HATA]: Hesap numaran�z bankam�za ait de�il!\n");
		printf("[S�STEM - B�LG�]: Bankam�za ait hesap numaralar� 10000-99999 aras�ndad�r!\n");
		printf("Hesap numaran�z� giriniz: ");
		scanf("%d", &hesapno);
	}
	printf("1 - Para �ekme\n");
	printf("2 - Para Yat�rma\n");
	printf("3 - Para Transferi\n");
	printf("4 - Sistemden ��k��\n");
	printf("��lemi se�iniz: ");
	scanf("%d", &islem);
	while(islem < 1 || islem > 4)
	{
		printf("[S�STEM - HATA]: Ge�ersiz i�lem ID!\n");
		printf("[S�STEM - B�LG�]: Bankam�zda 4 i�lem ID bulunmaktad�r!\n");
		printf("1 - Para �ekme\n");
		printf("2 - Para Yat�rma\n");
		printf("3 - Para Transferi\n");
		printf("4 - Sistemden ��k��\n");
		printf("��lemi se�iniz: ");
		scanf("%d", &islem);
	}
	Islemler(hesapno, islem);
	return 0;
}
