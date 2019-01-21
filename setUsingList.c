#include <stdio.h>
#include <stdlib.h>

//creation of sets using linked lists

typedef struct node_tag{
  int data ;
  struct node_tag * next ;
}node;


//TYPICAL SET OPERATIONS
//1.
/*
int is_element_of(int x,node * s)
{
	node * nptr = s->start ;
	while(nptr != NULL)
	{
		if(nptr->data == x)
		return 1 ;
		nptr = nptr->next ;
	}
	
	return 0 ;
}

int is_empty(node * s)
{
	
	//Returns 1 if empty else 0
	
	if(s->start == NULL)
	return 1 ;

	return 0 ;
}

int size(node * s)
{
	int count = 0 ;
	while(s->start != NULL)
	{
		count++ ;	
	}
	
	return count ;
}
*/



node * createNode(node * list_ptr)
{
	node * nptr = (node *)malloc(sizeof(node)) , * ptr ;
	
	ptr = list_ptr ;
	
	printf("Enter data : ") ;
	scanf("%d" , &nptr->data) ;
	
	
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


node * createSet(node * nptr)
{
    int c ;
    printf("Do you want to create an empty set ?(1/0)\n") ;
    scanf("%d",&c) ;
    
    if(c == 1)
    {
        nptr = NULL ;
    }
    else if(c == 0)
    {
        int num,i ;
        printf("Enter number of elements to be entered in set : \n") ;
        scanf("%d",&num) ;
        
        for(i=0;i<num;i++)
        {
            nptr = createNode(nptr) ;
        }
    }
    
    return nptr ;
}

void printSet(node ** set_pptr,int count)
{
    int si,c = 0,p;

    re :
    printf("Enter set index to be printed : \n") ;
    scanf("%d",&si) ;
    
    while(set_pptr[si] != NULL)
    {
        printf("%d ",set_pptr[si]->data) ;
        set_pptr[si] = set_pptr[si]->next ;
    }
    c++;
    printf("Do you want to print more sets : (1/0)\n") ;
    scanf("%d",&p) ;
    
    if(p == 1 && c<=count)
    goto re ;
    else
    printf("Sorry cannot print . ") ;
    
}

int main() 
{
    node ** set_pptr ;
    int count = 0;
    set_pptr = (node **)malloc(sizeof(node *)) ;
    
    int n , ai;
    printf("enter 1 to create list . 3 to see list .") ;
    char c;
    do
    {
        printf("For Typical Operations:\n
        Type 1 for is_element_of \n
        Type 2 for is_empty \n
        Type 3 for size\n
        Type 4 for printing any list\n
        Type 5 for set creation\n");
        
        printf("For Other Operations:\n
        Type 6 for add if not already present \n
        Type 7 for remove any element from list \n
        
        printf("For Operations on 2 sets:\n
        Type 8 for union of 2 sets \n
        Type 9 for intersection of 2 sets \n
        Type 10 for difference between 2 sets\n
        Type 11 for whether checking set A is subset of set B\n
        Type 12 for set creation\n");
        
        scanf("%d",&n) ;
        
        
        
        if(n == 1)
        {
            set_pptr[count] = createSet(set_pptr[count]) ;
            count++ ;
            set_pptr = (node **)realloc(set_pptr,count) ;
        }

    	if(n == 2)
	    {
            printf("Enter set index to which you want to add an element : \n") ;
            scanf("%d",&ai) ;
            
            set_pptr[ai] = createNode(set_pptr[ai]) ;
	    }   
        
        else if(n == 3)
        {
            printSet(set_pptr,count) ;
        }
    }
    while(n!=100) ;
    
    
	return 0;
}
