/**
 *
 * Project 1: Key-Value Database
 *
 * Author: Hoang Nguyen
 *
 * Date created: 1/29/2026
 * Last modified: 2/9/2026
 *
 * Description: This program will demonstrate a key-value pairs database.
 * User can use commands such as SET, GET, DELETE, PRINT to use the functionalities of the database.
 * User can also type EXIT to exit out the program.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// constants
// source: https://stackoverflow.com/questions/36749331/what-is-the-right-declaration-of-constants-in-c
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

    // case 1: key already existed, overwrite it value
    for (int i = 0; i < MAX_PAIRS; ++i)
    {
        if (pairs[i].key[0] != '\0' && strcmp(pairs[i].key, key) == 0)
        {
            strcpy(pairs[i].value, value);
            return;
        }
    }

    // case 2: key doesn't exist yet, set new key-value pair
    for (int i = 0; i < MAX_PAIRS; ++i)
    {
        if (pairs[i].key[0] == '\0')
        {
            // copy new value to array (string)
            // source: https://stackoverflow.com/questions/3131319/how-can-i-correctly-assign-a-new-string-value
            strcpy(pairs[i].key, key);
            strcpy(pairs[i].value, value);
            return;
        }
    }

    // case 3
    printf("ERROR: Database is full\n");
}

struct KeyValue* getCmd(struct KeyValue* pairs, const char* key)
{
    for (int i = 0; i < MAX_PAIRS; ++i)
    {
        // if key is null, continue to next pair
        if (pairs[i].key[0] == '\0')
        {
            continue;
        }

        // if keys matched, return the address of kv pair
        if (strcmp(pairs[i].key, key) == 0)
        {
            return &pairs[i];
        }
    }

    // if kv pair not found (doesn't exist)
	return NULL;
}

bool deleteCmd(struct KeyValue* pairs, const char* key)
{
    // case 1: if key existed to be deleted
    for (int i = 0; i < MAX_PAIRS; ++i)
    {
        // if key is null, continue to next pair
        if (pairs[i].key[0] == '\0')
        {
            continue;
        }

        // if keys matched, "delete" by set kv pair to NULL
        if (strcmp(pairs[i].key, key) == 0)
        {
            pairs[i].key[0] = '\0';
            pairs[i].value[0] = '\0';
            return true;
        }
    }

    // case 2: if key doesn't exist
    return false;
}

void printCmd(struct KeyValue* pairs)
{
    for (int i = 0; i < MAX_PAIRS; ++i)
    {
        if (pairs[i].key[0] != '\0')
            printf("%s : %s\n", pairs[i].key, pairs[i].value);
    }
}

int main(void)
{
    // Array to store kv pairs
    struct KeyValue pairs[MAX_PAIRS] = {0};

    while (1)
    {
        printf("> ");

        // read input line from user
        char input[MAX_BUFFER_LENGTH];
        if (!fgets(input, MAX_BUFFER_LENGTH, stdin)) {
            break;
        }

        // get command string from input
        // source: https://www.w3schools.com/c/ref_string_strtok.php
        char* command = strtok(input, " \t\n");

        // case 1: if user enter nothing
        if (!command)
        {
            continue;
        }

        // case 2: if user enter something
        if (strcmp(command, "SET") == 0)
        {

            // use string tokenize to get key and value (ignore whitespaces)
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
                    printf("ERROR: Key exceeded max length of 20\n\n");
                    continue;
                }

                if (strlen(value) >= MAX_VALUE_LENGTH)
                {
                    printf("ERROR: Value exceeded max length of 20\n\n");
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
                printf("ERROR: Expected: %s <KEY>\n", command);
            }
            else
            {
                struct KeyValue* foundPair = getCmd(pairs, key);

                if (foundPair)
                {
                    printf("SUCCESS: (%s, %s)\n", key, foundPair->value);
                }
                else
                {
                    printf("ERROR: (%s, (null))\n", key);
                }
            }
        }
        else if (strcmp(command, "DELETE") == 0)
        {
            char* key = strtok(NULL, " \t\n");
            char* value = strtok(NULL, " \t\n");

            if (!key || value)
            {
                printf("ERROR: Expected %s <KEY>\n", command);
            }
            else
            {
                if (deleteCmd(pairs, key))
                {
                    printf("SUCCESS: Deleted pair with key %s\n", key);
                }
                else
                {
                    printf("ERROR: Pair with key %s not found\n", key);
                }
            }
        }
        else if (strcmp(command, "EXIT") == 0)
        {
            exit(0);
        }
        else if (strcmp(command, "PRINT") == 0)
        {
            printCmd(pairs);
        }
        else
        {
            printf("ERROR: Invalid command. Use GET/SET/DELETE/PRINT/EXIT\n");
        }

		printf("\n");
    }
}