/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int absen(int absen) {
    // menentukan status lulus

    // return status lulus
    return 0;
}

int nilai(int tugas, int ujian, int tubes) {
    // menghitung nilai akhir

    // return nilai akhir
    return 0;
}

int main() {
    // inisialisasi

    // proses input file
    char file[255];
    printf("Masukkan file: "); scanf("%s", &file);
    FILE* stream = fopen(file, "r");

    // data
    char line[255]; char* token; int i = 0;

    fgets(line, 255, stream);
    token = strtok(line, "\n");
    int N = atoi(token);
    int matriks[N][5];

    while(fgets(line, 255, stream)) {
        token = strtok(line, ",");  matriks[i][0] = atoi(token);
        token = strtok(NULL, ",");  matriks[i][1] = atoi(token);
        token = strtok(NULL, ",");  matriks[i][2] = atoi(token);
        token = strtok(NULL, ",");  matriks[i][3] = atoi(token);
        token = strtok(NULL, "\n"); matriks[i][4] = atoi(token);
        i++;
    }
   
    // input NIM
    // printf("Masukkan NIM: ");
    // scanf("%d", ...);

    // proses

    // output
    // printf("File tidak ada!");
    // printf("NIM tidak ada!");
    // printf("NIM %d lulus dengan indeks %s", ..., ...);
    // printf("NIM %d tidak lulus dengan indeks %s", ..., ...);

    return 0;
}
