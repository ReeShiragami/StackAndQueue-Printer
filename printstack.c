#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
typedef struct{
   int id; 
   char nama[50];
} Itemtype ; //Mendeklarasikan tipe bentukan Stack
typedef  struct {
   Itemtype item[MAX];
   int count;
}Stack;

void Inisialisasi (Stack *s){
	s->count=0;//Agar Stack kosong pada awalnya
}

int Penuh (Stack *s){
   return (s->count==MAX); //Jika count sama dengan MAX, maka Stack penuh
}

int Kosong (Stack *s){
   return (s->count==0);//Jika count sama dengan 0, maka Stack kosong 
}

void Push (Stack *s, Itemtype x) {
    if (Penuh(s)) {
        printf("Stack penuh! Tidak dapat menambahkan elemen.\n");
    } 
    else {
        s->item[s->count] = x; // Menambahkan elemen ke Stack
        s->count++; // Meningkatkan jumlah elemen dalam Stack
        printf("Dokumen [%d - %s] telah masuk antrian\n", x.id, x.nama);
    }
}

Itemtype Pop (Stack *s)
{
   Itemtype kosong_item = {-1, ""}; //Menyimpan nilai kosong jika Stack kosong

   Itemtype temp; //Menyimpan elemen yang akan di-pop
   if(Kosong(s)) {
      printf("Stack Kosong\n");
      return kosong_item;// Mengembalikan nilai kosong jika Stack kosong
   }

   else {
      s->count--;
      temp=s->item[s->count];
      return(temp);// Mengembalikan elemen yang di-pop
   }
}

void menu() {
      printf("\n=== Menu Stack ===\n");
      printf("1. Masukan Dokumen(Push)\n");
      printf("2. Mencetak Dokumen(Pop)\n");
      printf("3. Tampilkan Antrian \n");
      printf("0. Keluar\n");
      printf("==================\n");
}

void tampil(Stack *s) {
   if (Kosong(s)) {
      printf("Stack kosong");
   } 
   else{
      printf("Isi Stack (Prioritas Atas):\n"); 
      for (int i = s->count -1; i >= 0; i--) {
         printf("%d. ID: %d, Nama: %s\n", s->count - i, s->item[i].id, s->item[i].nama);
      }
   }
   printf("========================================\n");
}

int main () {
   Stack s; 
   Inisialisasi(&s); 
   int pilihan; 
   Itemtype elemen; 
   do
   {
      menu(); 
      printf("Pilih menu: ");
      scanf("%d", &pilihan); 
      switch (pilihan) {
         case 1: 
            printf("========================================\n");
            printf("Masukkan ID dokumen yang ingin ditambahkan: ");
            scanf("%d", &elemen.id);
            printf("Masukkan nama dokumen yang ingin ditambahkan: ");
            scanf(" %[^\n]", elemen.nama); // Membaca string dengan spasi 
            Push(&s, elemen); //menambahkan elemen ke stack
            break;
         
         case 2: 
            {
               Itemtype hasilPop = Pop(&s); //menghapus elemen dari stack
               if (hasilPop.id != -1) {
                  printf("========================================\n");
                  printf("Mencetak dokumen\n");
                  printf("ID: %d\nNama: %s\n", hasilPop.id, hasilPop.nama);
                  printf("========================================\n");
               }
               break; 
            }

         case 3: 
            tampil(&s); //menampilkan isi stack
            break; 

         case 0: 
            printf("Keluar dari program.\n"); 
            break; 
            
         default: 
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
      }
   } while (pilihan !=0 );
   return 0; 
}
