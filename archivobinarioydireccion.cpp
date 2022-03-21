//Gutavo Chiguichon 5990 13 21 8 5 3
// metodo de eliminar no lo pude hacer

#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;
const char *nombe_archivo = "archivo.dat";

struct Estudiante{
	int codigo;
	char direccion[65];
	char nombre[65];
	char apellido[65];
	int telefono;
};
 void ingresar_estudiante();
void abrir_estudiante();
 void modificar_estudiante();
 void buscar_codigo();

int main (){
	abrir_estudiante();
 ingresar_estudiante();
	modificar_estudiante();
	return 0;	
}

void buscar_codigo(){
		FILE* archivo = fopen(nombe_archivo,"rb");	
	int pos=0,indice=0,cod=0;
	cout<<"Que codigo desea ver: ";
	cin>>cod;
	
	Estudiante estudiante;
	fread(&estudiante,sizeof(Estudiante),1,archivo);	
	do{
	   if(estudiante.codigo == cod)	{
	   	cout<<"Codigo: "<<estudiante.codigo<<endl;
	   	cout<<"Nombres: "<<estudiante.nombre<<endl;
	   	cout<<"Apellidos: "<<estudiante.apellido<<endl;
	   	cout<<"Telefono: "<<estudiante.telefono<<endl;
	   	cout<<"Direccion: "<<estudiante.direccion<<endl;
	   }
	   fread(&estudiante,sizeof(Estudiante),1,archivo);	
	} while(feof(archivo)==0);
	
	
	
	fclose(archivo);
}


void buscar_indice(){
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"***************** "<<pos<<" **************************"<<endl;
	fseek ( archivo,pos * sizeof(Estudiante), SEEK_SET );
	
	Estudiante estudiante;
	
    fread ( &estudiante, sizeof( Estudiante ), 1, archivo );

    	cout << "Codigo: " << estudiante.codigo << endl;
        cout << "Nombre: " << estudiante.nombre << endl;
        cout << "Apellido: " << estudiante.apellido << endl;
        cout << "Telefono: " << estudiante.telefono << endl;
        cout << "Telefono: " << estudiante.direccion<< endl;
        cout << endl;
	
	fclose(archivo);

	
}


void abrir_estudiante(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Estudiante estudiante;
	int registro=0;
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	cout<<"/////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
	cout << "ident" <<"|"<< "CODIGO" <<"|"<< "NOMBRE"<<" "<<"APELLIDO"<<" "<<"TELEFONO"<<" "  <<"DIRECCION"<<" "<<endl;	
		do{
		cout<<"/////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
		cout << registro <<" |  "<< estudiante.codigo <<" | "<< estudiante.nombre<<" "<<estudiante.apellido<<" "<<estudiante.telefono<<" | "<<estudiante.direccion<<endl;
        
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
void ingresar_estudiante(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); 
	
	
		Estudiante estudiante;
		 string nombre,apellido,direccion;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		cout<<"Ingrese la Direccion:";
		getline(cin,direccion);
    	strcpy(estudiante.direccion, direccion.c_str()); 
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_estudiante();	
	buscar_codigo();
}
void modificar_estudiante(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido,direccion;	
    	Estudiante estudiante;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Estudiante), SEEK_SET );  
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		cout<<"Ingrese la direccion:";
		getline(cin,direccion);
    	strcpy(estudiante.direccion, direccion.c_str());
		
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
	fclose(archivo);
	abrir_estudiante();
		system("PAUSE");
}

