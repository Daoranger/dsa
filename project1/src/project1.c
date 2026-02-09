#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PAIRS 1000
#define MAX_KEY_LENGTH 21
#define MAX_VALUE_LENGTH 21
#define MAX_BUFFER_LENGTH 200

struct KeyValue
{
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
};

void setCmd(struct KeyValue* pairs, const char* key, const char* value)
{
    // loop through the pairs arrays
        // if find an empty slot (that is represented as NULL)
    // out of loop means no more space (db full), print error message

    // update if key exists
    for (int i = 0; i < MAX_PAIRS; ++i)
    {
        if (pairs[i].key[0] != '\0' && strcmp(pairs[i].key, key) == 0)
        {
            strcpy(pairs[i].value, value); // only update value
            return;
        }
    }

    for (int i = 0; i < MAX_PAIRS; ++i)
    {
        if (pairs[i].key[0] == '\0')
        {
            strcpy(pairs[i].key, key);
            strcpy(pairs[i].value, value);
            return;
        }
    }

    printf("Database is full\n");
}

struct KeyValue* getCmd(struct KeyValue* pairs, const char* key)
{
    // loop through the array of kv pairs
        // if element key is empty
            // continue
        // if the current element key = the key we need to find
            // return that element
    // return NULL (not found)
    for (int i = 0; i < MAX_PAIRS; ++i)
    {
        if (pairs[i].key[0] == '\0')
        {
            continue;
        }

        if (strcmp(pairs[i].key, key) == 0)
        {
            return &pairs[i];
        }
    }
	return NULL;
}

bool deleteCmd(struct KeyValue* pairs, const char* key)
{
    // loop through the array of kv pairs
        // if the current element = the key we need to find
            // set the key and value of that element to null
            // return true for successful delete
    // return false for unsuccessful delete (not found)
    for (int i = 0; i < MAX_PAIRS; ++i)
    {
        if (pairs[i].key[0] == '\0')
        {
            continue;
        }

        if (strcmp(pairs[i].key, key) == 0)
        {
            pairs[i].key[0] = '\0';
            pairs[i].value[0] = '\0';
            return true;
        }
    }
    return false;
}

int main(void)
{

    struct KeyValue pairs[MAX_PAIRS] = {0};

    while (1)
    {
        printf("Enter a command (SET/GET/DELETE): ");

        char input[MAX_BUFFER_LENGTH];

        if (!fgets(input, MAX_BUFFER_LENGTH, stdin)) {
            break;
        }

        char* command = strtok(input, " \t\n");

        if (!command)
        {
            continue;
        }

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
                if (strlen(key) >= MAX_KEY_LENGTH)
                {
                    printf("Error: key exceeded max length\n");
                    continue;
                }

                if (strlen(value) >= MAX_VALUE_LENGTH)
                {
                    printf("Error: value exceeded max length\n");
                    continue;
                }

                setCmd(pairs, key, value);
            }

        }
        else if (strcmp(command, "GET") == 0)
        {
            char* key = strtok(NULL, " \t\n");
            char* value = strtok(NULL, " \t\n");

            if (!key || value)
            {
                printf("Error: expected: %s <KEY>\n", command);
            }
            else
            {
                struct KeyValue* foundPair = getCmd(pairs, key);

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
                if (deleteCmd(pairs, key))
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