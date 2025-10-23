#include <stdio.h>


int tabuleiro[10][10]; // tabuleiro é uma variavel global

// função que converte a coluna para o indice da matriz
int converte_coluna(char coluna) {
    return coluna - 'A';
}

// função que converte a linha para o indice da matriz
int converte_linha(int linha) {
    return linha - 1;
}

// recebe as coordenadas inicias do elemento (A1) e a posição atual no tabuleiro ja convertido e devolve se a celula atual pertence a um navio
int navio_horizontal (char x_inicial, int y_inicial, int x_atual, int y_atual) {
    int coluna;
    int linha;
    int i;

    coluna = converte_coluna(x_inicial);
    linha = converte_linha(y_inicial);

    if (y_atual == linha && (x_atual == coluna || x_atual == coluna + 1 || x_atual == coluna + 2)) {
        return 1;
    } else {
        return 0;
    }
}

// para posicionar o navio, primeiro testa se o navio excedeu os limites do tabuleiro
//  e se esta sobrepondo algum outro elemento, caso isto ocorre nao posiciona o navio
void posiciona_navio_horizontal (char x_inicial, int y_inicial) {
    int coluna;
    int linha;
    int lin;
    int col;
    int liberado = 1;

    coluna = converte_coluna(x_inicial);
    linha = converte_linha(y_inicial);

    // testa se a linha se encontra fora do limite do tabuleiro
    if (linha < 0 || linha > 9) {
        liberado = 0;
    }

    // testa se o elemento ultrapassou o limite horizontal do tabuleiro
    if (coluna + 2 > 9) {
        liberado = 0;
    }
    
    // testa se existe alguma sobreposicao com outro elemento
    for (lin = linha; lin < linha + 1; lin++) {
            for (col = coluna; col < coluna + 3; col++) {
                // testo se ja existe algum elemento nesta celula
                if (tabuleiro [lin] [col] != 0) {
                    liberado = 0;
                }
         }
    }
    

    // sena o há sobreposicao ou excedeu limite, posiciono o elemento
    if (liberado) {
        for (lin = 0; lin < 10; lin++) {
            for (col = 0; col < 10; col++) {
                if (navio_horizontal(x_inicial, y_inicial, col, lin)) {
                    tabuleiro [lin] [col] = 3;
                }    
            }
        }    
    }
}    

// recebe as coordenadas inicias do elemento (A1) e a posição atual no tabuleiro ja convertido e devolve se a celula atual pertence a um navio
int navio_vertical (char x_inicial, int y_inicial, int x_atual, int y_atual) {
    int coluna;
    int linha;
    int i;

    coluna = converte_coluna(x_inicial);
    linha = converte_linha(y_inicial);
    if (x_atual == coluna && (y_atual == linha || y_atual == linha + 1 || y_atual == linha + 2)) {
        return 1;
    } else {
        return 0;
    }
}

// para posicionar o navio, primeiro testa se o navio excedeu os limites do tabuleiro
//  e se esta sobrepondo algum outro elemento, caso isto ocorre nao posiciona o navio
void posiciona_navio_vertical (char x_inicial, int y_inicial) {
    int coluna;
    int linha;
    int i;
    int lin;
    int col;
    int liberado = 1;

    coluna = converte_coluna(x_inicial);
    linha = converte_linha(y_inicial);

    // testa se a linha se encontra fora do limite do tabuleiro
    if (linha < 0 || linha > 9) {
        liberado = 0;
    }

    // testa se a coluna se encontra fora do limite do tabuleiro
    if (coluna < 0 || coluna > 9) {
        liberado = 0;
    }

    // testa se o elemento ultrapassou o limite vertical do tabuleiro
    if (linha + 2 > 9) {
        liberado = 0;
    }
    

    
    // testa se existe alguma sobreposicao com outro elemento
    for (i = 0; i < 3; i++) {
        if (tabuleiro [linha + i] [coluna + i] != 0) {
            liberado = 0;    
        }
    }

    // sena o há sobreposicao ou excedeu limite, posiciono o elemento
    if (liberado) {
        for (lin = 0; lin < 10; lin++) {
            for (col = 0; col < 10; col++) {
                if (navio_vertical(x_inicial, y_inicial, col, lin)) {
                    tabuleiro [lin] [col] = 3;
                }    
            }
        }    
    }
}    

