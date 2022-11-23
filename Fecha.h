#ifndef CLASEFECHA_H_INCLUDED
#define CLASEFECHA_H_INCLUDED


bool comprobarBisiesto (int anio);

bool comprobarBisiesto (int anio)
{

    if (anio%4==0)
    {
        if(anio%100==0)
        {
            if (anio%400==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (anio%400==0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }

}

class Fecha
{

///propiedades
private:
    int dia, mes, anio;

public:
    ///constructor parametros default
    Fecha (int d= 1,int m=1, int a= 1998)
    {
        dia=d;
        mes=m;
        anio=a;

    }
    bool Cargar();
    void Mostrar();
    void Mostrar(int dia, int mes, int anio);
    void MostrarFechaActual();

    ///sets
    void setDia (int d)
    {
        dia= d;
    }

    void setMes (int m)
    {
        mes= m;
    }

    void setAnio (int a)
    {
        anio= a;
    }

    ///gets

    int getDia ()
    {
        return dia;
    }

    int getMes()
    {
        return mes;
    }

    int getAnio()
    {
        return anio;
    }

};

void Fecha::MostrarFechaActual()
{
     time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);

 Mostrar(tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year);
}


bool Fecha::Cargar()
{
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    bool bandera=false;


    while(!bandera)
    {
        cout<< "Ingrese día (1-31): ";
        cin>> dia;
        if (dia>31 || dia<1)
        {
            do
            {
                cout<< "Ingrese un número de día válido (1-31)" <<endl;
                cin>> dia;

            }
            while (dia>31 || dia<1);
        }
        cout<< "Ingrese mes (1-12): ";
        cin>> mes;

        while(mes<1 || mes>12)
        {
            cout<< "Ingrese un número de mes válido (1-12)" <<endl;
            cin>>mes;
        }
        while((mes==4 && dia > 30)|| (mes==6 && dia > 30) || (mes==9 && dia > 30) || (mes==11 && dia > 30))
        {
          cout<<"El día ingresado no corresponde. El mes ingresado tiene únicamente 30 dias"<<endl;
          cout<< "Ingrese día (1-31): ";
          cin>> dia;
          cout<<"Ingrese mes (1-12): ";
          cin>> mes;
        }
        cout<< "Ingrese año: ";
        cin>> anio;

        while(anio>1900+tmPtr->tm_year)
        {
            cout<<"Ingrese un año válido: "<<endl;
            cin>>anio;
        }

        int bisiesto=comprobarBisiesto(anio);
        if(bisiesto == true && mes== 2 && dia == 29) bandera=true;
            else if (!bisiesto && mes == 2 && dia>=29)
            {
                cout<<"El año ingresado no es bisiesto, no puede corresponder una fecha mayor al 28-02 "<<endl;
            }
            else
            {
            if(anio!=1900+tmPtr->tm_year)bandera=true;
            else if (mes<=tmPtr->tm_mon+1){
                if (mes==tmPtr->tm_mon+1){
                    if (dia<=tmPtr->tm_mday)bandera=true;
                    else cout<<"No es posible ingresar fechas futuras a la del Sistema "<<endl;
                }
                else bandera=true;
                }
                else cout<<"No es posible ingresar fechas futuras a la del Sistema "<<endl;
            }
    }
    return true;
}

void Fecha::Mostrar()
{
    cout<< getDia() <<"/" << getMes() << "/" << getAnio() <<endl;
}
void Fecha::Mostrar(int dia, int mes, int anio)
{
    cout<< dia <<"/" << mes << "/" << anio <<endl;
}

#endif // CLASEFECHA_H_INCLUDED
