#include<iostream>
#include<cstring>

using namespace std;


void obtenerTablaFallos(string patron, int m, int* f);

int buscarKMP(string patron, string texto){
	int n = texto.size();
	int m = patron.size();
	
	int f[m];
	obtenerTablaFallos(patron, m, f);

	cout << endl;
	for (int i = 0; i < m; i ++){
		cout << patron[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < m; i ++){
		cout << f[i] << "\t";
	}
	cout << endl;

	int i = 0; // texto
	int j = 0; // patron
	while (i < n){
		if (patron[j] == texto[i]){
			i++;
			j++;
		}
		if (j == m) {
			cout << endl << "Patrón encontrado en posición: " << i - j << endl;
			j = f[j-1];
		}	
		else if(i < n && patron[j] != texto[i]){
			if (j != 0)
				j = f[j-1];
			else	
				i = i + 1;
		}
		
	}
	return 0;
}

void obtenerTablaFallos(string patron, int m, int* f){
	int j = 0;
	int i = 1;
	f[0] = 0;

	while(i < m){
		if(patron[i] == patron[j]){
			j++;
			f[i] = j;
			i++;
		}
		else{
			if(j != 0){
				j = f[j-1];
			}
			else{
				f[i] = 0;
				i++;
			}
		}

	}
}



int main(){
	string texto = "ABABDABACDABABCABAB"; //"AABAACAADAABAAABAA";
	string patron = "ABABCABAB"; //"ADAA";

	buscarKMP(patron, texto);

	return 0;

}
