#ifndef CLASECLIENTES_H_INCLUDED
#define CLASECLIENTES_H_INCLUDED

class Cliente
{
private:

    int cID;
    char cNombre[30];
    char cApellido[30];
    char dni[10];
    char whatsapp[10];
    Fecha fecha_registro;
    bool estado;

public:

    bool cargarCliente();
    void mostrarCliente();
    bool leerDeDiscoC(int pos);
    bool leerDeDiscoCINI(int pos);
    bool grabarEnDiscoC();
    bool modificarEnDiscoC(int pos);

    void setcID( int ID)
    {
        cID=ID;
    }
    void setcNombre(const char* n)
    {
        strcpy(cNombre,n);
    }
    void setcApellido(const char *a)
    {
        strcpy(cApellido,a);
    }
    void setDNI(const char* d)
    {
        strcpy(dni,d);
    }
    void setFechaRegistro (int d,int m, int a)
    {
        fecha_registro.setDia(d);
        fecha_registro.setMes(m);
        fecha_registro.setAnio(a);
    }
    void setWpp(const char* w)
    {
       strcpy(whatsapp,w);
    }
    void setEstadoC(bool e)
    {
        estado=e;
    }

    int getcID() {return cID;}
    const char* getcNombre() {return cNombre;}
    const char* getcApellido() {return cApellido;}
    const char* getDNI() {return dni;}
    const char* getWpp() {return whatsapp;}
    void getFechaRegistro() {fecha_registro.Mostrar();}
    bool getEstadoc() {return estado;}

};

int contarClientes()
{
    Cliente clientes;
    int pos=0;
    while(clientes.leerDeDiscoC(pos)==1)
    {
        pos++;
    }
    return pos;
}

bool verificarDni(const char* cadDni)
{
    Cliente cliente;
    int pos=0;
    while(cliente.leerDeDiscoC(pos++))
    {
        if((strcmp(cliente.getDNI(),cadDni))==0)
        return true;
    }
    return false;
}

bool Cliente::cargarCliente()
{
    int cID=0,pos;
    bool valido;
    imprimir("CARGAR NUEVO CLIENTE\n");
    cout<<endl;
    imprimir("INGRESE DNI: ");
    cargarCadena(dni,9);
    cout<<endl;
    valido=verificarDni(dni);
    while(valido)
    {
        imprimir("EL DNI YA FUE INGRESADO EN EL SISTEMA, INGRESE OTRO DNI: ");
        cargarCadena(dni,9);
        valido=verificarDni(dni);
    }
    pos=contarClientes();
    if(pos>=0)
    {
        cID=pos+1;
        setcID(cID);
    }
    cout<<"ID: ";
    cout<<cID;
    cout<<endl;
    cout<<endl;
    cout<<"INGRESE NOMBRE: ";
    cargarCadena(cNombre,29);
    cout<<endl;
    cout<<"INGRESE APELLIDO: ";
    cargarCadena(cApellido,29);
    cout<<endl;
    cout<<"INGRESE NUMERO DE WHATSAPP: ";
    cargarCadena(whatsapp,9);
    cout<<endl;
    cout<<"FECHA DE REGISTRO: ";
    cout<<endl;
    fecha_registro.Cargar();
    cout<<endl;

    estado=true;

    return true;
}

void Cliente::mostrarCliente()
{
    if(this->getEstadoc())
    {
    cout<<"CLIENTE ID: ";
    cout<<cID<<endl;
    cout<<"NOMBRE: ";
    cout<<cNombre<<endl;
    cout<<"APELLIDO: ";
    cout<<cApellido<<endl;
    cout<<"DNI: ";
    cout<<dni<<endl;
    cout<<"WHATSAPP: ";
    cout<<whatsapp<<endl;
    cout<<"FECHA DE REGISTRO: ";
    fecha_registro.Mostrar();
    cout<<endl<<endl;
    }

}


bool Cliente::leerDeDiscoC(int pos)
{
    FILE *p;
    p=fopen(ArchivoClientes,"rb");
    if(p==NULL) return false;
    fseek(p,pos*sizeof(Cliente),0);
    bool leyo=fread(this, sizeof(Cliente),1,p);
    fclose(p);
    return leyo;
}

bool Cliente::leerDeDiscoCINI(int pos)
{
    FILE *p;
    p=fopen(ArchivoClientesINI,"rb");
    if(p==NULL) return false;
    fseek(p,pos*sizeof(Cliente),0);
    bool leyo=fread(this, sizeof(Cliente),1,p);
    fclose(p);
    return leyo;
}

bool Cliente::grabarEnDiscoC()
{
    FILE *p;
    p=fopen(ArchivoClientes,"ab");
    if(p==NULL) return false;
    bool escribio=fwrite(this, sizeof(Cliente),1,p);
    fclose(p);
    return escribio;
}

bool Cliente::modificarEnDiscoC(int pos)
{
    FILE *p;
    p=fopen(ArchivoClientes,"rb+");
    if(p==NULL) return false;
    fseek(p,pos*sizeof(Cliente),0);
    bool modifico=fwrite(this, sizeof(Cliente),1,p);
    fclose(p);
    return modifico;
}



#endif // CLASECLIENTES_H_INCLUDED
