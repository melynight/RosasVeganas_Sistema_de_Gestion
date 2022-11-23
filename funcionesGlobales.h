#ifndef CARGARCADENA_H_INCLUDED
#define CARGARCADENA_H_INCLUDED

void cargarCadena(char *pal, int tam)
{
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}



///FUNCIONES PROPIAS.

void imprimir (const char *cadena)
{
    int i, tam= strlen(cadena);

    for (i=0; i<tam; i++)
    {
        cout << cadena[i];
        //Sleep(1);
    }
}

void imprimirFechaSistema()
{
    Fecha fechaActual;
    fechaActual.MostrarFechaActual();

}



void cls()
{
    system("cls");
    gotoxy(107,1);
    imprimirFechaSistema();
}


void MostrarLineaHorizontal(int x, int y, int tam)
{
    for (int i= 0; i < tam; i+=3)
    {
        gotoxy(x,y);
        x+=3;
        imprimir("___");
        Sleep(1);
    }
}


const char *ocultarContrasenia(char *cad)
{
    int pos=0,tam=10;
    char caracter;
    strcpy(cad," ");

    fflush(stdin);


    caracter = getch();

    while(caracter != '\r' && pos < tam)
    {
        cad[pos++]= caracter;
        cout<<"*";
        caracter = getch();
        if(caracter == '\b') break;

    }

    cad[pos]= '\0';
    fflush(stdin);

    return cad;

}





#endif // CARGARCADENA_H_INCLUDED
