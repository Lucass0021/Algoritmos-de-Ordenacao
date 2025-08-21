#include <stdio.h>
#include <string.h>
// --------------------
// Métricas de execução
// --------------------
typedef struct {
    long comparacoes;
    long trocas;
} Metricas;
void zera_metricas(Metricas *m) { m->comparacoes = 0; m->trocas = 0; }
// --------------------
// Utilidades
// --------------------
void imprime_int(const int *v, int n, const char *titulo) {
    printf("%s [", titulo);
    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1 ? ", " : ""));
    }
    printf("]\n");
}
void swap_int(int *a, int *b, Metricas *m) {
    int tmp = *a; *a = *b; *b = tmp;
    if (m) m->trocas++;
}
// ------------------------------------
// Bubble Sort (int decrescente)
// ------------------------------------
void bubble_int_desc(int *v, int n, Metricas *m) {
    zera_metricas(m);
    for (int pass = 0; pass < n - 1; pass++) {
        int mudou = 0;
        for (int i = 0; i < n - 1 - pass; i++) {
            m->comparacoes++;
            if (v[i] < v[i + 1]) { // decrescente: maior vem antes
                swap_int(&v[i], &v[i + 1], m);
                mudou = 1;
            }
        }
        if (!mudou) break;
    }
}

int main(void) {
    int v1[] = {5, 2, 9, 1, 7, 6, 9, 3, 4, 8, 10, 0};

    Metricas m;

    bubble_int_desc(v1, 12, &m);
    imprime_int(v1, 12, "Pontuacao ordenada (Decrescente)");
    printf("Comparações: %ld | Trocas: %ld\n\n", m.comparacoes, m.trocas);

    return 0;
}