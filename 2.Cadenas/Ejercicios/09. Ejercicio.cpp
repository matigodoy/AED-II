#include <iostream>
#include <string.h>

using namespace std;


void horizontal(string patron,int p, char matriz[5][5]){
	int k = 0; //contador
	int m = patron.size();
	
    for (int i=0; i<p; i++) {
    	for (int j=0; j<p; j++) {
    		while (patron[k] == matriz[i][j]){
    			k++;
    			j++;
    			if (k == m) cout << "Se encontro horizontal"<<endl;	
		
			}
			k = 0;
		}
	}
	k=0;
}

void vertical(string patron, int p, char matriz [5][5]){
	int k = 0;
	int v = patron.size();
	for (int i=0; i<p; i++) {
    	for (int j=0; j<p; j++) {
    		while (patron[k] == matriz[j][i])
			{
    			k++;
    			j++;
    			if (k == v) cout << "Se encontro vertical" <<endl;
			}
			k = 0;		
		}
	}
	k=0;
	
}

void diagonal(string patron,int p, char matriz [5][5]){
	int k = 0;
	int m = patron.size();
	for (int i=0; i<p; i++) {
   		for (int j=0; j<p; j++) {
   			int a = i;
   			int b = j;
    		while (patron[k] == matriz[a][b]) {
    			k++;
    			a++;
    			b++;
    			if (k == m) cout << "Se encontro diagonal" << endl;
				
			}
			k = 0;
		}
	}
	k = 0;
}

void diagonalinvertida(string patron,int p, char matriz [5][5]){
	int k = 0;
	int m = patron.size();
	for (int i=p-1; i>-1; i--) {
    	for (int j=p-1; j>-1; j--) {
    		int a = i;
    		int b = j;
    		while (patron[k] == matriz[j][i]) {
    			k++;
    			a--;
    			b--;
    			if (k == m) cout << "Se encontro diagonal invertida" << endl;
			}
			k = 0;
		}
	}
	k = 0;
}


int main(){
	int p = 5;
	char matriz [5][5] = {{'h', 'j', 'h', 'y', 'm'},
						  {'e', 'm', 'm', 'e', 'a'}, 
					      {'y', 'm', 's', 'e', 'a'},
						  {'k', 'a', 'e', 'q', 'a'},
						  {'m', 'm', 's', 'a', 'm'}
						  };
	string patron = "mesa"; //patron que hay que buscar
	
	horizontal(patron,p,matriz);
	vertical(patron, p, matriz);
	diagonal(patron, p, matriz);
	diagonalinvertida(patron, p, matriz);
	
	
	cin.get();
	
	return 0;
}
