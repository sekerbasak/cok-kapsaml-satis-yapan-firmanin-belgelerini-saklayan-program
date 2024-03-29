/****************************************************************************
**					      SAKARYA UNIVERSITESI
**			     BILGISAYAR VE BILISIM BILIMLERI FAKULTESI
**		             BILGISAYAR MUHENDISLIGI BOLUMU
**			           PROGRAMLAMAYA GIRIS DERSI
**
**			    	ODEV NUMARASI.... : Proje 1
**				    OGRENCI ADI.......: BASAK SEKER
**				    OGRENCI NUMARASI..: B211210028
**				    DERS GRUBU........: B
****************************************************************************/
#include <iostream> 
#include <locale.h>  //diller kutuphanesi
#include <stdio.h> 
#include <fstream>  //dosya islem kutuphanesi
#include <string> 
#include <ctime>        //zamani bulmak icin kutuphane                                                     
#include <cmath>          //matematik kutuphane 
#include <iomanip>         //manipulator kutuphanesi 
#include <windows.h>    



using namespace std;

/*

Urun icin  islemler              Siparis icin                             Musteri dosyasi islemleri

Urun ekleme                      Siparis olustur                          Musteri ekle
Urun arama                       Siparis arama                            Musteri duzeltme
Urun listeleme                   Siparis silme                            Musteri arama
Urun duzeltme                    Siparis duzeltme                         Musteri silme
Urun silme                       Siparis raporlama                                 */



