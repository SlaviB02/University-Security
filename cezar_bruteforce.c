#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000
#define ALPHA_LENGTH 26

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

int main()
{
    char cipher[MAXN];
    fgets(cipher, MAXN, stdin);
    for(int key = 0; key < ALPHA_LENGTH; key++)
    {
        char* text = cezar_decipher(cipher, key);
        printf("key %d -> %s\n", key, text); 
        free(text);
    }
    return EXIT_SUCCESS;
}