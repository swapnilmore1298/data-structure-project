/* Singly Linked List (Basic Operations) - Program to create a linked list abstract data type and perform various operations on it (Variable first declared globally) */
#include<string.h>
#include  <stdio.h>
#include <conio.h>
#include  <stdlib.h>
#define  NULL 0

struct  node
{
  char name[50];
  char tel[50];
  struct  node  *next ;
} ;

struct  node  *first=NULL ;

void  create()
{ FILE *fptr;
  int  i , n ;
  struct  node  *pnode , *p ;
  fptr = fopen("Record.csv","a+");
  printf("Enter the number of nodes required:\n") ;
  scanf("%d",&n) ;

  printf("Enter the data value of each node:\n") ;
  for(i=1 ; i<=n ; i++)
  {
    pnode=(struct node*)malloc(sizeof(struct node)) ;

    if(pnode==NULL)
    {
      printf("Memory overflow. Unable to create.\n") ;
      return ;
    }

    printf("Enter the name of the contact: ");
    scanf("%s",pnode->name);
    fprintf(fptr,"%s\t",pnode->name);
    printf("Enter the telephone no. of the contact: ");
    scanf("%s",pnode->tel);
    fprintf(fptr,",%s\n",pnode->tel);
    /* New node will be the last node */
    pnode->next=NULL ;

    if(first==NULL)
	 first=p=pnode ;
    else
    {
	    p->next=pnode ;
	    p=pnode ;   /* p keeps track of last node */
    }
  }
  fclose(fptr);
}

void  read()
{
   char buffer[1024] ;
   char *record,*line;
   int i=0,j=0,m=-1,n=0,ch;
   int mat[100][100];
   struct  node  *pnode , *p ;
   FILE *fstream = fopen("Record.csv","r");
   first = NULL;
   clrscr();

   if(fstream == NULL)
   {
      printf("\n file opening failed");
   }
   while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL)
   {
     record = strtok(line,",");
     while(record != NULL)
     {
	     pnode=(struct node*)malloc(sizeof(struct node)) ;
	    //here you can put the record into the array as per your requirement.
	    ++m;
	    if(m%2==0)
	   { strcpy(pnode->name,record);
	    printf("/* %s in %d(name)*/",pnode->name,pnode);
	   }
	    if(m%2!=0)
	   { strcpy(pnode->tel,record);
	    printf("/* %s in %d(tel)*/\n",pnode->tel,pnode);
	   }
	    mat[i][j++] = atoi(record) ;

	    record = strtok(NULL,",");
	       pnode->next=NULL ;

    if(first==NULL)
	 first=p=pnode ;
    else
    {
	    p->next=pnode ;
	    p=pnode ;   /* p keeps track of last node */
    }

   }
  ++i ;
  }
  pnode->next=NULL;
}

void  insertbegining(char n[],char t[])
{ int j;
  struct  node  *pnode , *p ;
  pnode=(struct node*)malloc(sizeof(struct node)) ;

  if(pnode==NULL)
  {
    printf("Memory overflow. Unable to create.\n") ;
    return ;
  }

  strcpy(pnode->name,n) ;
  strcpy(pnode->tel,t);

  pnode->next=first ;
  first=pnode ;
}

void  deletenode(char n[])
{
  struct  node  *p , *follow ;

  p=first ;
  follow=NULL ;
  while(p!=NULL)
  {
	if(strcmp(p->name,n)==0)
	  break ;
    follow=p ;
    p=p->next ;
  }

  if(p==NULL)
     printf("Required node not found.\n") ;
  else
  {
    if(p==first)   /* first node to be deleted */
      first=first->next ;
    else	   /* deleting any other node */
      follow->next=p->next ;

    free(p) ;  /* Memory De-allocation */
  }
}

void  search(char n[])
{
  struct  node  *p ;

  p=first ;
  while(p!=NULL)
  {
	if(strcpy(p->name,n)==0)
	  break ;
	p=p->next ;
  }

  if(p==NULL)
     printf("Required node not found.\n") ;
  else
    printf("Required node is present at address %X \n",p) ;
}

void  traverse()
{
  struct  node  *p ;
   if(first==NULL)
    printf("Linked List Empty") ;
  else
  {
    printf("Linked List is as shown: \n") ;

    p=first ;
    while(p!=NULL)
    {
      printf("<*>p->name is %s & p->tel is %s<*> ",p->name,p->tel) ;
      p=p->next ;
    }
    printf("\n") ;
  }
}

void count()
{
  int  n=0 ;
  struct  node  *p ;

  p=first ;
  while(p!=NULL)
  {
    n++ ;
    p=p->next ;
  }

  printf("Number of nodes in Linked List is %d \n",n) ;
}

void  destroylist()
{
  first=NULL ;
}

void  main()
{ FILE *fptr;
  char  n[50] , t[50] ;
  int ch ;
  clrscr() ;
  do
  { fptr = fopen("record.txt","a+");
    printf("\n Menu: \n") ;
    printf("0:Read data");
    printf("1:Create Linked List \n") ;
    printf("4:Insert Begining \n") ;
    printf("7:Delete Node \n") ;
    printf("8:Search Node \n") ;
    printf("9:Traverse \n") ;
    printf("10:Count \n") ;
    printf("12:Destroy List \n") ;
    printf("13:Exit \n") ;

    printf("\nEnter your choice: ") ;
    scanf("%d",&ch) ;

    switch(ch)
    {
      case 0:
      read();
      break;

      case 1:
      create() ;
      break ;

      case 4:
      printf("Enter the name of new contact: ") ;
      scanf("%s",n) ;
      fprintf(fptr,"%s\t",n);
      printf("Enter the telephone no of new contact:");
      scanf("%s",t);
      fprintf(fptr,"%s\n",t);
      insertbegining(n,t) ;
      break ;

      case 7:
      printf("Enter the name of the contact to be deleted: ") ;
      scanf("%s",n) ;
      deletenode(n) ;
      break ;

      case 8:
      printf("Enter the name of the contact to be searched: ") ;
      scanf("%s",n) ;
      search(n) ;
      break ;

      case 9:
      traverse() ;
      break ;

      case 10:
      count() ;
      break ;

      case 12:
      destroylist() ;
      break ;

      case 13:
      break ;
    }
  fclose(fptr);
  }
  while(ch!=13) ;

  getch() ;
}
