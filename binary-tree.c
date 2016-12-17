/*Napisati program koji iz datoteke čita podatke o broju bodova koje je jedan student dobio na ispitu
(struct _student{char ime[128];char prezime[128];int broj_bodova; int relativni_broj_bodova;struct
_student *left; ;struct _student right;}) i sprema ih u binarno stablo pretraživanja. (Napomena : 0 <
broj_bodova <= 100). Ispisati binarno stablo na „inorder“ način.
U tako kreiranom binarnom stablu potrebno je za svakog od studenata izračunati i relativan broj bodova
po formuli: relativan_broj_bodova=( broj_bodova / MAX(broj_bodova) ). Ispisati binarno stablo na
„preorder“ način. */



#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct _student* Position;
typedef struct _student{
	char ime[128];
	char prezime[128];
	int broj_bodova;
	float relativni_broj_bodova;
	Position left;
	Position right;
}Student;

Position ReadFromFile(char*);
Position Insert(Position,char*,char*,int);
Position CreateNode(char*,char*,int);
void MaxBroj(Position,int*);
void PrintInOrder(Position);
void PrintPostOrder(Position);
void InsertRel(Position,int);

int main(void)
{
  Position root;
  root=NULL;
  int max=0;
  char fileName[50];
  printf("Unesite ime filea:");
  scanf("%s",fileName);
  root= ReadFromFile(fileName);

  printf("Print prije rel broja:\n");
  PrintInOrder(root);

  printf("Maksimalni broj je:");
  MaxBroj(root,&max);
  InsertRel(root,max);

  printf("Print posli rel broja:\n");
  PrintPostOrder(root);
}
Position ReadFromFile(char* fileName)
{
  FILE* fp;
  Position p=NULL;
  char ime[124],prezime[124];
  int broj_bd;
  fp=fopen(fileName,"r");
  if(fp==NULL)
  {
    printf("Greska u otvaranju!\n");
	return NULL;
  }
  while(!feof(fp))
  {
	  fscanf(fp,"%s %s %d",ime,prezime,&broj_bd);
	  p=Insert(p,ime,prezime,broj_bd);
  }
  fclose(fp);
  return p;
}

Position Insert(Position p, char* ime, char* prezime, int br_bd)
{
  if(p==NULL)
	  p=CreateNode(ime,prezime,br_bd);
  else if(p->broj_bodova < br_bd)
	  p->right=Insert(p->right,ime,prezime,br_bd);
  else if(p->broj_bodova > br_bd)
	  p->left=Insert(p->left,ime,prezime,br_bd);
  else
	  printf("Nije moguce unit!");
  return p;
}

Position CreateNode(char* ime, char* prezime, int br_bd)
{
  Position q=(Position)malloc(sizeof(Student));
  strcpy(q->ime,ime);
  strcpy(q->prezime,prezime);
  q->broj_bodova=br_bd;
  q->relativni_broj_bodova=0;
  q->left=NULL;
  q->right=NULL;

  return q;
}

void MaxBroj(Position p, int* max)
{
  if(p==NULL)
	  return;
  else 
  {
	  MaxBroj(p->right,max);
	  *max=p->broj_bodova;
  }
  printf("%d",*max);
}

void InsertRel(Position p,int max)
{
  if(p==NULL)
	  return;
  else
  {
	  InsertRel(p->left,max);
	  p->relativni_broj_bodova=(float)p->broj_bodova/max;
	  InsertRel(p->right,max);
  }
}

void PrintInOrder(Position p)
{
	if(p==NULL)
          return;
	else
	{
	  PrintInOrder(p->left);
	  printf("%s %s %d %f\n",p->ime,p->prezime,p->broj_bodova,p->relativni_broj_bodova);
	  PrintInOrder(p->right);
	}
}

void PrintPostOrder(Position p)
{
	if(p==NULL)
		return;
	else
	{
	  PrintPostOrder(p->left);
	  PrintPostOrder(p->right);
	  printf("%s %s %d %f\n",p->ime,p->prezime,p->broj_bodova,p->relativni_broj_bodova);
	}
}