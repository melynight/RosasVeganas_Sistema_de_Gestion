#ifndef FUNCIONESPEDIDOS_H_INCLUDED
#define FUNCIONESPEDIDOS_H_INCLUDED


int contarPedidos(){

    Pedido pedido;

    int pos=0;
    while(pedido.leerDeDisco(pos)==1){
       pos++;
    }
    return pos;
 }

bool altaPedido()
{
    Pedido pedido;

    pedido.cargar();

    cls();

    bool grabo = pedido.grabarEnDisco();

    cls();
    pedido.imprimirTicket();
    cout<<endl<<endl<<endl;
    return grabo;
}

int buscarIDPedido(int ID)
{

   Pedido pedido;
    int pos=0;

    while(pedido.leerDeDisco(pos)==1)
    {
        if(pedido.getIDPedido()==ID)
        {
            return pos;
        }
        pos++;
    }
    return -1;
}


bool mostrarPedidoPorID()
{
    int pos=0,id;
    Pedido pedido;

    imprimir("INGRESE ID DEL PEDIDO A MOSTRAR: ");
    cin>>id;
    while(id<1)
    {
    imprimir("INGRESE ID VÁLIDO, ID MAYOR A 0: ");
    cin>>id;
    }
    cout<<endl<<endl;

    while(pedido.leerDeDisco(pos++))
    {
        if(pedido.getIDPedido() == id && pedido.getEstadoPedido())
        {
            pedido.imprimirTicket();
            return true;
        }
    }
    return false;
}

bool bajaPedido()
{
    Pedido pedido;
    int pos=0, ID;

    imprimir("INGRESE EL ID DEL PEDIDO A BUSCAR: ");
    cin>>ID;
    cout<<endl;
    pos=buscarIDPedido(ID);
    if(pos == -1)
    {
        imprimir("EL ID DEL PEDIDO INGRESADO NO EXISTE EN EL SISTEMA ");
        return false;
    }

    pedido.leerDeDisco(pos);
    pedido.setEstadoPedido(false);
    cout<<endl<<endl;
    imprimir("EL PEDIDO FUE ELIMINADO CORRECTAMENTE ");
    return pedido.modificarEnDisco(pos);

}




#endif // FUNCIONESPEDIDOS_H_INCLUDED
