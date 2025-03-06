#include "header.h"

int Sum(int a, int b) { return a + b; }
int Dif(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return (b != 0) ? a / b : 0; }

int main()
{
    char input[12] = "-*++/-++-*-";
    func Operatori[4] = {Sum, Dif, Mul, Div}; 
    int S = 0;
    Content x = {0, 0};
    int idx;

    for (int i = 0; i < strlen(input); i++)
    {
        switch (input[i] - 42)
        {
            case SUMA:
                idx = 0;
                x.p1 = 7;
                x.p2 = 5;
                break;
            case DIFERENTA:
                idx = 1;
                x.p1 = 10;
                x.p2 = 1;
                break;
            case INMULTIRE:
                idx = 2;
                x.p1 = 3;
                x.p2 = 3;
                break;
            case IMPARTIRE:
                idx = 3;
                x.p1 = 8;
                x.p2 = 4;
                break;
            default:
                continue;
        }

        S += Operatori[idx](x.p1, x.p2);
    }

    printf("S = %d\n", S); 

    return 0;
}

