#include <iostream>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct Node{
    int Ukuran;
    int kodepakaian;
    char warna[50];
    char namapakaian[50];
    Node *next;
};

typedef Node *Pakaian;
Pakaian Head, Tail, Main;

void inisialisasi();
void buatpakaian();
void ambilpakaian();
void tampilkan();
void detail();



int main()
{
   int n;
   char pil;
   inisialisasi();
   awal:
   cout<<"=================================="<<endl;
   cout<<"Selamat Datang Di Toko Tekstil XXX"<<endl;
   cout<<"Silahkan Pilih Menu Logistik Anda!"<<endl;
   cout<<"----------------------------------"<<endl;
   cout<<"1. Daftar Pakaian"<<endl;
   cout<<"2. Detail Pakaian"<<endl;
   cout<<"3. Masukkan Pakaian"<<endl;
   cout<<"4. Ambil Pakaian"<<endl;
   cout<<"5. Out"<<endl;

   cout<<"Masukkan aktivitas anda : ";cin>>pil;

   switch(pil)
   {
    case '1':
        system("cls");
        tampilkan();
        getch();
        system("cls");
        break;

    case '2':
        system("cls");
        if((Head==NULL)&&(Tail==NULL))
        {tampilkan();}
        else
        {tampilkan();
        detail();}

        getch();
        system("cls");
        break;

    case '3':
        system("cls");
        buatpakaian();
        getch();
        system("cls");
        break;
    case '4':
        system("cls");
        ambilpakaian();
        system("cls");
        break;

    case '5':
        goto akhir;
    default:
        cout<<"Masukkan aktivitas dengan benar!"<<endl;
        getch();
        system("cls");
        goto awal;
   }
   goto awal;
   akhir:
       getch();
       return 0;
}

void inisialisasi()
{
    Head = NULL;
    Tail = NULL;
}

void buatpakaian()
{
    cout<<"Kode Atasan : 1xxx (1000-1999)"<<endl;
    cout<<"Kode Bawahan : 2xxx (2000-2999)"<<endl<<endl;
    Main = new Node();
    ulang:
    cout<<"Kode Pakaian : ";cin>>Main->kodepakaian;
    if((Main->kodepakaian>=1000)&&(Main->kodepakaian<=1999))
    {
        cout<<"Atasan :"<<endl;
        cout<<"Format nama (kalau berspasi) : nama1_nama2_nama(n)"<<endl<<endl;
        cout<<"Nama/Merek Atasan : ";cin>>(Main->namapakaian);
        cout<<"Warna Atasan : ";cin>>(Main->warna);
        lagi:
        cout<<"Ukuran : "<<endl;
        cout<<"1. XS"<<endl;
        cout<<"2. S"<<endl;
        cout<<"3. M"<<endl;
        cout<<"4. L"<<endl;
        cout<<"5. XL"<<endl;
        cout<<"6. XXL"<<endl;
        cout<<"7. XXXL"<<endl;
        cout<<"Enter : ";cin>>Main->Ukuran;

        if((Main->Ukuran < 1)&&(Main->Ukuran > 7))
        {
            cout<<"Masukkan ukuran dgn benar!"<<endl;
            goto lagi;
        }

            if((Head==NULL)&&(Tail==NULL))
            {
                Head = Main;
                Tail=Main;
                Head->next=NULL;
                Tail->next=NULL;
                cout<<"Pakaian telah ditambahkan!"<<endl;
            }
            else{
                Main->next=Head;
                Head=Main;
                cout<<"Pakaian telah ditambahkan!"<<endl;
            }

    }
    else if((Main->kodepakaian>=2000)&&(Main->kodepakaian<=2999))
    {
        cout<<"Bawahan :"<<endl;
        cout<<"Format nama (kalau berspasi) : nama1_nama2_nama(n)"<<endl<<endl;
        cout<<"Nama/Merek Bawahan : ";cin>>(Main->namapakaian);
        cout<<"Warna Bawahan : ";cin>>(Main->warna);
        again:
        cout<<"Ukuran : "<<endl;
        cout<<"1. XS"<<endl;
        cout<<"2. S"<<endl;
        cout<<"3. M"<<endl;
        cout<<"4. L"<<endl;
        cout<<"5. XL"<<endl;
        cout<<"6. XXL"<<endl;
        cout<<"7. XXXL"<<endl;
        cout<<"Enter : ";cin>>Main->Ukuran;

        if((Main->Ukuran < 1)&&(Main->Ukuran > 7))
        {
            cout<<"Masukkan ukuran dgn benar!"<<endl;
            goto again;
        }



    Main->next=NULL;

    if((Head==NULL)&&(Tail==NULL))
    {
        Head = Main;
        Tail=Main;
        Head->next=NULL;
        Tail->next=NULL;
        cout<<"Pakaian telah ditambahkan!"<<endl;
    }
    else
    {
        Tail = Head;
        do{
         Tail=Tail->next;
        }while(Tail->next!=NULL);
        Main->next=NULL;
        Tail->next=Main;
        Tail=Tail->next;
        cout<<"Pakaian telah ditambahkan!"<<endl;
    }
  }

    else{
        cout<<"Masukkan dgn benar!!"<<endl;
        goto ulang;
    }

}

