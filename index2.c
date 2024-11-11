#include <stdio.h>
#include <stdlib.h>

int main() {
    const int TOTAL_PHASES = 6;
    
    int* progress = (int*)malloc(TOTAL_PHASES * sizeof(int));
    if (progress == NULL) {
        printf("Falha na alocação de memória para progress!\n");
        return 1;
    }
    
    for (int i = 0; i < TOTAL_PHASES; i++) {
        progress[i] = 0;
    }

    int phases_completed = 0;
    int choice;

    const char* phases[] = {
        "Planejamento",
        "Desenvolvimento Inicial",
        "Testes de Integração",
        "Testes de Qualidade",
        "Implementação de Funcionalidades",
        "Finalização"
    };

    printf("Simulação do Progresso do Desenvolvimento do Projeto\n");
    printf("=====================================================\n");
    printf("Vamos acompanhar o progresso das principais fases do projeto!\n");

    while (phases_completed < TOTAL_PHASES) {
        printf("\nStatus atual do progresso do projeto:\n");

        for (int i = 0; i < TOTAL_PHASES; i++) {
            printf("%d. %s - %d%% concluída\n", i + 1, phases[i], progress[i]);
        }

        printf("\nEscolha uma fase para atualizar o progresso (1 a %d): ", TOTAL_PHASES);
        scanf("%d", &choice);

        if (choice < 1 || choice > TOTAL_PHASES) {
            printf("Escolha inválida! Por favor, selecione uma fase entre 1 e %d.\n", TOTAL_PHASES);
            continue;
        }

        int phase = choice - 1;

        if (progress[phase] == 100) {
            printf("A fase %s já foi concluída!\n", phases[phase]);
            continue;
        }

        printf("Digite o progresso atual para %s (0 a 100): ", phases[phase]);
        int new_progress;
        scanf("%d", &new_progress);

        if (new_progress < 0 || new_progress > 100) {
            printf("Progresso inválido! Insira um valor entre 0 e 100.\n");
            continue;
        }

        progress[phase] = new_progress;
        if (progress[phase] == 100) {
            printf("Parabéns! A fase %s foi concluída!\n", phases[phase]);
            phases_completed++;
        } else {
            printf("Progresso de %s atualizado para %d%%.\n", phases[phase], progress[phase]);
        }
    }

    printf("\nTodas as fases do projeto foram concluídas com sucesso! Parabéns pelo progresso finalizado!\n");

    free(progress);

    return 0;
}
