#include <stdio.h>      // Para funções de entrada/saída (printf, scanf, etc.)
#include <string.h>     // Para manipular strings (strlen, etc.)
#include <locale.h>     // Para permitir acentuação em português no terminal

#define TAM 100         // Define um tamanho padrão para as strings

// Função auxiliar para remover o caractere '\n' que o fgets insere no final da string
void removerNovaLinha(char *str) {
    size_t len = strlen(str);              // Calcula o tamanho da string
    if (len > 0 && str[len - 1] == '\n') { // Se o último caractere for '\n', substitui por '\0'
        str[len - 1] = '\0';
    }
}

// Struct para armazenar dados do responsável
typedef struct {
    char nome[TAM];
    char email[TAM];
    char senha[TAM];
    char dataNascimento[11]; // Formato DD/MM/AAAA
    char cpf[15];            // Formato 000.000.000-00
} Responsavel;

// Struct para armazenar dados do idoso
typedef struct {
    char nome[TAM];
    char dataNascimento[11];
    char cpf[15];
    float peso;
    char temDoenca[4];       // "Sim" ou "Não"
    char qualDoenca[TAM];    // Se tiver Doença, qual?
} Idoso;

int main() {
    setlocale(LC_ALL, "Portuguese"); // Ativa suporte a acentos no terminal

    Responsavel responsavel; // Declara variável do tipo Responsavel
    Idoso idoso;             // Declara variável do tipo Idoso

    // Coleta de dados do responsável
    printf("Cadastro do responsável:\n");

    printf("Nome completo: ");
    fgets(responsavel.nome, TAM, stdin);
    removerNovaLinha(responsavel.nome);

    printf("E-mail: ");
    fgets(responsavel.email, TAM, stdin);
    removerNovaLinha(responsavel.email);

    printf("Senha: ");
    fgets(responsavel.senha, TAM, stdin);
    removerNovaLinha(responsavel.senha);

    printf("Data de nascimento (DD/MM/AAAA): ");
    fgets(responsavel.dataNascimento, sizeof(responsavel.dataNascimento), stdin);
    removerNovaLinha(responsavel.dataNascimento);

    printf("CPF (000.000.000-00): ");
    fgets(responsavel.cpf, sizeof(responsavel.cpf), stdin);
    removerNovaLinha(responsavel.cpf);

    // Coleta de dados do idoso
    printf("\nCadastro do idoso:\n");

    printf("Nome completo: ");
    fgets(idoso.nome, TAM, stdin);
    removerNovaLinha(idoso.nome);

    printf("Data de nascimento (DD/MM/AAAA): ");
    fgets(idoso.dataNascimento, sizeof(idoso.dataNascimento), stdin);
    removerNovaLinha(idoso.dataNascimento);

    printf("CPF (000.000.000-00): ");
    fgets(idoso.cpf, sizeof(idoso.cpf), stdin);
    removerNovaLinha(idoso.cpf);

    printf("Peso (kg): ");
    scanf("%f", &idoso.peso);
    getchar(); // Limpa o '\n' que ficou no buffer após o scanf

    printf("O idoso possui alguma doença? (Sim/Não): ");
    fgets(idoso.temDoenca, sizeof(idoso.temDoenca), stdin);
    removerNovaLinha(idoso.temDoenca);

    // Se respondeu "Sim", perguntar qual Doença
    if (idoso.temDoenca[0] == 'S' || idoso.temDoenca[0] == 's') {
        printf("Qual doença? ");
        fgets(idoso.qualDoenca, TAM, stdin);
        removerNovaLinha(idoso.qualDoenca);
    }

    // Exibe um resumo dos dados cadastrados
    printf("\nResumo do cadastro:\n");

    printf("Responsável: %s\n", responsavel.nome);
    printf("E-mail: %s\n", responsavel.email);
    printf("Data de nascimento: %s\n", responsavel.dataNascimento);
    printf("CPF: %s\n", responsavel.cpf);

    printf("Idoso: %s\n", idoso.nome);
    printf("Data de nascimento: %s\n", idoso.dataNascimento);
    printf("CPF: %s\n", idoso.cpf);
    printf("Peso: %.2f kg\n", idoso.peso);
    printf("Possui alguma doença? %s\n", idoso.temDoenca);

    // Exibe a Doença, se houver
    if (idoso.temDoenca[0] == 'S' || idoso.temDoenca[0] == 's') {
        printf("Doença informada: %s\n", idoso.qualDoenca);
    } else {
        printf("Nenhuma Doença relatada.\n");
    }

    return 0; // Fim do programa
}
