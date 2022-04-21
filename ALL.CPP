#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define structure
typedef struct nodetype
{
	int info;
	struct nodetype* next;
}node;
//function prototype
void createemptylist(node **head );
void traverseinorder(node *head);
void insertatbeginning(node **head,int item);
void deleteafterelement(node **head);
void deletefrombegining(node **head);
void deletefromend(node **head);

void main()
{
	node *head;
	int choice,element,after,number;
	clrscr();
	createemptylist(&head);
	while(1)
	{
		printf("operations available are \n");
		printf("1. Insert at begining \n");
		printf("2. Traverse in order \n");
		printf("3. Delete from begining \n");
		printf("4. Delete from end \n");
		printf("5. Delete after element\n");
		printf("Enter choice 1, 2 ,3 ,4 or 5\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\nEnter element : ");
				scanf("%d",&element);
				insertatbeginning(&head,element);
				break;
			case 2:if(head==NULL)
				printf("\nList is empty");
				else
				traverseinorder(head);
				break;
			case 3:printf("\nEnter element : ");
				scanf("%d",&element);
				scanf("%d",&number);
				deletefrombegining(&head);
				break;
			case 4: printf("\nEnter element : ");
				scanf("%d",&element);
				deletefromend(&head);
				break;
			case 5: if(head==NULL)
				printf("\nList is empty");
				else
				deleteafterelement(head);
				printf("\Press any key to continue");
				getch();
				break;
			default:exit(0);
		}
	}
}
void createemptylist(node **head)
{
	*head=NULL;
}
void insertatbeginning(node **head,int item)
{
	node* ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	if(*head==NULL)
	ptr->next=NULL;
	else
	ptr->next=*head;
	*head=ptr;
}
void traverseinorder(node *head)
{
	while(head!=NULL)
	{
		printf("\n%d",head->info);
		head=head->next;
	}
}
void deletefrombegining(node **head)
{
     node* ptr;
	if(*head==NULL)
	return;
	else
	{
	ptr= *head;
	*head= *head->next;
	free(ptr);
	}
}
void deletefromend(node **head)
{
node ** ptr;
if(*head==NULL)
return;
else if((*head)->next==NULL)
{
ptr=*head;
*head=NULL;
free(ptr);
}
else
{
loc=*head;
ptr=(*head)->next;
while(ptr->next!=NULL)
{
loc=ptr;
ptr=ptr->next;
}
loc->next=NULL;
free(ptr);
}}
void deletefafterelement(node **head)
{
node * ptr;
if(*head==NULL)
return;
else{
ptr=loc->next;
loc->next=ptr->next;
free(ptr);
}
}

