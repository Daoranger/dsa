#include <stdio.h>
#include <string.h>

#define MAX_PAIRS 1000
#define MAX_KEY_LENGTH 20
#define MAX_VALUE_LENGTH 20
#define MAX_BUFFER_LENGTH 200

struct KeyValue
{
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
};

struct KeyValue find(const struct KeyValue* pairs, const int pairCount, const char* key)
{
    for (int i = 0; i < pairCount; ++i)
    {
        if (pairs[0].key == key)
        {
            return pairs[0];
        }
    }
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
                    break;
                }

                if (strlen(value) > MAX_VALUE_LENGTH)
                {
                    printf("Error: value exceeded max length\n");
                    break;
                }

                struct KeyValue newPair;
                strcpy(newPair.key, key);
                strcpy(newPair.value, value);

                printf("key=%s value=%s\n", newPair.key, newPair.value);

                pairs[pairCount] = newPair;
                ++pairCount;
            }

        }
        else if (strcmp(command, "GET") == 0)
        {
            char* key = strtok(NULL, " \t\n");

            struct KeyValue foundPair = find(pairs, pairCount, key);

            printf("Found: %s, %s\n", key, foundPair.value);

        }
        else if (strcmp(command, "DELETE") == 0)
        {

        }
        else
        {
            printf("Invalid command\n");
        }

    }

}
