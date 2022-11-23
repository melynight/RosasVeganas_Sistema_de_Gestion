#ifndef MENU_PRINCIPAL_H_INCLUDED
#define MENU_PRINCIPAL_H_INCLUDED

void mensaje_bienvenida();
void mensaje_cerrarSesion();
bool interfaz_usuario();
void menu_clientes();
void menu_usuarios();
void menuPedidos();
void menuEntrada(bool admin);
void menuBebida(bool admin);
void menu_empleado(bool admin) ;
void menu_administrador();
void menu_configuracion();



void mensaje_cerrarSesion()
{
    cls();
    gotoxy(30,7);
    cout<<"SESION CERRADA CON ÉXITO"<<endl;
    gotoxy(30,9);
    system("pause");
}

void mensaje_bienvenida()
{
    MostrarLineaHorizontal(30,10,65);
    gotoxy(30,12);
    imprimir("BIENVENID@ AL SISTEMA DE GESTION DE ARCHIVOS: BAR ROSAS VEGANAS ");
    MostrarLineaHorizontal(30,14,65);

    gotoxy(30,18);
    system("pause");
    cls();
}

bool interfaz_usuario()
{
    int ID;
    Usuario usuarios;
    char contrasenia[10];
    bool userFound,matchPassword,admin;

    gotoxy(30,7);
    imprimir("USUARIO: ");
    gotoxy(39,7);
    cin>>ID;
    userFound=comprobar_usuario(ID);

    while(!userFound)
    {
        gotoxy(30,7);
        imprimir("USUARIO NO VÁLIDO INTENTE NUEVAMENTE ");
        gotoxy(30,9);
        system("pause");
        cls();
        gotoxy(30,7);
        imprimir("USUARIO: ");
        gotoxy(39,7);
        cin>>ID;
        userFound=comprobar_usuario(ID);

    }
    gotoxy(30,8);
    imprimir("CONTRASEÑA: ");
    strcpy(contrasenia,ocultarContrasenia(contrasenia));
    matchPassword=comprobar_contrasenia(ID,contrasenia);

    while(!matchPassword)
    {
        cls();
        gotoxy(30,18);
        cout<<"CONTRASEÑA NO VÁLIDA, INTENTE NUEVAMENTE"<<endl;
        int y=8;
        gotoxy(30,7);
        cout<<"USUARIO: ";
        gotoxy(39,7);
        cout<<ID;
        gotoxy(30,y++);
        cout<<"CONTRASEÑA: ";
        strcpy(contrasenia,ocultarContrasenia(contrasenia));
        matchPassword=comprobar_contrasenia(ID,contrasenia);
    }
    cls();
    gotoxy(40,10);
    imprimir("SESION INICIADA ");
    gotoxy(40,15);
    system("pause");

    admin=comprobar_administrador(ID);

    return admin;

}

void menu_usuarios()
{
    int opc;
    bool encontrado,cargo,baja;

    while (true)
    {
        cls();
        gotoxy(39,3);
        imprimir("1. AGREGAR USUARIO");
        gotoxy(39,4);
        imprimir("2. MOSTRAR TODOS LOS USUARIOS");
        gotoxy(39,5);
        imprimir("3. MOSTRAR USUARIO POR ID");
        gotoxy(39,6);
        imprimir("4. ELIMINAR USUARIO");
        gotoxy(39,7);
        imprimir("0. VOLVER ATRAS");
        gotoxy(39,9);
        imprimir("INGRESE LA OPCION :");
        gotoxy(59,9);
        cin>>opc;

        switch(opc)
        {
        case 1:
            cls();
            cargo=agregar_usuario();
            if(cargo)
            {
                imprimir("USUARIO AGREGADO CON EXITO");
                cout<<endl;
                system("pause");
            }
            else
            {
                imprimir("ERROR AL CARGAR EL USUARIO");
                cout<<endl;
                system("pause");
            }
            break;
        case 2:
            cls();
            mostrar_usuariosALL();
            imprimir("FIN DEL LISTADO");
            cout<<endl;
            system("pause");
            break;
        case 3:
            cls();
            encontrado=mostrar_porID();
            if (encontrado) imprimir("USUARIO ENCONTRADO CON EXITO");
            else imprimir("NO SE HA ENCONTRADO USUARIO");
            cout<<endl;
            system("pause");
            break;
        case 4:
            cls();
            baja=baja_usuario();
            if(baja) imprimir("EL USUARIO FUE ELIMINADO CORRECTAMENTE\n");
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            imprimir("OPCION INCORRECTA\n\n");
            system("pause");
            return;
            break;

        }

    }

}

