#include <stdio.h>

// struct indice primario
typedef struct {
    int kindex; // chave
    int pos;    // posicao
} bloco_indice;

// sub-rotina BSI
int bsi(int v[], int n, bloco_indice indice[], int tamanho_indice, int x) {
    
    // elemento fora da tabela
    if (tamanho_indice == 0 || x < indice[0].kindex) {
        return -1; 
    }
    
    // ajusta elemento ao bloco correto
    int i = 0;
    while (i < tamanho_indice - 1 && x >= indice[i + 1].kindex) {
        i++;
    }
    
    // identifica bloco
    int inicio = indice[i].pos;
    int fim;
    if (i < tamanho_indice - 1) {
        fim = indice[i + 1].pos;
    } else {
        // assume ultimo vetor
        fim = n;
    }

    // busca no bloco identificado
    for (int j = inicio; j < fim; j++) {
        if (v[j] == x) {
            return j; // posicao do elemento buscado
        }
        // condicao de parada para vetor ordenado
        if (v[j] > x) {
            break;
        }
    }
    return -1; // elemento nao encontrado
}

//teste em vetor ordenado
int main() {
    int v[] = {12, 25, 33, 37, 48, 57, 86, 92, 105};
    int n = sizeof(v) / sizeof(v[0]);

    // tabela de indices primarios
    bloco_indice indice[] = {
        {12, 0},
        {37, 3}, 
        {86, 6}  
    };
    int tamanho = sizeof(indice) / sizeof(indice[0]);

    // valores a serem buscados
    int busca[] = {37, 105, 50, 10}; 
    int n_busca = sizeof(busca) / sizeof(busca[0]);

    printf("Teste de BSI:\n\n");
    
    // exibindo resultados
    for (int i = 0; i < n_busca; i++) {
        int resultado = bsi(v, n, indice, tamanho, busca[i]);

        if (resultado != -1) { 
            printf("elemento %d na posicao: %d\n", busca[i], resultado);
        } else {
            printf("elemento %d não encontrado.\n", busca[i]);
        }
    }
    return 0;
}
