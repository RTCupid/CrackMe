#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#include "crack.h"
#include "colors.h"
#include "../Tablet/Graphics.h"
#include "../FreadFile/FreadFile.h"

bool CheckArgc (int argc)
{
    if (argc > 1)
    {
        printf (GRN "OK, START!\n" RESET);
        return 1;
    }
    else
    {
        printf (RED "Don't find file of patch\n" RESET);
        return 0;
    }
}

//---------------------------------------------------------

bool PatchCtor (patch_t* patch, char* patch_file)
{
    patch->file = fopen (patch_file, "r");
    if (!patch->file)
    {
        printf (RED "PatchCtor: can't open file of patch\n" RESET);
        return 0;
    }
    printf (GRN "OK, open file patch\n" RESET);

    patch->name = (char*) calloc (MAX_LEN_NAME_FILE, sizeof (*patch->name));

    assert (patch->name != NULL);
    printf (GRN "patch->name = %p\n" RESET, patch->name);

    fscanf (patch->file, "%s", patch->name);

    printf (GRN "OK, make name patch\n patch->name = <%s>" RESET, patch->name);

    assert (&patch->hash != NULL);

    printf (GRN "&patch->hash = %p\n patch->hash = %u\n" RESET, &patch->hash, patch->hash);

    fscanf (patch->file, "%u", &patch->hash);

    printf (GRN "OK, make struct patch\n" RESET);

    return 1;
}

//---------------------------------------------------------

bool InptCtor (inpt_t* input)
{
    input->name = InputNameOfFile ();                               // Input name of file from dialog window
    if (!input->name)
    {
        printf (RED "InptCtor: error of input name of file\n" RESET);
        return 0;
    }

    input->buffer = NULL;

    struct MP Ongn                                                  // buffer's structure
    {
        &input->buffer,
        0,
        input->name,
    };

    input->size = InputOnegin (&Ongn);

    if (!input->size)                                               // func to find len of file
    {                                                               // and make buffer from file
        printf (RED "ERROR: CAN'T MAKE BUFFER FROM FILE\n" RESET);
        return 0;
    }

    input->hash = HashCount (input->size, input->buffer);

    printf (GRN "OK, hash = %u\n" RESET, input->hash);

    printf (GRN "OK, make struct input\n" RESET);

    return 1;
}

//---------------------------------------------------------

size_t HashCount (size_t size, char* buffer)
{
    char   symbol  = 0;
    size_t hash    = 0;

    symbol = buffer[0];

    for (size_t index = 1; index < size; index++, symbol = buffer[index])
    {
        //printf ("symbol = <%c>, symbol = <%d>\n", symbol, symbol);
        //hash += (size_t) pow (symbol, 2);
        hash += (size_t) abs (symbol);
        //printf ("hash = <%u>\n", hash);
    }

    return hash;
}

//---------------------------------------------------------

bool PatchDtor (patch_t* patch)
{
    free (patch->file);
    patch->file = NULL;

    free (patch->name);
    patch->name = NULL;

    free (patch);
    patch = NULL;

    return 1;
}

bool InptDtor (inpt_t* input)
{
    free (input->buffer);
    input->buffer = NULL;

    free (input->name);
    input->name = NULL;

    free (input);
    input = NULL;

    return 1;
}
