#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char *c);
void swap(char *c,char *s);

int main(void){
    unsigned int a,b,*res;
    int i,tc,j;
    char ch[12];
    scanf("%d",&tc);
    res=(unsigned int *)malloc(sizeof(unsigned int)*tc);
    for(i=0;i<tc;i++){
        scanf("%u%u",&a,&b);
        sprintf(ch,"%u",a);
        reverse(ch);
        sscanf(ch,"%u",&a);
        sprintf(ch,"%u",b);
        reverse(ch);
        sscanf(ch,"%u",&b);
        a+=b;
        sprintf(ch,"%u",a);
        reverse(ch);
        j=strlen(ch)-1;
        while(ch[j]==0)
            j--;
        ch[j+1]='\0';
        sscanf(ch,"%u",&*(res+i));
    }
    for(i=0;i<tc;i++)
        printf("%u\n",*(res+i));
    getchar();
    return 0;
}

void reverse(char *c){
    int l=strlen(c),i=0,j=l-1;
    while(i<=j)
        swap(c+i++,c+j--);
}

void swap(char *c,char *s){
    char temp=*c;
    *c=*s;
    *s=temp;
}
