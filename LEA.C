#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LISTA.H"
#include"LEA.H"

LIS_tppLista lea;


typedef struct mem{
	void * address;
	char * nome;
	int size;
}Memory;


void CriaLea();


void imprimeEsp(Memory * f)
{
	if(f->nome != NULL)
		printf("entrou %s  :  %d bytes\n", f->nome, f->size);
	else
		printf("entrou %p  :  %d bytes\n", f->address, f->size);
	
}

void * AlocaLea(int tamanho)
{
	Memory * f = (Memory*)malloc(sizeof(Memory));
	void * p;
	
	if(lea == NULL)
		CriaLea();

	
	p = malloc(tamanho);

	
	f->address = p;
	f->size = tamanho;
	f->nome = NULL;
	IrFinalLista(lea);
	
	;
	LIS_InserirElementoApos(lea, f);

	return p;
}

void * AlocaLeaTag(int tamanho, char * nome)
{
	
	Memory * f = (Memory*)malloc(sizeof(Memory));
	void * p;

	

	if(lea == NULL)
		CriaLea();

	p = malloc(tamanho);

	f->address = p;
	f->size = tamanho;
	f->nome = nome;
	IrFinalLista(lea);
	
	LIS_InserirElementoApos(lea, f);

	return p;
}

void excluirNo(void * p){
	free(p);
}


void ImprimeLea()
{
	Memory * fat;
	IrInicioLista(lea);
	do
	{
		fat = (Memory*) LIS_ObterValor(lea);
		imprimeEsp(fat);
	} while(LIS_AvancarElementoCorrente(lea,1) != LIS_CondRetFimLista);
}

void CriaLea()
{
	lea = LIS_CriarLista(excluirNo);
}

void FreeLea(void * p)
{
	Memory * fat;
	IrInicioLista(lea);
	do
	{
		fat = (Memory*) LIS_ObterValor(lea);
		if(fat->address == p){
			LIS_ExcluirElemento(lea);
			free(p);
			return;
		}

	} while(LIS_AvancarElementoCorrente(lea,1) != LIS_CondRetFimLista);
	printf("Endere�o nao existe ou ja foi liberado.\n");
}


//int main()
//{
//	int * i;
//	char * abc;
//	float * ff;
//	
//	CriaLea();
//
//	i = (int*)AlocaLea(2*sizeof(int));
//	abc = (char*)AlocaLea(sizeof(char));
//	ff = (float*)AlocaLea(sizeof(float));
//
//	FreeLea(i);
//	FreeLea(i);
//
//	ImprimeLea(lea);
//
//	return 0;
//}