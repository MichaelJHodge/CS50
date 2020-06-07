// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <strings.h>

#include "dictionary.h"


// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

int wordcount = 0;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
    {
        // Initialize hash table
        for (int i = 0; i < N; i++)
        {
            hashtable[i] = NULL;
        }

        // Open dictionary
        FILE *file = fopen(dictionary, "r");
        if (file == NULL)
        {
            unload();
            return false;
        }

        // Buffer for a word
        char word[LENGTH + 1];

        // Insert words into hash table
        while (fscanf(file, "%s", word) != EOF)
        {
            node *new_node = malloc(sizeof(node));
            if (new_node == NULL)
            {
                fclose(file);
                return false;
            }

            strcpy(new_node->word, word); //This copies a word into a new struct
            int hashval = tolower(word[0] - 'a');
            new_node->next = hashtable[hashval];
            hashtable[hashval] = new_node;

            wordcount++;
        }

        // Close dictionary
        fclose(file);

        // Indicate success
        return true;
    }

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (wordcount > 0)
    {
        return wordcount;
    }
    else
    {
        return 0;
    }
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
   char copy[strlen(word)];
   for (int j = 0; j < strlen(word); j++)
   {
       copy[j] = tolower(word[j]);
   }

    // get the hash value of the passed in word
    int hashval = tolower (copy[0] - 'a');

    node *cursor = malloc(sizeof(node));
    cursor = hashtable[hashval];

    // if word is found return true
    while (cursor != NULL)
    {
        int result = strcasecmp(copy, cursor->word); //compares the word with the next in the linked list

        if (result == 0) // result of 0 means they are the same
        {
            return true;
        }
        else
        {
            cursor = cursor->next; //moves along to next in the linked list
        }

    }
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < 25; i++)
        {
            node *cursor = hashtable[i];

            while (cursor != NULL)
            {
                node *temp = cursor;
                cursor = cursor->next;
                free(temp);
            }
        }
    return true;
}
