#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAX 10
typedef struct{
    int id;
    char nama[50]; 
}itemtype;  

typedef struct {
    itemtype item [MAX]; 
    int front; 
    int rear; 
    int count;
} queue; 

void inisialisasi (queue *q) {
    q->front = 0; 
    q->rear = -1; 
    q->count = 0;
}

int penuh (queue *q) {
    return (q->count == MAX);  
}

int kosong (queue *q) {
    return (q->count == 0); 
}

void enqueue (queue *q, itemtype x) { 
    if (penuh(q)) {
        printf("Antrian printer penuh!\n");
        printf("========================================\n");
        return; 
    }

    q->rear = (q->rear +1) % MAX; 
    q->item[q->rear] = x; 
    q->count++; 
    printf ("Dokumen [%d - %s] telah masuk antrian\n", x.id, x.nama);
    printf("========================================\n");
}

itemtype dequeue (queue *q) {
    itemtype kosong_item = {-1,""};
    
    if(kosong(q)) {
        printf("Antrian kosong\n"); 
        printf("========================================\n");
        return kosong_item; 
    }

    itemtype temp = q->item[q->front]; 
    
    q->front = (q->front + 1) % MAX; 
    q->count--;
    return temp; 
}

void menu() { 
    printf("\n=== Menu Antrian Printer ===\n");
    printf("1. Masukkan Dokumen(Enqueue)\n");
    printf("2. Mencetak Dokumen(Dequeue)\n");
    printf("3. Tampilkan Antrian\n");
    printf("0. Keluar\n");
    printf("===========================\n");
}

void tampil(queue *q) {
    if (kosong(q)) {
        printf("Antrian kosong!\n");
        return;
    }
    printf("========================================\n");
    printf("Daftar Antrian Printer:\n");
    for (int i = 0; i < q->count; i++) {
        int index = (q->front + i) % MAX;

        printf("%d. ID: %d, Nama: %s\n", i+1, q->item[index].id, q->item[index].nama);
    }
    printf("========================================\n");
}

int main() { 
    queue q; 
    inisialisasi(&q);
    int pilihan; 
    itemtype dokumen;
    do { 
        menu(); 
        printf("Pilih menu : "); 
        scanf("%d", &pilihan); 
        switch (pilihan) {
            case 1: 
            printf("========================================\n");
            
            printf("Masukkan ID dokumen yang ingin dicetak: ");
            scanf("%d", &dokumen.id); 

            printf("Masukkan nama dokumen: ");
            scanf(" %[^\n]", dokumen.nama);

            printf("========================================\n");
            
            enqueue(&q, dokumen); 
            break;
            
            case 2: {
                itemtype cetak = dequeue(&q); 
                if (cetak.id != -1) {
                    printf("========================================\n");
                    printf("Mencetak dokumen : \n");
                    printf("ID: %d\nNama: %s\n", cetak.id, cetak.nama); 
                    printf("========================================\n");
                }
                break;
            }
            case 3: 
            tampil(&q); 
            break;

            case 0: 
            printf("Keluar dari program.\n");
            printf("========================================\n");
                break;

            default: 
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                printf("========================================\n");
        }
    }
    while (pilihan != 0); 
    return 0;
}