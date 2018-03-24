#include <stdio.h>
#include <stdlib.h>
//Estrutura utilizada para guadar os registros de evento
typedef struct event{
	long long date;
	long long ID;
	long long user;
}EVENT;

int compare(const void *a, const void *b);

int main(int argc, char **argv){
	//Abertura e tratamento de erro de arquivos
	FILE *input = fopen(argv[1], "r");
	FILE *output = fopen("output.txt", "w");
	if(input == NULL || output == NULL){
		printf("Erro na abertura do arquivo. Favor verificar o arquivo de input\n");
		return -1;
	}
	
	int data_size = 1, alloc_size = 4, i;
	char temp;
	EVENT *list = malloc(alloc_size * sizeof(EVENT));

	//Aquisição dos dados do arquivo de input
	while(1){
		fscanf(input,"%lli",&list[data_size-1].date);
		temp = fgetc(input);
		fscanf(input,"%llX",&list[data_size-1].ID);
		temp = fgetc(input);
		fscanf(input,"%lli",&list[data_size-1].user);
		temp = fgetc(input);

		if(feof(input)){
			break;
		}
		data_size++;
		if(data_size>alloc_size){
			alloc_size *=2;
			list = realloc(list, alloc_size * sizeof(EVENT));
		}
	}
	data_size--;
	list = realloc(list, data_size * sizeof(EVENT));
	//Ordenação e armazenamento dos dados ordenados por data em um arquivo de output
	qsort(list, data_size, sizeof(EVENT), compare);

	fprintf(output, "%d\n", data_size);

	for(i=0;i<data_size;i++){
		fprintf(output, "%lli %.8llX %lli\n", list[i].date, list[i].ID, list[i].user);
	}

	fclose(input);
	fclose(output);
	free(list);
	return 0;
}


int compare(const void *a, const void *b){
	EVENT *eventA = (EVENT *)a;
	EVENT *eventB = (EVENT *)b;

	if(eventA->date-eventB->date < 0){
		return -1;
	}
	if(eventA->date-eventB->date > 0){
		return 1;
	}
	return 0;
}