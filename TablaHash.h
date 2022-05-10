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
void addToTable(HashTable*, char* /*key*/,int /*value*/);
bool existsInTable(HashTable*, char* /*key*/);
int getFromTable(HashTable*, char* /*key*/);
void removeFromTable(HashTable*, char* /*key*/);

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

void addToTable(HashTable *ht, char *key, int value){
	*(ht->arr + hash(ht,key)) = value;
}

bool existsInTable(HashTable *ht, char *key){
	return *(ht->arr + hash(ht,key));
}

int getFromTable(HashTable *ht, char *key){
	return 0;
}

void removeFromTable(HashTable *ht, char *key){
	
}
///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////