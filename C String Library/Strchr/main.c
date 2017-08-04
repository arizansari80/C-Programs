#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define endl printf("\n")

int main(int argc,char **argv){
	char ch[30]="Jamia Millia Islamia";
	char *ch1;
	ch1=strstr(ch,"mia");
	if(ch1==NULL)
		return 0;
	int l=ch1-ch+1;
	printf("%d\n",l);
	return 0;
}