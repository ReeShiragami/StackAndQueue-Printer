#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
typedef int Itemtype ; //Mendeklarasikan tipe bentukan Stack
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
    } else {
        s->item[s->count] = x; // Menambahkan elemen ke Stack
        s->count++; // Meningkatkan jumlah elemen dalam Stack
    }
}

Itemtype Pop (Stack *s)
{
   Itemtype temp; //Menyimpan elemen yang akan di-pop
   if(Kosong(s)) {
      printf("Stack Kosong\n");
      return ' ';// Mengembalikan nilai kosong jika Stack kosong
   }
   else {
      s->count--;
      temp=s->item[s->count];
      return(temp);// Mengembalikan elemen yang di-pop
   }
}