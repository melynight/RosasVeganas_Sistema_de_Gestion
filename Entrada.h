#ifndef CLASEENTRADA_H_INCLUDED
#define CLASEENTRADA_H_INCLUDED

int contarEntradas();

class Entrada
{
private:

    int ID;
    float precio;
    char nombre[30];
    char descripcion[60];
    bool estado;

public:

    void setID(int e)
    {
        ID=e;
    }
    void setPrecio(float p)
    {
        precio=p;
    }
    void setNombre(const char* nom)
    {
        strcpy(nombre,nom);
    }
    void setDespcripcion(const char* desc)
    {
        strcpy(descripcion,desc);
    }
    void setEstado(bool est)
    {
        estado=est;
    }

    int getID()
    {
        return ID;
    }
    float getPrecio()
    {
        return precio;
    }
    const char* getNombre()
    {
        return nombre;
    }
    const char* getDescripcion()
    {
        return descripcion;
    }
    bool getEstado()
    {
        return estado;
    }

    void Cargar();
    void Mostrar();
    int leerDeDisco(int pos);
    int grabarEnDisco();
    int modificarEnDisco(int pos);
    float seleccionar();

};

float Entrada::seleccionar()
{
    int pos=0,entrada=0,opc;
    float seleccionEntrada=0;

    while(leerDeDisco(pos++))
    {
        if(getEstado())
        {
            cout<<(++entrada)<<". "<<getNombre()<<endl;
        }
    }

    cout<<endl;
    imprimir("SELECCIONE ENTRADA: ");
    cin>>opc;
    this->leerDeDisco(opc-1);
    seleccionEntrada=this->getPrecio();

    return seleccionEntrada;

}


int Entrada::leerDeDisco(int pos)
{
    FILE *p;

    p=fopen(ArchivoEntradas,"rb");
    if(p==NULL) return -1;
    fseek(p, pos*sizeof(Entrada),0);
    bool leyo= fread(this, sizeof(Entrada),1,p);
    fclose(p);
    return leyo;
}


int Entrada::grabarEnDisco()
{
    FILE *p;
    p=fopen(ArchivoEntradas,"ab");
    if(p==NULL) return -1;
    bool grabo=fwrite(this, sizeof (Entrada),1,p);
    fclose(p);
    return grabo;
}


int Entrada::modificarEnDisco(int pos)
{
    FILE * p;
    p=fopen(ArchivoEntradas,"rb+");
    if(p==NULL) return -1;
    fseek(p,pos*sizeof(Entrada),0);
    bool modifico=fwrite(this, sizeof (Entrada),1,p);
    fclose(p);
    return modifico;
}

void Entrada::Cargar()
{
    int ID, pos;
    pos=contarEntradas();
    if(pos>=0)
    {
        ID=pos+1;
        setID(ID);
    }
    cout<<endl;
    cout<<"ID ENTRADA: ";
    cout<<ID;
    cout<<endl<<endl;
    cout<<"NOMBRE: ";
    cargarCadena(nombre,29);
    cout<<endl;
    cout<<"DESCRIPCIÓN: ";
    cargarCadena(descripcion,59);
    cout<<endl;
    cout<<"PRECIO: $";
    cin>>precio;
    while(precio<0)
    {
        cout<<"INGRESE UN PRECIO VÁLIDO (MAYOR A 0): ";
        cin>>precio;
    }
    cout<<endl;

    estado=true;
}


void Entrada::Mostrar()
{

    if(this->getEstado())
    {
        cout<<"ID ENTRADA: ";
        cout<<ID<<endl;
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;
        cout<<"DESCRIPCIÓN: ";
        cout<<descripcion<<endl;
        cout<<"PRECIO: ";
        cout<<"$"<<precio;
        cout<<endl;
    }
}

#endif // CLASEENTRADA_H_INCLUDED