int main() {

    // urunle ilgili tanimlamalar..  
    string urunAdi = "";
    double urunKodu = 0;
    string urunUreticisi = "";
    double urunFiyat = 0;
    double arananurunkodu = 0;
    double urununKodu = 0;
    int urunStok = 0;
    double urunFiyat_ozel = 0;
    double urun_KdvOrani = 0;
    int urunTeminsuresi = 0;
    int secim = 0;
    int urunislem_secim = 0;
    // musteri islemleri ile ilgili tanimlamalar..  
    int musteri_islemsecim = 0;
    double firma_no = 0;
    string firma_adi = "";
    double firma_telefon = 0;
    string firma_sorumlusu = "";
    string firma_adres = "";
    //Siparis islemleri ile ilgili tanimlamalar..  
    int siparis_islemsecim = 0;
    string siparis_alan = "";
    string siparisfirma_no = "";
    string siparis_tarihi = "";
    double siparis_tutari = 0;
    double aranansiparis_kodu = 0;
    double siparis_kodu = 0;


    char cevap = 'e';


    cout << endl << setw(40) << "HOSGELDINIZ!" << endl << endl;


    do {
        cout << "   Ne yapmak istiyorsunuz ? " << endl << endl;
        cout << "   1) URUN ISLEMLERI  " << endl;
        cout << "   2) MUSTERI DOSYA ISLEMLERI  " << endl;
        cout << "   3) SIPARIS ISLEMLERI " << endl;
        cout << "   4) CIKIS " << endl;
        cin >> secim;
    } while (secim != 1 && secim != 2 && secim != 3 && secim != 4); //kullanicinin girdigi sayi 1,2,3,4 degilse surekli doner..

    if (secim == 1) { // eger kullanici urun ile ilgili islemleri secerse if calisir.karsisina urunle ilgili islem secenekleri cikar
      
        do {
            cout << "   YAPMAK ISTEDIGINIZ URUN ISLEMINI SECINIZ..." << endl;
            cout << "   1) URUN EKLEME  " << endl;
            cout << "   2) URUN ARAMA " << endl;
            cout << "   3) URUN LISTELEME " << endl;
            cout << "   4) URUN DUZELTME " << endl;
            cout << "   5) URUN SILME " << endl;
            cin >> urunislem_secim;
        } while (secim != 1 && secim != 2 && secim != 3 && secim != 4);

       ofstream DosyaYaz; //yazma dosyasina isim verdik
        DosyaYaz.open("urun.txt", ios::app);// urun adli dosya acildi 

        if (urunislem_secim == 1) { // kullanici URUN EKLEMEYI secti..

            cout << "========== URUN EKLEME ==========" << endl << endl;
            do {
                cout << "  Eklemek istediginiz urun bilgilerini giriniz.." << endl;
                cout << "urun kodu: "; cin >> urunKodu;
                cout << "urun adi: "; cin >> urunAdi;
                cout << "urun ureticisi: "; cin >> urunUreticisi;              //kullanicidan bilgileri aliyoruz
                cout << "urun fiyat(genel musteriler): "; cin >> urunFiyat;
                cout << "urun fiyat ozel(iyi musteriler): "; cin >> urunFiyat_ozel;
                cout << "urunun kdv orani(%): "; cin >> urun_KdvOrani;
                cout << "urun stok adedi: "; cin >> urunStok;
                cout << "urunun temin suresi(gun): "; cin >> urunTeminsuresi;

                DosyaYaz << urunKodu << " " << urunAdi << " " << urunUreticisi << " " << urunFiyat << " " << urunFiyat_ozel << " " << urun_KdvOrani << " " << urunStok << " " << urunTeminsuresi << endl;

                cout << "  Baska urun ekleyecek misiniz?(e/h)" << endl;
                cin >> cevap;
            } while (!(cevap == 'h')); // cevap hayir olana kadar dondurur..
            
            DosyaYaz.close(); //dosyayi kapatir
            cout << " Dosya yazimi basariyla tamamlandi:)" << endl;
            return 0;
        }
        if (urunislem_secim == 2) { // kullanici URUN ARAMAYI secti...

            cout << "========== URUN ARAMA ==========" << endl << endl;

            ifstream dosyaOku; // ifstream dosyalardan veri okur
            dosyaOku.open("urun.txt", ios::in);// ios ::in var olan dosyayi okumak uzere acar. dosya yok ise hata dondurur.. 
            cout << " Aramak istediginiz urunun kodunu giriniz.." << endl;
            cin >> arananurunkodu;
            if (dosyaOku.is_open()) {
                int x = 0; // aranan kodla dosyadaki urun bilgileri arasinda uyumu dogrulamak icin deger atadik..(e/h gibi)
                do {
                    dosyaOku >> urunKodu >> urunAdi >> urunUreticisi >> urunFiyat >> urunFiyat_ozel >> urun_KdvOrani >> urunStok >> urunTeminsuresi; //dosyadan urun bilgilerini okuduk..
                    if (urunKodu == arananurunkodu) { // dosyadaki kodla kullanicinin aradigi kod uyusursa iceri girir..
                        x = 1;
                        cout << "Urun Bulundu" << endl;
                        cout << urunKodu << " " << urunAdi << " " << urunUreticisi << " " << urunFiyat << " " << urunFiyat_ozel << " " << urun_KdvOrani << " " << urunStok << " " << urunTeminsuresi << endl;
                        return 0;
                    }

                } while (!dosyaOku.eof()); // dosyanin sonuna gelinip gelinmedigini kontrol eder.
                dosyaOku.close();
                if (x == 0) {
                    cout << " Aradiginiz koda ait urun bulunamadi!" << endl;

                }

            }
            else
                cout << " Dosya acilamadi!!";
            system("pause");
            return 0;
        }


        if (urunislem_secim == 3) { // kullaini URUN LISTELEMEYI secti

            cout << "========== URUN LISTELEME==========" << endl << endl;

            ifstream okumaDosyasi;
            okumaDosyasi.open("urun.txt", ios::in); //ios:: app dosya yazmak icin kullanilir dosya yok ise olusturur..
            string satir = " ";
            if (okumaDosyasi.is_open()) {

                while (getline(okumaDosyasi, satir)) { // dosyadaki verileri tek tek okuyup cikti verir..
                    cout << satir << endl;
                }
                okumaDosyasi.close();
                return 0;
            }

        }

        if (urunislem_secim == 4) {

            cout << "========== URUN DUZELTME ==========" << endl << endl;

            double sorgu_urunkod;
            ifstream DosyaOku("urun.txt"); //Dosya cikisi yapabilmek için gerekli kodu yazdim.
            ofstream DosyaYaz("gecici.tmp");//Gecici bir dosya actim


            cout << "Duzenlenecek Urun Kodu...:";
            cin >> sorgu_urunkod;

            int gcc = 0;
            while (!(DosyaOku.eof())) //DosyaOku da belirttiğim urun.txt dosyasını sonuna kadar okuttum.
            {

                DosyaOku >> urunKodu >> urunAdi >> urunUreticisi >> urunFiyat >> urunFiyat_ozel >> urun_KdvOrani >> urunStok >> urunTeminsuresi;//hasta.txt dosyasındaki kayıtlar okunur

                if (sorgu_urunkod == urunKodu)//Sorgulanan  urun numarasi varsa urun bilgilerini gosterir.
                {
                    cout << "******Urun  Bilgileri******" << endl << endl;//urun bilgieri yazdirilir.


                    cout << "urun kodu: " << urunKodu;
                    cout << "\n urun adi: " << urunAdi;
                    cout << "\n urun ureticisi: " << urunUreticisi;
                    cout << "\n urun fiyat(genel musteriler): " << urunFiyat;
                    cout << "\n urun fiyat ozel(iyi musteriler): " << urunFiyat_ozel;
                    cout << "\n urunun kdv orani(%): " << urun_KdvOrani;
                    cout << "\n urun stok adedi: " << urunStok;
                    cout << "\n urunun temin suresi(gun): " << urunTeminsuresi << endl << endl;

                    cout << "urun Bilgilerini Yenileyiniz..." << endl << endl; //urun bilgilerini disardan girdirilir


                    cout << "urun kodu: "; cin >> urunKodu;
                    cout << "urun adi: "; cin >> urunAdi;
                    cout << "urun ureticisi: "; cin >> urunUreticisi;
                    cout << "urun fiyat(genel musteriler): "; cin >> urunFiyat;
                    cout << "urun fiyat ozel(iyi musteriler): "; cin >> urunFiyat_ozel;
                    cout << "urunun kdv orani(%): "; cin >> urun_KdvOrani;
                    cout << "urun stok adedi: "; cin >> urunStok;
                    cout << "urunun temin suresi(gun): "; cin >> urunTeminsuresi;

                    DosyaYaz << urunKodu << " " << urunAdi << " " << urunUreticisi << " " << urunFiyat << " " << urunFiyat_ozel << " " << urun_KdvOrani << " " << urunStok << " " << urunTeminsuresi;//Düzenlenen dosya bilgileri yazdırılır.

                    gcc = 1;
                }
                else {

                    DosyaYaz << urunKodu << " " << urunAdi << " " << urunUreticisi << " " << urunFiyat << " " << urunFiyat_ozel << " " << urun_KdvOrani << " " << urunStok << " " << urunTeminsuresi;
                }
            }
            if (gcc == 0){
                cout << "Boyle Bir Kayit Bulunamamistir..." << endl;
             }
            DosyaYaz.close();
            DosyaOku.close();
            remove("urun.txt");// urun.txt dosyası silinirken
            rename("gecici.tmp", "urun.txt");//gecici.tmp dosyası urun.txt dosyası olarak degistirilir

        }

        if (urunislem_secim == 5) { // kullanici URUN SILMEYI secti

            cout << "========== URUN SILME ==========" << endl << endl;

            ifstream silmeDosyasi;
            ofstream YedekOkumaDosyasi; // yazmak uzere yedek dosya acildi..
            int sil = 0;
            string satir = "";
            YedekOkumaDosyasi.open("urunyeni.txt", ios::app);//ios:: app dosya yazmak icin kullanilir dosya yok ise olusturur..// yedek dosya acildi 
            silmeDosyasi.open("urun.txt", ios::in);// ios:: in var olan dosyanin okunmak uzere acilmasi 

            cout << " Silmek istediginiz urunun kodunu giriniz: " << endl;
            cin >> arananurunkodu;

            if (silmeDosyasi.is_open()) {
                do
                {
                    silmeDosyasi >> urunKodu >> urunAdi >> urunUreticisi >> urunFiyat >> urunFiyat_ozel >> urun_KdvOrani >> urunStok >> urunTeminsuresi;
                    if (urunKodu == arananurunkodu)
                    {
                        sil = 1;
                    }
                    else
                    {
                        YedekOkumaDosyasi << urunKodu << " " << urunAdi << " " << urunUreticisi << " " << urunFiyat << " " << urunFiyat_ozel << " " << urun_KdvOrani << " " << urunStok << " " << urunTeminsuresi << endl;
                    }
                } while (!silmeDosyasi.eof());
                if (sil == 0)
                {
                    cout << arananurunkodu << " urun kodlu urun bulunamadi..." << endl;
                }
                else
                {
                    cout << arananurunkodu << " urun kodlu urun silindi..." << endl;
                }

            }
            else
            {
                cout << " dosya acilamadi";
                system(" pause");
            }

            silmeDosyasi.close();
            YedekOkumaDosyasi.close();
            remove("urun.txt");// eski dosya silinir..
            rename("urunyeni.txt", "urun.txt");// dosyanin adi degisir


        }
    }


    else if (secim == 2) {   // kullanici MUSTERI ISLEMLERINI  secerse..

        ofstream DosyaYaz;
        DosyaYaz.open("cari.txt", ios::app);  //ios:: app dosya yazmak icin kullanilir dosya yok ise olusturur..
        do {
            cout << "  YAPMAK ISTEDIGINIZ MUSTERI ISLEMINI SECINIZ..   " << endl;
            cout << "   1) MUSTERI EKLE  " << endl;
            cout << "   2) MUSTERI ARAMA  " << endl;
            cout << "   3) MUSTERI DUZELTME  " << endl;
            cout << "   4) MUSTERI SILME " << endl;
            cin >> musteri_islemsecim;
        } while (secim != 1 && secim != 2 && secim != 3 && secim != 4);



        if (musteri_islemsecim == 1) { // kullanici musteri islemlerinden MUSTERI EKLE secerse..

            cout << "========== MUSTERI EKLEME ==========" << endl << endl;
            do {

                cout << " Eklemek Istediginiz Musteri Bilgilerini Giriniz.. " << endl;
                cout << " firma kod numarasi: "; cin >> firma_no;
                cout << " firma adi: "; cin >> firma_adi;
                cout << " firma telefon: "; cin >> firma_telefon;       //musteri bilgilerini giriyor..
                cout << " firma sorumlusu: "; cin >> firma_sorumlusu;
                cout << " firma adres: "; cin >> firma_adres;

                DosyaYaz << firma_no << "  " << firma_adi << "  " << firma_telefon << "  " << firma_sorumlusu << "  " << firma_adres << endl << endl;
                cout << "  Baska urun ekleyecek misiniz?(e/h)" << endl;
                cin >> cevap;
            } while (!(cevap == 'h')); // cevap h olana kadar dondurur..

            DosyaYaz.close();
            cout << " dosya yazimi basariyla tamamlandi:)" << endl;
        }

        if (musteri_islemsecim == 2) { // kullanici MUSTERI ARAMAYI secerse..

            cout << "========== MUSTERI ARAMA ==========" << endl << endl;

            ifstream dosyaOku;   //dosya okuma
            dosyaOku.open("cari.txt", ios::in);
            cout << " Aramak istediginiz musteri numarasini giriniz.." << endl;
            double arananFirma_kodu;

            cin >> arananFirma_kodu;
            if (dosyaOku.is_open()) {
                int x = 0;
                do {
                    dosyaOku >> firma_no >> firma_adi >> firma_telefon >> firma_sorumlusu >> firma_adres;
                    if (firma_no == arananFirma_kodu) {
                        x = 1;
                        cout << "Aranan Musteri Bulundu!" << endl;
                        cout << firma_no << "  " << firma_adi << "  " << firma_telefon << "  " << firma_sorumlusu << "  " << firma_adres << endl << endl;
                        return 0;
                    }

                } while (!(dosyaOku.eof()));
                dosyaOku.close();
                if (x == 0)
                    cout << " Aradiginiz Koda Ait Musteri Bulunamadi, Kodu Kontrol Ediniz!" << endl;

            }

            else
                cout << " Dosya Acilamadi!!";
            system(" pause");
        }

        if (musteri_islemsecim == 3)// MUSTERI DUZELTME
        {
            cout << "========== MUSTERI DUZELTME ==========" << endl << endl;

            ifstream DosyaOku("cari.txt");
            ofstream DosyaYaz("gecici.tmp");  //Gecici bir dosya acilir

            double arananFirma_kodu = 0;
            cin >> arananFirma_kodu; //duzenlenecek musteri kodunu sorgulattim.

            int gcc = 0;
            while (!(DosyaOku.eof())) //DosyaOku da belirttigim cari.txt dosyasini sonuna kadar okuttum.
            {

                DosyaOku >> firma_no >> firma_adi >> firma_telefon >> firma_sorumlusu >> firma_adres;//cari.txt dosyasindaki kayitlar okunur


                if (arananFirma_kodu == firma_no)//Sorgulanan firma numarasi varsa musteri bilgilerini gosterir.
                {

                    cout << "========== Musteri Bilgileri ==========" << endl << endl;//musteri bilgieri yazdirilir.

                    cout << " firma kod numarasi: " << firma_no;
                    cout << " \n firma adi: " << firma_adi;
                    cout << " \n firma telefon: " << firma_telefon;
                    cout << " \n firma sorumlusu: " << firma_sorumlusu;
                    cout << " \n firma adres: " << firma_adres;

                    cout << "Degistirmek Istediginiz Musteri  Bilgilerini Yenileyiniz..." << endl << endl;//musteri bilgilerini disardan girdirilir


                    cout << " firma kod numarasi: ";
                    cin >> firma_no;
                    cout << " firma adi: ";
                    cin >> firma_adi;
                    cout << " firma telefon: ";
                    cin >> firma_telefon;
                    cout << " firma sorumlusu: ";
                    cin >> firma_sorumlusu;
                    cout << " firma adres: ";
                    cin >> firma_adres;

                    DosyaYaz << "\n" << arananFirma_kodu << " " << firma_adi << " " << firma_telefon << " " << firma_sorumlusu;//Duzenlenen dosya bilgileri yazdirilir

                    gcc = 1;
                }
                else
                {
                    DosyaYaz << "\n" << firma_no << " " << firma_adi << " " << firma_telefon << " " << firma_sorumlusu;
                }
            }
            if (gcc == 0)
                cout << "Boyle Bir Kayit Bulunamamistir..." << endl;

            DosyaYaz.close();
            DosyaOku.close();
            remove("cari.txt");// cari.txt dosyasi silinirken
            rename("gecici.tmp", "cari.txt");//gecici.tmp dosyasi cari.txt dosyasi olarak degistirilir
            return 0;
        }


        if (musteri_islemsecim == 4) {// kullanici MUSTERI SILMEYI secerse..

            cout << "========== MUSTERI SILME ==========" << endl << endl;

            ifstream silmeDosyasi;
            ofstream YedekOkumaDosyasi;
            int sil = 0;
            string satir = "";
            YedekOkumaDosyasi.open("musteriyeni.txt", ios::app);////ios:: app dosya yazmak icin kullanilir dosya yok ise olusturur..
            silmeDosyasi.open("cari.txt", ios::in);// ios:: in var olan dosyanin okunmak uzere acilmasi 

            cout << " Silmek istediginiz musteri firmanin kodunu giriniz: " << endl;
            double sil_firmaKodu;
            cin >> sil_firmaKodu;
            if (silmeDosyasi.is_open()) {

                do
                {
                    silmeDosyasi >> firma_no >> firma_adi >> firma_telefon >> firma_sorumlusu >> firma_adres;
                    if (firma_no == sil_firmaKodu)
                    {
                        sil = 1;
                    }
                    else
                    {
                        YedekOkumaDosyasi << firma_no << " " << firma_adi << " " << firma_telefon << " " << firma_sorumlusu << " " << firma_adres << endl << endl;
                    }


                } while (!(silmeDosyasi.eof()));
                if (sil == 0)
                {
                    cout << sil_firmaKodu << "  kodlu siparis bulunamadi..." << endl;
                }
                else
                {
                    cout << sil_firmaKodu << "  kodlu siparis silindi..." << endl;
                }

            }
            else
            {
                cout << " dosya acilamadi";
                system(" pause");
            }
            silmeDosyasi.close();
            YedekOkumaDosyasi.close();

        }

    }

    else if (secim == 3) { //  kullanici siparis ile ilgili islemleri secerse

        ofstream DosyaYaz;

        DosyaYaz.open("siparis.txt", ios::app);
        do {
            cout << "  YAPMAK ISTEDIGINIZ SIPARIS ISLEMINI SECINIZ..  " << endl;
            cout << "   1) SIPARIS OLUSTUR " << endl;
            cout << "   2) SIPARIS ARAMA  " << endl;
            cout << "   3) SIPARIS RAPORLAMA " << endl;
            cout << "   4) SIPARIS DUZELTME " << endl;
            cout << "   5) SIPARIS SILME " << endl;
            cin >> siparis_islemsecim;
        } while (secim != 1 && secim != 2 && secim != 3 && secim != 4);

        if (siparis_islemsecim == 1) { //kullanici SIPARIS OLUSTUR secerse
            do {

                cout << "========== SIPARIS OLUSTUR ==========" << endl << endl;

                cout << " olusturmak istediginiz siparis bilgilerini giriniz.." << endl;
                cout << " siparis kodu: "; cin >> siparis_kodu;
                cout << " siparisi alan kisi:  "; cin >> siparis_alan;
                cout << " siparis veren firma no:  "; cin >> siparisfirma_no;
                cout << " siparis tarihi(gg.ay.yil):  "; cin >> siparis_tarihi;
                cout << " siparis tutari: "; cin >> siparis_tutari;

                DosyaYaz << siparis_kodu << " " << siparis_alan << "  " << siparisfirma_no << "  " << siparis_tarihi << " " << siparis_tutari << endl << endl;
                cout << "  baska urun ekleyecek misiniz?(e/h)" << endl;
                cin >> cevap;
            } while (!(cevap == 'h'));
            DosyaYaz.close();
            cout << " Dosya yazimi basariyla tamamlandi:)" << endl;

        }
        if (siparis_islemsecim == 2) { // kullanici  SIPARIS ARAMA secerse

            cout << "========== SIPARIS ARAMA ==========" << endl << endl;

            ifstream dosyaOku;
            dosyaOku.open("siparis.txt", ios::in);
            cout << " Aramak istediginiz siparis numarasini giriniz.." << endl;
            double aranansiparis_kodu;
            cin >> aranansiparis_kodu;
            if (dosyaOku.is_open()) {
                int x = 0;
                do {
                    dosyaOku >> siparis_kodu >> siparis_alan >> siparisfirma_no >> siparis_tarihi >> siparis_tutari;
                    if (siparis_kodu == aranansiparis_kodu) {
                        x = 1;
                        cout << "Aranan Siparis Bulundu!" << endl;
                        cout << siparis_kodu << " " << siparis_alan << " " << siparisfirma_no << " " << siparis_tarihi << siparis_tutari << endl;
                    }break;

                } while (!dosyaOku.eof());
                dosyaOku.close();
                if (x == 0) {
                    cout << " Aradiginiz Koda Ait Siparis Bulunamadi, Kodu Kontrol Ediniz!" << endl;
                }

            }

            else
                cout << " Dosya Acilamadi";
            system(" pause");
            return 0;
        }



        if (siparis_islemsecim == 3) { // kullanici SIPARIS RAPORLAMAYI secerse..

            cout << "========== SIPARIS RAPORLAMA ==========" << endl << endl;

            ifstream okumaDosyasi;
            okumaDosyasi.open("siparis.txt", ios::app);
            string satir = " ";
            if (okumaDosyasi.is_open()) {

                while (getline(okumaDosyasi, satir)) {
                    cout << satir << endl;
                }
                okumaDosyasi.close();
                return 0;

            }

        }


        if (siparis_islemsecim == 4) { // siparis duzeltme

            cout << "========== SIPARIS DUZELTME ==========" << endl << endl;

            double aranansiparis_kodu = 0;

            ifstream DosyaOku("siparis.txt"); //Dosya okuma yapabilmek icin gerekli kodu yazdim.
            ofstream DosyaYaz("gecici.tmp");//Gecici bir dosya acilir

            double sil_siparisKodu;
            cin >> sil_siparisKodu; //duzenlenecek siparis kodunu sorgulattim.

            int gcc = 0;
            while (!(DosyaOku.eof())) //DosyaOku da belirttigim siparis.txt dosyasini sonuna kadar okuttum.
            {

                DosyaOku >> siparis_kodu >> siparis_alan >> siparisfirma_no >> siparis_tarihi >> siparis_tutari;//siparis.txt dosyasindaki kayitlar okunur


                if (sil_siparisKodu == siparis_kodu)//Sorgulanan siparis kodu varsa siparis bilgilerini gosterir.
                {

                    cout << "========== Siparis Bilgileri ==========" << endl << endl;//siparis bilgieri yazdirilir.

                    cout << " siparis kodu: " << siparis_kodu;
                    cout << " siparisi alan kisi:  " << siparis_alan;
                    cout << " siparis veren firma no:  " << siparisfirma_no;
                    cout << " siparis tarihi(gg.ay.yil):  " << siparis_tarihi;
                    cout << " siparis tutari(TL): " << siparis_tutari;

                    cout << " siparis Bilgilerini Yenileyiniz..." << endl << endl;//siparis bilgilerini disardan girdirilir

                    cout << " siparis kodu: "; cin >> siparis_kodu;
                    cout << " siparisi alan kisi:  "; cin >> siparis_alan;
                    cout << " siparis veren firma no:  "; cin >> siparisfirma_no;
                    cout << " siparis tarihi(gg.ay.yil):  "; cin >> siparis_tarihi;
                    cout << " siparis tutari(TL): "; cin >> siparis_tutari;

                    DosyaYaz << "\n" << aranansiparis_kodu << " " << siparis_alan << " " << siparisfirma_no << " " << siparis_tarihi << " " << siparis_tutari;//Duzenlenen dosya bilgileri yazdirilir

                    gcc = 1;
                }
                else
                {
                    DosyaYaz << siparis_kodu << " " << siparis_alan << " " << siparisfirma_no << " " << siparis_tarihi << " " << siparis_tutari;
                }
            }
            if (gcc == 0)
                cout << "Boyle Bir Kayit Bulunamamistir..." << endl;

            DosyaYaz.close();
            DosyaOku.close();

            remove("siparis.txt");// siparis.txt dosyasi silinirken
            rename("gecici.tmp", "siparis.txt");//gecici.tmp dosyasi siparis.txt dosyasi olarak degistirilir
            return 0;
        }


        if (siparis_islemsecim == 5) {// kullanici SIPARIS SILMEYI secerse..

            cout << "========== SIPARIS SILME ==========" << endl << endl;

            ifstream silmeDosyasi;
            ofstream YedekOkumaDosyasi;
            int sil = 0;
            string satir = "";

            YedekOkumaDosyasi.open("siparisyeni.txt", ios::app);////ios:: app dosya yazmak icin kullanilir dosya yok ise olusturur..
            silmeDosyasi.open("siparis.txt", ios::in);// ios:: in var olan dosyanin okunmak uzere acilmasi 

            cout << " Silmek istediginiz siparis  kodunu giriniz: " << endl;
            double sil_siparisKodu;
            cin >> sil_siparisKodu;
            if (silmeDosyasi.is_open()) {

                do
                {
                    silmeDosyasi >> siparis_kodu >> siparis_alan >> siparisfirma_no >> siparis_tarihi >> siparis_tutari;

                    if (siparis_kodu == sil_siparisKodu)
                    {
                        sil = 1;
                    }
                    else
                    {
                        YedekOkumaDosyasi << siparis_kodu << " " << siparis_alan << " " << siparisfirma_no << " " << siparis_tarihi << " " << siparis_tutari << endl << endl;
                    }


                } while (!(silmeDosyasi.eof()));
                if (sil == 0)
                {
                    cout << sil_siparisKodu << "  kodlu siparis bulunamadi..." << endl;
                }
                else
                {
                    cout << sil_siparisKodu << "  kodlu siparis silindi..." << endl;
                }

            }
            else
            {
                cout << " dosya acilamadi";
                system(" pause");
            }
            silmeDosyasi.close();
            YedekOkumaDosyasi.close();


        }

    }

    else
    {
        cout << endl << endl << "Programdan cikis yaptiniz.." << endl;

        exit(1);
    }


}
