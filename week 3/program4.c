
#include <stdio.h>


int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}


int fibonacci(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}


int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}


int sumOfDigits(int n)
{
    if (n == 0)
        return 0;

    return (n % 10) + sumOfDigits(n / 10);
}

int main()
{
    int choice, n, a, b, i;

    printf("\n--- RECURSION MENU ---\n");
    printf("1. Factorial\n");
    printf("2. Fibonacci\n");
    printf("3. GCD\n");
    printf("4. Sum of Digits\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter number: ");
            scanf("%d", &n);

            printf("Factorial = %d\n", factorial(n));
            break;

        case 2:
            printf("Enter number of terms: ");
            scanf("%d", &n);

            printf("Fibonacci Series: ");
            for (i = 0; i < n; i++)
            {
                printf("%d ", fibonacci(i));
            }
            printf("\n");
            break;

        case 3:
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);

            printf("GCD = %d\n", gcd(a, b));
            break;

        case 4:
            printf("Enter number: ");
            scanf("%d", &n);

            printf("Sum of Digits = %d\n", sumOfDigits(n));
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

