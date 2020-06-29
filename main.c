/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Asus
 *
 * Created on 20 de junio de 2020, 11:16 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/*
 * Funciones para validación de datos.
 */
bool validateChain(char chain[]){
    
    for (int i = 0; i < strlen(chain)-1; i++){
        chain[i] = toupper(chain[i]);
        while (chain[i] == 'O' || chain[i] == 'X' ){
            return true;
        }
        break;
    }
    return false;
}

bool validateNumbers(char num[]){
    for (int i = 0; i < strlen(num)-1; i++){
        if(!isdigit(num[i]) ) {
            return false;
        }
    }
    return true;
}
/*
 * FIN funciones validación de datos.
 */

int calculateEgomaniacNumber(char chainNumber[]){
    int nume;
    int suma=0;
    for(int i = 0; i<strlen(chainNumber)-1; i++){
        nume = chainNumber[i] - '0';
        suma+=pow(nume,strlen(chainNumber)-1);
    }
    return suma;
}
void egomaniacNumber(){
    char chainNum[30];
    printf("%s","Digite el numero:");
    fgets(chainNum,30,stdin);
    int number = atoi(chainNum);
    validateNumbers(chainNum) ? printf("El numero %d %s\n",number, number == calculateEgomaniacNumber(chainNum) ? "es EGOLATRA" : "NO es EGOLATRA") : printf("%s","¡¡ERROR!!\nIngrese unicamente valores numericos\n");
}

int calculateScore(char chain[]){
    int cont = 0;
    int suma = 0;
    for(int i = 0; i < strlen(chain)-1; i++){
        if (chain[i] == 'o' || chain[i] == 'O'){
            cont++;
            suma = cont+suma;
        }else{
            cont = 0;
        }
    }
    return suma;
}

void score(){
    char chain[30];
    printf("%s","Digite la cadena:");
    fgets(chain, 30, stdin);
    if (validateChain(chain)){
        printf("El puntaje es: %d \n", calculateScore(chain));
    }else{
        printf("%s","!!ERROR¡¡\nLa cadena solo debe contener las letras 'X' y/o 'O'\n");
    }
}

void cousingNumber() {
    char numOne[30];
    int contador;
    int primo;
    printf("%s","Ingrese un valor:");
    fgets(numOne,30,stdin);
    if(validateNumbers(numOne)){
        int number = atoi(numOne);
        printf("Números primos ordenados descendentemente desde %i\n",number);
        for(int i = number; i >= 1; i--) {
            primo = 1;
            contador = 2;
            while(contador <= i/2 && primo) {
                if(i % contador == 0) {
                    primo = 0;
                }
                contador++;
            }
            if(primo) {
                printf("%d\t", i);
            }
        }
    }else{
         printf("%s","¡¡ERROR!!\nIngrese unicamente valores numericos.\n");
    }
}

int descendingOrdering(char chain[]){
    int number;
    for(int i = 0; i<strlen(chain)-2;i++){
        for(int j=i+1; j<strlen(chain)-1;j++){
            if(chain[i] > chain[j]){
                char varAux;
                varAux = chain[i];
                chain[i] = chain[j];
                chain[j] = varAux;
            }
        }
    }
    number = atoi(chain);
    return number;
}
int ascendingOrdering(char chain[]){
    int number;
    for(int i = 0; i<strlen(chain)-2;i++){
        for(int j=i+1; j<strlen(chain)-1;j++){
            if(chain[i] < chain[j]){
                char varAux;
                varAux = chain[i];
                chain[i] = chain[j];
                chain[j] = varAux;
            }
        }
    }
    number = atoi(chain);
    return number;
}
int calculateMagicNumber(int biggerNum, int lowerNum){
    int substraction =biggerNum - lowerNum;
    return substraction;
}
void magicNumber(){
    char chain[30];
    printf("%s","Digite el número:");
    fgets(chain,30,stdin);
    int number = atoi(chain);
    validateNumbers(chain) ? calculateMagicNumber(ascendingOrdering(chain),descendingOrdering(chain)) == number ? printf("%s,%d,%s","El numero ",number," es MAGICO\n"): printf("%s %d %s","El numero ",number," NO es MAGICO\n") : printf("%s","ERROR");   
}
void mainMenu(){
    char option;
    do{
        printf("\n<<<<MENU>>>\n\n "
               "1.Numeros Primos\n "
               "2.Numero Egolatra\n "
               "3.Numero Magico\n "
               "4.Indice Masa Corporal\n"
               " 5.Suma Numeros Excluidos\n"
               " 6.F(n)\n"
               " 7.Juego de Puntajes\n "
               "Digite: [s/S]-Salir\n");
        scanf("%c",&option);
        getchar();
        fflush(stdin);
        switch (option) {
            case '1':
                printf("%s","**Numeros Primos Descendentemente**\n");
                cousingNumber();
                break;
            case '2':
                printf("%s","**Numero Egolatra**\n");
                egomaniacNumber();                
                break;
            case '3':
                printf("%s","**Numero Magico**\n");
                magicNumber();
                break;
            case '4':
                printf("%s","**Indice Masa Corporal**\n");
                break;
            case '5':
                printf("%s","**Suma**");
                break;
            case '6':
                printf("%s","**F(n)**");
                break;
            case '7':
                printf("%s","**Juego de Puntajes**\n\n");              
                score();
                break;
        }
    }while (toupper(option) != 'S');

}

int main() {       
    mainMenu();
    return (EXIT_SUCCESS);
}
