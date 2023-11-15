#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


char a[20][20], f[20];
int n, m;


void follow(char c);
void first(char c);

int main(int argc, char const *argv[])
{
	int z;
	char c,ch;
	printf("Enter the number of produtions: \n");
	scanf("%d", &n);
	printf("Enter the procutions: \n");
	for (int i =0; i < n; i ++) {
		scanf("%s%c", a[i], &ch);
	}

	
	do  {
		m = 0;
		printf("First and follow \n");
	scanf("%c", &c);
		first(c);
		printf("first(%c) = {", c);
		for (int i = 0; i < n; i++) {
			printf("%c", f[i]);
			printf("}\n");
			strcpy(f, " ");
			m = 0;
			follow(c);
			printf("follow(%c) = {", c);
			for (int i = 0; i < m; i ++) {
				printf("%c", f[i]);
				
			}
			printf("}\n");
			printf("continue(0/1)?");
			scanf("%d%c", &z, &ch);
		} 
	}while (z == 1);

}

void first (char c) {
	int k;

	if (!isupper(c))
		f[m++] = c;

	for ( k = 0; k < n; k ++) {
		if (a[k][0] == c){
			if (a[k][0] == '$')
				follow(a[k][0]);
			else if (islower(a[k][2]))
				f[m++] = a[k][2];
			else
				first(a[k][2]);
		}
	}
}

void follow(char c){
	if ( a[0][0] == c )
		f[m++] = '$';
	for (int i = 0; i < n; i++) {
		for(int j = 2; j < strlen(a[i]); j++){

			if (a[i][j] == c) {
				if (a[i][j+1]!='\0')
					first(a[i][j+1]);
				if(a[i][j+1] == '\0' && c!=a[i][0])
					follow(a[i][0]);
			}
		}
	}
}