void menu_clientes()
{
    int opc;
    bool agregado,mostro;

    while (true)
    {
        cls();
        gotoxy(39,3);
        imprimir("1. AGREGAR NUEVO CLIENTE");
        gotoxy(39,4);
        imprimir("2. BUSCAR CLIENTE POR ID");
        gotoxy(39,5);
        imprimir("3. DAR DE BAJA CLIENTE");
        gotoxy(39,6);
        imprimir("4. MOSTRAR TODOS LOS CLIENTES");
        gotoxy(39,7);
        imprimir("0. VOLVER ATRAS");
        gotoxy(39,9);
        imprimir("INGRESE LA OPCION :");
        gotoxy(59,9);
        cin>>opc;

        switch(opc)
        {
        case 1:
            cls();
            agregado=agregar_cliente();
            if (agregado) imprimir("CLIENTE AGREGADO CON EXITO");
            else imprimir("ERROR AL AGREGAR CLIENTE NUEVO");
            cout<<endl;
            system("pause");
            break;
        case 2:
            cls();
            mostro=mostrar_porIDc();
            if(mostro) cout<<"CLIENTE ENCONTRADON CON EXITO"<<endl;
            else cout<<"NO SE HA ENCONTRADO CLIENTE"<<endl;
            system("pause");
            break;

        case 3:
            cls();
            baja_cliente();
            cout<<endl;
            system("pause");
            break;
        case 4:
            cls();
            mostrar_clientesALL();
            imprimir("FIN DEL LISTADO");
            cout<<endl;
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            imprimir("OPCION INCORRECTA\n\n");
            system("pause");
            return;
            break;

        }

    }
}

void menuPedidos()
{
    int opc;
    bool agregado,mostro;


    while (true)
    {
        cls();
        gotoxy(39,3);
        imprimir("1. TOMAR PEDIDO");
        gotoxy(39,4);
        imprimir("2. BUSCAR PEDIDO POR ID");
        gotoxy(39,5);
        imprimir("3. CANCELAR PEDIDO");
        gotoxy(39,6);
        imprimir("0. VOLVER ATRÁS");
        gotoxy(39,8);
        imprimir("INGRESE LA OPCIÓN :");
        gotoxy(59,8);
        cin>>opc;

        switch(opc)
        {
        case 1:
            cls();
            agregado=altaPedido();
            if (agregado) imprimir("PEDIDO GUARDADO CON ÉXITO");
            else imprimir("ERROR AL AGREGAR PEDIDO NUEVO");
            cout<<endl<<endl;
            system("pause");
            break;
        case 2:
            cls();
            mostro=mostrarPedidoPorID();
            if(mostro)
            {
                cout<<endl;
                imprimir("SE HA ENCONTRADO PEDIDO CON ÉXITO");
            }
            else imprimir("NO SE HA ENCONTRADO PEDIDO EN EL SISTEMA");
            cout<<endl;
            system("pause");
            break;

        case 3:
            cls();
            bajaPedido();
            cout<<endl<<endl;
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            imprimir("OPCIÓN INCORRECTA\n\n");
            system("pause");
            return;
            break;

        }

    }
}


