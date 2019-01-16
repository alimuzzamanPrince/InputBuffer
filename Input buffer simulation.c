#include <stdio.h>
#include <string.h>
#include <stdbool.h>
    bool isSpace(char ch)
    {
        if (ch == ' ')
            return (true);
        return (false);
    }

    int main(){
        char ch, Buffer[10];
        FILE *fp;
        int i=0;

        fp = fopen("input.c","r");

        if(fp == NULL){
            printf("error opening the file\n");
            exit(0);
        }

        while((ch = fgetc(fp)) != EOF){

             if(isalnum(ch)){
                   Buffer[i++] = ch;
               }
               else if((ch == ' ' || ch == '\n') && (i != 0)){
                       Buffer[i] = '\0';
                       i = 0;

                      if (isSpace(Buffer) != true)
                           printf("Token Found!\t'%s'\n", Buffer);
                   }

        }

        fclose(fp);

        return 0;
    }

