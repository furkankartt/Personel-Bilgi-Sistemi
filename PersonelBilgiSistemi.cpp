#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<windows.h>
#include <locale.h>
int cks;

 struct personel
 {
    char isim[100];
    long int TCKimlikNo;
    long int telefon;
    char eposta[100];
    char adres[100];
 }yeni,ekleme;
void yeniKayit();
void listele();
void duzenle();
void TcArama();
void isimArama();
void sil();
void close();


int main(){
    setlocale(LC_ALL, "Turkish");
    int choice;
    printf("\n\t\t\t PERSONEL BÝLGÝ SÝSTEMÝ");
    printf("\n\t ÝÞLEMLER ");
    printf("\n\t1.Kayýt Ekle");
    printf("\n\t2.Personel Listele");
    printf("\n\t3.Kaydý Düzenle");
    printf("\n\t4.TC Kimlik No ile Arama");
    printf("\n\t5.Ýsim ile Arama");
    printf("\n\t6.Kayýt Sil");
    printf("\n\t0.Çýkýþ");

    printf("\n\t Tercihiniz:");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:yeniKayit();
        break;
        case 2:listele();
        break;
        case 3:duzenle();
        break;
        case 4:TcArama();
        break;
        case 5:isimArama();
        break;
        case 6:sil();
        break;
        case 7:close();
        break;
    }
    return 0;
}

void yeniKayit(){
    FILE *dosya;
    dosya=fopen("Personel.txt","a+");
    printf("\t\t\t Yeni Kayýt");

    printf("\n Ýsim:");
    scanf("%s",yeni.isim);
    printf("\n Tc:");
    scanf("%ld",&yeni.TCKimlikNo);
    printf("\n Telefon:");
    scanf("%ld",&yeni.telefon);
    printf("\n Eposta:");
    scanf("%s",yeni.eposta);
    printf("\n Adres:");
    scanf("%s", yeni.adres);

    fprintf(dosya,"%s %ld %ld %s %s\n",yeni.isim,yeni.TCKimlikNo,yeni.telefon,yeni.eposta,yeni.adres);
    fclose(dosya);

    printf("\n  Kayýt oluþturuldu.");
    gecerli1:
    printf("\n\n\n\t Yeni kayýt için 0, Ana Menü için 1:");
    scanf("%d", &cks);
    if (cks==1)
        main();
    else if(cks==0)
        yeniKayit();
    else{
        printf("\n hatalý giriþ");
        goto gecerli1;
    }
}

void listele(){
    FILE *dosya;
    dosya=fopen("Personel.txt","r");
    int test=0;
    printf("\nÝSÝM \t\t TC \t\t TELEFON \t\t EPOSTA \t\t ADRES \n");

    while(fscanf(dosya,"%s %ld %ld %s %s",yeni.isim,&yeni.TCKimlikNo,&yeni.telefon, yeni.eposta, yeni.adres)!=EOF){
           printf("\n %s \t\t %ld \t\t %ld \t\t %s \t\t %s",yeni.isim,yeni.TCKimlikNo,yeni.telefon,yeni.eposta,yeni.adres);
           test++;
    }

    fclose(dosya);
    if (test==0)
        {  printf("\nKAYIT YOK!\n");}

    gecerli2:
    printf("\n\n\n\t Ana Menü için 1, çýkmak için 0:");
    scanf("%d",&cks);
    if (cks==1)
        main();
    else if(cks==0)
        close();
    else{
        printf("\n hatalý giriþ");
        goto gecerli2;
    }
}


void duzenle(){
    int test=0;
    FILE *eski,*fark;
    eski=fopen("Personel.txt","r");
    fark=fopen("fark.txt","w");

    printf("\nPersonel Ýsmi:");
    scanf("%s",ekleme.isim);
    while(fscanf(eski,"%s %ld %ld %s %s",yeni.isim,&yeni.TCKimlikNo,&yeni.telefon, yeni.eposta, yeni.adres)!=EOF)
    {
        if (strcmp(ekleme.isim,yeni.isim) == 0){
            test=1;
            printf("Yeni TC:");
            scanf("%ld",&ekleme.TCKimlikNo);
            printf("Yeni Telefon:");
            scanf("%ld",&ekleme.telefon);
            printf("Yeni Eposta:");
            scanf("%s",ekleme.eposta);
            printf("Yeni Adres:");
            scanf("%s",ekleme.adres);
            fprintf(fark,"%s %ld %ld %s %s\n",ekleme.isim,ekleme.TCKimlikNo,ekleme.telefon,ekleme.eposta,ekleme.adres);
            printf("Deðiþiklik kaydedildi.");
        }
        else{
            fprintf(fark,"%s %ld %ld %s %s\n",yeni.isim,yeni.TCKimlikNo,yeni.telefon,yeni.eposta,yeni.adres);
        }
    }
    fclose(eski);
    fclose(fark);
    remove("Personel.txt");
    rename("fark.txt","Personel.txt");
    if(test!=1)
        printf("\nÝsim Bulunamadý\a\a\a");

        gecersiz3:
            printf("\nTekrar sorgulamak için 0,Ana Menü için 1:");
            scanf("%d",&cks);
            if (cks==1)
                main();
            else if(cks==0)
                duzenle();
            else{
                printf("\nYanlýþ Giriþ\a");
                goto gecersiz3;
            }
}


