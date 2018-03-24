#include <stdio.h>
#include <stdlib.h>
//Estrutura utilizada para guadar os registros de evento
typedef struct event{
	long long date;
	long long ID;
	long long user;
}EVENT;


int main(int argc, char **argv){
	//Verifica se o usuario colocou pelo menos duas datas
	if(argc < 3){
		printf("Numero de argumentos insuficientes\n");
		return -1;
	}
	FILE *input = fopen("output.txt", "r");
	long long start_date = atoll(argv[1]);
	long long end_date = atoll(argv[2]);
	//Verifica se as datas de input desejadas estao em ordem crescente
	if(start_date>end_date){
		long long aux = start_date;
		start_date = end_date;
		end_date = aux;
	}
	//Verifica se o usuario já executou o programa armazenador
	if(input == NULL){
		printf("Erro na leitura de arquivo. Favor verificar se o programa armazenador ja foi executado.\n");
		return -1;
	}

	int data_size, i, j;
	fscanf(input,"%d", &data_size);
	EVENT *list = malloc(data_size*sizeof(EVENT));

	for(i=0;i<data_size;i++){
		fscanf(input,"%lli %llX %lli", &list[i].date, &list[i].ID, &list[i].user);
	}
	//Realiza busca binária para saber qual a posição da data inicial e final
	//no array e definir o intervalo de datas a serem impressas
	int start=0, end=data_size-1, mid=(start+end)/2;

	while(1){
		if(start == mid){
			if(list[start].date >= start_date){
				i=start;
				break;
			}
			else{
				i=start+1;
				break;
			}
		}
		else if(list[mid].date>=start_date){
			end=mid;
			mid=(start+end)/2;
		}
		else if(list[mid].date<start_date){
			start=mid;
			mid=(start+end)/2;	
		}
	}

	start=0, end=data_size-1, mid=(start+end)/2;

	while(1){
		if(start == mid){
			if(list[end].date <= end_date){
				j=end;
				break;
			}
			else{
				j=end-1;
				break;
			}
		}
		else if(list[mid].date<=end_date){
			start=mid;
			mid=(start+end)/2;
		}
		else if(list[mid].date>end_date){
			end=mid;
			mid=(start+end)/2;	
		}
	}
	//Verifica se foi dado algum tag de identificação para as datas a serem impressas
	if(argc>3){
		int tags;
			if(i>j){
				printf("Nenhum registro encontrado\n");
			}
			else{
				for(;i<=j;i++){
					for(tags=3;tags<argc;tags++){
						if(list[i].ID == strtoll(argv[tags], NULL, 16)){
							printf("%lli;%.8llX;%lli\n", list[i].date, list[i].ID, list[i].user);
						}
					}
				}
			}
	}
	else{
		if(i>j){
			printf("Nenhum registro encontrado\n");
		}
		else{
			for(;i<=j;i++){
				printf("%lli;%.8llX;%lli\n", list[i].date, list[i].ID, list[i].user);
			}
		}
	}

	fclose(input);
	free(list);
	return 0;
}