void menuEntrada(bool admin)
{


    int opc,validacion;
    bool encontro,agrego;

    while(true)
    {
        cls();
        MostrarLineaHorizontal(30,1,35);
        gotoxy(39,3);
        imprimir("MENÚ ENTRADAS");
        MostrarLineaHorizontal(30,4,35);
        cout<<endl;
        gotoxy(37,6);
        imprimir("1. VER TODAS LAS ENTRADAS ");
        gotoxy(37,7);
        imprimir("2. VER ENTRADA POR ID ");
        if(admin)
        {
            gotoxy(37,8);
            imprimir("3. AGREGAR ENTRADA ");
            gotoxy(37,9);
            imprimir("4. DAR DE BAJA ENTRADA ");
            gotoxy(37,10);
            imprimir("0. VOLVER ATRÁS");
            gotoxy(37,12);
            imprimir("INGRESE LA OPCIÓN: ");
            gotoxy(56,12);
            cin>>opc;
        }
        else
        {
            gotoxy(37,8);
            imprimir("0. VOLVER ATRÁS");
            gotoxy(37,10);
            imprimir("INGRESE LA OPCIÓN: ");
            gotoxy(56,10);
            cin>>opc;
        }
        switch(opc)
        {

        case 1:
            cls();
            validacion=listarEntradas();
            if (validacion == 1) imprimir("FIN DEL LISTADO\n");
            system("pause");
            break;
        case 2:
            cls();
            encontro=mostrarEntradaPorID();
            cout<<endl;
            if(encontro) imprimir("ENTRADA ENCONTRADA CON ÉXITO\n");
            else imprimir("NO SE ENCONTRÓ ID DE LA ENTRADA EN EL SISTEMA\n");
            system("pause");
            break;
        case 3:
            cls();
            agrego=altaEntrada();
            if(agrego) imprimir("ENTRADA AGREGADA CON ÉXITO\n");
            else imprimir("ERROR AL AGREGAR NUEVA ENTRADA\n");
            system("pause");
            break;
        case 4:
            cls();
            baja_entrada();
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            cout<<"RESPUESTA INCORRECTA";
            cls();
            break;
        }
    }
}

void menuBebida(bool admin)
{

    int opc;
    bool agrego,mostro,baja;

    while(true)
    {
        cls();
        MostrarLineaHorizontal(30,1,35);
        gotoxy(42,3);
        imprimir("MENÚ TRAGOS");
        MostrarLineaHorizontal(30,4,35);
        cout<<endl;
        gotoxy(37,6);
        imprimir("1. VER TODOS LOS TRAGOS ");
        gotoxy(37,7);
        imprimir("2. VER TRAGO POR ID ");
        if(admin)
        {
            gotoxy(37,8);
            imprimir("3. AGREGAR TRAGO ");
            gotoxy(37,9);
            imprimir("4. DAR DE BAJA TRAGO ");
            gotoxy(37,10);
            imprimir("0. VOLVER ATRÁS");
            gotoxy(37,12);
            imprimir("INGRESE LA OPCION: ");
            gotoxy(56,12);
            cin>>opc;
        }
        else
        {
            gotoxy(37,8);
            imprimir("0. VOLVER ATRÁS");
            gotoxy(37,10);
            imprimir("INGRESE LA OPCIÓN: ");
            gotoxy(56,10);
            cin>>opc;
        }

        cls();

        switch(opc)
        {

        case 1:
            cls();
            mostrar_bebidasALL();
            imprimir("FIN DEL LISTADO\n");
            system("pause");
            break;
        case 2:
            cls();
            if(contarBebidas() == 0)
            {
                imprimir("NO HAY TRAGOS DISPONIBLES\n");
                system("pause");
                return;
            }
            mostro=mostrar_porIDT();
            cout<<endl;
            if(mostro) imprimir("TRAGO ENCONTRADO CON ÉXITO\n");
            else imprimir("NO SE ENCONTRÓ ID DEL TRAGO EN EL SISTEMA\n");
            system("pause");
            break;
        case 3:
            cls();
            agrego=altaBebida();
            if(agrego) imprimir("TRAGO AGREGADO CON ÉXITO\n");
            else imprimir("ERROR AL AGREGAR NUEVO TRAGO\n");
            system("pause");
            break;
        case 4:
            cls();
            baja=baja_bebida();
            if(baja) imprimir("EL TRAGO SE ELIMINÓ CORRECTAMENTE\n");
            else imprimir("ERROR AL ELIMINAR EL TRAGO\n");
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            cout<<"RESPUESTA INCORRECTA";
            cls();
            break;
        }
    }
}



