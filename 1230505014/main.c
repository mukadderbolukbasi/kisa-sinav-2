#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// tanýmlama
typedef struct {
    char urunAdi[50];
    double baslangicFiyati;
    double suankiFiyat;
    int kazanan_no;
    double odeme;
} Urun;

// ürünün baþlangýç fiyatýný belirleyen fonksiyon
void baslangicFiyatBelirle(Urun *urun, double fiyat) {
    strcpy(urun->urunAdi, "Yakut Kolye");
    urun->baslangicFiyati = urun->suankiFiyat = fiyat;
}

// yeni teklif verenin teklifini kontrol eden ve gerekli iþlemleri yapan fonksiyon
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

// ürünün bilgilerini ekrana yazdýran fonksiyon
void urunuGoster(Urun urun) {
    printf("Urun Adi: %s\n Baslangic Fiyati: %.2f TL\n En Yuksek Teklif: %.2f TL\n Kazanan Numara: %d \n Odeme: %.2f TL \n\n",
           urun.urunAdi, urun.baslangicFiyati, urun.suankiFiyat, urun.kazanan_no, urun.odeme);
}

void odemeYap(Urun *urun) { // kazanan teklif sahibinin ödeme yapmasýný saðlayan fonksiyon
    urun->odeme = urun->suankiFiyat;
    printf("Odeme tamamlandi . \n Kazanan Numara: %d \n Ödeme Miktari: %.2f TL\n", urun->kazanan_no, urun->odeme);
}

int main() {  // açýk arttýrmada kullanýlacak ürünü tanýmlayan deðiþken
    Urun acikArtirmaUrunu;

    // baþlangýç fiyatýný kullanýcýdan alýnan deðerle belirleyen fonksiyonu çaðýrma
    printf("Acik arttirmaya hos geldiniz. \n Baslangic fiyatini belirleyin : \n ");
    double baslangicFiyati;
    scanf("%lf", &baslangicFiyati);
    baslangicFiyatBelirle(&acikArtirmaUrunu, baslangicFiyati);

    // üç farklý kiþinin teklif verdiði durumu simüle eden fonksiyonlarý çaðýrma
    yeniTeklifVer(&acikArtirmaUrunu, "Esra Hanim", 1);
    yeniTeklifVer(&acikArtirmaUrunu, "Zeynep Hanim", 2);
    yeniTeklifVer(&acikArtirmaUrunu, "Mukadder Hanim", 3);

    printf("Acik arttirma tamamlandi. \n Odeme yapiliyor...\n");   // açýk arttýrmanýn tamamlandýðýný ve ödeme yapýldýðýný belirten mesajý ekrana yazdýrma
    

    odemeYap(&acikArtirmaUrunu); // kazanan teklif sahibinin ödeme yapmasýný saðlayan fonksiyonu çaðýrma


    printf("Acik arttirma sonuclari :\n"); // açýk arttýrmanýn sonuçlarýný ekrana yazdýran fonksiyonu çaðýrma
    urunuGoster(acikArtirmaUrunu);

    return 0;
}
