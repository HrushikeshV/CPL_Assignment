#include<stdio.h>
#include<stdlib.h>

typedef struct node_tag {
	int data ;
	struct node_tag * next ;
}node;

typedef struct set_wrap {
	node * start ;
}set;

node * DeleteFromStart(node * list_ptr)
{
	node * nptr ;
	
	nptr = list_ptr ;
	list_ptr = list_ptr->next ;
	
	free(nptr) ;
	
	return list_ptr ;
}

node * DeleteFromEnd(node * list_ptr)
{
	//node * nptr = (node *)malloc(sizeof(node)) ;
	node *ptr1 , *ptr2 ;
	
	ptr1 = list_ptr ;
	ptr2 = list_ptr ;
	
	if(ptr1->next == NULL)
	{
		list_ptr = NULL ;
		free(ptr1) ;
	}
	else
	{
		while(ptr1->next != NULL)
		{
			ptr1 = ptr1->next ;
			 if(ptr1->next != NULL)
			 {
	 			ptr2 = ptr2->next ;
			 }	
		}
		
		ptr2->next = NULL ;
		free(ptr1) ;
	}
	

	return list_ptr ;	
}

void DeleteList(node *list_ptr )
{
	int option ;
	printf("Press 1 to delete from start and 0 to delete from end : ") ;
	scanf("%d", &option) ;
	
	/*int num , i;
	printf("Enter no. of elements to be deleted : ") ;
	scanf("%d" , &num) ;*/
	
		if(list_ptr != NULL)
		{
			if(option)
			{
	
				list_ptr = DeleteFromStart(list_ptr) ;
			}
			else
			{
				list_ptr = DeleteFromEnd(list_ptr) ;
		
			}
		}

}












node * createNewNode(node * list_ptr , int n) 
{
	node * nptr = (node *)malloc(sizeof(node)) , * ptr ;
	
	ptr = list_ptr ;
	
	nptr->data = n ;
	
	if(list_ptr == NULL)
	{
		list_ptr = nptr ;
		list_ptr->next = NULL;
		
		return list_ptr ;
	}
	else
	{
		
		while(ptr->next  != NULL)
		ptr = ptr->next ;
	
		ptr->next = nptr ;
		nptr->next = NULL ;
	}
	
	return list_ptr;
}

int check(node * nptr , int temp)
{
	while(nptr != NULL)
	{
		if(nptr->data == temp)
		return 0;
		
		nptr = nptr->next ;
	}
	
	return 1;
}

set * createNewSet(set * s , int * sc)
{
	*sc = 1 ;
	int act_no = 0 , num , i,temp;
	printf("Enter number of elements to be entered in a set : ") ;	
	scanf("%d",&num) ;
	
	start :
	for(i=0;i<num;i++)
	{
		printf("Enter Data : ") ;
		scanf("%d",&temp) ;
		
		if(check(s->start,temp) == 1) //returns 1 if number is NOT duplicate
		{
			s->start = createNewNode(s->start,temp) ;
		}
		else
		{
			int c ;	
			printf("you have entered a duplicate number .\nIt will not feature in your set and\n the size of your set will be reduced .\nTo prevent it start over by typing 1") ;
			scanf("%d",&c) ;
			
			if(c == 1)
			{
				while(s->start != NULL)
				{
					s->start = DeleteFromStart(s->start) ;
				}
				goto start ; 
			}
		}
	}
	
}

void printLists(set ** s_pptr, int count)
{
	int temp ,all,i,c=0 ;

	printf("Do you want to print all the sets ?(1/0)") ;
	scanf("%d",&all) ;

	if(!all)
	{
		rerun :
		printf("Enter set number you want to print .\n") ;
		scanf("%d",&temp) ;
		
		if(temp<count)
		{
			while(s_pptr[temp]->start != NULL)
			{
				printf("%d ",s_pptr[temp]->start->data) ;
				s_pptr[temp]->start = s_pptr[temp]->start->next ;
			}
		}
		else
		{
			printf("Wrong Index\n") ;
		}
		int again ;
		printf("Enter 1 to print another set and 2 to skip printing .\n") ;
		scanf("%d",&again) ;
		c++ ;
		if(again == 1&&c<=count)
		goto rerun;
	}
	else 
	{
		for(i=0;i<count;i++)
		{
			while(s_pptr[temp]->start != NULL)
			{
				printf("%d ",s_pptr[temp]->start->data) ;
				s_pptr[temp]->start = s_pptr[temp]->start->next ;
			}
			printf("\n") ;
		}
	}
	
}

int main()
{
	int n,i,sc ;

	set **s_pptr = (set **)malloc(sizeof(set *)); 
	int count = 1 ;
	
	printf("CPL Assignment :\nType 1 to create new set\nType 2 to print any number of sets\nType 100 to exit") ;
	do
	{
		scanf("%d",&n) ;
		
		if(n == 1)
		{
			*s_pptr = createNewSet(*s_pptr,&sc) ;
			count ++ ;
			s_pptr = (set **)realloc(s_pptr,sizeof(set *)*count) ;
		}
		
		if(n == 2)
		{
			printLists(s_pptr,count) ;
		}
		
	}while(n!=100) ;
	return 0 ;
}