void ambilpakaian()
{
    int kode;
    Pakaian posisi,before,prev;
    cout<<"Format Atasan : 1xxx (1000-1999)"<<endl;
    cout<<"Format Bawahan : 2xxx (2000-2999)"<<endl;
    up:
    cout<<"Kode pakaian yang mau diambil : ";cin>>kode;
    if((kode>=1000)&&(kode<=2999))
    {
      if(Head->kodepakaian==kode)
     {
        posisi = Head;
        Head = Head->next;
        delete posisi;
        cout<<"Pakaian telah diambil!"<<endl;
      }
        else{
        before = Head;
        do{
            prev=before;
            before=before->next;
        }while(before->kodepakaian!=kode);
        posisi=before;
        prev->next=before->next;
        delete posisi;
        cout<<"Pakaian telah diambil!"<<endl;
       }
    }
    else
    {
        system("cls");
        cout<<"Masukkan dengan benar!!"<<endl;
        goto up;
    }
}

void tampilkan()
{
 if((Head==NULL)&&(Tail==NULL))
 {
      cout<<"MAAF! Pakaian Tidak Tersedia! Silahkan Diisi terlebih dahulu"<<endl;
 }
 else{
 Main = Head;
 cout<<"=======================================================\n";
 cout<<"|  Kode  |          Nama Pakaian      | Tipe Pakaian | \n";
 cout<<"=======================================================\n";
  while(Main!=NULL){
   cout<<"| "<<setiosflags(ios::left)<<setw(5)<<Main->kodepakaian<<"|";
   cout<<" "<<setiosflags(ios::left)<<setw(25)<<Main->namapakaian<<"|";
   if((Main->kodepakaian>=1000)&&(Main->kodepakaian<=1999))
   {cout<<" "<<setiosflags(ios::left)<<setw(8)<<"Atasan"<<"|";}
   else if((Main->kodepakaian>=2000)&&(Main->kodepakaian<=2999))
   {cout<<" "<<setiosflags(ios::left)<<setw(8)<<"Bawahan"<<"|";}
   cout<<"\n=======================================================\n";
   Main = Main->next;
     }
 }


}

void detail()
{
    int kode;
    cout<<endl<<endl;
    cout<<"Atasan : 1xxx (1000-1999)"<<endl;
    cout<<"Bawahan : 2xxx (2000-2999)"<<endl;
    kod:
    cout<<"Cari pakaian yang ingin dicari (berdasarkan kode) : ";cin>>kode;
    Main=Head;

    while((Main->kodepakaian!=kode)&&(Main!=NULL))
    {
        Main = Main->next;
    }


    if(kode==Main->kodepakaian)
    {
        system("cls");
        cout<<"Ukuran : "<<endl;
        cout<<"===================================="<<endl;
        cout<<"Kode Pakaian : "<<Main->kodepakaian<<endl;
        cout<<"Nama Pakaian : "<<Main->namapakaian<<endl;

        switch(Main->Ukuran){
        case 1:
            cout<<"Ukuran : "<<"XS"<<endl;
            break;
        case 2:
            cout<<"Ukuran : S"<<endl;
            break;
        case 3:
            cout<<"Ukuran : M"<<endl;
            break;
        case 4:
            cout<<"Ukuran : L"<<endl;
            break;
        case 5:
            cout<<"Ukuran : XL"<<endl;
            break;
        case 6:
            cout<<"Ukuran : XXL"<<endl;
            break;
        case 7:
            cout<<"Ukuran : XXXL"<<endl;
            break;
        }

        cout<<"Warna : "<<Main->warna<<endl;
        cout<<"===================================="<<endl;
    }
    else
    {
        cout<<"Pakaian tak tersedia"<<endl;
        getch();
        goto kod;

    }

    cout<<"Tekan enter untuk kembali"<<endl;


}




