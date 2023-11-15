#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

	char choice, isExit, str[10];

	int s,n, finalState, len, idx, q, b=0, nxt;

	int state[10], input[10], transition[20];

	printf("Enter the no of states: ");
	scanf("%d", &s);

	printf("Enter the no of inputs: ");
	scanf("%d", &n);
	

	for (int i=0; i<s; i++){
		printf("Enter the state: \n");
		scanf("%d", &state[i]);

		printf("Is it final state?(Y/n): \n");
		getchar();
		scanf("%c", &choice);

		if (choice == 'Y' || choice == 'y') {
			finalState = state[i];
		}else {
			continue;
		}

	}


	printf("Enter the inputs: \n");
	for (int i = 0; i< n; i++) {
		scanf("%d", &input[i]);
	}


	printf("printing state");
	for (int i =0 ;i < s; i++) {
		printf("%d ", state[i]);
	}


	printf("printing  input");
	for (int i =0 ;i < n; i++) {
		printf("%d ", input[i]);
	}

	printf("Transition state:\n");

	int k = 0;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < n; j++) {

			printf("Q(%d, %d)", state[i], input[j]);
			getchar();
			scanf("%d", &b);
			transition[k] = b;
			k++;
		}
	}
       
	do {

		printf("Enter the length of string \n");
		scanf("%d",&len);
		printf("Enter the input string \n");

		for (int i=0; i <len; i++){
			scanf("%d", &str[i]);
		}

		for (int i =0; i<len; i++) {
			idx = 0;

			do {
				if (str[i] == input[idx]) {
					nxt = transition[n*q+idx];
					for (int j = 0; j < s; j++) {
						if (nxt == state[j]) {
							q = j;
						}
					}
					idx++;
				}

				else 
					idx++;
				
			}while(idx!=n);
		}
		if (nxt == finalState)
			printf("String is accepted\n");
		else
			printf("Not accepted \n");

	printf("\n\nDo you want to continue?(Y/n)\n");
	getchar();
	scanf("%c", &isExit);
	}while (isExit != 'Y' || isExit != 'y');
}