void TcArama(){
    FILE *dosya;
    int test=0;
    dosya=fopen("Personel.txt","r");
    printf("TC:");
    scanf("%ld",&ekleme.TCKimlikNo);
    while(fscanf(dosya,"%s %ld %ld %s %s",yeni.isim,&yeni.TCKimlikNo,&yeni.telefon, yeni.eposta, yeni.adres)!=EOF)
    {
            if(ekleme.TCKimlikNo==yeni.TCKimlikNo){
                test=1;
                printf("\nÝsim:%s \nTC:%ld \nTelefon:%ld \nEposta:%s \nAdres:%s\n",yeni.isim,yeni.TCKimlikNo,yeni.telefon,yeni.eposta,yeni.adres);
            }
    }
    fclose(dosya);
     if(test!=1)
        printf("\nKayýt Bulunamadý!\a\a\a");
    gecersiz5:
        printf("\nTekrar aramak için 0, Ana Menü için 1, çýkmak için 2:");
        scanf("%d",&cks);
            if (cks==1)
                main();
            else if (cks==2)
                close();
            else if(cks==0)
                TcArama();
            else{
                printf("\nYanlýþ Giriþ!\a");
                goto gecersiz5;
            }
}

void isimArama(){
    FILE *dosya;
    int test=0;
    dosya=fopen("Personel.txt","r");
    printf("Ýsim:");
    scanf("%s",&ekleme.isim);
    while(fscanf(dosya,"%s %ld %ld %s %s",yeni.isim,&yeni.TCKimlikNo,&yeni.telefon, yeni.eposta, yeni.adres)!=EOF)
    {
            if(strcmp(ekleme.isim,yeni.isim) == 0){
                test=1;
                printf("\nÝsim:%s \nTC:%ld \nTelefon:%ld \nEposta:%s \nAdres:%s\n",yeni.isim,yeni.TCKimlikNo,yeni.telefon,yeni.eposta,yeni.adres);
            }
    }
    fclose(dosya);
    if(test!=1)
        printf("\nKayýt Bulunamadý!\a\a\a");
    gecersiz6:
        printf("\nTekrar aramak için 0, Ana Menü için 1, çýkmak için 2:");
        scanf("%d",&cks);
            if (cks==1)
                main();
            else if (cks==2)
                close();
            else if(cks==0)
                isimArama();
            else{
                printf("\nYanlýþ Giriþ!\a");
                goto gecersiz6;
            }
}

void sil(){
    FILE *eski,*fark;
    int test=0;
    eski=fopen("Personel.txt","r");
    fark=fopen("fark.txt","w");
    printf("Silinecek kiþi TC'si:");
    scanf("%ld",&ekleme.TCKimlikNo);
    while(fscanf(eski,"%s %ld %ld %s %s",yeni.isim,&yeni.TCKimlikNo,&yeni.telefon, yeni.eposta, yeni.adres)!=EOF)
    {
        if(ekleme.TCKimlikNo!=yeni.TCKimlikNo)
            fprintf(fark,"%s %ld %ld %s %s\n",yeni.isim,yeni.TCKimlikNo,yeni.telefon,yeni.eposta,yeni.adres);
        else{
            test++;
            printf("\nKayýt silindi.\n");
        }
   }
   fclose(eski);
   fclose(fark);
   remove("Personel.txt");
   rename("fark.txt","Personel.txt");
   if(test==0)
        printf("\nKayýt bulunamadý!\a\a\a");
    gecersiz7:
        printf("\nTekrar silme aramasý yapmak için 0, Ana Menü için 1, Çýkmak için 2:");
        scanf("%d",&cks);
        if (cks==1)
            main();
        else if (cks==2)
            close();
        else if(cks==0)
            sil();
        else{
        printf("\nYanlýþ Giriþ!\a");
        goto gecersiz7;
        }
}


void close(){
    printf("Furkan KART ");
}
