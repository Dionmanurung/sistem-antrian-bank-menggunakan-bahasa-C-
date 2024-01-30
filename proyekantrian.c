#include <stdio.h>
#include <stdlib.h>  //MENGGUNAKAN SYSTEM("CLS)
#include <stdbool.h> //MENGGUNAKAN BOOLEAN
#define MAX 1000     // MAKSIMAL NOMOR ANTRIAN

int nomer[MAX];
int head = -1, tail = -1;
int a;
bool IsEmpty()
{ // FUNGSI UNTUK MENUNJUKAN JIKA TAIL = -1
    if (tail == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool IsFull()
{ // FUNGSI UNTUK MENUNJUKAN JIKA TAIL = MAX-1
    if (tail == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void AntrianMasuk(int no)
{
    if (IsEmpty())
    {
        head = tail = 0;
    }
    else
    {
        tail++;
    }
    nomer[tail] = no;
}
void AntrianKeluar()
{
    if (IsEmpty())
    {
        printf("Antrian sudah kosong ! ");
        getchar();
    }
    else
    {
        for (a = head; a < tail; a++)
        {
            nomer[a] = nomer[a + 1];
        }
        tail--;
        if (tail == -1)
        {
            head = -1;
        }
    }
}
void Clear()
{
    head = tail = -1;
}
void View()
{
    if (IsEmpty())
    {
        printf("Antrian kosong ! ");
    }
    else
    {
        system("cls");
        for ( a = head; a <= tail; a++)
        {
            printf("===============================\n");
            printf("\n No. Antri : %d\n", nomer[a]);
            printf("\n===============================\n");
        }
    }
}

int main()
{
    system("color 79");
    int choose, p = 1, urut;
    do
    {
        system("cls");
        printf("\n\n===== PROGRAM ANTRIAN C++ =====");
        printf("\n===============================");
        printf("\n|1. Tambah Antrian            |");
        printf("\n|2. Panggil Antrian           |");
        printf("\n|3. Lihat daftar antrian      |");
        printf("\n|4. Format                    |");
        printf("\n|5. Exit                      |");
        printf("\n===============================");
        printf("\nChoose ! ");
        scanf("%d", &choose);
        printf("\n\n");
        if (choose == 1)
        {
            if (IsFull())
            {
                printf("Antrian sudah penuh, mohon tunggu beberapa saat lagi ");
            }
            else
            {
                urut = p;
                AntrianMasuk(urut);
                printf("\t---------------------------------\n");
                printf("\t|          NO. ANTRIAN          |\n");
                printf("\t|              %d               |\n", p);
                printf("\t---------------------------------\n");
                printf("\t|       Silahkan Mengantri      |\n");
                printf("\tMenunggu %d Antrian ||\n", tail);
                printf("\t---------------------------------");
                p++;
            }
        }
        else if (choose == 2)
        {
            printf("=================================\n");
            printf("No. Antri : %d\n", nomer[head]);
            printf("\n=================================\n");
            AntrianKeluar();
            printf("Silahkan Dipanggil !");
        }
        else if (choose == 3)
        {
            View();
        }
        else if (choose == 4)
        {
            Clear();
            printf("Antrian dikosongkan ! ");
        }
        else if (choose == 5)
        {
        }
        else
        {
            printf("Masukan anda salah ! \n");
        }
        getchar();
    } while (choose != 5);
    return 0;
}