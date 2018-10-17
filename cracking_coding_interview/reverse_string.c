#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char * input){
	char * p = input;
	int ll = 0;
	while(*p!='\0'){
		p++;
		ll++;
	}
	p--;
	ll--;
	char * p1 = input;
	printf("%d\n",ll/2);
	for(int k=0; k<=ll/2; k++){
		char temp = *p;
		*p = *p1;
		*p1 = temp;
		p1++;
		p--;
	}

	char * test = input;
	while(*test!='\0'){
		printf("%c\n",*test);
		test++;
	}
}

int main(int argc, char* argv[]){
	char input[] = "Manane";
	reverse(input);
	return 0;
}
