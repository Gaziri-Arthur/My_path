#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[256];
    int partidasGanha;
    int partidasEmpate;
    int partidasDerrota;
    int golsMarcados;
    int golsSofridos;
    int pontuacao;
} Time;

typedef struct
{
    Time *time1;
    Time *time2;
    int golsTime1;
    int golsTime2;
} Partida;

Time *carregarTimes(char *nomeArquivo, int nTimes)
{
    char linha[256];
    FILE *arqTimes;
    Time *times;
    int contTimes = 0;

    arqTimes = fopen(nomeArquivo, "rt");
    if (!arqTimes)
    {
        printf("Erro ao abrir arquivo de times");
        exit(EXIT_FAILURE);
    }

    times = (Time *)calloc(nTimes, sizeof(Time));
    while (fgets(linha, sizeof(linha), arqTimes) != NULL)
    {
        linha[strcspn(linha, "\n")] = '\0';
        if (linha[0] != '#')
        {
            strcpy(times[contTimes].nome, linha);
            contTimes++;
        }
    }

    fclose(arqTimes);
    return times;
}

Time *buscarTime(char *nome, int nTimes, Time *times)
{
    for (int i = 0; i < nTimes; i++)
    {
        if (strcmp(times[i].nome, nome) == 0)
        {
            return &times[i];
        }
    }
    return NULL;
}

Partida *carregarPartidas(char *nomeArquivo, int nPartidas, Time *times, int nTimes)
{
    char linha[256];
    char sTime1[256], sTime2[256];
    int golsTime1, golsTime2;

    FILE *arqPartidas;
    Partida *partidas;
    int contPartidas = 0;

    arqPartidas = fopen(nomeArquivo, "rt");
    if (!arqPartidas)
    {
        perror("Erro ao abrir arquivo de partidas");
        exit(EXIT_FAILURE);
    }

    partidas = (Partida *)calloc(nPartidas, sizeof(Partida));
    while (fgets(linha, sizeof(linha), arqPartidas) != NULL)
    {
        linha[strcspn(linha, "\n")] = '\0';
        if (linha[0] != '#')
        {
            sscanf(linha, "%s %d %d %s", sTime1, &golsTime1, &golsTime2, sTime2);

            Time *time1 = buscarTime(sTime1, nTimes, times);
            Time *time2 = buscarTime(sTime2, nTimes, times);

            partidas[contPartidas].time1 = time1;
            partidas[contPartidas].time2 = time2;
            partidas[contPartidas].golsTime1 = golsTime1;
            partidas[contPartidas].golsTime2 = golsTime2;

            contPartidas++;
        }
    }

    fclose(arqPartidas);
    return partidas;
}

void processarPartidas(Partida *partidas, int nPartidas)
{
    for (int i = 0; i < nPartidas; i++)
    {
        Partida p = partidas[i];
        p.time1->golsMarcados += p.golsTime1;
        p.time1->golsSofridos += p.golsTime2;
        p.time2->golsMarcados += p.golsTime2;
        p.time2->golsSofridos += p.golsTime1;

        if (p.golsTime1 > p.golsTime2)
        {
            p.time1->partidasGanha++;
            p.time1->pontuacao += 3;
            p.time2->partidasDerrota++;
        }
        else if (p.golsTime1 < p.golsTime2)
        {
            p.time2->partidasGanha++;
            p.time2->pontuacao += 3;
            p.time1->partidasDerrota++;
        }
        else
        {
            p.time1->partidasEmpate++;
            p.time2->partidasEmpate++;
            p.time1->pontuacao += 1;
            p.time2->pontuacao += 1;
        }
    }
}

void salvarResultado(Time *times, int nTimes, char *nomeArquivo)
{
    FILE *arqSaida = fopen(nomeArquivo, "wt");
    if (!arqSaida)
    {
        perror("Erro ao criar arquivo de resultados");
        exit(EXIT_FAILURE);
    }

    fprintf(arqSaida, "Time, Pontos, Vitórias, Empates, Derrotas, Saldo de Gols\n");
    for (int i = 0; i < nTimes; i++)
    {
        int saldoGols = times[i].golsMarcados - times[i].golsSofridos;
        fprintf(arqSaida, "%s, %d, %d, %d, %d, %d\n",
                times[i].nome,
                times[i].pontuacao,
                times[i].partidasGanha,
                times[i].partidasEmpate,
                times[i].partidasDerrota,
                saldoGols);
    }

    fclose(arqSaida);
}

int main()
{
    system("cls");
    int nTimes = 10;
    int nPartidas = (nTimes * (nTimes - 1)) / 2;
    Time *times = carregarTimes("times.txt", nTimes);
    Partida *partidas = carregarPartidas("partidas.txt", nPartidas, times, nTimes);

    processarPartidas(partidas, nPartidas);
    salvarResultado(times, nTimes, "resultado.txt");

    printf("Tabela final salva no arquivo 'resultado.txt'.\n");

    free(times);
    free(partidas);

    return 0;
}
