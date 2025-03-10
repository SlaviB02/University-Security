#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXN 1000
  
char* cezar_decipher(char* cipher,int key)
{
 int length=strlen(cipher);
 char * text = (char*)malloc(sizeof(char) * (length+1));
 for(int i = 0;i<length;i++)
 {
    if(cipher[i] >= 'a' && cipher[i] <= 'z')
    {
        text[i]=((cipher[i]-'a')-key+26)%26 + 'a';
    }
    else if(cipher[i]>= 'A' && cipher[i] <= 'Z')
    {
        text[i]=((cipher[i]-'A')-key+26)%26 + 'A';
    }
    else if(cipher[i]>= '0' && cipher[i] <= '9')
    {
        text[i]=((cipher[i]-'0')-key+10)%10 + '0';
    }
    else
    {
        text[i]=cipher[i];
    }
    
 }
 return text;
}
int read_cipher(char* fname, char* cipher)
{
    FILE *fp = fopen(fname, "r");
    if(fp == NULL)
    {
        printf("Error opening file.");
        return EXIT_FAILURE;
    }

    if(fgets(cipher, MAXN, fp) == NULL)
    {
        printf("Error reading from file.");
        return EXIT_FAILURE;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}
void write_text(char* filename, char* text)
{
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "%s", text);
    fclose(fp);
}

int main()
{
    char cipher[MAXN];
    read_cipher("cezar.txt", cipher);

    int key;
    scanf("%d", &key);
    char* text = cezar_decipher(cipher, key);
    printf("%s", text);
    write_text("plaintext.txt", text);
    free(text);
    return EXIT_SUCCESS;

}