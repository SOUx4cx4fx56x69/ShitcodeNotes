typedef FILE;
//typedef size_t;
#include<time.h>
#define NULL 0
#define SEEK_END 2
writeToFile(FILE*file,int c, char**array)
{
//char * tmp;
//for time
char tmp_time[114];
time_t rtime;
time (&rtime);
strftime (tmp_time, 114, "In %Y-%m-%d %H:%M:%S You write:", localtime (&rtime));
fwrite(tmp_time, strlen(tmp_time), 1, file);
fwrite("\n",1,sizeof("\n"),file);
//
for(int i=1; i!=c; i++)
{
 // tmp = (char*)calloc( sizeof(char), strlen(array[i]) );
  fwrite(array[i], strlen(array[i]), 1, file);
}
fwrite("\n",1,sizeof("\n"),file);
//
printf("Succefully write\n");
printf("now file look as: \n");
//
ReadFromFile(file);
fclose(file);
}

size_t getSizeFile(FILE*file)
{
 fseek(file,0,SEEK_END);
 size_t tmp=ftell(file);
 rewind(file);
 return tmp;
}

ReadFromFile(FILE*file)
{
size_t size = getSizeFile(file);
printf("SIZE NOTES: %d\n",size);
char * ch;
ch = (char*) calloc(1,1);
for(long long i=size;i--;)
 {
  fread(ch,1,1,file); // & optional
  printf("%c",*ch);
 }
free(ch);
}
