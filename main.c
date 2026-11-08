#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removerQuebraLinha(char entrada[]) {
    entrada[strcspn(entrada, "\n")] = '\0';
}

int lerOpcao() {
    char entrada[100];
    char *fim;
    long opcao;

    while (1) {
        printf("Opção: ");

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            return 5;
        }

        removerQuebraLinha(entrada);

        opcao = strtol(entrada, &fim, 10);

        if (entrada == fim || *fim != '\0' ||
            opcao < 1 || opcao > 5) {
            printf("Opção inválida! Digite um número entre 1 e 5.\n");
        } else {
            return (int)opcao;
        }
    }
}

int lerNumero(char mensagem[], double *numero) {
    char entrada[100];
    char *fim;

    printf("%s", mensagem);

    if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
        return 0;
    }

    removerQuebraLinha(entrada);

    *numero = strtod(entrada, &fim);

    if (entrada == fim || *fim != '\0') {
        printf("Erro: Número inválido.\n");
        return 0;
    }

    return 1;
}

char perguntarContinuacao() {
    char entrada[100];

    while (1) {
        printf("\nDeseja realizar outra operação? (s/n): ");

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            return 'n';
        }

        removerQuebraLinha(entrada);

        if (strcmp(entrada, "s") == 0 ||
            strcmp(entrada, "S") == 0) {
            return 's';
        }

        if (strcmp(entrada, "n") == 0 ||
            strcmp(entrada, "N") == 0) {
            return 'n';
        }

        printf("Resposta inválida. Digite 's' para sim ou 'n' para não.\n");
    }
}

int main() {
    int opcao;
    double num1, num2, resultado;
    char continuar;

    do {
        printf("\n===============================\n");
        printf("       Calculadora Simples\n");
        printf("===============================\n");
        printf("Selecione uma operação:\n");
        printf("1. Adição\n");
        printf("2. Subtração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("5. Sair\n");

        opcao = lerOpcao();

        if (opcao == 5) {
            printf("\nObrigado por usar a calculadora! Até a próxima.\n");
            break;
        }

        int valido = 1;

        if (!lerNumero("Digite o primeiro número: ", &num1)) {
            valido = 0;
        } else if (!lerNumero("Digite o segundo número: ", &num2)) {
            valido = 0;
        }

        if (valido) {
            switch (opcao) {
                case 1:
                    resultado = num1 + num2;
                    printf("Resultado: %g + %g = %g\n",
                           num1, num2, resultado);
                    break;

                case 2:
                    resultado = num1 - num2;
                    printf("Resultado: %g - %g = %g\n",
                           num1, num2, resultado);
                    break;

                case 3:
                    resultado = num1 * num2;
                    printf("Resultado: %g * %g = %g\n",
                           num1, num2, resultado);
                    break;

                case 4:
                    if (num2 == 0) {
                        printf("Erro: Divisão por zero não é permitida.\n");
                    } else {
                        resultado = num1 / num2;
                        printf("Resultado: %g / %g = %g\n",
                               num1, num2, resultado);
                    }
                    break;
            }
        }

        continuar = perguntarContinuacao();

        if (continuar == 'n') {
            printf("\nObrigado por usar a calculadora! Até a próxima.\n");
            break;
        }

    } while (1);

    return 0;
}
