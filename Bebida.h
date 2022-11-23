#ifndef CLASEBebida_H_INCLUDED
#define CLASEBebida_H_INCLUDED

int contarBebidas();

class Bebida
{

    int ID;
    float precio;
    char nombre[30];
    char descripcion[60];
    bool estado;

public:

    void setID (int e)
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
    void setDespcripcion(const char*desc)
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

int Bebida::leerDeDisco(int pos)
{
    FILE *p;
    p=fopen(ArchivoBebidas,"rb");
    if(p==NULL) return -1;
    fseek(p, pos*sizeof(Bebida),0);
    bool leyo= fread(this, sizeof(Bebida),1,p);
    fclose(p);
    return leyo;
}


int Bebida::grabarEnDisco()
{
    FILE *p;

    p=fopen(ArchivoBebidas,"ab");
    if(p==NULL) return -1;
    bool grabo=fwrite(this, sizeof (Bebida),1,p);
    fclose(p);
    return grabo;
}


int Bebida::modificarEnDisco(int pos)
{
    FILE * p;
    p=fopen(ArchivoBebidas,"rb+");
    if(p==NULL) return -1;
    fseek(p,pos*sizeof(Bebida),0);
    bool modifico=fwrite(this, sizeof (Bebida),1,p);
    fclose(p);
    return modifico;
}

float Bebida::seleccionar()
{
    int pos=0,bebida=0,opc;
    int seleccionBebida=0;

    while(leerDeDisco(pos++))
    {
        if(getEstado())
        {
        cout<<(++bebida)<<". "<<getNombre()<<endl;
        }
    }
    cout<<endl;
    imprimir("SELECCIONE BEBIDA: ");
    cin>>opc;
    this->leerDeDisco(opc-1);
    seleccionBebida= this->getPrecio();

    return seleccionBebida;

}

void Bebida::Cargar()
{
    int ID, pos;
    pos=contarBebidas();
    if(pos>=0)
    {
        ID=pos+1;
        setID(ID);
    }
    cout<<endl;
    imprimir("ID TRAGO: ");
    cout<<ID;
    cout<<endl<<endl;
    imprimir("NOMBRE: ");
    cargarCadena(nombre,29);
    cout<<endl;
    imprimir("DESCRIPCIÓN: ");
    cargarCadena(descripcion,59);
    cout<<endl;
    imprimir("PRECIO: $");
    cin>>precio;
    while(precio<0)
    {
        imprimir("PRECIO NO VÁLIDO, INGRESE PRECIO MAYOR A 0: ");
        cin>>precio;
    }
    cout<<endl;

    estado=true;
}


void Bebida::Mostrar()
{

    if(this->getEstado())
    {
        imprimir("ID TRAGO: ");
        cout<<ID<<endl;
        imprimir("NOMBRE: ");
        cout<<nombre<<endl;
        imprimir("DESCRIPCIÓN : ");
        cout<<descripcion<<endl;
        imprimir("PRECIO: ");
        cout<<"$"<<precio<<endl;
        cout<<endl;
    }
}




#endif // CLASEBebida_H_INCLUDED
