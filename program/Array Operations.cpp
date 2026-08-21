#include <stdio.h>

int main()
{
    int a[20], n, i, ch, pos, item;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    printf("\n1.Insert\n2.Delete\n3.Display\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1:
            printf("Enter position and element: ");
            scanf("%d%d", &pos, &item);
            for(i=n; i>=pos; i--)
                a[i]=a[i-1];
            a[pos-1]=item;
            n++;
            break;

        case 2:
            printf("Enter position: ");
            scanf("%d", &pos);
            for(i=pos-1; i<n-1; i++)
                a[i]=a[i+1];
            n--;
            break;

        case 3:
            break;

        default:
            printf("Invalid Choice");
    }

    printf("Array Elements:\n");
    for(i=0; i<n; i++)
        printf("%d ", a[i]);

    return 0;
}
