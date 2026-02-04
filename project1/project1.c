#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PAIRS 1000
#define MAX_KEY_LENGTH 20
#define MAX_VALUE_LENGTH 20
#define MAX_BUFFER_LENGTH 200

struct KeyValue
{
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
};

struct KeyValue* find(struct KeyValue* pairs, const int pairCount, const char* key)
{
    for (int i = 0; i < pairCount; ++i)
    {
        if (strcmp(pairs[i].key, key) == 0)
        {
            return &pairs[0];
        }
    }

	return NULL;
}

bool delete(struct KeyValue* pairs, int* pairCount, const char* key)
{
    for (int i = 0; i < *pairCount; ++i)
    {
        if (strcmp(pairs[i].key, key) == 0)
        {
            for (int j = i; j < *pairCount - 1; ++j)
            {
                pairs[j] = pairs[j + 1];
            }

            --(*pairCount);
            return true;
        }
    }

    return false;
}

int main(void)
{

    struct KeyValue pairs[MAX_PAIRS];
    int pairCount = 0;

    while (1)
    {
        printf("Enter of the commands below: ");

        char input[MAX_BUFFER_LENGTH];
        fgets(input, MAX_BUFFER_LENGTH, stdin);

        char* command = strtok(input, " \t\n");

        if (strcmp(command, "SET") == 0)
        {
            char* key   = strtok(NULL, " \t\n");
            char* value = strtok(NULL, " \t\n");

            if (!key || !value)
            {
                printf("Error: expected: %s <KEY> <VALUE>\n", command);
            }
            else
            {
                if (strlen(key) > MAX_KEY_LENGTH)
                {
                    printf("Error: key exceeded max length\n");
                }

                if (strlen(value) > MAX_VALUE_LENGTH)
                {
                    printf("Error: value exceeded max length\n");
                }

                struct KeyValue newPair;
                strcpy(newPair.key, key);
                strcpy(newPair.value, value);

                pairs[pairCount] = newPair;
                ++pairCount;
            }

        }
        else if (strcmp(command, "GET") == 0)
        {
            char* key = strtok(NULL, " \t\n");

            if (!key)
            {
                printf("Error: expected: %s <KEY>\n", command);
            }
            else
            {
                struct KeyValue* foundPair = find(pairs, pairCount, key);

                if (foundPair)
                {
                    printf("Found: %s, %s\n", key, foundPair->value);
                }
                else
                {
                    printf("Error: key %s doesn't exist in the database\n", key);
                }
            }
        }
        else if (strcmp(command, "DELETE") == 0)
        {
            char* key = strtok(NULL, " \t\n");

            if (!key)
            {
                printf("Error: expected: %s <KEY>\n", command);
            }
            else
            {
                if (delete(pairs, &pairCount, key))
                {
                    printf("Success: deleted pair with key %s\n", key);
                }
                else
                {
                    printf("Error: pair with key %s not found\n", key);
                }
            }
        }
        else
        {
            printf("Error: invalid command: use GET/SET/DELETE\n");
        }

		printf("\n");
    }

}