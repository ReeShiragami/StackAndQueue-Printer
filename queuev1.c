#include <stdio.h>
#include <string.h>

#define MAX 5 // Maksimal hanya bisa menampung 5 dokumen di daftar tunggu

typedef struct {
    char namaPemilik[30];
    char namaFile[30];
    int halaman;
} Dokumen;

typedef struct {
    Dokumen item[MAX]; 
    int depan;   // Penanda dokumen mana yang harus dicetak sekarang
    int belakang; // Penanda tempat untuk menaruh dokumen baru yang masuk
    int jumlah;   // Menghitung berapa banyak dokumen yang sedang mengantre
} Antrean;

void inisialisasi(Antrean *q) {
    q->depan = 0;
    q->belakang = -1;
    q->jumlah = 0; // Awalnya antrean kosong
}

void tambah_antrean(Antrean *q) {
    if (q->jumlah == MAX) {
        printf("\n[!] Antrean penuh! Tunggu sampai ada yang selesai dicetak.\n");
    } else {
        // Biar antrean bisa kembali ke nomor 0 kalau sudah sampai batas maksimal
        q->belakang = (q->belakang + 1) % MAX; 
        
        printf("\n--- Input Data Dokumen ---\n");
        printf("Nama Pemilik: "); scanf("%s", q->item[q->belakang].namaPemilik);
        printf("Nama File   : "); scanf("%s", q->item[q->belakang].namaFile);
        printf("Jumlah Hal  : "); scanf("%d", &q->item[q->belakang].halaman);
        
        q->jumlah++; // Dokumen bertambah di daftar
        printf("=> Dokumen berhasil masuk daftar tunggu.\n");
    }
}

void proses_cetak(Antrean *q) {
    if (q->jumlah == 0) {
        printf("\n[!] tidak ada yang perlu dicetak, antrean kosong.\n");
    } else {
        // Ambil data yang paling depan
        Dokumen data = q->item[q->depan];
        
        printf("\n--- Sedang Mencetak ---\n");
        printf("Mencetak file: %s punya si %s\n", data.namaFile, data.namaPemilik);
        printf("Estimasi: %d menit...\n", data.halaman * 1);
        
        // Geser penanda depan ke dokumen selanjutnya dalam antrean
        q->depan = (q->depan + 1) % MAX;
        q->jumlah--; // Dokumen berkurang karena sudah selesai dicetak
        printf("=> Selesai! Dokumen sudah keluar dari mesin.\n");
    }
}

void lihat_daftar(Antrean *q) {
    if (q->jumlah == 0) {
        printf("\n[!] Antrean kosong melompong.\n");
    } else {
        printf("\n=== DAFTAR TUNGGU CETAK ===\n");
        for (int i = 0; i < q->jumlah; i++) {
            // Cara nyari posisi dokumen biar urut dari yang paling lama mengantre
            int posisi = (q->depan + i) % MAX; 
            printf("%d. File: %s (Pemilik: %s)\n", 
                i + 1, q->item[posisi].namaFile, q->item[posisi].namaPemilik);
        }
    }
}

int main() {
    Antrean q;
    int menu;
    inisialisasi(&q);

    do {
        printf("\n--- MENU ANTRIAN PRINTER ---\n");
        printf("1. Masukkan Dokumen Baru\n");
        printf("2. Cetak Dokumen Sekarang\n");
        printf("3. Lihat Daftar Antrean\n");
        printf("4. Tutup Program\n");
        printf("Pilih: "); scanf("%d", &menu);
        
        if(menu == 1) tambah_antrean(&q);
        else if(menu == 2) proses_cetak(&q);
        else if(menu == 3) lihat_daftar(&q);
    } while (menu != 4);
    return 0;
}