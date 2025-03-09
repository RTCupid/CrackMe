#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include "../common/colors.h"
#include "FreadFile.h"

#define DBG if(1)

// читаю из файла в буффер текст Онегина и определяю размер буффера

bool InputOnegin (MP* Ongn)//char** Onegin, size_t* sizeOfFile, const char* nameFile)
{
    struct stat fileInf = {};

    if (!SizeFile (&fileInf, Ongn->nameFile))
    {
        printf ("Error SizeFile!");
        return 0;
    }

    DBG printf (GRN "count of char = %ld\n" RESET, fileInf.st_size / sizeof (char));

    printf (GRN "Onegin isn't create\n" RESET);

    *Ongn->HackBuffer = (char*)calloc (fileInf.st_size + 1, sizeof(char));     // каллочу буффер, чтобы в него считать текст

    printf (GRN "Onegin is create\n" RESET);

    if (Ongn->HackBuffer == NULL)
    {
        printf ("Onegin = NULL");
        return 0;
    }

    FILE* file = fopen (Ongn->nameFile, "rb+");

    if (file == NULL)
    {
        printf ("File opening error\n");
        printf("errno = <%d>\n", errno);
        perror(Ongn->nameFile);
        return 0;
    }

    Ongn->sizeOfFile = fread (*Ongn->HackBuffer, sizeof (char), fileInf.st_size, file); // с помощью fread читаю файл в буффер, сохраняю возвращаемое значение fread ()

    if (Ongn->sizeOfFile == 0)
    {
        printf ("errno = <%d>\n", errno);
        perror (Ongn->nameFile);
        return 0;
    }

    printf ("\n%s\n", *Ongn->HackBuffer);                                      // вывожу начальный текст Онегина

    printf (GRN "Ongn->HackBuffer = %p\n"  RESET,  Ongn->HackBuffer);
    printf (GRN "*Ongn->HackBuffer = %p\n" RESET, *Ongn->HackBuffer);

    fclose (file);                                                   // закрываю файл

    DBG printf ("sizeOfFile = <%d>\n\n", Ongn->sizeOfFile);
    return 1;
}

// функция определения размера файла с помощью стата

bool SizeFile (struct stat* fileInf, const char* nameFile)
{
    int err = stat (nameFile, fileInf);
    if (err != 0)
    {
        printf("Stat err %d\n", err);
        return 0;
    }

    DBG printf ("\n%ld\n", (*fileInf).st_size);
    DBG printf ("count of char = %ld\n", (*fileInf).st_size / sizeof (char));
    return 1;
}
