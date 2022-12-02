#include <stdio.h>
void main()
{
    FILE *fptr;
    char ch;
    fptr = fopen("arqtext.txt","w");
    while ((ch=getche()) != 27){

        if (ch==13){
            putc('\n', fptr);
        }else{
        putc(ch,fptr);
        }
    }
    fclose(fptr);
}//Fim main