void menu_empleado(bool admin)
{
    int opc;
    while(true)
    {
        cls();
        MostrarLineaHorizontal(34,1,30);
        gotoxy(43,3);
        imprimir("MENÚ EMPLEAD@ ");
        MostrarLineaHorizontal(34,4,30);
        cout<<endl;
        gotoxy(41,6);
        imprimir("1. MENÚ PEDIDOS ");
        gotoxy(41,7);
        imprimir("2. MENÚ BEBIDAS ");
        gotoxy(41,8);
        imprimir("3. MENÚ ENTRADAS ");
        gotoxy(41,9);
        imprimir("4. MENÚ CLIENTE ");
        if(admin)
        {
            gotoxy(41,10);
            imprimir("0. VOLVER ATRÁS");
        }
        else
        {
            gotoxy(41,10);
            imprimir("0. CERRAR SESIÓN");
        }
        gotoxy(41,12);
        imprimir("INGRESE LA OPCIÓN: ");
        gotoxy(60,12);
        cin>>opc;

        switch(opc)
        {
        case 1:
            cls();
            menuPedidos();
            break;
        case 2:
            cls();
            menuBebida(admin);
            break;
        case 3:
            cls();
            menuEntrada(admin);
            break;
        case 4:
            cls();
            menu_clientes();
            break;
        case 0:
            if(admin) return;
            else mensaje_cerrarSesion();
            return;
            break;

        default:
            imprimir("OPCIÓN INCORRECTA\n\n");
            system("pause");
            return;
            break;
        }

    }


}

void menu_configuracion()
{
    int opc;
    bool establecio,copio,recupero;
    while(true)
    {
        cls();
        MostrarLineaHorizontal(30,1,36);
        gotoxy(39,3);
        imprimir("MENÚ CONFIGURACIÓN ");
        MostrarLineaHorizontal(30,4,36);
        cout<<endl;
        gotoxy(34,6);
        imprimir("1. ESTABLECER DATOS DE INICIO ");
        gotoxy(34,7);
        imprimir("2. COPIA DE SEGURIDAD CLIENTES ");
        gotoxy(34,8);
        imprimir("3. COPIA DE SEGURIDAD USUARIOS ");
        gotoxy(34,9);
        imprimir("4. RECUPERAR ARCHIVO CLIENTES ");
        gotoxy(34,10);
        imprimir("5. RECUPERAR ARCHIVO USUARIOS ");
        gotoxy(34,11);
        imprimir("0. VOLVER ATRÁS");
        gotoxy(34,14);
        imprimir("INGRESE LA OPCIÓN: ");
        gotoxy(54,14);
        cin>>opc;

        switch(opc)
        {
        case 1:
            cls();
            establecio=establecer_datosini();
            if(establecio) imprimir("DATOS DE INICIO CORRECTAMENTE ESTABLECIDOS\n");
            system("pause");
            break;
        case 2:
            cls();
            copio=copia_clientes();
            if(copio) imprimir("COPIA DE SEGURIDAD DE CLIENTE REALIZADA CORRECTAMENTE\n");
            else imprimir("NO SE REALIZO COPIA DE SEGURIDAD\n");
            cout<<endl;
            system("pause");
            break;
        case 3:
            cls();
            copio=copia_usuarios();
            if(copio) imprimir("COPIA DE SEGURIDAD DE USUARIOS REALIZADA CORRECTAMENTE\n");
            else imprimir("NO SE REALIZÓ COPIA DE SEGURIDAD\n");
            cout<<endl;
            system("pause");
            break;
        case 4:
            cls();
            recupero=recuperarClientes();
            if(recupero) imprimir("ARCHIVO DE CLIENTES RECUPERADO CORRECTAMENTE\n");
             else imprimir("NO SE REALIZÓ EL RECUPERO DEL ARCHIVO\n");
             cout<<endl;
            system("pause");
            break;
        case 5:
            cls();
            recupero=recuperarUsuarios();
            if(recupero) imprimir("ARCHIVO DE USUARIOS RECUPERADO CORRECTAMENTE\n");
            else imprimir("NO SE REALIZÓ EL RECUPERO DEL ARCHIVO\n");
            cout<<endl;
            system("pause");
            break;
        case 0:
            return;
            break;

        default:
            imprimir("OPCIÓN INCORRECTA\n\n");
            system("pause");
            return;
            break;
        }

    }


}

