#include <stdio.h>
#include <string.h>

#define MAX 5 // Baki printer cuma muat 5 lembar kertas

typedef struct {
    char jenis[20];
    char ukuran[10];
    char warna[15];
} Kertas;

typedef struct {
    Kertas lembar[MAX]; // Tempat naruh tumpukan kertas
    int isi;            // Menghitung ada berapa lembar kertas di baki
} Baki;

void inisialisasi(Baki *b) {
    b->isi = 0; // Awalnya baki kosong
}

void isi_kertas(Baki *b) {
    if (b->isi == MAX) {
        printf("\n[!] Baki sudah penuh\n");
    } else {
        printf("\n--- Masukkan Kertas ke Baki ---\n");
        // Kertas ditaruh di atas kertas yang sudah ada (sesuai jumlah isi sekarang)
        printf("Jenis Kertas: "); scanf("%s", b->lembar[b->isi].jenis);
        printf("Ukuran Kertas: "); scanf("%s", b->lembar[b->isi].ukuran);
        printf("Warna Kertas: "); scanf("%s", b->lembar[b->isi].warna);
        
        b->isi++; // Jumlah kertas di baki bertambah
        printf("=> Kertas ditaruh di tumpukan paling atas.\n");
    }
}

void ambil_kertas(Baki *b) {
    if (b->isi == 0) {
        printf("\n[!] Kertas habis! Isi dulu bakinya.\n");
    } else {
        // Ambil kertas yang paling terakhir ditaruh (posisinya di paling atas)
        b->isi--; 
        Kertas diambil = b->lembar[b->isi];
        
        printf("\n--- Mesin Menarik Kertas ---\n");
        printf("Kertas yang diambil: %s %s warna %s\n", 
            diambil.jenis, diambil.ukuran, diambil.warna);
        printf("=> Kertas teratas berhasil masuk ke ruang cetak.\n");
    }
}

void cek_baki(Baki *b) {
    if (b->isi == 0) {
        printf("\n[!] Bakinya kosong, tidak ada kertas.\n");
    } else {
        printf("\n=== ISI BAKI (DARI ATAS KE BAWAH) ===\n");
        // Kita lihat dari urutan paling atas (jumlah isi dikurangi 1) ke bawah
        for (int i = b->isi - 1; i >= 0; i--) {
            printf("Lapis ke-%d: %s %s (%s)\n", 
                i + 1, b->lembar[i].jenis, b->lembar[i].ukuran, b->lembar[i].warna);
        }
    }
}

int main() {
    Baki b;
    int menu;
    inisialisasi(&b);

    do {
        printf("\n--- MANAJEMEN BAKI KERTAS ---\n");
        printf("1. Isi Kertas Baru\n");
        printf("2. Ambil Kertas (Cetak)\n");
        printf("3. Intip Isi Baki\n");
        printf("4. Keluar\n");
        printf("Pilih: "); scanf("%d", &menu);
        
        if(menu == 1) isi_kertas(&b);
        else if(menu == 2) ambil_kertas(&b);
        else if(menu == 3) cek_baki(&b);
    } while (menu != 4);
    return 0;
}