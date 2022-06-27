#include<iostream>

using namespace std;

int decimal(int a[8])               
{

    int i, nr = 0;                  
    for (i = 0; i <= 7; i++)
        nr = nr * 10 + a[i];        
                                    
    return nr;
}

int DinZecimalInBinar(int a)
{
    int i, v[8];
    for (i = 0; i <= 7; i++)            
        v[i] = 0;

    for (i = 7; i >= 0; i--)            
    {   

        v[i] = a % 2;                   
        a = a / 2;                      
    }
    return decimal(v);                  
}


int Adunare(int a[8], int b[8])         
{
    int transport = 0, c[8];          
    for (int i = 7; i >= 0; i--)
    {

        c[i] = a[i] + b[i] + transport;  
                                         
                                         
        transport = 0;
        if (c[i] == 2)                   
        {                               
            c[i] = 0;
            transport = 1;
        }
        if (c[i] == 3)                   
        {                               
            c[i] = 1;
            transport = 1;
        }
    }
                            
    return decimal(c);                  
}

int Scadere(int a[8], int b[8])         
{
    int transport = 0, c[8];            

    for (int i = 7; i >= 0; i--)
    {

        c[i] = a[i] - b[i] - transport;     

        if (c[i] == 0)                  
            transport = 0;
        if (c[i] == -1)
        {
            c[i] = 1;
            transport = 1;
        }
        if (c[i] == -2)
            c[i] = 0;

    }

    return decimal(c);

}
int Invers(int a[8])               
{
    int x[8];                       
    for (int i = 0; i <= 7; i++)
    {
        if (a[i] == 1)              
            x[i] = 0;
        else if (a[i] == 0)         
            x[i] = 1;
    }
   
    return decimal(x);              
}
int FunctiaAND(int a[8], int b[8])  
{
    int rez[8];                     
    int key = 0;                    
    while (key < 8)
    {
        if (a[key] == 1 && b[key] == 1)     
        {
            rez[key] = 1;
        }
        else
            rez[key] = 0;               
        key++;                          
    }
    int d = decimal(rez);               
    return d;
}
int FunctiaOR(int a[8], int b[8])       
{
    int rez[8], key = 0;                
    while (key < 8)
    {
        if (a[key] == 1 || b[key] == 1)     
            rez[key] = 1;
        else
            rez[key] = 0;                   
        key++;
    }
    int d = decimal(rez);                   
    return d;
}
int FunctiaXOR(int a[8], int b[8])          
{
    int rez[8], key = 0;                  
    while (key < 8)
    {
        if (a[key] == 1 && b[key] == 0)        
            rez[key] = 1;
        else if (a[key] == 0 && b[key] == 1)   
            rez[key] = 1;
        else if (a[key] == 1 && b[key] == 1)    
            rez[key] = 0;
        else
            rez[key] = 0;                       
        key++;
    }
    int d = decimal(rez);
    return d;
}
int main()
{
    int d, e, a[8] = {0,0,0,0,0,0,0,0}, b[8] = { 0,0,0,0,0,0,0,0}, i = 1, k = 1;

    
    while (k != 0)
    {
        cout << endl;
        cout << "Unitate aritmetico-logica pe 8 biti\n";
        cout << "---------------------------------------\n";       
        cout << "Alegeti operatia dorita \n 1 - Adunare \n 2 - Scadere \n 3 - Invers \n 4 - Functia AND \n 5 - Functia OR \n 6 - Functia XOR \n 0 - Pentru a iesi din program \n";
        cin >> k;
        if (k == 0)
        {
            exit(0);      
        }
        cout << "\nIntroduceti un numar pentru efectuarea operatiei = ";
        cin >> d;
        d = DinZecimalInBinar(d); 
        for (i = 7; i >= 0; i--)
        {
            a[i] = d % 10;          
            d = d / 10;
        }
        
        if (k == 3)
        {
            goto inv;      
        }

        cout << "Introduceti un al doilea numar = ";

        cin >> e;
        e = DinZecimalInBinar(e);
        for (i = 7; i >= 0; i--)
        {
            b[i] = e % 10;          
            e = e / 10;
        }

        if (k == 1)
        {
            cout << endl;
            cout << "---------------------------------------\n";
            cout <<"Rezultatul adunarii este: "<< Adunare(a, b)<<endl;
            cout << "---------------------------------------\n";
            cout << endl;
        }
        if (k == 2)
        {
            cout << endl;
            cout << "---------------------------------------\n";
            cout << "Rezultatul scaderii este: " << Scadere(a, b)<<endl;
            cout << "---------------------------------------\n";
            cout << endl;
            

        }
        inv:
        if (k == 3)
        {
            cout << endl;
            cout << "---------------------------------------\n";
            cout<< "Valoarea numarului la care s-a aplicat functia NOT este: " << Invers(a) << endl;
            cout << "---------------------------------------\n";
            cout << endl;
        }
        if (k == 4)
        {
           
            cout << endl;
            cout << "---------------------------------------\n";
            cout <<"Rezultatul dupa aplicare functiei AND este: " <<FunctiaAND(a, b)<<endl;
            cout << "---------------------------------------\n";
            cout << endl;
        }
        if (k == 5)
        {
           
            cout << endl;
            cout << "---------------------------------------\n";
            cout << "Rezultatul dupa aplicare functiei OR este: " << FunctiaOR(a, b)<<endl;
            cout << "---------------------------------------\n";
            cout << endl;
        }
        if (k == 6)
        {
            cout << endl;
            cout <<"Rezultatul dupa aplicare functiei XOR este: " <<FunctiaXOR(a, b)<<endl;
            cout << "---------------------------------------\n";
            cout << endl;
        }
    }

    return 0;
}
