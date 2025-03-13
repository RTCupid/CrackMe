#ifndef GRAPHICS_H
#define GRAPHICS_H

void  CreateBaseWindow ();

void  LoadHacking      ();

void  Graphics         (const char* wallpaper);

char* InputNameOfFile  ();

bool  CheckNameOfFile  (char* OriginalNameOfPatchFile, char* InputNameFile);

//bool  CheckHash        (uint64_t OriginalHash, char* InputNameFile);

//uint64_t CountHash     (char* InputNameFile);

void  CorrectFile      ();

#endif
