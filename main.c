/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int MinPeriod(int * a, int n){
    /*i->pocetak j->setaPoNizu p->period*/
    int i, j, p=n, pomI, pomJ;
    /*j proseta da nadje element na koji pokazuje i. Ako ga nadje proverava da li je to periodicno*/
    
    for(i=0,j=1;j<n;j++){
       // printf("cao");
       // printf("%d %d\n", a[i], a[j]);
        if(a[i]==a[j]){
            //naisli na isti. Da li su svi isti?
            for(pomI=i+1, pomJ=j+1;pomJ<n;pomI++, pomJ++){
                if(a[pomI]!=a[pomJ]){
                    break; //izlazimo, nije period
                }
                
            }
            //ako je bio period
            if((pomJ==n) && (pomJ%j==0)){
                p=j; //nasli smo period
                break;
            }
        }
    }
    return p;   
}

int main()
{
    int a1[]={2,5,3,4,2,5,3,4};
    int a2[]={2,5,3,2,5,3,2,5};
    int a3[]={2,5,3,2,2,5,3,2};
    printf("test 1 ? 4 == %d\n", MinPeriod(a1, 8));
    printf("test 2 ? 8 == %d\n", MinPeriod(a2, 8));
    printf("test 2 ? 4 == %d\n", MinPeriod(a3, 8));


    return 0;
}
