#include <stdio.h>
#include <stdlib.h>

#include "common/colors.h"
#include "FreadFile/FreadFile.h"

int main ()
{
    printf (GRN "# Program for Hacking .com file\n" RESET);
    printf (GRN "# (c) RTCupid, 2025\n" RESET);

    char* HackBuffer = NULL;

    struct MP Ongn
    {
        &HackBuffer,
        0,
        "DimaMorg/CRACK.COM",
    };

    if (!InputOnegin (&Ongn))
    {
        printf (RED "ERROR: CAN'T OPEN FILE" RESET);
        return 0;
    }
    printf (GRN "%s\n" RESET, *Ongn.HackBuffer);

    (*Ongn.HackBuffer)[97] = char(144);                               // jz -> jmp in CRACKME.COM

    FILE* Hacked_file = fopen ("DimaMorg/HACKED_CRACKME.COM", "w");

    fwrite (*Ongn.HackBuffer, sizeof (char), Ongn.sizeOfFile, Hacked_file);

    fclose (Hacked_file);

    free (*Ongn.HackBuffer);

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
