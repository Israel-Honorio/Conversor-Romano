// Copyright 2025 Israel Honório
// Conversor de números romanos

#include "romanos.hpp"
#include <cstring>

int valor_algarismo(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1;
    }
}

bool pode_subtrair(char c) {
    return (c == 'I' || c == 'X' || c == 'C');
}

int romanos_para_decimal(const char* num_romano) {
    int tamanho = strlen(num_romano);
    if (tamanho == 0 || tamanho > 30) return -1;

    // Verifica caracteres inválidos
    for (int i = 0; i < tamanho; i++) {
        if (valor_algarismo(num_romano[i]) == -1) return -1;
    }

    // Verifica repetições de V, L, D e consecutivos de I, X, C, M
    int contador_V = 0, contador_L = 0, contador_D = 0;
    for (int i = 0; i < tamanho; i++) {
        switch (num_romano[i]) {
            case 'V': if (++contador_V > 1) return -1; break;
            case 'L': if (++contador_L > 1) return -1; break;
            case 'D': if (++contador_D > 1) return -1; break;
            default: break;
        }

        // Verifica repetições consecutivas de I, X, C, M (max 3)
        if (i > 0 && num_romano[i] == num_romano[i-1]) {
            char c = num_romano[i];
            if (c == 'I' || c == 'X' || c == 'C' || c == 'M') {
                int contador = 1;
                while (i < tamanho && num_romano[i] == c) {
                    contador++;
                    i++;
                }
                if (contador > 3) return -1;
                i--;
            }
        }
    }

    int resultado = 0;
    for (int i = 0; i < tamanho; i++) {
        int valor_atual = valor_algarismo(num_romano[i]);

        if (i + 1 < tamanho) {
            int valor_proximo = valor_algarismo(num_romano[i+1]);
            if (valor_atual < valor_proximo) {
                // Verifica se a subtração é válida
                if (!pode_subtrair(num_romano[i]) || 
                    (i > 0 && num_romano[i] == num_romano[i-1])) { // <--- NOVA VALIDAÇÃO
                    return -1;
                }

                // Valida pares de subtração
                if ((valor_atual == 1 && (valor_proximo != 5 && valor_proximo != 10)) ||
                    (valor_atual == 10 && (valor_proximo != 50 && valor_proximo != 100)) ||
                    (valor_atual == 100 && (valor_proximo != 500 && valor_proximo != 1000))) {
                    return -1;
                }

                resultado -= valor_atual;
            } else {
                resultado += valor_atual;
            }
        } else {
            resultado += valor_atual;
        }
    }

    return (resultado > 3000) ? -1 : resultado;
}