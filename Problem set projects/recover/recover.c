#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

#define BLOCK_SIZE 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Please use corrext # of arguments\n");
        return 1;
    }
    // Remember the names of the files
    char *infile = argv[1];

    // Assure correct file format
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "File coudln't be opened!\n");
        return 2;
    }

    BYTE buffer [512];
    int counter = 0;

    char filename[8];
    FILE *outptr = NULL;

    while (true)
    {
        size_t bytesRead = fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr);

        if (bytesRead == 0  && feof(inptr))
        {
            break;
        }

        // Did we find a Jpeg?
        bool containsJpegheader = buffer [0] == 0xff && buffer [1] == 0xd8 && buffer [2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

        // If YES, we need to close the already open file
        if (containsJpegheader && outptr != NULL)
        {
            fclose(outptr);
            counter++;
        }

        // Open a new file for writing
        if (containsJpegheader)
        {
            sprintf(filename, "%03i.jpg", counter);
            outptr = fopen(filename, "w");
        }

        // Write if/when we have a file that's open
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE), bytesRead, outptr);
        }

    }

    // Close last jpeg file, close infile, and return 0
    fclose(outptr);
    fclose(inptr);
    return 0;

}