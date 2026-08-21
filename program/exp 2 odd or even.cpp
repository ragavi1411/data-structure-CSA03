#include <stdio.h>

int main()
{
    int a[10], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    for(i=0; i<n; i++)
    {
        if(a[i] % 2 == 0)
            printf("%d is Even\n", a[i]);
        else
            printf("%d is Odd\n", a[i]);
    }

    return 0;
}
