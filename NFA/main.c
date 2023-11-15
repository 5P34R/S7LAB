#include <stdio.h>
#include <string.h>

char result[20][20], copy[3], states[20][20];


void add_state(char a[10], int i){
	strcpy(result[i], a);
}



void display(int n) {
	int k = 0; 
	printf("\n Epsilon closure of %s = {", copy);
	while (k < n) {
		printf(" %s ", result[k]);
		k++;
	}
	printf("} \n");
}



int main()
{
	FILE *INPUT;

	INPUT  = fopen("input.dat", "r");
	char state[10], state1[10], state2[10], input[10];
	int end, n, k = 0, i = 0;

	printf("Enter the number of states:");
	scanf("%d", &n);

	printf("Enter the states :");

	for (k = 0; k < n; k ++) {
		scanf("%s", states[k]);
	}


	for (k = 0; k < n; k ++){

		i = 0;
		strcpy(state, states[k]);
		strcpy(copy, state);
		add_state(state, i++);

		while (1) {
			end = fscanf(INPUT, "%s%s%s", state1, input, state2);
			if(end == EOF) {
				break;
			}

			if (strcmp(state, state1) == 0) {
				if(strcmp(input, "e") == 0) {
					add_state(state2, i++);
					strcpy(state, state2);
				}
			}
		}

		display(i);
		rewind(INPUT);

	}

	return 0;
}
