#ifndef FUNCIONES_ENTRADA_H_INCLUDED
#define FUNCIONES_ENTRADA_H_INCLUDED


int contarEntradas();
bool altaEntrada();
int buscarIDEntrada(int id);
int listarEntradas();
bool mostrarEntradaPorID(int id);
bool baja_entrada();
int totalEntradasPedidas (int v[], int tam);
int contarBebidas();
bool altaBebida();
bool mostrar_porIDT();
void mostrar_bebidasALL();
int buscarID_bebida();
bool baja_bebida();
int totalBebidasPedidas (int v[], int tam);

int contarEntradas()
{
    Entrada entrada;
    int pos=0;
    while(entrada.leerDeDisco(pos)==1)
    {
        pos++;
    }
    return pos;
}

bool altaEntrada()
{

    Entrada entrada;

    entrada.Cargar();
    cls();

    return entrada.grabarEnDisco();
}



int buscarIDEntrada(int ID)
{

    Entrada entrada;
    int pos=0;

    while(entrada.leerDeDisco(pos)==1)
    {
        if(entrada.getID()==ID)
        {
            return pos;
        }
        pos++;
    }
    return -1;
}

int listarEntradas()
{

    Entrada entrada;

    int pos=0;

    if(contarEntradas() == 0)
    {
        imprimir("NO HAY ENTRADAS DISPONIBLES\n");
        return -1;
    }

    imprimir("TODAS LAS ENTRADAS DISPONIBLES ");

    cout<<endl<<endl;

    while(entrada.leerDeDisco(pos++))
    {
        if(entrada.getEstado())
        {
            entrada.Mostrar();
            cout<<endl;
        }

    }
    return 1;
}

bool mostrarEntradaPorID()
{
    int id;
    Entrada entrada;
    int pos;

    imprimir("INGRESE ID DE LA ENTRADA A MOSTRAR: ");
    cin>>id;
    while(id<0)
    {
        imprimir("INGRESE ID VÁLIDO, ID MAYOR A 0: ");
        cin>>id;
    }
    cout<<endl<<endl;

    while(entrada.leerDeDisco(pos++))
        if(entrada.getID()==id && entrada.getEstado())
        {
            entrada.Mostrar();
            return true;
        }


    return false;
}


bool baja_entrada()
{
    Entrada entrada;
    int pos=0, ID;
    char r;

    imprimir("INGRESE EL ID DE LA ENTRADA A BUSCAR:\n");
    cin>>ID;
    while(ID<0)
    {
        imprimir("INGRESE ID VÁLIDO, ID MAYOR A 0: ");
        cin>>ID;
    }
    pos=buscarIDEntrada(ID);
    if(pos == -1)
    {
        imprimir("EL ID DE LA ENTRADA INGRESADA NO EXISTE EN EL SISTEMA ");
        return false;
    }

    entrada.leerDeDisco(pos);
    if(entrada.getEstado())
    {
        cout<<"ENTRADA ENCONTRADA"<<endl<<endl;
        entrada.Mostrar();
        cout<<endl;
        cout<<"DESEA ELIMINAR DEFINITIVAMENTE LA ENTRADA? (S/N)"<<endl;
        cin>>r;
        cout<<endl;

        if('s' || 'S')
        {

            entrada.setEstado(false);
            imprimir("LA ENTRADA FUE ELIMINADA CORRECTAMENTE\n\n");
            return entrada.modificarEnDisco(pos);


        }
        else
        {
            cout<<"NO SE HA ELIMINADO LA ENTRADA"<<endl;
            return false;

        }
    }
    else
    {
        cout<<"LA ENTRADA YA HA SIDO ELIMINADA"<<endl;
        return false;
    }


}

int totalEntradasPedidas (int v[], int tam)
{
    int totalEntradas=0;

    for(int i=0; i<tam; i++)
    {
        totalEntradas+=v[i];
    }
    return totalEntradas;
}

void inicializarVector (Entrada v[], int tam)
{
    Entrada entrada;
    entrada.setID(0);
    for(int i=0; i<tam; i++)
    {
        v[i]=entrada;
    }
}


/////////////FUNCIONES TRAGOS////////////

int contarBebidas()
{
    Bebida bebida;
    int pos=0;
    while(bebida.leerDeDisco(pos)==1)
    {
        pos++;
    }
    return pos;
}

bool altaBebida()
{

    Bebida bebida;

    bebida.Cargar();
    system("cls");

    return bebida.grabarEnDisco();
}
void inicializarVector (Bebida v[], int tam)
{
    Bebida bebida;
    bebida.setID(0);
    for(int i=0; i<tam; i++)
    {
        v[i]=bebida;
    }
}

bool mostrar_porIDT()
{
    int ID;
    int pos=0;
    Bebida bebida;

    imprimir("INGRESE ID DEL TRAGO A MOSTRAR: ");
    cin>>ID;
    while(ID<0)
    {
        imprimir("INGRESE ID VÁLIDO, ID MAYOR A 0: ");
        cin>>ID;
    }
    cout<<endl<<endl;
    while(bebida.leerDeDisco(pos++))
    {
        if(bebida.getID() == ID && bebida.getEstado())
        {
            bebida.Mostrar();
            return true;
        }
    }
    return false;
}

void mostrar_bebidasALL()
{
    int pos=0;
    Bebida bebidas;

    if(contarBebidas() == 0)
    {
        imprimir("NO HAY TRAGOS DISPONIBLES\n");
        return;
    }

    imprimir("TODOS LOS TRAGOS DISPONIBLES");
    cout<<endl<<endl;
    while(bebidas.leerDeDisco(pos++))
    {
        if(bebidas.getEstado())
        {
            bebidas.Mostrar();
            cout<<endl;
        }
    }
}

int buscarID_bebida()
{
    int ID;
    Bebida bebida;

    gotoxy(39,3);
    imprimir("INGRESE ID DEL TRAGO A BUSCAR: ");
    gotoxy(73,3);
    cin>>ID;
    int pos=0;
    while(bebida.leerDeDisco(pos++))
        if(bebida.getID() == ID && bebida.getEstado())
        {
            return pos;
        }

    return -1;
}

bool baja_bebida()
{
    Bebida bebida;
    int pos=0;
    pos=buscarID_bebida();
    if(pos == -1)
    {
        imprimir("EL ID DEL TRAGO INGRESADO NO EXISTE EN EL SISTEMA ");
        return false;
    }

    bebida.leerDeDisco(pos-1);
    bebida.setEstado(false);
    return bebida.modificarEnDisco(pos-1);


}

int totalBebidasPedidas (int v[], int tam)
{
    int totalBebidas=0;

    for(int i=0; i<tam; i++)
    {
        totalBebidas+=v[i];
    }
    return totalBebidas;
}






#endif // FUNCIONES_ENTRADA_H_INCLUDED
