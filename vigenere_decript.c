#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXN 1000
char * vigenere_decript(char* cipher,char* key)
{
    int cipher_length=strlen(cipher);
    int key_length=strlen(key);
    char* text=(char*)malloc(sizeof(char)*cipher_length+1);
    memset(text,'\0',sizeof(char)*cipher_length+1);
    for(int i=0;i<cipher_length;i++)
    {
        int shift=tolower(key[i%key_length])-'a';
        if(isalpha(cipher[i]))
        {
              if(islower(cipher[i]))
              {
                text[i]='a'+(cipher[i]-'a'-shift+26)%26;
              }
              else
              {
                text[i]='A'+(cipher[i]-'A'-shift+26)%26;
              }
        }
        else
        {
            text[i]=cipher[i];
        }
    }
    text[cipher_length]='\0';
    return text;
}
int read_cipher(char * fname,char * cipher)
{
    FILE *p = fopen(fname,"r");
    if(p==NULL)
    {
        printf("Error opening the file");
        return EXIT_FAILURE;
    }
    if(fgets(cipher,MAXN,p)==NULL)
    {
        printf("Error reading the file");
        return EXIT_FAILURE;
    }
    fclose(p);
    return EXIT_SUCCESS;
}
void write_file(char* fname,char*text)
{
 FILE *fp=fopen(fname,"wb");
 fprintf(fp,"%s",text);
 fclose(fp);
}
int main()
{
  char cipher_file[MAXN];
  scanf("%s",cipher_file);
  char key_file[MAXN];
  scanf("%s",key_file);
  char cipher[MAXN];
  read_cipher(cipher_file,cipher);
  char key[MAXN];
  read_cipher(key_file,key);
  char * text = vigenere_decript(cipher,key);
  write_file("plaintext.txt",text);
  free(text);
  return EXIT_SUCCESS;
}