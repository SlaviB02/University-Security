#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
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
char* cezar_cipher(char* str,int key)
{
 int length=strlen(str);
 char * cipher = (char*)malloc(sizeof(char) * (length+1));
 for(int i = 0;i<length;i++)
 {
    if(str[i] >= 'a' && str[i] <= 'z')
    {
        cipher[i]=((str[i]-'a')+key)%26 + 'a';
    }
    else if(str[i]>= 'A' && str[i] <= 'Z')
    {
        cipher[i]=((str[i]-'A')+key)%26 + 'A';
    }
    else if(str[i]>= '0' && str[i] <= '9')
    {
        cipher[i]=((str[i]-'0')+key)%10 + '0';
    }
    else
    {
        cipher[i]=str[i];
    }
    
 }
 return cipher;
}

int main()
{
    while(true)
    {
        printf("Cipher, Decipher or END:\n");
        char command[MAXN];
        scanf("%s",command);
        getchar();
        if (strcmp(command,"END") == 0)
        {
            break;
        }

        if(strcmp(command,"Cipher") == 0)
        {
            printf("Insert plain text:\n");
            char str[MAXN];
            fgets(str, MAXN, stdin);
            printf("Insert shift:\n");
            int key;
            scanf("%d",&key);
            char * cipher = cezar_cipher(str,key);
            printf("Cipher: %s\n",cipher);
            free(cipher);
        }
        if (strcmp(command,"Decipher") == 0)
        {
            printf("Insert cipher:\n");
            char cipher[MAXN];
            fgets(cipher, MAXN, stdin);
            printf("Insert shift:\n");
            int key;
            scanf("%d", &key);
            char* text = cezar_decipher(cipher, key);
            printf("Plain text: %s\n", text);
            free(text);
        }

    }

    
    return EXIT_SUCCESS;

}