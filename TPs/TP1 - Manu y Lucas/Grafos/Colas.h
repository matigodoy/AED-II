class nodoc{
public:
	int valor;
	
	nodoc *siguiente;
	nodoc(int val,nodoc *sig=NULL){
	valor=val;
	
	siguiente=sig;
	}
	class cola;
};
typedef nodoc *pnodoc;
class cola{
public:
	pnodoc inicio;
	pnodoc fin;
	cola(){
	inicio=NULL;
	fin=NULL;
	}
	bool colavacia();
	void ingresar(int val);
	int leer();


};

bool cola::colavacia(){
return inicio==NULL;
}
void cola::ingresar(int val){

	if(colavacia()){
		inicio=new nodoc(val);
		fin=inicio;
	}
	else{
		fin->siguiente=new nodoc(val);
		fin=fin->siguiente;
	}
}
int cola::leer(){
nodoc *auxnodoc;
auxnodoc=inicio;
if(colavacia()){
cout<<"cola vacia"<<endl;

}
else{
inicio=auxnodoc->siguiente;
return auxnodoc->valor;
delete(auxnodoc);

if(colavacia()){
	fin=NULL;
}}
}