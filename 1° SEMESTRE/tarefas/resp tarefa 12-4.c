#include <stdio.h>
long int tribonacci(int n)
{
    if ((n == 0) || (n == 1))
    {
        return 0;
    }
    if (n==2)
    {
        return 1;
    }
    return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
}
int main(int argc, char const *argv[])
{
    int num1, rsoma;
    printf("digite um numero: ");
    scanf("%d", &num1);
    printf("sequencia tribonacci do num %d = %d\n\n", num1, tribonacci(num1));
    return 0;
}