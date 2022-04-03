#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
  char n[100];
  struct node *next;
}*ptr,*newnode,*start = NULL,*preptr;
struct node *create(struct node*);
struct node *insertbeg(struct node*);
struct node *delword(struct node *);
struct node *deletebeg(struct node*);
void search(struct node*);
void display(struct node*);
void main()
{
  int i;
  while(1)
    {
      printf("press 1 for create\n");
      printf("press 2 for insertbeg\n");
      printf("press 3 for deletebeg\n");
      printf("press 4 for delword\n");
      printf("press 5 for search\n");
      printf("press 6 for display\n");
      printf("enter ur choice\n");
      scanf("%d",&i);
  switch(i)
    {
    case 1:start=create(start);
       break;
    case 2:start=insertbeg(start);
       break;
    case 3:start=deletebeg(start);
        break;
    case 4:start=delword(start);
        break;
    case 5:search(start);
        break;
    case 6:display(start);
        break;
    default:exit(0);
    }
}
}
struct node *create(struct node *start)
{
  char s[100];
  printf("Enter word: ");
  scanf("%s",s);
  newnode=(struct node*)malloc(sizeof(struct node));
  strcpy(newnode->n,s);
  if (start==NULL)
    {
      start=newnode;
      newnode->next=NULL;
    }
  else
    {
      ptr=start;
      while(ptr->next!= NULL)
    {
      ptr=ptr->next;
    }
      ptr->next = newnode;
      newnode->next = NULL;
    }
  return start;
}
struct node *insertbeg(struct node *start)
{
  char s[100];
  printf("Enter word: ");
  scanf("%s",s);
  newnode=(struct node*)malloc(sizeof (struct node));
  strcpy(newnode->n,s);
  newnode->next=start;
  start=newnode;
  return start;
}
struct node *deletebeg(struct node *start)
{
  ptr=start;
  start=start->next;
  free(ptr);
  return start;
}
struct node *delword(struct node *start)
{
    char x[100];
    scanf("%s",x);
    ptr=start;
    while(strcmp(ptr->n,x)!=0)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    return start;
}
void display(struct node *start)
{
  ptr=start;
  while(ptr!=NULL)
    {
      printf("%s\n",ptr->n);
      ptr=ptr->next;
    }
}
void search(struct node *start)
{
  int count=0;
  printf("enter word to be searched:");
  char x[100];
  scanf("%s",x);
  ptr=start;
  while(ptr!=NULL)
    {
      if(strcmp(ptr->n,x)==0)
    {
        count++;
        break;
    }
         ptr=ptr->next;
    }
    if(count!=0)
    {
        printf("word found");
    }
    else
    {
        printf("word is not available");
    }
}