void menu_reportes()
{
    int opc;
    bool bandera;
    while(true)
    {
        cls();
        MostrarLineaHorizontal(30,1,44);
        gotoxy(46,3);
        imprimir("MENÚ REPORTES ");
        MostrarLineaHorizontal(30,4,44);
        cout<<endl;
        gotoxy(32,6);
        imprimir("1. TOTAL RECAUDADO DEL BAR ");
        gotoxy(32,7);
        imprimir("2. CLIENTE CON MÁS PEDIDOS ");
        gotoxy(32,8);
        imprimir("3. PEDIDOS DE UN MES INGRESADO POR TECLADO ");
        gotoxy(32,9);
        imprimir("0. VOLVER ATRÁS");
        gotoxy(32,11);
        imprimir("INGRESE LA OPCIÓN: ");
        gotoxy(51,11);
        cin>>opc;

        switch(opc)

        {
        case 1:
            cls();
            totalRecaudado();
            system("pause");
            break;
        case 2:
            cls();
            clienteMasFrecuente();
            cout<<endl<<endl;
            system("pause");
            break;
        case 3:
            cls();
            bandera=pedidosxMes();
            if(bandera) imprimir("FIN DEL LISTADO\n\n");
            else imprimir("NO SE HA ENCONTRADO PEDIDO EN EL MES INGRESADO\n\n");
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            imprimir("OPCIÓN INCORRECTA\n\n");
            system("pause");
            return;
            break;
        }

    }


}

void menu_administrador()
{
    bool administrador=true;
    int opc;
    while(true)
    {
        cls();
        MostrarLineaHorizontal(30,1,36);
        gotoxy(39,3);
        imprimir("MENU ADMINISTRADOR");
        MostrarLineaHorizontal(30,4,36);
        cout<<endl;
        gotoxy(38,6);
        imprimir("1. MENÚ USUARIOS ");
        gotoxy(38,7);
        imprimir("2. MENÚ CLIENTES ");
        gotoxy(38,8);
        imprimir("3. MENÚ EMPLEADO ");
        gotoxy(38,9);
        imprimir("4. REPORTES ");
        gotoxy(38,10);
        imprimir("5. CONFIGURACIÓN");
        gotoxy(38,11);
        imprimir("0. CERRAR SESIÓN");
        gotoxy(38,14);
        imprimir("INGRESE LA OPCIÓN: ");
        gotoxy(58,14);
        cin>>opc;

        switch(opc)
        {
        case 1:
            cls();
            menu_usuarios();
            break;
        case 2:
            cls();
            menu_clientes();
            break;
        case 3:
            cls();
            menu_empleado(administrador);
            break;
        case 4:
            cls();
            menu_reportes();
            break;
        case 5:
            cls();
            menu_configuracion();
            break;
        case 0:
            mensaje_cerrarSesion();
            return;
            break;

        default:
            imprimir("OPCIÓN INCORRECTA\n\n");
            system("pause");
            return;
            break;
        }

    }


}


#endif // MENU_PRINCIPAL_H_INCLUDED
