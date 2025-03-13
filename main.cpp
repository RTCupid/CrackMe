#include <stdio.h>
#include <stdlib.h>

#include "common/crack.h"
#include "common/colors.h"
#include "Tablet/Tablet.h"
#include "Tablet/Graphics.h"

int main (int argc, char* argv[])
{
    printf (GRN "# Program for Hacking .com file\n" RESET);
    printf (GRN "# (c) RTCupid, 2025\n" RESET);

    if (!CheckArgc (argc))
    {
        printf (RED "main: argc = 0\n exit\n" RESET);
        exit (0);
    }

    patch_t patch = {};

    if (!PatchCtor (&patch, argv[1]))
    {
        printf (RED "main: can't construct patch\n exit\n" RESET);
        printf (RED "exit\n" RESET);
        exit (0);
    }

    inpt_t input = {};

    if (!InptCtor (&input))
    {
        printf (RED "main: can't construct input\n" RESET);
        printf (RED "exit\n" RESET);
        exit (0);
    }

    return 0;

    FILE* PatchingFile = fopen (argv[1], "r");

    CreateBaseWindow ();

    Graphics ("bmp/1.bmp");                                         // Make wallpaper

    char* InputNameFile = InputNameOfFile ();                       // Input name of file from dialog window
    if (InputNameFile == NULL)
    {
        printf (RED "ERROR: InputNameOfFile\n" RESET);
        return 0;
    }

    char* OriginalNameOfPatchFile = (char*) calloc (30, sizeof (*OriginalNameOfPatchFile));

    fscanf (PatchingFile, "%s", OriginalNameOfPatchFile);

    if (!CheckNameOfFile (OriginalNameOfPatchFile, InputNameFile))
    {
        return 0;
    }

    //uint64_t OriginalHash = 0;

    //fscanf (PatchingFile, "%lu", OriginalNameOfPatchFile);

    //if (!CheckHash (OriginalHash, InputNameFile))
    //{
    //    return 0;
    //}


    if (!Tablet (PatchingFile, OriginalNameOfPatchFile))
    {
        printf (RED "ERROR: CAN'T HACK FILE" RESET);
        return 0;
    }

    LoadHacking ();

    CorrectFile ();

    free (OriginalNameOfPatchFile);
    free (PatchingFile);

    bool PatchDtor ();

    return 0;
}

/*-D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ \
	-Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations \
	-Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion \
	-Wctor-dtor-privacy -Wempty-body -Wformat-nonliteral -Wformat-security \
	-Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd \
	-Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow \
	-Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 \
	-Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand \
	-Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers \
	-Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector \
	-fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=580192 -Wstack-usage=8192 -pie -fPIE -Werror=vla \
	-fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,$\
	nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,$\
	signed-integer-overflow,undefined,unreachable,vla-bound,vptr*/

/*-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal \
	-Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum \
	-Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion \
	-Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op \
	-Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo \
	-Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla \
	-D_DEBUG -D_EJUDGE_CLIENT_SIDE*/
