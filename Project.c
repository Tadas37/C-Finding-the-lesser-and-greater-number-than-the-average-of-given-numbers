#include <stdio.h>
#include <stdlib.h>

double findAverage(int N, int number[]);
double lower(int N, int number[], double average, double low);
double higher(int N, int number[], double average, double high);
void sortAscend(int N, int number[]);
void sortDescend(int N, int number[]);

int main()
{
    int test1 = 0, test2 = 0;
    int i = 0, N;
    int number[N];
    char symbol;
    double average, low, high;

    printf("Enter the number N:\n");
    while (test1 != 1)
    {
        if (scanf("%d%c", &N, &symbol) != 2 || symbol != '\n')
        {
            printf("The input is incorrect, enter a positive integer that is not 0\n");
            while (getchar() != '\n');
        }
        else if (N <= 0)
        {
            printf("The input is incorrect, enter a positive integer that is not 0\n");
        }
        else if(N == 1)
        {
            printf("The N needs to be atleast 2 to calculate the average, enter another number\n");
        }
        else
        {
            test1 = 1;
        }
    }

    printf("Enter N numbers:\n");
    while (i < N)
    {
        if (scanf("%d%c", &number[i], &symbol) != 2 || symbol != '\n')
        {
            printf("The input is incorrect, enter an integer\n");
            while (getchar() != '\n');
        }
        else
        {
            if (number[i] == number[0])
            {
                test2++;
            }
            i++;
        }
    }
    
    if (test2 == N)
    {
        printf("All the numbers entered are equal");
    }
    else
    {
    average = findAverage(N, number);
    printf("Average: %.2lf\n", average);

    sortAscend(N, number);
    low = number[0];
    printf("Lesser than average: %.0lf\n", lower(N, number, average, low));

    sortDescend(N, number);
    high = number[0];
    printf("Greater than average: %.0lf\n", higher(N, number, average, high));
    }
}
double findAverage(int N, int number[])
{
    double average = 0;
    for (int i = 0; i < N; i++)
    {
        average += number[i];
    }
    return (average / N);
}
double lower(int N, int number[], double average, double low)
{
    for (int i = 1; i < N; i++)
    {
        if (number[i] < average && number[i] > low)
            low = number[i];
    }
    return low;
}
double higher(int N, int number[], double average, double high)
{
    for (int i = 1; i < N; i++)
    {
        if (number[i] > average && number[i] < high)
            high = number[i];
    }
    return high;
}
void sortAscend(int N, int number[])
{
    int temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (number[i] > number[j])
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
    }
}
void sortDescend(int N, int number[])
{
    int temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (number[i] < number[j])
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
    }
}