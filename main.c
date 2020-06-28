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
    printf("El numero %d %s\n",number, number == calculateEgomaniacNumber(chainNum) ? "es EGOLATRA" : "NO es EGOLATRA");
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
    printf("El puntaje es: %d \n", calculateScore(chain));
}

void cousingNumber() {
    int numOne;
    int contador; 
    int primo;
    
    printf("Ingrese un valor\n");
    scanf("%i", &numOne);
    printf("\nNúmeros primos ordenados descendentemente desde %i\n", numOne);
    
    
    for(int i = numOne; i >= 2; i--) {
        primo = 1;
        contador = 2;
        
        while(contador <= i/2 && primo) {
            if(i % contador == 0) {
                primo = 0;
            }
            contador++;
        }
        if(primo) {
            printf("%d\n", i);
        }
    }
}

void magicNumbers() {
    int num = 0;
    int aux = 0;
    int cont = 0;
    int n = 0;
    int numOne = 0;
    int numTwo = 0;
    int rest = 0;
    int numVec = 0;
    
    printf("Digite la cantidad de cifras del número mágico\n");
    scanf("%i", &num);
    
    int nOne[num];
    int nTwo[num];
    int vector[num];
    int auxVect[num];
    
    printf("Digite de cifra en cifra el número mágico\n");
    
    for(int i = 0; i < num; i++) {
        printf("Cifra %d: ", cont);
        scanf("%d", &n);
        vector[i] = n;
        cont++;
    }
    
    /**
     * Numero ingresado, listo para ordenar
     * 
     */
    printf("\nEl número es: \n");
    for(int i = 0; i < num; i++) {
        printf("%d ", vector[i]);
    }
    
    /**
     * Ordenamiento Ascendente
     * 
     */
    
    for(int i = 0; i < num; i++) {
        auxVect[i] = vector[i];
    }
    
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num - (i+1); j++) {
            if(auxVect[j] > auxVect[j+1]) {
                aux = auxVect[j];
                auxVect[j] = auxVect[j+1];
                auxVect[j+1] = aux;
            }
        }
    }
    
    printf("\n\nNúmero ordenado Ascendente(?)\n");
    
    for(int i = 0; i < num; i++) {
        printf("%d ", auxVect[i]);
        nOne[i] = auxVect[i];
    }
    
    /**
     * Ordenamiento Descendente
     * 
     */
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num - (i+1); j++) {
            if(auxVect[j] < auxVect[j+1]) {
                aux = auxVect[j];
                auxVect[j] = auxVect[j+1];
                auxVect[j+1] = aux;
            }
        }
    }
    
    printf("\n\nNúmero ordenado Descendente(?)\n");
    
    for(int i = 0; i < num; i++) {
        printf("%d ", auxVect[i]);
        nTwo[i] = auxVect[i];
    }
    
    
    /**
     * Conversion de array a integer
     * 
     */
    for(int i = 0; i < num; i++) {
        numVec = 10 * numVec + vector[i];
    }
    
    for(int i = 0; i < num; i++) {
        numOne = 10 * numOne + nOne[i];
    }
    
    for(int i = 0; i < num; i++) {
        numTwo = 10 * numTwo + nTwo[i];
    }
    
    
    /**
     * Resta de numero descendente con numero ascendente
     * 
     */
    rest = (numTwo - numOne);
    
    printf("\n\nResta de número descendente y ascendente: \n%i\n", rest);
    
    if(rest == numVec) {
        printf("\nEl número ingresado, SÍ es número mágico\n");
    } else {
        printf("\nEl número ingresado, NO es número mágico\n");
    }
    
}
void mainMenu(){
    char option;
    do{
        printf("\n<<<<MENU>>>\n\n "
               "1.Numeros Primos\n "
               "2.Numero Egolatra\n "
               "3.Numero Magico\n "
               "4.Indice Masa Corporal\n "
               "7.Juego de Puntajes\n "
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
                magicNumbers();
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
