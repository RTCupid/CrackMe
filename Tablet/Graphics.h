#ifndef GRAPHICS_H
#define GRAPHICS_H

void  CreateBaseWindow ();

void  LoadHacking      ();

void  Graphics         (const char* wallpaper);

char* InputNameOfFile  ();

bool  CheckNameOfFile  (char* OriginalNameOfPatchFile, char* InputNameFile);

void  CorrectFile      ();

#endif
