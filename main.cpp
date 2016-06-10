#include <cstdlib>
#include <iostream>
#include "conio.h"
#include "stdlib.h"

using namespace std;
/*Stephanie Correa 19.598.574
  yohan Villamizar 17.876.465*/
class data{
	public:
		int cod;
		char nombre[25];
		int edad;
		data *enl;
		data(){enl=NULL;}
		
};

class archivo{
 public:
	void abrir(char *);
	void ins(data);
	void eliminar(data);
	int menu();
	void imprimir();
	data *fte,*fin;
	archivo(){
	fte=fin=NULL;
	}
};
 void archivo::abrir(char *nom){
 FILE *fp;
 int i=0;
 int band;
 data *com;
 com = new data[100];
 char *x;
 char cad[100];
   fp=fopen(nom,"r");
   if(!fp){
   cout<<"Error de apertura"<<endl;
   return;
   }
   band=1;
   fgets(cad,100,fp);
   while(!feof(fp)){
	   band=1;
   x=strtok(cad,",");
   com[i].cod=atoi(x);
   x=strtok(NULL,",");
   strcpy(com[i].nombre,x);
   x=strtok(NULL,",");
   com[i].edad=atoi(x);
  
   for(int j=0;j<i;j++){
	   if(com[j].cod==com[i].cod){
	   band=0;
	   }
   }
   if(band==1){
	   ins(com[i]);}
   fgets(cad,100,fp);
   i++;
   }
 }
 void archivo::ins(data d){
 data *nuevo;
 nuevo = new data();
  if(nuevo){
    (*nuevo)=d;
	nuevo->enl=NULL;
	 if(!fte)
		 fte=nuevo;
	 else
		 fin->enl=nuevo;
	     fin=nuevo;
  }
  else
	  cout<<"Esta lleno"<<endl;
 }
 void archivo::eliminar(data d){
 data *aux;
  if (fte!=NULL){
    aux = fte;
    fte = fte->enl;
    if(!fte)
    fin = NULL;
    delete aux;
 }
    else
	 cout<<"Cola vacia"<<endl;
 }

 void archivo::imprimir(){
	 if (fte!=NULL){
      data *p=fte;
	  while (p)
	 {
		 cout<<""<<p->cod<<" "<<p->nombre<<" "<<p->edad<<endl;
	     p=p->enl;
	}
 }
 }

 int archivo::menu(){
 int opc;
 cout<<"**************Menu de opciones**************"<<endl;
 cout<<"1.Insertar"<<endl;
 cout<<"2.Eliminar"<<endl;
 cout<<"3.Imprimir Cola"<<endl;
 cout<<"4.Salir"<<endl;
 cout<<"Cual es su opcion: "<<endl;
 cin>>opc;
 return opc;
 }

int main(int argc, char *argv[])
{   char nom[]="data.txt";
	archivo a;
	data d;
	int opc;
	do{
	opc=a.menu();
    system("cls");
	switch(opc){
	case 1:{
            system("cls"); 
		    a.abrir(nom);
		    cout<<"Ya inserto los elementos a la Cola Dinamica"<<endl;
		    cin.sync();
			cin.get();
		    system("cls");
		    break;
		   }
	case 2:{
            system("cls");
		    a.eliminar(d);
		    cout<<"Ya se elimino el elemento"<<endl;
		    cin.sync();
			cin.get();
		    system("cls");
		    break;
		   }
	case 3:{
		    a.imprimir();
			cin.sync();
			cin.get();
		    system("cls");
		    break;
		   }
	case 4:{cout<<"Hasta luego =D"<<endl;
		    break;
		   }
	}
	}while(opc!=4);

    system("PAUSE");
    return EXIT_SUCCESS;
}
