#include <stdio.h>
#include <string.h>

struct Pessoa
{
    char nome[10];
    int idade;
    char sexo[1];
    float peso;
    float altura;
    float imc;
};

int main(){
    struct Pessoa p1, p2, p3;

    strcpy(p1.nome, "Maria");
    p1.idade = 18;
    strcpy(p1.sexo, "F"); 
    p1.peso = 48;
    p1.altura = 1.56;
    p1.imc = p1.peso/(p1.altura*p1.altura);


    strcpy(p2.nome, "Pedro"); 
    p2.idade = 16;
    strcpy(p2.sexo, "M"); 
    p2.peso = 59;
    p2.altura = 1.65;
    p2.imc = p2.peso/(p2.altura*p2.altura);

    strcpy(p3.nome, "Lucas"); 
    p3.idade = 24;
    strcpy(p3.sexo, "M"); 
    p3.peso = 89;
    p3.altura = 1.70;
    p3.imc = p3.peso/(p3.altura*p3.altura);

    printf("%s\n", p1.nome);
    printf("%i\n", p1.idade);
    printf("%f\n", p1.altura);
    printf("%s\n", p1.sexo);
    printf("%f\n", p1.peso);
    printf("%f\n", p1.imc);

    printf("%s\n", p2.nome);
    printf("%i\n", p2.idade);
    printf("%f\n", p2.altura);
    printf("%s\n", p2.sexo);
    printf("%f\n", p2.peso);
    printf("%f\n", p2.imc);

    printf("%s\n", p3.nome);
    printf("%i\n", p3.idade);
    printf("%f\n", p3.altura);
    printf("%s\n", p3.sexo);
    printf("%f\n", p3.peso);
    printf("%f\n", p3.imc);

    return 0;
}