// recebe as coordenadas inicias do elemento (A1) e a posição atual no tabuleiro ja convertido e devolve se a celula atual pertence a um navio
int navio_diagonal_direita (char x_inicial, int y_inicial, int x_atual, int y_atual) {
    int coluna;
    int linha;
    int i;

    coluna = converte_coluna(x_inicial);
    linha = converte_linha(y_inicial);

    

    if ((linha == y_atual && coluna == x_atual) || (linha + 1 == y_atual && coluna + 1 == x_atual) || (linha + 2 == y_atual && coluna + 2 == x_atual)) {
        return 1;
    } else {
        return 0;
    }
}


// para posicionar o navio, primeiro testa se o navio excedeu os limites do tabuleiro
//  e se esta sobrepondo algum outro elemento, caso isto ocorre nao posiciona o navio
void posiciona_navio_diagonal_direita (char x_inicial, int y_inicial) {
    int coluna;
    int linha;
    int i;
    int lin;
    int col;
    int liberado = 1;

    coluna = converte_coluna(x_inicial);
    linha = converte_linha(y_inicial);

    // testa se a linha se encontra fora do limite do tabuleiro
    if (linha < 0 || linha > 9) {
        liberado = 0;
    }

    // testa se a coluna se encontra fora do limite do tabuleiro
    if (coluna < 0 || coluna > 9) {
        liberado = 0;
    }

    // testa se o elemento ultrapassou o limite vertical do tabuleiro
    if (linha + 2 > 9) {
        liberado = 0;
    }

    // testa se o elemento ultrapassou o limite horizontal do tabuleiro
    if (coluna + 2 > 9) {
        liberado = 0;
    }
    
     // testa se existe alguma sobreposicao com outro elemento
    for (i = 0; i < 3; i++) {
        if (tabuleiro [linha + i] [coluna + i] != 0) {
            liberado = 0;    
        }
    }

    // sena o há sobreposicao ou excedeu limite, posiciono o elemento
    if (liberado) {
        for (lin = 0; lin < 10; lin++) {
            for (col = 0; col < 10; col++) {
                if (navio_diagonal_direita(x_inicial, y_inicial, col, lin)) {
                    tabuleiro [lin] [col] = 3;
                }    
            }
        }    
    }
}    

// recebe as coordenadas inicias do elemento (A1) e a posição atual no tabuleiro ja convertido e devolve se a celula atual pertence a um navio
int navio_diagonal_esquerda (char x_inicial, int y_inicial, int x_atual, int y_atual) {
    int coluna;
    int linha;
    int i;

    coluna = converte_coluna(x_inicial);
    linha = converte_linha(y_inicial);

    

    if ((linha == y_atual && coluna == x_atual) || (linha + 1 == y_atual && coluna - 1 == x_atual) || (linha + 2 == y_atual && coluna - 2 == x_atual)) {
        return 1;
    } else {
        return 0;
    }
}

// para posicionar o navio, primeiro testa se o navio excedeu os limites do tabuleiro
//  e se esta sobrepondo algum outro elemento, caso isto ocorre nao posiciona o navio
void posiciona_navio_diagonal_esquerda (char x_inicial, int y_inicial) {
    int coluna;
    int linha;
    int i;
    int lin;
    int col;
    int liberado = 1;

    coluna = converte_coluna(x_inicial);
    linha = converte_linha(y_inicial);

    // testa se a linha se encontra fora do limite do tabuleiro
    if (linha < 0 || linha > 9) {
        liberado = 0;
    }

    // testa se a coluna se encontra fora do limite do tabuleiro
    if (coluna < 0 || coluna > 9) {
        liberado = 0;
    }

    // testa se o elemento ultrapassou o limite vertical do tabuleiro
    if (linha + 2 > 9) {
        liberado = 0;
    }

    // testa se o elemento ultrapassou o limite horizontal do tabuleiro
    if (coluna - 2 < 0) {
        liberado = 0;
    }
    
    // testa se existe alguma sobreposicao com outro elemento
    for (i = 0; i < 3; i++) {
        if (tabuleiro [linha + i] [coluna - i] != 0) {
            liberado = 0;    
        }
    }
    

    // se nao há sobreposicao ou excedeu limite, posiciono o elemento
    if (liberado) {
        for (lin = 0; lin < 10; lin++) {
            for (col = 0; col < 10; col++) {
                if (navio_diagonal_esquerda(x_inicial, y_inicial, col, lin)) {
                    tabuleiro [lin] [col] = 3;
                }    
            }
        }    
    }
}    


