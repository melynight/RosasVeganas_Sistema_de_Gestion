#ifndef FUNCIONESCLIENTES_H_INCLUDED
#define FUNCIONESCLIENTES_H_INCLUDED

bool agregar_cliente();
bool baja_cliente();
int buscarID_cliente();
void mostrar_clientesALL();
bool mostrar_porIDc();


bool agregar_cliente()
{
    FILE *p;
    Cliente clientes;
    p=fopen(ArchivoClientes,"ab");
    if(p==NULL)
    {
        return false;
    }
    clientes.cargarCliente();
    fwrite(&clientes,sizeof(Cliente),1,p);
    fclose(p);

    return true;
}

void mostrar_clientesALL()
{
    int pos=0;
    Cliente clientes;

    if(contarClientes() == 0)
    {
        imprimir("NO HAY CLIENTES REGISTRADOS ");
        return;
    }
    imprimir("TODOS LOS CLIENTES DEL BAR:\n\n");

    while(clientes.leerDeDiscoC(pos++))
    {
        if(clientes.getEstadoc())
        {
            clientes.mostrarCliente();
            cout<<endl;

        }

    }
}

bool mostrar_porIDc()
{
    int ID;
    int pos=0;
    Cliente clientes;

    imprimir("INGRESE ID DEL CLIENTE A MOSTRAR: ");
    cin>>ID;
    cout<<endl;
    while(ID<0)
    {
        imprimir("ID DEL CLIENTE NO VÁLIDO, INGRESE ID MAYOR A 0: ");
        cin>>ID;
        cout<<endl;
    }

    while(clientes.leerDeDiscoC(pos++))
    {
        if(clientes.getcID() == ID && clientes.getEstadoc())
        {
            clientes.mostrarCliente();
            return true;
        }
    }
    return false;
}

int buscarID_cliente()
{
    int ID;
    Cliente clientes;


    imprimir("INGRESE ID DEL CLIENTE: ");
    cin>>ID;
    cout<<endl;
    while(ID<0)
    {
        imprimir("ID DEL CLIENTE NO VÁLIDO, INGRESE ID MAYOR A 0: ");
        cin>>ID;
        cout<<endl;
    }

    int pos=0;
    while(clientes.leerDeDiscoC(pos++))
        if(clientes.getcID() == ID && clientes.getEstadoc())
        {
            return pos-1;
        }

    return -1;
}


bool baja_cliente()
{
    Cliente clientes;
    int pos=0;
    pos=buscarID_cliente();

    if(pos == -1)
    {
        imprimir("EL ID DE CLIENTE INGRESADO NO EXISTE EN EL SISTEMA ");
        return false;
    }

    clientes.leerDeDiscoC(pos);
    clientes.setEstadoC(false);
    imprimir("EL CLIENTE FUE ELIMINADO CORRECTAMENTE ");
    cout<<endl;
    return clientes.modificarEnDiscoC(pos);


}
#endif // FUNCIONESCLIENTES_H_INCLUDED
