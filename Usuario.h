#ifndef CLASE_USUARIO_H_INCLUDED
#define CLASE_USUARIO_H_INCLUDED

int contarUsuarios();

class Usuario
{
private:
    int ID;
    int tipo; //1.administrador o 2.empleado
    char nombre[30];
    char apellido[30];
    char cuil[8];
    char contrasenia_ingreso[10];
    Fecha fecha_ingreso;
    bool estado;

public:

    bool cargarUsuario();
    void mostrarUsuario();
    bool leerDeDisco(int pos);
    bool leerDeDiscoINI(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(int pos);

    void setID(int id)
    {
        ID=id;
    }
    void setTipo(int t)
    {
        tipo=t;
    }
    void setNombre (const char* n)
    {
        strcpy(nombre,n);
    }
    void setApellido (const char* a)
    {
        strcpy(apellido,a);
    }
    void setCuil (const char* cu)
    {
        strcpy(cuil,cu);
    }
    void setContrasenia (const char* password)
    {
        strcpy(contrasenia_ingreso,password);
    }
    void setFechaIngreso (int d, int m, int a)
    {
        fecha_ingreso.setDia(d);
        fecha_ingreso.setMes(m);
        fecha_ingreso.setAnio(a);
    }
    void setEstado (bool e)
    {
        estado=e;
    }

    int getID()
    {
        return ID;
    }
    int getTipo()
    {
        return tipo;
    }
    const char* getNombre()
    {
        return nombre;
    }
    const char* getApellido()
    {
        return apellido;
    }
    const char* getCuil()
    {
        return cuil;
    }
    void getFechaIngreso()
    {
        return fecha_ingreso.Mostrar();
    }
    const char *getPassword()
    {
        return contrasenia_ingreso;
    }
    bool getEstado()
    {
        return estado;
    }


};


bool Usuario::cargarUsuario()
{
    int uID=0,pos;
    imprimir("CARGAR NUEVO USUARIO\n");
    cout<<endl;
    pos=contarUsuarios();
    if(pos>=0)
    {
        uID=pos+1;
        setID(uID);
    }
    imprimir("ID: ");
    cout<<uID;
    cout<<endl;
    imprimir("INGRESE TIPO DE USUARIO (1.ADMINISTRADOR - 2.EMPLEADO): ");
    cin>>tipo;
    cout<<endl;
    imprimir("INGRESE NOMBRE: ");
    cargarCadena(nombre,29);
    cout<<endl;
    imprimir("INGRESE APELLIDO: ");
    cargarCadena(apellido,29);
    cout<<endl;
    imprimir("INGRESE CUIL: ");
    cin>>cuil;
    cout<<endl;
    imprimir("INGRESE CONTRASEÑA DEL SISTEMA: ");
    cargarCadena(contrasenia_ingreso,9);
    cout<<endl;
    imprimir("FECHA DE INGRESO: ");
    fecha_ingreso.Cargar();
    cout<<endl;

    estado=1;
    return true;

}

void Usuario::mostrarUsuario()
{
    if (this->getEstado() == false) return;

        imprimir("ID USUARIO: ");
        cout<<ID<<endl;
        imprimir("TIPO DE USUARIO: ");
        cout<<tipo<<endl;
        imprimir("NOMBRE: ");
        cout<<nombre<<endl;
        imprimir("APELLIDO: ");
        cout<<apellido<<endl;
        imprimir("CUIL: ");
        cout<<cuil<<endl;
        imprimir("CONTRASENIA DEL SISTEMA: ");
        cout<<contrasenia_ingreso<<endl;
        imprimir("FECHA DE INGRESO: ");
        fecha_ingreso.Mostrar();
        cout<<endl<<endl;


}

bool Usuario::leerDeDisco(int pos)
{
    FILE *p;
    p=fopen(ArchivoUsuarios,"rb");
    if(p==NULL) return false;
    fseek(p,pos*sizeof(Usuario),0);
    bool leyo=fread(this, sizeof(Usuario),1,p);
    fclose(p);
    return leyo;
}

bool Usuario::leerDeDiscoINI(int pos)
{
    FILE *p;
    p=fopen(ArchivoUsuariosINI,"rb");
    if(p==NULL) return false;
    fseek(p,pos*sizeof(Usuario),0);
    bool leyo=fread(this, sizeof(Usuario),1,p);
    fclose(p);
    return leyo;
}

bool Usuario::grabarEnDisco()
{
    FILE *p;
    p=fopen(ArchivoUsuarios,"ab");
    if(p==NULL) return false;
    bool escribio=fwrite(this, sizeof(Usuario),1,p);
    fclose(p);
    return escribio;
}

bool Usuario::modificarEnDisco(int pos)
{
    FILE *p;
    p=fopen(ArchivoUsuarios,"rb+");
    if(p==NULL) return false;
    fseek(p,pos*sizeof(Usuario),0);
    bool modifico=fwrite(this, sizeof(Usuario),1,p);
    fclose(p);
    return modifico;
}



#endif // CLASE_USUARIO_H_INCLUDED