void habilidades(char x_inicial, int y_inicial, int x_desloc, int y_desloc, int padrao[5][5]) {
    
    int coluna;
    int linha;
    int i;
    int lin;
    int col;
    int liberado = 1;

    coluna = converte_coluna(x_inicial) - x_desloc;
    linha = converte_linha(y_inicial) - y_desloc;

    // testa se a linha se encontra fora do limite do tabuleiro
    if (linha < 0 || linha > 9) {
        liberado = 0;
    }

    // testa se a coluna se encontra fora do limite do tabuleiro
    if (coluna < 0 || coluna > 9) {
        liberado = 0;
    }
    
    // se não excedeu os limites do tabuleiro testo se existe sobreposicao
    if (liberado) {
        // testa se existe alguma sobreposicao com outro elemento
        for (lin = 0; lin < 5; lin++) {
            for (col = 0; col < 5; col++) {
                if (padrao[lin][col]) {
                    if (tabuleiro[lin+linha][col+coluna] != 0) {
                    liberado = 0;
                    }
                }
            }
        }
    }
    if (liberado) {
        // posiciona o elemento no tabuleiro
        for (lin = 0; lin < 5; lin++) {
            for (col = 0; col < 5; col++) {
                tabuleiro[lin+linha][col+coluna] = padrao[lin][col];
            }
        }
    }
}            


void posiciona_cone(char x_inicial, int y_inicial) {
    

    // Padrao Cone
    int cone[5][5] = {
        {8,8,1,8,8},
        {8,1,1,1,8},
        {1,1,1,1,1},
        {8,8,8,8,8},
        {8,8,8,8,8}
        };    
    
    habilidades(x_inicial, y_inicial, 2, 0, cone);
    
}

void posiciona_cruz(char x_inicial, int y_inicial) {
    

    // Padrao Cruz
    int cruz[5][5] = {
        {8,8,1,8,8},
        {8,8,1,8,8},
        {1,1,1,1,1},
        {8,8,1,8,8},
        {8,8,1,8,8}
    };   
    
    habilidades(x_inicial, y_inicial, 2, 2, cruz);
    
}


void posiciona_octaedro(char x_inicial, int y_inicial) {
    

    // Padrao Octaedro
    int octaedro[5][5] = {
        {8,8,8,8,8},
        {8,8,1,8,8},
        {8,1,1,1,8},
        {8,8,1,8,8},
        {8,8,8,8,8}
    }; 
    
    habilidades(x_inicial, y_inicial, 2, 2, octaedro);
    
}


void desenha_tabuleiro() {

    char cabecalho[22] = "   A B C D E F G H I J";
    int linha, coluna;


    printf("%s\n", cabecalho);
    for (linha = 0; linha < 10; linha++) {
        printf("%2d", linha + 1);
        for (coluna = 0; coluna < 10; coluna++) {
            if (tabuleiro [linha][coluna] == 8) {
                printf(" *");    
            } else {
            printf("%2d", tabuleiro [linha][coluna]);    
            }
        }
        printf("\n");
    }    
}
    


int main() {
    int linha, coluna;

    // Inicializa o tabuleiro
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }


    posiciona_octaedro('E', 6);
    posiciona_navio_horizontal ('A', 1);
    posiciona_navio_vertical ('I', 1);
    posiciona_navio_diagonal_direita ('E', 1);
    posiciona_navio_diagonal_esquerda ('D', 2);
    
    desenha_tabuleiro();

    return 0;
}



