#ifndef GRAPHICS_H
#define GRAPHICS_H

struct patch_t;

struct inpt_t;

void  CreateBaseWindow ();

void  LoadHacking      ();

void  Graphics         (const char* wallpaper);

char* InputNameOfFile  ();

bool  CheckHash  (patch_t patch, inpt_t input);

bool  CheckNameOfFile  (patch_t patch, inpt_t input);

void  CorrectFile      ();

#endif
