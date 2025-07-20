#include<iostream>
#include<string>
#include"menu.h"
using namespace std;

#define BOLD "\033[1m"
#define RESET "\033[0m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"

void imprimeMenu(menu &m){
	cout<<BOLD<<CYAN<<"----------------"<<RESET<<endl;
	cout<<BOLD<<CYAN<<"CARTA DEL DIA"<<RESET<<endl;
	cout<<BOLD<<CYAN<<"----------------"<<RESET<<endl;
	
	if(m.cantB>0){
		cout<<BOLD<<YELLOW<<"---BEBIDAS---"<<RESET<<endl;
    	for(int i=0;i<m.cantB;i++){
    	   cout<<"Bebida "<<i+1<<": "<<m.bebidas[i]<<" - S/."<<m.preciosBebidas[i]<<endl;
		}
    }
    
    if(m.cantC>0){
    	cout<<"\n";
    	cout<<BOLD<<YELLOW<<"---PLATO DE FONDO---"<<RESET<<endl;
        for(int i=0;i<m.cantC;i++){
            cout<<"Platillo "<<i+1<<": "<<m.platos[i]<<" - S/."<<m.preciosPlatos[i]<<endl;
        }          
    }
    
    if(m.cantP>0){
    	cout<<"\n";
    	cout<<BOLD<<YELLOW<<"---POSTRES---"<<RESET<<endl;
        for(int i=0;i<m.cantP;i++){
            cout<<"Postres "<<i+1<<": "<<m.postres[i]<<" - S/."<<m.preciosPostres[i]<<endl;
        }          
    }
        
}

