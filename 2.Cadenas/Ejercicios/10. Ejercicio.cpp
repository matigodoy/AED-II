#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <math.h>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stack>
using namespace std;
void palindromos(string texto,int largo){
    int l=texto.size();
    int i=0;
    int k=0;
    while (i<l-largo+1)
    {
        char cadena[largo];
        stack<char> s;
        k=i;
        cout<<"Cadena actual: ";
        for (int j=0;j<largo;j++)
        {
            cadena[j]=texto[k];
            s.push(texto[k]);
            cout<<cadena[j];
            k++;
        }
        cout<<endl;
        for (int j=0;j<largo;j++)
        {
            if (cadena[j]==s.top())
            {
                s.pop();
            }
        }
        if (s.empty()==true)
        {
            cout<<endl<<"Esta cadena es palindroma."<<endl<<endl;
        }
        else if (s.empty()==false)
        {
            cout<<endl<<"Esta cadena no es palindroma."<<endl<<endl;
        }
        i++;
    }
}
int main()
{
    string texto = "rallaradgtaddagtadbbbgaattbaadtattabsugus";
    //string texto = "dabale arroz a la zorra el abad";
    int largo=0;
    while (largo>6 or largo<3)
    {
        cout<<"Ingrese el largo del palindromo: ";
        cin>>largo;
    }
    palindromos(texto,largo);
    return 0;
}