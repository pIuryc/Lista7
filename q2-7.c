// #include <stdio.h>
// #include <stdlib.h>

// typedef struct estoque {
//     int registro;
//     char nome[50];
//     int quantidade;
//     float custo;
// }estoque;


// void inicializarArquivo() {
//     estoque ferramentas[100];
//     for (int i = 0; i < 100; i++) {
//         ferramentas[i].registro = i + 1;
//         ferramentas[i].nome[0] = '\0';
//         ferramentas[i].quantidade = 0;
//         ferramentas[i].custo = 0.0;
//     }

//     FILE *arquivo = fopen("hardware.dat", "wb");
//     if (arquivo != NULL) {
//         fwrite(&ferramentas, sizeof(estoque), 100, arquivo);
//         fclose(arquivo);
//     }
// }

// void listarFerramentas() {
//    estoque ferramentas[100];
//     FILE *arquivo = fopen("hardware.dat", "rb");
//     if (arquivo != NULL) {
//         fread(ferramentas, sizeof(estoque), 100, arquivo);
//         fclose(arquivo);

//         for (int i = 0; i < 100; i++) {
//             if (ferramentas[i].nome[0] != '\0') {
//                 printf("Registro: %d, Nome: %s, Quantidade: %d, Custo: %.2f\n", ferramentas[i].registro,
//                        ferramentas[i].nome, ferramentas[i].quantidade, ferramentas[i].custo);
//             }
//         }
//     }
// }

// void inserirFerramenta() {
//     estoque ferramenta;
//     printf("Digite o registro da ferramenta: ");
//     scanf("%d", &ferramenta.registro);
//     printf("Digite o nome da ferramenta: ");
//     scanf("%s", ferramenta.nome);
//     printf("Digite a quantidade da ferramenta: ");
//     scanf("%d", &ferramenta.quantidade);
//     printf("Digite o custo da ferramenta: ");
//     scanf("%f", &ferramenta.custo);

//     FILE *arquivo = fopen("hardware.dat", "rb+");
//     if (arquivo != NULL) {
//         fseek(arquivo, (ferramenta.registro - 1) * sizeof(estoque), SEEK_SET);
//         fwrite(&ferramenta, sizeof(estoque), 1, arquivo);
//         fclose(arquivo);
//     }
// }

// void excluirFerramenta() {
//     int registro;
//     printf("Digite o registro da ferramenta a ser excluída: ");
//     scanf("%d", &registro);

//     estoque ferramenta;
//     ferramenta.registro = registro;
//     ferramenta.nome[0] = '\0';
//     ferramenta.quantidade = 0;
//     ferramenta.custo = 0.0;

//     FILE *arquivo = fopen("hardware.dat", "rb+");
//     if (arquivo != NULL) {
//         fseek(arquivo, (registro - 1) * sizeof(estoque), SEEK_SET);
//         fwrite(&ferramenta, sizeof(estoque), 1, arquivo);
//         fclose(arquivo);
//     }
// }

// void editarFerramenta() {
//     int registro;
//     printf("Digite o registro da ferramenta a ser editada: ");
//     scanf("%d", &registro);

//     estoque ferramenta;
//     FILE *arquivo = fopen("hardware.dat", "rb+");
//     if (arquivo != NULL) {
//         fseek(arquivo, (registro - 1) * sizeof(estoque), SEEK_SET);
//         fread(&ferramenta, sizeof(estoque), 1, arquivo);

//         if (ferramenta.nome[0] != '\0') {
//             printf("Registro: %d, Nome: %s, Quantidade: %d, Custo: %.2f\n", ferramenta.registro,
//                    ferramenta.nome, ferramenta.quantidade, ferramenta.custo);

//             printf("Digite o novo nome da ferramenta: ");
//             scanf("%s", ferramenta.nome);
//             printf("Digite a nova quantidade da ferramenta: ");
//             scanf("%d", &ferramenta.quantidade);
//             printf("Digite o novo custo da ferramenta: ");
//             scanf("%f", &ferramenta.custo);

//             fseek(arquivo, (registro - 1) * sizeof(estoque), SEEK_SET);
//             fwrite(&ferramenta, sizeof(estoque), 1, arquivo);
//         } else {
//             printf("Ferramenta não encontrada.\n");
//         }

//         fclose(arquivo);
//     }
// }

// int main() {
//     FILE *arquivo = fopen("hardware.dat", "rb");
//     if (arquivo == NULL) {
//         fclose(arquivo);
//         inicializarArquivo();
//     }

//     int opcao;
//     do {
//         printf("\nEscolha uma opção:\n");
//         printf("1. Adicionar ferramenta\n");
//         printf("2. Excluir ferramenta\n");
//         printf("3. Editar ferramenta\n");
//         printf("4. Listar ferramentas\n");
//         printf("5. Sair\n");
//         printf("Opção: ");
//         scanf("%d", &opcao);

//         switch (opcao) {
//             case 1:
//                 inserirFerramenta();
//                 break;
//             case 2:
//                 excluirFerramenta();
//                 break;
//             case 3:
//                 editarFerramenta();
//                 break;
//             case 4:
//                 listarFerramentas();
//                 break;
//             case 5:
//                 printf("Encerrando o programa.\n");
//                 break;
//             default:
//                 printf("Opção inválida. Tente novamente.\n");
//         }
//     } while (opcao != 5);

//     return 0;
// }
