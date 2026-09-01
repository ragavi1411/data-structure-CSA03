#include <stdio.h>

#define SIZE 10

int main()
{
    int hash[SIZE], n, key, index, i, j;

    for(i = 0; i < SIZE; i++)
        hash[i] = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &key);

        index = key % SIZE;

        for(j = 0; j < SIZE; j++)
        {
            if(hash[index] == -1)
            {
                hash[index] = key;
                break;
            }

            index = (index + 1) % SIZE;
        }
    }

    printf("\nHash Table:\n");

    for(i = 0; i < SIZE; i++)
        printf("%d : %d\n", i, hash[i]);

    return 0;
}
