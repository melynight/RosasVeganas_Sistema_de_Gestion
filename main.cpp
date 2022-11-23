///NOMBRE: Melany Nahir Dalama
///FECHA:

#include <iostream>
#include <iostream>
#include<cstdlib>
#include<cstring>
#include<time.h>
#include <conio.h>

using namespace std;

const char* ArchivoUsuarios= "Usuarios.dat";
const char* ArchivoUsuariosINI= "Usuarios.ini";
const char* ArchivoEntradas= "Entradas.dat";
const char* ArchivoClientes= "Clientes.dat";
const char* ArchivoClientesINI= "Clientes.ini";
const char* ArchivoBebidas= "Bebidas.dat";
const char* ArchivoPedidos= "Pedidos.dat";

#include "rlutil.h"
#include "Fecha.h"
#include "funcionesGlobales.h"
#include "Usuario.h"
#include "Entrada.h"
#include "Bebida.h"
#include "Cliente.h"
#include "funcionesComida.h"
#include "funcionesUsuarios.h"
#include "funcionesClientes.h"
#include "Pedido.h"
#include "funcionesPedidos.h"
#include "funcionesConfiguracion.h"
#include "reportes.h"
#include "MenúesPrincipales.h"


int main ()
{

    setlocale(LC_ALL,"spanish");
    bool administrador;

    rlutil::setBackgroundColor(14);
    rlutil::setColor(0);

    while(true)
    {
        cls();
        if(contarUsuarios() == 0) establecer_datosini();

        mensaje_bienvenida();

        administrador=interfaz_usuario();

        if(administrador) menu_administrador();

        else menu_empleado(administrador);

    }


    return 0;
}
