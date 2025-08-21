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

// ------------------------------------
// Selection Sort (int decrescente)
// ------------------------------------
void selection_int_desc(int *v, int n, Metricas *m) {
    zera_metricas(m);
    for (int i = 0; i < n - 1; i++) {
        int idx_max = i;
        for (int j = i + 1; j < n; j++) {
            m->comparacoes++;
            if (v[j] > v[idx_max]) idx_max = j;
        }
        if (idx_max != i) swap_int(&v[i], &v[idx_max], m);
    }
}

// ------------------------------------
// Insertion Sort (int decrescente)
// ------------------------------------
void insertion_int_desc(int *v, int n, Metricas *m) {
    zera_metricas(m);
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0) {
            m->comparacoes++;
            if (v[j] < chave) { 
                v[j + 1] = v[j];
                if (m) m->trocas++;
                j--;
            } else {
                break;
            }
        }
        v[j + 1] = chave;
    }
}

// ------------------------------------
// Programa principal
// ------------------------------------
int main(void) {
    int pontuacao[] = {15, 32, 8, 27, 25, 5, 12, 20, 18, 10, 22, 25};
    int n_pontuacao = (int)(sizeof(pontuacao) / sizeof(pontuacao[0]));

    int a1[12], a2[12], a3[12];
    memcpy(a1, pontuacao, sizeof(pontuacao));
    memcpy(a2, pontuacao, sizeof(pontuacao));
    memcpy(a3, pontuacao, sizeof(pontuacao));

    imprime_int(pontuacao, n_pontuacao, "Ranking de Pontuacao (original)");

    Metricas mb, ms, mi;

    // Bubble
    bubble_int_desc(a1, n_pontuacao, &mb);
    imprime_int(a1, n_pontuacao, "Bubble (desc)");
    printf("Bubble -> comparacoes=%ld, trocas=%ld\n\n", mb.comparacoes, mb.trocas);

    // Selection
    selection_int_desc(a2, n_pontuacao, &ms);
    imprime_int(a2, n_pontuacao, "Selection (desc)");
    printf("Selection -> comparacoes=%ld, trocas=%ld\n\n", ms.comparacoes, ms.trocas);

    // Insertion
    insertion_int_desc(a3, n_pontuacao, &mi);
    imprime_int(a3, n_pontuacao, "Insertion (desc)");
    printf("Insertion -> comparacoes=%ld, trocas=%ld\n\n", mi.comparacoes, mi.trocas);

    return 0;
}
// --------------------