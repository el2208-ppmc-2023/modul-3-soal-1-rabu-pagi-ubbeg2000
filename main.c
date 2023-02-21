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

int absen(int absen)
{
    // menentukan status lulus
    int status_lulus;
    if (absen >= 75)
    {
        status_lulus = 1;
    }
    else
    {
        status_lulus = 0;
    }
    // return status lulus
    return status_lulus;
}

int nilai(int tugas, int ujian, int tubes)
{
    // menghitung nilai akhir
    int nilai_akhir = 0.5 * tugas + 0.35 * ujian + 0.25 * tubes;
    // return nilai akhir
    return nilai_akhir;
}

int main()
{
    // inisialisasi
    char indeks[3];
    int NIM;

    // inisialisasi file
    char file[255];
    printf("Masukkan file: ");
    scanf("%s", file);
    FILE *stream = fopen(file, "r");
    if (stream == NULL)
    {
        printf("\nFile tidak ada!");
        return 0;
    }

    // Coredata
    char line[255];
    char *token;
    int i = 0;

    fgets(line, 255, stream);
    token = strtok(line, "\n");
    int N = atoi(token);
    if (N == 0)
    {
        printf("\nFile tidak ada!");
        return 0;
    }
    int matriks[N][5];

    while (fgets(line, 255, stream))
    {
        token = strtok(line, ",");
        matriks[i][0] = atoi(token);
        token = strtok(NULL, ",");
        matriks[i][1] = atoi(token);
        token = strtok(NULL, ",");
        matriks[i][2] = atoi(token);
        token = strtok(NULL, ",");
        matriks[i][3] = atoi(token);
        token = strtok(NULL, "\n");
        matriks[i][4] = atoi(token);
        i++;
    }

    // input
    printf("Masukkan NIM: ");
    scanf("%d", &NIM);

    // proses
    i = 0;
    while (matriks[i][0] != NIM && i != N)
    {
        i++;
    }

    int nilai_akhir = nilai(matriks[i][2], matriks[i][3], matriks[i][4]);
    int kelulusan = absen(matriks[i][1]);

    if (90 <= nilai_akhir)
    {
        strcpy(indeks, "A");
    }
    else if (80 <= nilai_akhir && nilai_akhir < 90)
    {
        strcpy(indeks, "AB");
    }
    else if (75 <= nilai_akhir && nilai_akhir < 80)
    {
        strcpy(indeks, "B");
    }
    else if (65 <= nilai_akhir && nilai_akhir < 75)
    {
        strcpy(indeks, "BC");
    }
    else if (55 <= nilai_akhir && nilai_akhir < 65)
    {
        strcpy(indeks, "C");
    }
    else if (50 <= nilai_akhir && nilai_akhir < 55)
    {
        strcpy(indeks, "D");
    }
    else
    {
        strcpy(indeks, "E");
    }

    // output
    if (i == N)
    {
        printf("\nNIM tidak ada!");
    }
    else if (kelulusan && nilai_akhir >= 55)
    {
        printf("\nNIM %d lulus dengan indeks %s", NIM, indeks);
    }
    else
    {
        printf("\nNIM %d tidak lulus dengan indeks %s", NIM, indeks);
    }

    return 0;
}
