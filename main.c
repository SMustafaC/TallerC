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
    bool aux;
    for (int i = 0; i < strlen(chain)-1; i++){
        chain[i] = toupper(chain[i]);
        if(chain[i] == 'O' || chain[i] == 'X' ){
            aux = true;
        }else{
            aux = false;
            break;
        }        
    }
    return aux;
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

void magicNumbers() {
    char chainNum[30];
    int num = 0;
    int aux = 0;
    int cont = 0;
    int n = 0;
    int numOne = 0;
    int numTwo = 0;
    int rest = 0;
    int numVec = 0;
    
    printf("Digite la cantidad de cifras del número mágico\n");    
    fgets(chainNum,30,stdin);
    if(validateNumbers(chainNum)){
    num = atoi(chainNum);
    int nOne[num];
    int nTwo[num];
    int vector[num];
    int auxVect[num];
    
    printf("Digite de cifra en cifra el número mágico\n");
    
    for(int i = 0; i < num; i++) {
        printf("Cifra %d: ", cont);
        scanf("%d", &n);
        getchar();
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
    
    printf("\n\nNúmero ordenado Ascendente\n");
    
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
    
    printf("\n\nNúmero ordenado Descendente\n");
    
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
    
    }else{
        printf("%s","!!ERROR¡¡\nSolo ingrese valores numericos");
    }        
}

/**
 * Método donde se ejecuta la serie fibonacci.
 * 
 * Recibe un valor numérico, el cual es la cantidad de veces que se repetira
 * la serie.
 * 
 * Retorna un char con la cadena a buscar.
 * 
 * @param num
 * @return 
 */
char* functionFibo(int num) {
    char* chain = "";
    char* func1 = "";
    char* func2 = "";
    
    if(num == 0) {
        chain = "0";
    }
    
    else if(num == 1) {
        chain = "1";
    }
    
    else if(num >= 2) {
        func1 = functionFibo(num - 1);
        func2 = functionFibo(num - 2);
        const size_t linea1 = strlen(func1);
        const size_t linea2 = strlen(func2);
        
        char* result = malloc(linea1 + linea2 + 1);
        memcpy(result, func1, linea1);
        memcpy(result + linea1, func2, linea2 + 1);
        
        chain = result;
    }
    return chain;
}

/**
 * Método para comparar las cadenas y buscar la cadena elegida por el
 * usuario
 * 
 * Recibe dos char, una cadena ingresada por el usuario y otra cadena
 * que es devuelta del método de la serie fibonacci
 * 
 * Retorna un valor entero de la cantidad de veces que se repite la cadena
 * 
 * @param chain
 * @param chain2
 * @return 
 */

int comparacion(char* chain, char* chain2) {
    int cont = 0;
    char* search = NULL;
    
    search = strstr(chain, chain2);
    
    while(search != 0) {
        cont++;
        search = strstr(search + 1, chain2);
    }
    
    return cont;
}



void body_Mass_Index() {

    float IMC;
    char gender;
    
    printf("Ingrese el género (F/M): ");
    scanf("%c", & gender);
    getchar();

    printf("%s", "Ingrese la estatura en cm: ");
    char chainStature[30];
    fgets(chainStature, 30, stdin);

    if (validateNumbers(chainStature)) {
        int stature = atoi(chainStature);

        printf("%s", "Ingrese el peso en kg: ");
        char chainWeight[30];
        fgets(chainWeight, 30, stdin);

        if (validateNumbers(chainWeight)) {
            int bodyWeight = atoi(chainWeight);
            float statureM = ((float) stature / 100);
            
            IMC = bodyWeight / (statureM * statureM);

            printf("Su indice de masa corporal es: %f\n", IMC);
            
            printf("Su diagnostico es: ");

            if (gender == 'f' || gender == 'F') {
                if (IMC < 16) {
                    printf("Desnutricion");
                } else if (IMC > 16 && IMC < 20) {
                    printf("Bajo peso");
                } else if (IMC > 20 && IMC < 24) {
                    printf("Normal");
                } else if (IMC > 24 && IMC < 29) {
                    printf("Sobrepeso");
                } else if (IMC > 29 && IMC < 34) {
                    printf("Obesidad");
                } else if (IMC > 34 && IMC < 39) {
                    printf("Obesidad marcada");
                } else if (IMC > 39) {
                    printf("Obesidad morbida");
                }
            } else if (gender == 'm' || gender == 'M') {
                if (IMC < 17) {
                    printf("Desnutricion");
                } else if (IMC > 17 && IMC < 20) {
                    printf("Bajo peso");
                } else if (IMC > 20 && IMC < 25) {
                    printf("Normal");
                } else if (IMC > 25 && IMC < 30) {
                    printf("Sobrepeso");
                } else if (IMC > 30 && IMC < 35) {
                    printf("Obesidad");
                } else if (IMC > 35 && IMC < 40) {
                    printf("Obesidad marcada");
                } else if (IMC > 40) {
                    printf("Obesidad morbida");
                }
            } else {
                printf("Genero no reconocido, ingrese M (Masculino) ó F (Femenino)");
            }
        } else {
            printf("!ERROR¡ Ingrese el peso en kilogramos");
        }
    } else {
        printf("!ERROR¡ Ingrese el la estatura en centímetros");
    }
}

void sum_Excluded_Numbers() {
    printf("Ingrese los valores del rango numérico\n");

    printf("%s", "Valor 1: ");
    char chainNumb1[30];
    fgets(chainNumb1, 30, stdin);

    if (validateNumbers(chainNumb1)) {
        int num1 = atoi(chainNumb1);

        printf("%s", "Valor 2: ");
        char chainNumb2[30];
        fgets(chainNumb2, 30, stdin);

        if (validateNumbers(chainNumb2)) {
            int num2 = atoi(chainNumb2);

            printf("%s", "Ingrese el numero sin tener en cuenta: ");
            char chainExc[30];
            fgets(chainExc, 30, stdin);

            if (validateNumbers(chainExc)) {
                int contNull = atoi(chainExc);
                int tam = (num2 - num1) + 1;
                int valores[tam];

                int longitud = sizeof (valores) / sizeof (valores[0]);

                int cont = 0;
                for (int i = num1; i <= num2; i++) {
                    valores[cont] = i;
                    cont++;
                }

                int a, b, c, d, e;
                int contVal;
                int exc = 0;

                for (int i = 0; i <= (num2 - num1); i++) {
                    int numero = valores[i];

                    a = numero / 10000;
                    b = (numero % 10000) / 1000;
                    c = (numero % 10000) % 1000 / 100;
                    d = ((numero % 10000) % 1000) % 100 / 10;
                    e = (((numero % 10000) % 1000) % 100) % 10;
                    int vector[5] = {a, b, c, d, e};

                    int longitud2 = sizeof (vector) / sizeof (vector[0]);

                    for (int j = 0; j <= longitud2 - 1; j++) {
                        if (vector[j] == contNull) {
                            exc++;
                        } else {
                            contVal += vector[j];
                        }
                    }
                }
                printf("La suma es: %d\n", (contVal - 1));
                printf("No se tuvieron en cuenta %d dígitos", exc);
            } else {
                printf("!ERROR¡Ingrese valores enteros");
            }
        } else {
            printf("!ERROR¡Ingrese valores enteros");
        }
    } else {
        printf("!ERROR¡Ingrese valores enteros");
    }
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
                magicNumbers();
                break;
            case '4':
                printf("%s","**Indice Masa Corporal**\n");
                body_Mass_Index();
                break;
            case '5':
                printf("%s","**Suma Numeros Excluidos**");
                sum_Excluded_Numbers();
                break;
            case '6':
                printf("%s","**F(n)**");
                int num = 0;
                char* chain2 = "";
                
                printf("\nDigite valor de repetición para Serie Fibonacci\n");
                scanf("%d", &num);
                getchar();
                printf("Digite la cadena que desea buscar\n");
                scanf("%s", &chain2);
                getchar();
                
                char* chain1 = functionFibo(num);
                
                printf("La cadena se repite ");
                printf("%d", comparacion(chain1, &chain2));
                printf(" veces en la serie\n");
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
