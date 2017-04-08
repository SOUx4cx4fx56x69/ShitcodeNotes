#include<stdio.h>
#include<string.h>
#define NOTE_FILE "NOTES.TXT"
main(int argCount,char**arg)
{
FILE*notes=fopen(NOTE_FILE,"a+");
if(notes==NULL) return error("File not found!");
if(argCount !=1) return writeToFile(notes,argCount,arg);
return ReadFromFile(notes);
}
