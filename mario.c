#include <stdio.h>
int main(void)
{
    int h, a;
    do
    {
        printf("Height: ");
        a = scanf("%d", &h);
        if (a == 0)
        {
            while ((getchar()) != '\n')
                ;
        }
    }
    while (a == 0 || h < 1 || h > 8);

    for (int i = 0; i < h; i++)
    {
        int space = h - (i + 1);
        for (int j = 0; j < h; j++)
        {
            if (j < space)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");
        for (int j = 0; j < (i + 1); j++)
        {
            printf("#");
        }
        printf("\n");
    }
}