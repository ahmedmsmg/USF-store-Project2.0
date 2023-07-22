/*** Name: Ahmed Ghoneim..
 * This program is an upgrdaed version to project 7 that uses qsort to sort depending on the percentage of population for who is 65 years old+
 * ***/


#include<stdio.h>
//maximum num of states
#define max 100
//maximum num of state char
#define max_char 150
#include<string.h>
#include<stdlib.h>

//structure for states
struct state {
	char name[max_char+1];
	int pop2020;
	int pop2010;
	double pop5;
	double pop18;
	double pop65;
};

//int compare to call comparator function
int compare(const void* p, const void* q);

int main() {

//array of structures
struct state a[max];
char name1[100];

printf("Input file name: ");
scanf("%s", name1);


//reading file from user's input
FILE *fp = fopen(name1, "r");
if(fp == NULL){
	printf("error");
	return 1;
}

int i= 0;
while(!feof(fp) && !ferror(fp)){
	fscanf(fp,"%[^,], %d, %d, %lf, %lf, %lf\n", a[i].name, &a[i].pop2020, &a[i].pop2010, &a[i].pop5, &a[i].pop18, &a[i].pop65 );
i++;
}

//closing file fp
fclose(fp);

//using library function to sort the states
qsort(a,i,sizeof(struct state),compare);


char str1[100];

strcpy(str1, "sorted_");
strcat(str1, name1);

//creatinng new file and writing the output
FILE *fw = fopen(str1, "w");
if(fw == NULL){
        printf("error");
        return 1;
}
int j;

for(j = 0; j<i ; j++)
{

	fprintf(fw, "%s, %d, %d, %.1lf, %.1lf, %.1lf\n", a[j].name, a[j].pop2020, a[j].pop2010, a[j].pop5, a[j].pop18, a[j].pop65 );

	
}
fclose(fw);

printf("Output file name: %s",str1);


return 0;
}

//sort states function that uses a nested 
//for loop to sort the array of structers

int compare(const void * p, const void * q) {
	double n1 = ((struct state *)p)->pop65;
	double n2 = ((struct state *)q)->pop65;
	
	if(n1<n2) return 1;
	else if(n1 == n2) return 0;
	else return -1;
}

/***void sort_states(struct state list[], int n)
{
	qsort(list,n,sizeof(state),compare);
}
***/
