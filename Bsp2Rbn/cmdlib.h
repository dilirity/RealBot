/***
*
*  Copyright (c) 1998, Valve LLC. All rights reserved.
*
*  This product contains software technology licensed from Id
*  Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc.
*  All Rights Reserved.
*
****/

// cmdlib.h

#ifndef __CMDLIB__
#define __CMDLIB__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>

#ifndef __CMDUTIL__
#define __CMDUTIL__

typedef int qboolean;
#undef true
#undef false
#define true 1
#define false 0

typedef unsigned char byte;

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#endif // CMDUTIL

// the dec offsetof macro doesn't work very well...
#define myoffsetof(type,identifier) ((size_t)&((type *)0)->identifier)

// set these before calling CheckParm
extern int myargc;
extern char** myargv;

char* strupr(char* in);
char* strlower(char* in);
int Q_strncasecmp(char* s1, char* s2, int n);
int Q_strcasecmp(char* s1, char* s2);
void Q_getwd(char* out);

int filelength(FILE* f);
int FileTime(char* path);

void Q_mkdir(char* path);

extern char qdir[1024];
extern char gamedir[1024];
void SetQdirFromPath(char* path);
char* ExpandArg(char* path); // from cmd line
char* ExpandPath(char* path); // from scripts
char* ExpandPathAndArchive(char* path);

double I_FloatTime(void);

void Error(char* error, ...);
int  CheckParm(char* check);

FILE* SafeOpenWrite(char* filename);
FILE* SafeOpenRead(char* filename);
void SafeRead(FILE* f, void* buffer, int count);
void SafeWrite(FILE* f, void* buffer, int count);

int  LoadFile(char* filename, void** bufferptr);
void SaveFile(char* filename, void* buffer, int count);

void DefaultExtension(char* path, char* extension);
void DefaultPath(char* path, char* basepath);
void StripFilename(char* path);
void StripExtension(char* path);

void ExtractFilePath(char* path, char* dest);
void ExtractFileBase(char* path, char* dest);
void ExtractFileExtension(char* path, char* dest);

int  ParseNum(char* str);

short BigShort(short l);
short LittleShort(short l);
int   BigLong(int l);
int   LittleLong(int l);
float BigFloat(float l);
float LittleFloat(float l);

long flen(FILE* f);

char* COM_Parse(char* data);

extern char     com_token[1024];
extern qboolean com_eof;

char* copystring(char* s);

void CRC_Init(unsigned short* crcvalue);
void CRC_ProcessByte(unsigned short* crcvalue, byte data);
unsigned short CRC_Value(unsigned short crcvalue);

void CreatePath(char* path);
void QCopyFile(char* from, char* to);

extern qboolean   archive;
extern char       archivedir[1024];

extern qboolean verbose;
void qprintf(char* format, ...);

typedef struct
{
	char  name[56];
	int   filepos, filelen;
} packfile_t;

typedef struct
{
	char  id[4];
	int   dirofs;
	int   dirlen;
} packheader_t;

void ListPak(char* pakname);

#endif  // CMDLIB
