#include <stdio.h>
#include <stdlib.h>

struct info{
    char nome[50], email[50];
    int idade;
    
    };

int main() {
    FILE *arquivo;
    int numUsuarios;
    
   printf("Digite o número de usuários: ");
    scanf("%d", &numUsuarios);


    struct info *user = (struct info *)malloc(numUsuarios * sizeof(struct info));
  

    arquivo = fopen("usuarios.csv", "w");

 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; 
    }
    
    fprintf(arquivo, "Nome,Idade,E-mail\n");

    
    for (int i = 0; i < numUsuarios; ++i) {
       
        printf("\nUsuário %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", user[i].nome); 
        printf("Idade: ");
        scanf("%d", &user[i].idade);
        printf("E-mail: ");
        scanf("%s", user[i].email);

        for (int i = 0; i < numUsuarios; ++i) {
        fprintf(arquivo, "%s,%d,%s\n", user[i].nome, user[i].idade, user[i].email);
    }

    }

    
    fclose(arquivo);

    printf("\nDados gravados com sucesso no arquivo usuarios.csv.\n");

   free(user);
    return 0; 
}
