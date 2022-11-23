#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED


void totalRecaudado()
{
    Pedido pedido;
    int cantPedidos=0;
    float totalRecaudado=0;
    int pos=0;

    while(pedido.leerDeDisco(pos++))
    {
        if(pedido.getEstadoPedido())
        {
            cantPedidos++;
            totalRecaudado+=pedido.getTotalConDescuento();
        }
    }
    imprimir("EL TOTAL RECAUDADO HASTA EL MOMENTO: $");
    cout<<totalRecaudado<<endl;
    imprimir("CANT. PEDIDOS: ");
    cout<<cantPedidos<<endl;
    imprimir("PROMEDIO RECAUDADO POR PEDIDO: $");
    cout<<(totalRecaudado/cantPedidos)<<endl<<endl;
}

void clienteMasFrecuente()
{
    Pedido pedido;
    Cliente cliente;
    int totalPedidos=0,mayorTotal=0,pos=0,posC=0;
    int IDMayorCliente=0;


    while(cliente.leerDeDiscoC(posC++))
    {
        while(pedido.leerDeDisco(pos++))
        {
            if(cliente.getcID() == pedido.getIDCliente())
            {
                totalPedidos++;
            }
        }
        if(totalPedidos > mayorTotal)
        {
            mayorTotal= totalPedidos;
            IDMayorCliente= cliente.getcID();
        }
        pos=0;
        totalPedidos=0;
    }
    MostrarLineaHorizontal(3,1,40);
    gotoxy(6,3);
    imprimir("EL CLIENTE REGISTRADO MÁS FRECUENTE ");
    MostrarLineaHorizontal(3,4,40);
    gotoxy(2,6);
    cout<< "ID DE CLIENTE: " << IDMayorCliente << " CON " << mayorTotal << " PEDIDOS REALIZADOS." <<endl<<endl;


}

bool pedidosxMes()
{
    Pedido pedido;
    int pos=0,mes,bandera=false;

    imprimir("INGRESE MES PARA LISTAR PEDIDOS: ");
    cin>>mes;
    while(mes<1 || mes>12)
    {
        imprimir("INGRESE MES VÁLIDO (1-12): ");
        cin>>mes;
    }
    cout<<endl<<endl;
    while(pedido.leerDeDisco(pos++))
    {
        if(pedido.getFechaPedido().getMes() == mes && pedido.getEstadoPedido())
        {
            pedido.imprimirTicket();
            bandera=true;
            cout<<endl;
        }
    }
    return bandera;
}







#endif // REPORTES_H_INCLUDED
