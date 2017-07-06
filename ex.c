#include <stdio.h>
#include <string.h>

char *function(char *pnum1, char *pnum2);
void display(int num, char **str);

void main(void)
{
    char str[] = "This a book";
    char *ptbl[100], *pnum1, *pnum2;
    int no;

    pnum2 = str + strlen(str);
    no = 0;
    ptbl[no] = str;
    while(1){
        pnum1 = function(ptbl[no], pnum2);
        if (pnum1 == pnum2) break;
        no++;
        ptbl[no] = pnum1;
    }
    printf("%d\n",no);
    display(no+1, ptbl);
}

char *function(char *pnum1, char *pnum2)
{
    while((pnum1 < pnum2) && (*pnum1 !=' ')){
        pnum1++;
    }
    while((pnum1 < pnum2) && (*pnum1 == ' ')){
        *pnum1 = NULL;
        pnum1++;
    }
    return(pnum1);
}

void display(int num, char **str)
{
    int loop;

    for(loop = 0;loop < num;loop++){
        printf("%s\r\n",*str);
            str++;
    }
}
