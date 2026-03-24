#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Função: e^x - x².

float recebeerro()
{
    printf("Digite o valor do erro: ");
    float erro;
    scanf("%f", &erro);
    return erro;
}
float recebeA()
{
    printf("Digite o valor de A: ");
    float a;
    scanf("%f", &a);
    return a;
}
float recebeB()
{
    printf("Digite o valor de B: ");
    float b;
    scanf("%f", &b);
    return b;
}
float novoA(float x)
{
    float a = x;
    return a;
}
float novoB(float x)
{
    float b = x;
    return b;
}
float calcularX(float a, float b)
{
    float x = (a + b) / 2;
    return x;
}
float calcularFAXB(float x)
{
    float resultado = (pow(2.71, x) - (x * x));
    return resultado;
}
/*
float calcularFA(float a)
{
    float resultado = (pow(2.71, a) - (a * a));
    return resultado;
}
float calcularFB(float b)
{
    float resultado = (pow(2.71, b) - (b * b));
    return resultado;
}*/
void execucao(int k, float a, float b, float erro, float x, float fx, float fa, float fb)
{
    do
    {
        x = calcularX(a, b);
        fx = calcularFAXB(x);
        fa = calcularFAXB(a);
        fb = calcularFAXB(b);

        if ((fa < 0 && fb > 0) || (fa > 0 && fb < 0))
        {
            b = novoB(x);
        }
        else
        {
            a = novoA(x);
        }
        x = calcularX(a, b);
        fx = calcularFAXB(x);
        fa = calcularFAXB(a);
        fb = calcularFAXB(b);

        k++;
    } while (fabs(fx) > erro);
}
void menu()
{
    float a = 0, b = 0;
    float x = 0, fx = 0, fa = 0, fb = 0;
    int opcao;
    while (1)
    {
        system("cls");
        printf("\n\tEscolha uma opção:\n");
        printf("\n\n1. Escolher A.");
        printf("\n\n2. Escolher B.");
        printf("\n\n3. Rodar.");
        printf("\n\n4. Parar.");
        printf("\n\n5. Sair.");
        scanf("%d", &opcao);
        setbuf(stdin, NULL);

        switch (opcao)
        {
        case 1:
            system("cls");
            a = recebeA();
            break;

        case 2:
            system("cls");
            b = recebeB();
            break;

        case 3:
            system("cls");
            float erro = recebeerro();
            printf("\nErro recebido.");
            int k = 0;
            printf("\nExecução em progresso...");
            execucao(k, a, b, erro, x, fx, fa, fb);
            printf("\nExecução em concluída.");
            break;

        case 4:
            system("cls");
            printf("\nInterrompendo.");
            printf("\nProcesso interrompido.");
            break;

        case 5:
            system("cls");
            printf("\nSaindo.");
            exit(0);
        }
    }
}
int main()
{
    menu();
    return 0;
}
