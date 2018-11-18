/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int AreStringsIsomorphic(char * a, char * b){
    char used[26]; // da li je vec iskoristen kao slika 
    char image1[26]; // image[i]=map(i+'a')
    /*
    a b c d e 
    f g h i j
    k l m n o
    p q r s t
    u v w h y z 
    */
    int i, j, k;
    char c, d;
    /*sve se slika u 0*/
    for(i=0;i<26;i++){
        image1[i]=0;
        used[i]=0;
    }
    
    if(sizeof(a)==sizeof(b)){
        for(k=0;a[k]!=0;k++){
            c=a[k]; //karakter koji treba mapirati
            d=b[k]; // karakter u koji mapiramo c
            //Da li je vec mapiran
            //printf("poredim %c i %c\n", c, d);
            if(image1[c-'a']==0){
                //nije mapiran
                //Da li je d zauzet
                if(used[d-'a']==0){
                    //nije zauzet
                    // vrsimo mapiranje 
                    //printf("mapiram %c->%c\n", c, d );
                    image1[c-'a']=d;
                    used[d-'a']=c;
                }
                //zauzet je d
                else{
                    //printf("%c je vec slika karaktera %c\n", d, used[d-'a']);
                    return 0;
                }
            }
            //vec je mapiran
            //proveri da li sa istim kao i sad
            else if(image1[c-'a']==d){
                //sve u redu, nastavi dalje
                //printf("%c je vec mapiran u karakter %c OK\n", c, image1[c]);
                continue;
            }
            else{
                // jedan karakter ima dve slike
                //printf("%c je vec mapiran u karakter %c ERROR\n", c, image1[c]);
                return 0;
            }
        }
        
        //printf("kraj petlje\n");
        return 1;
    }
    
    //printf("ne poklapaju se\n");
    return 0;
    
}

int main()
{
    char *a1="brain";
    char *b1="space";
    char *a2="noon";
    char *b2="feet";
    char *a3="aab";
    char *b3="ccd";
    printf("%s->%s ??? %s\n",a1, b1, AreStringsIsomorphic(a1, b1)==1?"true":"false");
    printf("%s->%s ??? %s\n",a2, b2, AreStringsIsomorphic(a2, b2)==1?"true":"false");
    printf("%s->%s ??? %s\n",a3, b3, AreStringsIsomorphic(a3, b3)==1?"true":"false");

    return 0;
}
