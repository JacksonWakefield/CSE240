// f i l e c o n t e n t s
// k e y k e y k e y k e y
#include <stdio.h>
#include <stdlib.h>

const int NUM_CYPHER_ELEMENTS = 93;

int getCharIndexInTable(char ch, int row, int **table)
{
    for (int y = 0; y < NUM_CYPHER_ELEMENTS; y++)
    {
        printf("%c", table[row][y]);
        if (table[row][y] == ch)
        {
            return y;
        }
    }

    printf("Could not find given index!");

    return NULL;
}

int main()
{
    // get our file
    FILE *file = fopen("input.txt", "rb");

    int *file_contents;

    //get length of file

    fseek(file, 0L, SEEK_END);

    int size = ftell(file);

    file_contents = (int *)malloc(size - 1 * sizeof(int));

    rewind(file);

    //read file

    int num;

    num = fgetc(file);

    for (int i = 0; i <= size; i++)
    {
        file_contents[i] = num;

        num = fgetc(file);

        if (num == EOF)
        {
            break;
        }
    }

    
    int keySize = 5;

    char key[100] = "hello";

    //height of table will be NUM_CYPHER_ELEMENTS

    //segmentation fault occuring, no idea why

    int **table_address;
    int **table;

    printf("%d", &table_address);

    table = &table_address;

    **table = (int **)malloc(size * sizeof(int *));

    printf("sdfsd");
    for (int i = 0; i < size; i++)
    {
        table[i] = (int *)malloc(NUM_CYPHER_ELEMENTS * sizeof(int));
    }

    int *keyString;

    keyString = (int *)malloc(size * sizeof(int));

    printf("%d", size);

    int stringIndex = 0;

    //create keystring - k e y k e y k ....

    for (int i = 0; i < size; i++)
    {

        keyString[i] = key[stringIndex];

        stringIndex += 1;

        if (stringIndex >= keySize)
        {
            stringIndex = 0;
        }
    }

    //create table
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < NUM_CYPHER_ELEMENTS; y++)
        {
            if (y == 0)
            {
                table[x][y] = keyString[x];
            }
            else
            {
                if (table[x][y - 1] + 1 > 126)
                {
                    table[x][y] = 33;
                }
                else
                {
                    table[x][y] = table[x][y - 1] + 1;
                }
            }
        }
    }

    fclose(file);

    char *encryptedString = (char *)malloc(size * sizeof(char));
    //encript file
    for (int i = 0; i < size; i++)
    {
        int index = file_contents[i] - 33;
        encryptedString[i] = table[i][index];
        printf("%c", encryptedString[i]);
    }

    char *decryptedString = (char *)malloc(size * sizeof(char));
    printf("\n");
    //decript file
    for (int i = 0; i < size; i++)
    {
        decryptedString[i] = getCharIndexInTable(encryptedString[i], i, table);
        printf("%c", decryptedString[i]);
    }

    free(keyString);
    free(file_contents);
    free(encryptedString);
    free(decryptedString);
}
