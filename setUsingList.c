#include <stdio.h>
#include <stdlib.h>

//creation of sets using linked lists

typedef struct node_tag{
  int data ;
  struct node_tag * next ;
}node;

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
    
}

int main() 
{
    node ** set_pptr ;
    int count = 0;
    set_pptr = (node **)malloc(sizeof(node *)) ;
    
    int n ;
    printf("enter 1 to create list . 2 to see list .") ;
    char c;
    do
    {
        scanf("%d",&n) ;
        
        if(n == 1)
        {
            set_pptr[count] = createSet(set_pptr[count]) ;
            count++ ;
            set_pptr = (node **)realloc(set_pptr,count) ;
        }
        
        else if(n == 2)
        {
            printSet(set_pptr,count) ;
        }
    }
    while(n!=100) ;
    
    
	return 0;
}
