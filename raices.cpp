#include <iostream>
#include <string>
using namespace std;



int main(int argc,char const *argv[]){
    string aux=argv[1];
    int longitud = aux.length();
    char polinomio[longitud];
    int posicionarray;
    int aux2;
    int indiceaux;

    int arreglopolinomio[longitud];
    for (int i=0;i<longitud;i++){
        polinomio[i]=aux[i];
        arreglopolinomio[i]=0;
    }
    for (int i=0;i<longitud;i++){
        if (polinomio[i]=='x'){
            aux2=1;
            indiceaux=i;
            posicionarray=(polinomio[i+3]-48);
            while (polinomio[indiceaux-1]!='+' && polinomio[indiceaux-1]!='-'){
                if (polinomio[indiceaux-2]=='-'){
                    arreglopolinomio[posicionarray]=(arreglopolinomio[posicionarray]+((polinomio[indiceaux-1]-48)*aux2))*-1;
                }
                else{
                    arreglopolinomio[posicionarray]=arreglopolinomio[posicionarray]+((polinomio[indiceaux-1]-48)*aux2);

                }
                aux2=aux2*10;
                indiceaux--;
            }
        }
    }
    cout << endl;
    cout << endl;
    for (int i=0;i<longitud;i++){
        if (arreglopolinomio[i]!=0){
            if (arreglopolinomio[i]>0){
                cout << "+" << arreglopolinomio[i] << "x" << "**" << i;
            }
            else{
                cout << arreglopolinomio[i] << "x" << "**" << i ;
            }
        }
    }
    cout << endl;
    return 0;
}