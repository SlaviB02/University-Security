#include<stdlib.h>
#include<string.h>
#include<openssl/des.h>
#include<stdio.h>
#define KEY_SIZE 8
#define MAXN 100

//gcc des_encrypt.c -o des_encrypt -lcrypto

int main()
{
    unsigned char key[MAXN]="banichka";
    unsigned char input[MAXN];
    fgets(input,MAXN,stdin);
    input[strcspn(input,"\n")]='\0';
    unsigned int length = strlen(input);

    int padded_length=((length+7)/8)*8;  //padding to be multiple of 8
    unsigned char padded_input[padded_length];
    unsigned char output[padded_length];
    memcpy(padded_input,input,length);
    memset(padded_input+length,padded_length-length,padded_length-length);

    DES_key_schedule key_schedule;
    DES_set_key((DES_cblock*)key,&key_schedule); //make the key in cblock from string

    for(int i=0;i<padded_length;i+=8)
    {
        DES_ecb_encrypt((DES_cblock*)(padded_input+i),(DES_cblock*)(output+i),
        &key_schedule,DES_ENCRYPT); // encrypt the message
    }

    for(int i=0;i<padded_length;i++)
    {
        printf("%02x",output[i]);
    }

    return EXIT_SUCCESS;
}
