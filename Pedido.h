#ifndef CLASEMENU_H_INCLUDED
#define CLASEMENU_H_INCLUDED

int contarPedidos();

class Pedido
{

private:

    int IDPedido;
    int IDCliente;
    char nombreInvitado[30];
    float totalBebidas;
    float totalEntradas;
    float total;
    bool estadoPedido;
    Fecha fechaPedido;


public:

    bool cargar();
    int leerDeDisco(int pos);
    int grabarEnDisco();
    int modificarEnDisco(int pos);
    void imprimirTicket();
    bool esCliente();


    void setIDPedido (int IDT)
    {
        IDPedido=IDT;
    }
    void setIDCliente (int IDC)
    {
        IDCliente=IDC;
    }
    void setNombreInvitado (const char* n)
    {
        strcpy(nombreInvitado,n);
    }

    void setEstadoPedido (bool e)
    {
        estadoPedido=e;
    }
    void setTotalEntradas (float te)
    {
        totalEntradas=te;
    }

     void setTotalBebidas (float tb)
    {
        totalBebidas=tb;
    }

    void setTotal()
    {
        total=totalBebidas+totalEntradas;
    }

    int getIDPedido()
    {
        return IDPedido;
    }

    void setFecha (int dia, int mes, int anio)
    {
        fechaPedido.setDia(dia);
        fechaPedido.setMes(mes);
        fechaPedido.setAnio(anio);
    }

    int getIDCliente()
    {
        return IDCliente;
    }

    float getTotal ()
    {
        return total;
    }

    float getTotalConDescuento()
    {
        return total * (esCliente() ? 0.9 : 1);
    }

    bool getEstadoPedido()
    {
        return estadoPedido;
    }
    const char* getNombreInvitado()
    {
        return nombreInvitado;
    }

     float getTotalEntradas ()
    {
        return totalEntradas;
    }

     float getTotalBebidas ()
    {
        return totalBebidas;
    }

    Fecha getFechaPedido()
    {
        return fechaPedido;
    }

};

bool Pedido::esCliente()
{
    return this->getIDCliente() != 0;
}

void Pedido::imprimirTicket ()
{
    imprimir("TICKET ID: ");
    cout<<this->getIDPedido();
    imprimir(" - FECHA: ");
    this->getFechaPedido().Mostrar();
    cout<<endl;

    if(this->esCliente())
    {
        imprimir("ID CLIENTE: ");
        cout<<getIDCliente()<<endl<<endl;
    }
    else
    {
        imprimir("NOMBRE INVITADO: ");
        cout<<getNombreInvitado()<<endl<<endl;
    }
    if(getTotalBebidas() != 0)
    {
    imprimir("TOTAL BEBIDAS: $");
    cout<<getTotalBebidas()<<endl<<endl;
    }
    if(getTotalEntradas() != 0)
    {
    imprimir("TOTAL ENTRADAS: $");
    cout<<getTotalEntradas()<<endl<<endl;
    }
    imprimir("-----------------------------------\n");

    float totalPedido = this->getTotal();

    if (this->esCliente())
    {
        imprimir("TOTAL PEDIDO ");
        cout<<" $"<<totalPedido<<endl;
        imprimir("DESCUENTO POR CLIENTE 10% ");
        cout << " ($" << (totalPedido*0.1) << ")\n";
    }
    imprimir("TOTAL ");

    cout<<" $"<<this->getTotalConDescuento()<<endl;

}


int Pedido::leerDeDisco(int pos)
{
    FILE *p;
    p=fopen(ArchivoPedidos,"rb");
    if(p==NULL) return false;
    fseek(p,pos*sizeof(Pedido),0);
    bool leyo=fread(this, sizeof(Pedido),1,p);
    fclose(p);
    return leyo;
}

int Pedido::grabarEnDisco()
{
    FILE *p;
    p=fopen(ArchivoPedidos,"ab");
    if(p==NULL) return false;
    bool escribio=fwrite(this, sizeof(Pedido),1,p);
    fclose(p);
    return escribio;
}

int Pedido::modificarEnDisco(int pos)
{
    FILE *p;
    p=fopen(ArchivoPedidos,"rb+");
    if(p==NULL) return false;
    fseek(p,pos*sizeof(Pedido),0);
    bool modifico=fwrite(this, sizeof(Pedido),1,p);
    fclose(p);
    return modifico;
}


bool Pedido::cargar()
{
    int pos=0,pID=0,encontro=0,precio;
    char opc;
    Bebida bebida;
    Entrada entrada;
    Usuario usuario;
    Cliente clientes;
    this->setIDCliente(0);

    imprimir("NUEVO PEDIDO\n");
    pos=contarPedidos();
    if(pos>=0)
    {
        pID=pos+1;
        setIDPedido(pID);
    }
    imprimir("PEDIDO ID: ");
    cout<<this->getIDPedido()<<endl;
    imprimir("ES CLIENTE REGISTRADO? (S-N): ");
    cin>>opc;
    switch(opc)
    {

    case 'S':
    case 's':
        cout<<endl;
        encontro=buscarID_cliente();
        while(encontro == -1)
        {
            imprimir("ID NO ENCONTRADO, POR FAVOR INGRESE ID QUE ESTE EN EL SISTEMA:\n");
            encontro=buscarID_cliente();
        }
        clientes.leerDeDiscoC(encontro);
        this->setIDCliente(clientes.getcID());
        break;
    case 'N':
    case 'n':
        cout<<endl;
        imprimir("INGRESE NOMBRE DEL CLIENTE (NO REGISTRADO): ");
        cargarCadena(nombreInvitado,29);
        this->setNombreInvitado(nombreInvitado);
        break;
    default:
        imprimir("OPCION INCORRECTA\n\n");
        system("pause");
        return false;
        break;
    }
    cout<<endl;
    imprimir("AGREGAR ITEM (B- BEBIDA, E- ENTRADA, C- CERRAR PEDIDO): ");
    cin>>opc;
    while(opc!='C' || opc != 'c')
    {
        switch(opc)
        {
        case 'B':
        case 'b':
            precio=bebida.seleccionar();
            totalBebidas+=precio;
            break;
        case 'E':
        case 'e':
            precio=entrada.seleccionar();
            totalEntradas+=precio;
            break;
        case 'C':
        case 'c':
            this->setEstadoPedido(true);
            time_t tiempo;
            struct tm *tmPtr;
            tiempo = time(NULL);
            tmPtr = localtime(&tiempo);
            this->setFecha(tmPtr->tm_mday,tmPtr->tm_mon+1,1900+tmPtr->tm_year);
            this->setTotal();
            return true;
            break;
        default:
            imprimir("OPCION INCORRECTA\n\n");
            system("pause");
            break;
        }
        cout<<endl;
        imprimir("AGREGAR ITEM (B- BEBIDA, E- ENTRADA, C- CERRAR PEDIDO): ");
        cin>>opc;
    }

    return false;
}





#endif // CLASEMENU_H_INCLUDED
