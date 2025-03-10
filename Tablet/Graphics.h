#ifndef GRAPHICS_H
#define GRAPHICS_H

void  CreateBaseWindow ();

void  LoadHacking      ();

void  Graphics         (const char* wallpaper);

char* InputNameOfFile  ();

bool  CheckNameOfFile  (FILE* PatchingFile, char* InputNameFile);

void  CorrectFile      ();

#endif
