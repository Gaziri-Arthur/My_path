#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    char nome[256];
    int partidasGanha;
    int partidasEmpate;
    int partidasDerrota;
    int pontuacao;
}Time;

typedef struct{
    
    Time* time1;
    Time* time2;
    int golsTime1;
    int golsTime2;
}Partida;

Time* carregarTimes(char* nomeArquivo, int nTimes){
    char linha[256];
    FILE* arqTimes;
    Time* times;
    int contTimes=0;

    arqTimes = fopen(nomeArquivo,"rt");
    times = (Time*) calloc(nTimes,sizeof(Time));
    
    while(fgets(linha, sizeof(linha),arqTimes) != NULL){
        
        linha[strcspn(linha, "\n")] = '\0';
        if(linha[0] != '#'){
            strcpy(times[contTimes].nome,linha);
            contTimes += 1;
        }
    }
    return times;
}

Time* buscarTime(char* nome, int nTimes, Time* times){

    for(int i=0;i<nTimes;i++){
        if(strcmp(times[i].nome,nome) == 0){
            return &times[i];
        }
    }
    return NULL;

}


Partida* carregarPartidas(char* nomeArquivo, int nTimes, Time* times){
    char linha[256];
    char sTime1[256];
    char sTime2[256];
    char sGolsTime1[256];
    char sGolsTime2[256];

    Time* time1;
    Time* time2;
    int golsTime1;
    int golsTime2;

    FILE* arqPartidas;
    Partida* partidas;
    int contPartidas=0;
    int nPartidas = (nTimes/2)*(nTimes/2);
    char* token;

    arqPartidas = fopen(nomeArquivo,"rt");
    partidas = (Partida*) calloc(nPartidas,sizeof(Partida));
    
    while(fgets(linha, sizeof(linha),arqPartidas) != NULL){
        
        linha[strcspn(linha, "\n")] = '\0';
        if(linha[0] != '#'){

            token = strtok(linha," ");
            strcpy(sTime1,token);
            token = strtok(NULL," ");   
            strcpy(sGolsTime1,token);
            token = strtok(NULL," ");
            strcpy(sGolsTime2,token);
            token = strtok(NULL," ");
            strcpy(sTime2,token);

            time1 = buscarTime(sTime1,nTimes,times);
            time2 = buscarTime(sTime2,nTimes,times);
            golsTime1 = atoi(sGolsTime1);
            golsTime2 = atoi(sGolsTime2);

            partidas[contPartidas].time1 = time1;
            partidas[contPartidas].time2 = time2;
            partidas[contPartidas].golsTime1 = golsTime1;
            partidas[contPartidas].golsTime2 = golsTime2;

            contPartidas += 1;
        }
    }

    return partidas;
}


int main(int argc, char* argv){

    int nTimes=10;
    int nPartidas=(nTimes/2)*(nTimes/2);
    int contTimes = 0;
    Time* times;
    Partida* partidas;


    times = carregarTimes("times.txt",nTimes);
    //partidas = carregarPartidas("partidas.txt",nTimes,times);

    for(int i=0;i<nTimes;i++){
        printf("%s\n",times[i].nome);
    }

    /*for(int i=0;i<nPartidas;i++){
        printf("%s %d X %d %s\n",partidas[i].time1->nome,partidas[i].golsTime1,partidas[i].golsTime2,partidas[i].time2->nome);
    }*/

}