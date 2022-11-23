#ifndef FUNCIONESUSUARIOS_H_INCLUDED
#define FUNCIONESUSUARIOS_H_INCLUDED

int contarUsuarios();
bool agregar_usuario();
bool mostrar_porID();
void mostrar_usuariosALL();
int buscarID_usuario();
bool comprobar_usuario(int ID);
bool comprobar_contrasenia (int ID, const char *cad);
const char* buscarNombre(int ID, char nombre[]);
bool comprobar_administrador (int ID);
bool baja_usuario();

int contarUsuarios()
{
    Usuario usuarios;
    int pos=0;
    while(usuarios.leerDeDisco(pos)==1)
    {
        pos++;
    }
    return pos;
}

bool agregar_usuario()
{
    FILE *p;
    Usuario usuarios;
    p=fopen(ArchivoUsuarios,"ab");
    if(p==NULL)
    {
        return false;
    }
    usuarios.cargarUsuario();
    fwrite(&usuarios,sizeof(Usuario),1,p);
    fclose(p);

    return true;
}

bool mostrar_porID()
{
    int ID;
    int pos=0;
    Usuario usuarios;

    gotoxy(39,3);
    imprimir("INGRESE ID DEL USUARIO A MOSTRAR: ");
    gotoxy(73,3);
    cin>>ID;

    while(usuarios.leerDeDisco(pos++))
    {
        if(usuarios.getID() == ID && usuarios.getEstado())
        {
            usuarios.mostrarUsuario();
            return true;
        }
    }
    return false;
}

void mostrar_usuariosALL()
{
    int pos=0;
    Usuario usuarios;

    imprimir("TODOS LOS USUARIOS DEL SISTEMA:\n\n");

    while(usuarios.leerDeDisco(pos++))
    {
        if(usuarios.getEstado())
        {
            usuarios.mostrarUsuario();
            cout<<endl;
        }

    }
}


int buscarID_usuario()
{
    int ID;
    Usuario usuarios;

    imprimir("INGRESE ID DEL USUARIO A BUSCAR: ");
    cin>>ID;
    while(ID<0)
    {
        imprimir("INGRESE ID VÁLIDO, ID MAYOR A 0: ");
        cin>>ID;
    }
    int pos=0;
    while(usuarios.leerDeDisco(pos++))
        if(usuarios.getID() == ID && usuarios.getEstado() == true)
            return pos;


    return -1;
}

bool comprobar_usuario(int ID)
{
    Usuario usuarios;
    int pos=0;
    while(usuarios.leerDeDisco(pos++))
        if(usuarios.getID() == ID && usuarios.getEstado())
        {
            return true;
        }

    return false;
}

bool comprobar_contrasenia (int ID, const char *cad)
{
    Usuario usuarios;
    int pos=0;

    while(usuarios.leerDeDisco(pos++))
    {
        if(usuarios.getID() == ID)
        {
            if(strcmp(cad,usuarios.getPassword()) == 0)
                return true;
        }
    }
    return false;

}

const char* buscarNombre(int ID, char nombre[])
{
    Usuario usuarios;
    int pos=0;
    while(usuarios.leerDeDisco(pos++))
        if(usuarios.getID() == ID)
            strcpy(nombre,usuarios.getNombre());

    return nombre;
}

bool comprobar_administrador (int ID)
{
    Usuario usuarios;
    int pos=0;

    while(usuarios.leerDeDisco(pos++))
    {
        if(usuarios.getID() == ID && usuarios.getTipo() == 1)
        {
            return true;
        }
    }
    return false;
}

bool baja_usuario()
{
    Usuario usuarios;
    int pos=0;
    pos=buscarID_usuario();

    if(pos == -1)
    {
        imprimir("EL ID DE USUARIO INGRESADO NO EXISTE EN EL SISTEMA\n ");
        return false;
    }

    usuarios.leerDeDisco(pos-1); //porque me devuelve una pos mas.
    usuarios.setEstado(false);
    usuarios.modificarEnDisco(pos-1);

    return true;

}



#endif // FUNCIONESUSUARIOS_H_INCLUDED
