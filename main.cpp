//PREGUNTA 11
//
//Crear una programa en C++ que permita insertar secuencialmente en un
// archivo .dat de forma binaria la siguiente información:
// Codigo_Empleado, Nombres, Apellidos, Puesto, Sueldo Base, Bonificación
//El programa debe realizar lo siguiente:
//
//Calcular Automáticamente el Sueldo total ( Sueldo Base + Bonificación) y almacenarlo en el archivo .dat
//Debe Permitir Buscar un Registro por medio del Codigo_Empleado
//Debe Permitir Eliminar un Registro
//Debe Permitir Modificar un Registro
//Nota: Subir el link del repositorio en https://github.com/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const char *nombre_archivo = "archivo.dat";

struct Empleado{
    int codigoEmpleado;
    char nombresEmpleado[50];
    char apellidosEmpleado[50];
    char puesto[20];
    float salarioEmpleado;
    float bonoEmpleado;
    float totalDevengado = salarioEmpleado + bonoEmpleado;
};

void ingresarEmpleado();
void abrirEmpleado();
void modificarEmpleado();
//void eliminarEmpleado();

int main() {
  abrirEmpleado();
  ingresarEmpleado();
  modificarEmpleado();
  //eliminarEmpleado();
    return 0;
}

void buscarCodigo(){
 FILE* archivo = fopen(nombre_archivo, "rb");

 int indice = 0, pos=0, cod=0;

 cout<<"***BUSQUEDA POR CODIGO DE EMPLEADO***"<<endl;
 cout<<"Ingrese Codigo: "<<endl;
 cin>>cod;
 Empleado empleado;

 fread(&empleado, sizeof(Empleado), 1, archivo);

 do{
     if (empleado.codigoEmpleado == cod){
         pos = indice;
     }

     fread(&empleado, sizeof(Empleado), 1, archivo);
     indice += 1;

 }while (feof(archivo) == 0);

    cout<<"------------------ "<<pos<<" ------------------"<<endl;
    fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );

    fread ( &empleado, sizeof( Empleado ), 1, archivo );

    cout <<"Codigo Empleado   :"<< empleado.codigoEmpleado <<endl;
    cout <<"Nombres Empleado  :"<< empleado.nombresEmpleado <<endl;
    cout <<"Apellidos Empleado:"<< empleado.apellidosEmpleado <<endl;
    cout <<"Puesto            :"<< empleado.puesto<<endl;
    cout <<"Salario Empleado  :"<< empleado.salarioEmpleado<<endl;
    cout <<"Bono de Prod.     :"<< empleado.bonoEmpleado<<endl;
    cout <<"========================================"<<endl;
    cout <<"TOTAL DEVENGADO   :"<< empleado.salarioEmpleado + empleado.bonoEmpleado<<endl;

    fclose(archivo);
    system("PAUSE");
}

void buscarIndice(){
    FILE* archivo = fopen(nombre_archivo,"rb");

    int pos = 0;
    cout<<" REGISTRO QUE DESEA VER... :"<<endl;
    cin>>pos;
    cout<<"------------------ "<<pos<<" ------------------"<<endl;
    fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );

    Empleado empleado;

    fread (&empleado, sizeof(Empleado),1, archivo);

    cout <<"Codigo Empleado   :"<< empleado.codigoEmpleado <<endl;
    cout <<"Nombres Empleado  :"<< empleado.nombresEmpleado <<endl;
    cout <<"Apellidos Empleado:"<< empleado.apellidosEmpleado <<endl;
    cout <<"Puesto            :"<< empleado.puesto<<endl;
    cout <<"Salario Empleado  :"<< empleado.salarioEmpleado<<endl;
    cout <<"Bono de Prod.     :"<< empleado.bonoEmpleado<<endl;
    cout <<"========================================"<<endl;
    cout <<"TOTAL DEVENGADO   :"<< empleado.totalDevengado<<endl;

    fclose(archivo);

}

void abrirEmpleado(){
    system("cls");
    FILE* archivo = fopen(nombre_archivo, "rb");
    if(!archivo){
        archivo = fopen(nombre_archivo, "w+b");

    }
    Empleado empleado;
    int registro = 0;
    fread(&empleado, sizeof(Empleado), 1, archivo );
    cout<<"____________________________________________________________________"<<endl;
    cout << "id" <<"|"<< "CODIGO" <<"|"<< "NOMBRE"<<" "<<"APELLIDO"<<" "<<"PUESTO"<<" "<<"SALARIO"<<" "<<"BONO"<<" "<<"TOTAL"<<endl;
    do {
    cout << registro << "|" << empleado.codigoEmpleado << "|" << empleado.codigoEmpleado << "|" << empleado.nombresEmpleado << "|" << empleado.apellidosEmpleado << "|" << empleado.puesto <<"|"<< empleado.salarioEmpleado << "|" << empleado.bonoEmpleado <<"|"<< empleado.totalDevengado << endl;

    fread (&empleado, sizeof(Empleado), 1, archivo);
    registro += 1;
    } while (feof(archivo) == 0);

    cout<< endl;

    fclose(archivo);

}

void ingresarEmpleado(){
    char continuar;
    FILE* archivo = fopen(nombre_archivo, "ab");

    Empleado empleado;
    string nombre, apellido;
    do {
        fflush(stdin);
        cout << "Ingrese el Codigo de Empleado: ";
        cin >> empleado.codigoEmpleado;
        cin.ignore();

        cout << "Ingrese el Nombre del Empleado: ";
        cin >> empleado.nombresEmpleado;
        cin.ignore();

        cout << "Ingrese el Apellido del Empleado: ";
        cin >> empleado.apellidosEmpleado;
        cin.ignore();

        cout << "Ingrese el Puesto del Empleado: ";
        cin >> empleado.puesto;
        cin.ignore();

        cout << "Ingrese el Salario del Empleado: ";
        cin >> empleado.salarioEmpleado;
        cin.ignore();

        cout << "Ingrese el Bono del Empleado: ";
        cin >> empleado.bonoEmpleado;
        cin.ignore();

        cout << "EL TOTAL A DEVENGAR ES: " << empleado.totalDevengado << endl;

        cout << "Desea agregar otro registo (Ingrese S o N)";
        cin >> continuar;
    } while ((continuar='s') || (continuar == 'S'));

    fclose(archivo);
    abrirEmpleado();
    buscarCodigo();


}

void modificarEmpleado(){

    FILE * archivo = fopen(nombre_archivo, "r+b");

    int id;

    Empleado empleado;

    cout << "Ingrese el ID que desea  modificar";
    cin>> id;
    fseek(archivo, id *sizeof(Empleado), SEEK_SET);

    cout << "Ingrese el Codigo de Empleado: ";
    cin >> empleado.codigoEmpleado;
    cin.ignore();

    cout << "Ingrese el Nombre del Empleado: ";
    cin >> empleado.nombresEmpleado;
    cin.ignore();

    cout << "Ingrese el Apellido del Empleado: ";
    cin >> empleado.apellidosEmpleado;
    cin.ignore();

    cout << "Ingrese el Puesto del Empleado: ";
    cin >> empleado.puesto;
    cin.ignore();

    cout << "Ingrese el Salario del Empleado: ";
    cin >> empleado.salarioEmpleado;
    cin.ignore();

    cout << "Ingrese el Bono del Empleado: ";
    cin >> empleado.bonoEmpleado;
    cin.ignore();

    fwrite(&empleado, sizeof (Empleado), 1, archivo);
    fclose(archivo);
    abrirEmpleado();
    system("PAUSE");

}