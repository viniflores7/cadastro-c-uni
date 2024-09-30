// Algorítmo de cadastro de usuário no aplicativo

#include <stdio.h>

int main() {
    char nomeResponsavel[100];
    char email[100];
    char senha[100];
    char dataNascimentoResponsavel[11];
    char cpfResponsavel[15];
    
    char nomeIdoso[100];
    char dataNascimentoIdoso[11];
    char cpfIdoso[15];
    float peso;
    char temDoenca[4]; 
    char qualDoenca[100]; 
    
    printf("Cadastro de responsável:\n");
    printf("Nome completo do responsável: ");
    scanf(" %[^\n]s", nomeResponsavel);
    
    printf("Email do responsável: ");
    scanf(" %[^\n]s", email);

    printf("Senha do responsável: ");
    scanf(" %[^\n]s", senha);

    printf("Data de nascimento do responsável (DD/MM/AAAA): ");
    scanf(" %[^\n]s", dataNascimentoResponsavel);
    
    printf("CPF do responsável (000.000.000-00): ");
    scanf(" %[^\n]s", cpfResponsavel);
    
    printf("\nCadastro de idoso:\n");
    printf("Nome completo do idoso: ");
    scanf(" %[^\n]s", nomeIdoso);
    
    printf("Data de nascimento do idoso (DD/MM/AAAA): ");
    scanf(" %[^\n]s", dataNascimentoIdoso);
    
    printf("CPF do idoso (000.000.000-00): ");
    scanf(" %[^\n]s", cpfIdoso);
    
    printf("Peso do idoso: ");
    scanf("%f", &peso);
    
    printf("O idoso(a) tem alguma doença? (Sim/Não): ");
    scanf("%s", temDoenca);
    
    if (temDoenca[0] == 'S' || temDoenca[0] == 's') {
        printf("Se sim, qual? ");
        scanf(" %[^\n]s", qualDoenca);
    }
    
    printf("\nResumo do cadastro:\n");
    printf("Responsável: %s\n", nomeResponsavel);
    printf("Email: %s\n", email);
    printf("Data de nascimento: %s\n", dataNascimentoResponsavel);
    printf("CPF: %s\n", cpfResponsavel);
    
    printf("Idoso: %s\n", nomeIdoso);
    printf("Data de nascimento: %s\n", dataNascimentoIdoso);
    printf("CPF: %s\n", cpfIdoso);
    printf("Peso: %.2f\n", peso);
    printf("Tem alguma doença? %s\n", temDoenca);
    
    if (temDoenca[0] == 'S' || temDoenca[0] == 's') {
        printf("O idoso possui a seguinte doença: %s\n", qualDoenca);
    } else {
        printf("O idoso não possui doenças relatadas.\n");
    }

    return 0;
}
