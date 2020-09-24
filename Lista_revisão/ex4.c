#include <stdio.h>

int main (){

    float notas[3], total, media, falta;

    for(int i=0; i<3; i++){
        printf("Nota %i: ", i+1);
        scanf("%e", &notas[i]),

        total+= notas[i];
    }

    media = total/3;

    printf("A media do aluno e: %.2f\n", media);

    falta = 21 - total;

    if(media<7){
        if (falta<=10){
            printf("Recuperacao! Precisa tirar: %f\n", falta);
        }else{
            printf("Reprovado!\n");
        }
    }else{
        printf("Aprovado!\n");
    }

    return 0;
}