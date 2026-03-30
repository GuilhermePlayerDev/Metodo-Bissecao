#include <stdio.h>
#include <math.h>

// Defina a função alvo
double f(double x) {
	double r1 = pow(2.7182818284590452353602874713527, x);
	double r2 = x*x;
    return r1-r2; // Exemplo: f(x) = x^2 - 4
}

int main() {
    double a, b, erro, fa, fb, m, fm;
    int iter = 0;

    printf("Metodo da Bissecao\n");
    printf("Digite o ponto a: ");
    scanf("%lf", &a);
    printf("Digite o ponto b: ");
    scanf("%lf", &b);
    printf("Digite a margem de erro (para f(x)): ");
    scanf("%lf", &erro);

    fa = f(a);
    fb = f(b);

    if (fa * fb > 0) {
        printf("Nao ha raiz no intervalo [%.6lf, %.6lf]\n", a, b);
        return 1;
    }

    do {
        m = (a + b) / 2.0;
        fm = f(m);

        printf("Iteracao %d: a=%.6lf, b=%.6lf, m=%.6lf, f(m)=%.6lf\n",
               iter, a, b, m, fm);

        if (fa * fm < 0) {
            b = m;
            fb = fm;
        } else {
            a = m;
            fa = fm;
        }

        iter++;
    } while (fabs(fm) > erro);

    printf("\nA raiz aproximada eh: %.6lf (com f(m)=%.6lf)\n", m, fm);

    return 0;
}

