#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// tan�mlama
typedef struct {
    char urunAdi[50];
    double baslangicFiyati;
    double suankiFiyat;
    int kazanan_no;
    double odeme;
} Urun;

// �r�n�n ba�lang�� fiyat�n� belirleyen fonksiyon
void baslangicFiyatBelirle(Urun *urun, double fiyat) {
    strcpy(urun->urunAdi, "Yakut Kolye");
    urun->baslangicFiyati = urun->suankiFiyat = fiyat;
}

// yeni teklif verenin teklifini kontrol eden ve gerekli i�lemleri yapan fonksiyon
void yeniTeklifVer(Urun *urun, char *teklifVeren, int teklifVerenNo) {
    double yeniTeklif;
    printf("%s, ne kadar teklif vermek istiyorsunuz? \n ", teklifVeren);
    scanf("%lf", &yeniTeklif);

    if (yeniTeklif > urun->suankiFiyat && yeniTeklif >= urun->baslangicFiyati) {
        urun->suankiFiyat = urun->kazanan_no = yeniTeklif;
        printf("Teklif kabul edildi. \n Yeni fiyat: %.2f TL\n", urun->suankiFiyat);
    } else {
        printf("Teklif reddedildi. \n Gecerli fiyat: %.2f TL\n", urun->suankiFiyat);
    }
}

// �r�n�n bilgilerini ekrana yazd�ran fonksiyon
void urunuGoster(Urun urun) {
    printf("Urun Adi: %s\n Baslangic Fiyati: %.2f TL\n En Yuksek Teklif: %.2f TL\n Kazanan Numara: %d \n Odeme: %.2f TL \n\n",
           urun.urunAdi, urun.baslangicFiyati, urun.suankiFiyat, urun.kazanan_no, urun.odeme);
}

void odemeYap(Urun *urun) { // kazanan teklif sahibinin �deme yapmas�n� sa�layan fonksiyon
    urun->odeme = urun->suankiFiyat;
    printf("Odeme tamamlandi . \n Kazanan Numara: %d \n �deme Miktari: %.2f TL\n", urun->kazanan_no, urun->odeme);
}

int main() {  // a��k artt�rmada kullan�lacak �r�n� tan�mlayan de�i�ken
    Urun acikArtirmaUrunu;

    // ba�lang�� fiyat�n� kullan�c�dan al�nan de�erle belirleyen fonksiyonu �a��rma
    printf("Acik arttirmaya hos geldiniz. \n Baslangic fiyatini belirleyin : \n ");
    double baslangicFiyati;
    scanf("%lf", &baslangicFiyati);
    baslangicFiyatBelirle(&acikArtirmaUrunu, baslangicFiyati);

    // �� farkl� ki�inin teklif verdi�i durumu sim�le eden fonksiyonlar� �a��rma
    yeniTeklifVer(&acikArtirmaUrunu, "Esra Hanim", 1);
    yeniTeklifVer(&acikArtirmaUrunu, "Zeynep Hanim", 2);
    yeniTeklifVer(&acikArtirmaUrunu, "Mukadder Hanim", 3);

    printf("Acik arttirma tamamlandi. \n Odeme yapiliyor...\n");   // a��k artt�rman�n tamamland���n� ve �deme yap�ld���n� belirten mesaj� ekrana yazd�rma
    

    odemeYap(&acikArtirmaUrunu); // kazanan teklif sahibinin �deme yapmas�n� sa�layan fonksiyonu �a��rma


    printf("Acik arttirma sonuclari :\n"); // a��k artt�rman�n sonu�lar�n� ekrana yazd�ran fonksiyonu �a��rma
    urunuGoster(acikArtirmaUrunu);

    return 0;
}
