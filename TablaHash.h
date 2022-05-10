/*
Implement with array using linear probing
	hash(k, m) - m is size of hash table
	add(key, value) - if key already exists, update value
	exists(key)
	get(key)
	remove(key)
*/
///////////////////////////////////////////////////////BIBLIOTECAS///////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/////////////////////////////////////////////////////////DEFINES/////////////////////////////////////////////////////////
#define DEFAULT_TABLE_SIZE	10
#define SMALL_PRIME_NUM		103
#define MEDIUM_PRIME_NUM	100003
#define BIG_PRIME_NUM		1000000003
////////////////////////////////////////////////////////VARIABLES////////////////////////////////////////////////////////

///////////////////////////////////////////////////////ESTRUCTURAS///////////////////////////////////////////////////////
typedef struct
{
	int *arr;
	int m;
}HashTable;
/////////////////////////////////////////////////PROTOTIPOS DE FUNCIONES/////////////////////////////////////////////////
unsigned int hash(char* /*key*/);
void add(HashTable*, char* /*key*/,int /*value*/);
bool exists(HashTable*, char* /*key*/);
int get(HashTable*, char* /*key*/);
void remove(HashTable*, char* /*key*/);

//AUX FUNC.
void initHashTable(HashTable*);
void finishHashTable(HashTable*);
void printTable(HashTable *);
////////////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////
//AUX FUNC.
void initHashTable(HashTable *ht, int m){
	ht->arr = (int*)calloc(sizeof(int),m);
	ht->m = m;
}

void finishHashTable(HashTable *ht){
	free(ht->arr);
	ht->m = 0;
}

void printTable(HashTable *ht){
	printf("----------------------INICIO TABLA HASH----------------------\n");
	for (int i = 0; i < ht->m; ++i){
		printf("%d.\t%d\n",i+1, *(ht->arr + i));
	}
	printf("------------------------FIN TABLA HASH-----------------------\n");
}

//CONSIGNA
unsigned int hash(HashTable *ht, char *key){
	int length = strlen(key);
	unsigned int hash = 0;

	for (int i = 0; i < length; i++){
		hash += *(key + i) * *key;
		hash *= SMALL_PRIME_NUM;
	}

	hash %= ht->m;

	return hash;
}

void add(HashTable *ht, char *key, int value){
	*(ht->arr + hash(ht,key)) = value;
}

bool exists(HashTable *ht, char *key){
	return 0;
}

int get(HashTable *ht, char *key){
	return 0;
}

void remove(HashTable *ht, char *key){
	
}
///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////