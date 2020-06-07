#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h> 

// Welcome! This program is Caesar's Cipher, a program by which he encrpyted his messages. 

int main(int argc, string argv[])

{ 
if (argc != 2) //argc = 2 with one command line argument. argc is always at least 1
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

// Validating the Key: Converting the string to an integer

int k = atoi(argv[1]);


// Assure that integer remains positive

if (k < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

//Ask user for plain text 
    {
    string plaintext = get_string("plaintext:"); 
    {
        printf("ciphertext:"); 
    } 
        
     for (int i = 0, n = strlen(plaintext); i < n; i++)

      
//Checking if the letters are uppercase or lowercase and converting them 
     { 
        if(islower(plaintext[i]))
             printf("%c", (((plaintext[i] + k) - 97) % 26) + 97);
        else if(isupper(plaintext[i]))
             printf("%c", (((plaintext[i] + k) - 65) % 26) + 65);
        else 
            printf("%c", plaintext[i]);             
     }
        printf("\n");
        return 0;
    }
}
