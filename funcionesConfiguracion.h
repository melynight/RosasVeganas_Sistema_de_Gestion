#ifndef FUNCIONESCONFIGURACION_H_INCLUDED
#define FUNCIONESCONFIGURACION_H_INCLUDED


/*bool copia_archivos_ini()
{

    Usuario usuarios;
    Cliente clientes;
    FILE *u,*c;
    int pos=0,posc=0;

    u=fopen("Usuarios.ini","wb");
    while(usuarios.leerDeDisco(pos++)) fwrite(&usuarios,sizeof usuarios,1,u);
    fclose(u);

    c=fopen("Clientes.ini","wb");
    while(clientes.leerDeDiscoC(posc++)) fwrite(&clientes,sizeof clientes,1,c);
    fclose(c);


    return true;
}*/

bool establecer_datosini()
{
    Usuario usuarios;
    Cliente clientes;

    FILE *u,*c;
    int pos=0,posc=0;

    u=fopen(ArchivoUsuarios,"wb");
    if(u==NULL) return false;
    while(usuarios.leerDeDiscoINI(pos++)) fwrite(&usuarios,sizeof usuarios,1,u);
    fclose(u);

    c=fopen(ArchivoClientes,"wb");
    if(c==NULL) return false;
    while(clientes.leerDeDiscoCINI(posc++)) fwrite(&clientes,sizeof clientes,1,c);
    fclose(c);

    return true;
}

bool copia_usuarios()
{
    Usuario usuario;
    FILE *u;
    int pos=0;
    char r;

    cout<<"COPIA DE ARCHIVO USUARIOS"<<endl;
    cout<<"¿DESEA CONTINUAR? (S-s) / OTRA TECLA PARA CANCELAR"<<endl;
    cin>>r;

    if(r=='s' || r== 'S')
    {
        u=fopen("Usuarios.bak","wb");
        if(u==NULL) return false;

        while(usuario.leerDeDisco(pos++)) fwrite(&usuario, sizeof usuario,1,u);
        fclose(u);
        return true;
    }

    else return false;

}

bool copia_clientes()
{
    Cliente cliente;
    FILE *c;
    int pos=0;
    char r;

    cout<<"COPIA DE ARCHIVO USUARIOS"<<endl;
    cout<<"¿DESEA CONTINUAR? (S-s / OTRA TECLA PARA CANCELAR)"<<endl;
    cin>>r;

    if(r=='s' || r== 'S')
    {
        c=fopen("Cliente.bak","wb");
        if(c==NULL) return false;

        while(cliente.leerDeDiscoC(pos++)) fwrite(&cliente, sizeof cliente,1,c);
        fclose(c);
        return true;
    }

    else return false;

}

bool recuperarClientes()
{
    Cliente cliente;
    FILE *cBack,*cRest;
    char r;

    cout<<"RESTAURAR ARCHIVO CLIENTES"<<endl;
    cout<<"¿DESEA CONTINUAR? (S-s)"<<endl;
    cin>>r;

    if(r=='s' || r=='S')
    {
        cBack=fopen("Cliente.bak","rb");
        cRest=fopen(ArchivoClientes,"wb");

        if(cBack==NULL || cRest==NULL) return false;

        while(fread(&cliente, sizeof(Cliente),1,cBack)==1) fwrite(&cliente,sizeof cliente,1,cRest);

        fclose(cBack);
        fclose(cRest);

        return true;
    }

    else return false;

}

bool recuperarUsuarios()
{
    Usuario usuario;
    FILE *uBack,*uRest;
    char r;

    cout<<"RESTAURAR ARCHIVO USUARIOS"<<endl;
    cout<<"¿DESEA CONTINUAR? (S-s)"<<endl;
    cin>>r;

    if(r=='s' || r=='S')
    {
        uBack=fopen("Usuarios.bak","rb");
        uRest=fopen(ArchivoUsuarios,"wb");

        if(uBack==NULL || uRest==NULL) return false;

        while(fread(&usuario, sizeof(Usuario),1,uBack)==1) fwrite(&usuario,sizeof usuario,1,uRest);

        fclose(uBack);
        fclose(uRest);

        return true;
    }

    else return false;

}







#endif // FUNCIONESCONFIGURACION_H_INCLUDED
