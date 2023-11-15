#include <stdio.h>
#include <stdlib.h>


struct node {
	int st;
	struct node *link;
};

void findclosure(int, int);
void insert_trantbl(int, char, int);
int findalpha(char);
void findfinalstate(void);
void print_e_closure(int);
void unionclosure(int);

static int set[20], nostate, noalpha, s, notransition, nofinal, finalstate[20], r, buffer[20], start;
char alphabet[20], c;
static int e_closure[20][20] = {0};
struct node *transition[20][20] = {NULL};


int main(){
	int i,j,k,m,t,n;
	struct node *temp;

	printf("Enter the no of alphabets: ");
	scanf("%d", &noalpha);
	getchar();


	printf("Enter the alphabets: ");
	for (int i = 0; i < noalpha; i ++) {
		alphabet[i] = getchar();
		getchar();
	}


	printf("Enter the no.of states: ");
	scanf("%d", &nostate);
	printf("Enter the state state: ");
	scanf("%d", &start);
	printf("Enter the no.of final states: ");
	scanf("%d", &nofinal);
	printf("Enter the final states: ");

	for (int i = 0 ;i < nofinal; i ++) {
		scanf("%d", &finalstate[i]);	
	}
	
	printf("Enter the no of transitions: ");
	scanf("%d", &notransition);
	printf("Enter transitions: \n");
	for (int i = 0; i < notransition; i++){
		scanf("%d %c %d", &r, &c, &s);
		insert_trantbl(r, c ,s);
	}

	for (int i = 1; i <= nostate; i++){
		c = 0;
		for (int j = 0; j < 20; j++){
			buffer[j] = 0;
			e_closure[i][j] = 0;
		}

		findclosure(i, i);
	}

	printf("\n Equivalent NFA without epsilon\n");
	printf("---------------------------------\n");
	printf("Start state : ");

	print_e_closure(start);;
	printf("\nAlphabets:");
	for (int i = 0; i<noalpha; i++) {
		printf("%c ", alphabet[i]);
	}	
	printf("\nEpsilon closure of state:\n");

	for (int i = 1; i <= nostate; i++){
		printf("State q%d: ", i);
		print_e_closure(i);
		printf("\n");
	}


	printf("\nTransitions :=>\n");

	for (int i = 1; i <= nostate; i++) {
		for (int j = 0; j < noalpha -1 ; j++) {
			for (int m = 1; m <= nostate; m++) {
				set[m] = 0;
			}
			for (int k = 0; e_closure[i][k] != 0; k++){
				t = e_closure[i][k];
				temp = transition[t][j];
				while (temp != NULL) {
					unionclosure(temp->st);
					temp = temp->link;
				}
			}

			printf("{");
			print_e_closure(i);
			printf("}\t");
			printf("%c\t", alphabet[j]);
			printf("{");

			for (int n = 1; n <= nostate; n++){
				if(set[n] != 0){
					printf("q%d", n);
				}	
				if(set[n+1] != 0){
					printf(",");
				}	
				
			}
			printf("}\n");
		}
	}

	printf("\nFinal State: ");
	findfinalstate();
	printf("\n");
	return 0;
}


void findclosure(int x, int sta) {
	struct node *temp;
	int i;
	if(buffer[x])
		return;
	e_closure[sta][c++] = x;
	buffer[x] = 1;
	if(alphabet[noalpha - 1] == 'e' && transition[x][noalpha - 1] != NULL) {
		temp = transition[x][noalpha -1];
		while(temp != NULL) {
			findclosure(temp->st, sta);
			temp = temp -> link;
		}
	}
}

void insert_trantbl(int r, char c, int s) {
	int j; 
	struct node *temp;
	j = findalpha(c);
	if (j == 999) {
		printf("Error\n");
		exit(0);
	}
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> st = s;
	temp -> link = transition[r][j];
	transition[r][j] = temp;
}

int findalpha(char c) {
	int i;
	for (int i = 0; i < noalpha; i++)
		if(alphabet[i] == c)
			return i;
		

	
	return (999);
}


void unionclosure(int i) {
	int j = 0, k;
	while(e_closure[i][j] != 0) {
		k = e_closure[i][j];
		set[k] = i;
		j++;
	}
}


void findfinalstate() {
	int i,j,k,t;
	for (int i = 0; i < nofinal; i++) {
		for (int j = 1; j <= nostate; j++){
			for (int k = 0; e_closure[j][k] != 0; k++) {
				if(e_closure[j][k] == finalstate[i]) {
					print_e_closure(j);
				}
			}
		}
	}
}


void print_e_closure(int i) {
	int j;
	for (j = 0; e_closure[i][j] != 0; j++){
		printf("{");
		printf("q%d", e_closure[i][j]);
		printf("}");
	}
}

