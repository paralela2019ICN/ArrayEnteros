#include <iostream>
#include <string>
using namespace std;

void llenar_polinomio (int largo, char polinomio_letras[], int polinomio_numeros[]){
    int multiplicador;  //valor para que se multiplique por 1,10,100,1000 etc
    int indice_fijo;  //valor para mantener el infice fijo del lugar del polinomio de char
    int exponente;   // valor para guardar en la casilla del arreglo (exponente=casilla del arreglo)
    for (int i=0;i<largo;i++){
        if (polinomio_letras[i]=='x'){
            multiplicador=1;  //asociacion inicial de 1 para que se resetee cuando encuentre otros valores grandes
            indice_fijo=i;
            exponente=(polinomio_letras[i+3]-48);   //numero del exponente asociado
            while (polinomio_letras[indice_fijo-1]!='+' && polinomio_letras[indice_fijo-1]!='-'){  //recorrido hacia atras mientras no sea un + o un -
                if (polinomio_letras[indice_fijo-2]=='-'){  //en caso de que el numero sea negativo
                    polinomio_numeros[exponente]=(polinomio_numeros[exponente]+((polinomio_letras[indice_fijo-1]-48)*multiplicador))*-1;
                }
                else{
                    polinomio_numeros[exponente]=polinomio_numeros[exponente]+((polinomio_letras[indice_fijo-1]-48)*multiplicador);

                }
                multiplicador=multiplicador*10;  //aumento del multiplicador por 10
                indice_fijo--;
            }
        }
    }
}

void imprimir_polinomio (int largo,int polinomio[] ){
    cout << endl;
    for (int i=0;i<largo;i++){
        if (polinomio[i]!=0){
            if (polinomio[i]>0){
                cout << "+" << polinomio[i] << "x" << "**" << i;   //imprime de esta forma si el numero es mayor a 0
            }
            else{
                cout << polinomio[i] << "x" << "**" << i ;  //imprime de esta forma si el numero es menor a 0
            }
        }
    }
    cout << endl;
}


void crear_polinomios (string frase){
    int largo=frase.length();
    char polinomio_letras[largo];
    int polinomio_numeros[largo];
    for (int i=0;i<largo;i++){
        polinomio_letras[i]=frase[i]; // copia lo contenido en el string a un arreglo de char
        polinomio_numeros[i]=0;  //llena el polinomio con 0
    }
    llenar_polinomio(largo,polinomio_letras,polinomio_numeros);  //ordena y crea el arreglo de enteros que se usara en el metodo newton raphson
    imprimir_polinomio(largo,polinomio_numeros);  //imprime por pantalla el polinomio
}



int main(int argc,char const *argv[]){
    crear_polinomios(argv[1]); // crea los arreglos de polinomios (uno de letras otros de numeros)
    return 0;
}