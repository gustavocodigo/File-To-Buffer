#include <stdio.h>

#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    const char *SEPARATOR = "[content]";
    const char *SEPARATOR_LEN = "[size]";
    char *separator_preffix_pointer, *separator_suffix_pointer;
    separator_suffix_pointer = separator_preffix_pointer = 0;
    if (argc < 3)
    {
        printf("Usage: tobuffer <file> <output_file> <options>\n");
        printf("Options:\n");
        printf("  -ps prefix%ssuffix  to add the prefix and suffix name example: tobuffer -ps 'const char * fonData = \"%s\";'\n", SEPARATOR, SEPARATOR);
        printf("  you can use %s and %s where %s is the size and %s is an optional size\n", SEPARATOR_LEN, SEPARATOR, SEPARATOR_LEN, SEPARATOR);
        return 1;
    }

    if (argc >= 3)
    {
        FILE *file = fopen(argv[1], "r");
        if (!file)
        {
            printf("Could not open: %s\n", argv[1]);
            return 1;
        }
        FILE *outputFile = fopen(argv[2], "w");
        if (!outputFile)
        {
            fclose(file);
            printf("Could not create the outputfile: %s\n", argv[2]);
            return 1;
        }

        int c;
        if (argc > 3)
        {
            for (int i = 2; i < argc; i++)
            {
                if (strcmp(argv[i], "-ps") == 0)
                {
                    if ((argc - i) < 2)
                    {
                        puts("NO ARGUMENT FOR THE OPTION -ps.");
                        return 1;
                    }
                    char *arg1 = (char *)argv[i + 1];
                    separator_preffix_pointer = arg1;
                    if ((separator_suffix_pointer = (char *)strstr(arg1, SEPARATOR)) == 0)
                    {
                        printf("ILLEGAL ARGUMENT TO THE OPTION -ps NO %s FOUND TO SEPARATE SUFFIX AND PREFIX.\n", SEPARATOR);
                        return 1;
                    }
                    size_t prefixLen = (size_t)(separator_suffix_pointer - separator_preffix_pointer);
                    separator_suffix_pointer += strlen(SEPARATOR);
                    separator_preffix_pointer = (char *)malloc(prefixLen + 1);
                    memcpy(separator_preffix_pointer, arg1, prefixLen);
                    separator_preffix_pointer[prefixLen] = '\0';

                    while (*(arg1))
                    {
                        arg1 += 1;
                    }
                    i++;
                }
            }
        }


        fseek(file, 0L, SEEK_END);
        // calculating the size of the file
        int size = ftell(file);
        fseek(file, 0L, 0L);
        if (separator_preffix_pointer)
        {
            char nbuff[strlen(separator_suffix_pointer) + 100];
            char *pos;
            if (pos = strstr(separator_preffix_pointer, SEPARATOR_LEN))
            {
                size_t tlen1 = (size_t)(pos - separator_preffix_pointer);
                memcpy((void *)nbuff, (void *)separator_preffix_pointer, tlen1);
                nbuff[tlen1] = 0;
                char nbuff2[strlen(separator_preffix_pointer) + 100];
                sprintf(nbuff2, "%i%s", size, &pos[strlen(SEPARATOR_LEN)]);
                strcat(nbuff, nbuff2);
                fprintf(outputFile, "%s", nbuff);
            }
            else
            {
                fprintf(outputFile, "%s", separator_preffix_pointer);
            }
            free(separator_preffix_pointer);
        }
        while ((c = fgetc(file)) > -1)
        {
            fprintf(outputFile, "\\%i", c);
        }
        if (separator_suffix_pointer)
        {
            char nbuff[strlen(separator_suffix_pointer) + 100];
            char *pos;
            if (pos = strstr(separator_suffix_pointer, SEPARATOR_LEN))
            {
                size_t tlen1 = (size_t)(pos - separator_suffix_pointer);
                memcpy((void *)nbuff, (void *)separator_suffix_pointer, tlen1);
                nbuff[tlen1] = 0;
                char nbuff2[strlen(separator_suffix_pointer) + 100];
                sprintf(nbuff2, "%i%s", size, &pos[strlen(SEPARATOR_LEN)]);
                strcat(nbuff, nbuff2);
                puts(nbuff);
                strcpy(separator_suffix_pointer, nbuff);
                fprintf(outputFile, "%s", nbuff);
            }
            else
            {
                fprintf(outputFile, "%s", separator_suffix_pointer);
            }
        }
        fclose(outputFile);
        fclose(file);
    }
    return 0;
}
