#include <stdio.h>
#include <stdlib.h>

//creation of sets using linked lists

typedef struct node_tag{
  int data ;
  struct node_tag * next ;
}node;


//TYPICAL SET OPERATIONS
//1.

int is_element_of(int e,node ** s)
{
	//node * nptr = s ;
	int si;
	printf("Enter the set index for searching : ") ;
        scanf("%d",&si) ;
	while(s[si] != NULL)
	{
		if(s[si]->data == e)
		return 1 ;
		s[si] = s[si]->next ;
	}
	
	return 0 ;
}

int is_empty(node ** s,int e)
{
	
	//Returns 1 if empty else 0
	//int si;
	//printf("Enter the set index for searching : ") ;
        //scanf("%d",&si) ;
	
	if(s[e] == NULL)
	return 1 ;
	else
	return 0 ;
}

int size(node ** s,int e)
{
    //node * nptr = s ;
	int count = 0 ;
	while(s[e] != NULL)
	{
		count++ ;
		s[e] = s[e]->next ;
	}
	
	return count ;
}




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
    //c++;
    printf("Do you want to print more sets : (1/0)\n") ;
    scanf("%d",&p) ;
    
    if(p == 1)
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
    int e,si;
        printf("For Typical Operations:\n Type 1 for is_element_of \nType 2 for is_empty \nType 3 for size\nType 4 for printing any list\nType 5 for set creation\n");
        
        printf("For Other Operations:\nType 6 for add if not already present \nType 7 for remove any element from list \n");
        
        printf("For Operations on 2 sets:\nType 8 for union of 2 sets \nType 9 for intersection of 2 sets \nType 10 for difference between 2 sets\nType 11 for whether checking set A is subset of set \nType 12 for set creation\n");
   
    do
    {     
        scanf("%d",&n) ;
        if(n == 1)
        {
            printf("Enter the element you want to check : \n") ;
            scanf("%d",&e) ;
            //printf("Enter the set index for searching : ") ;
            //scanf("%d",&si) ;
            if(is_element_of(e,set_pptr) == 1)
            {
                printf("Element %d exists in set index %d\n",e,si);
            }
            else
            printf("Does not exist ! \n") ;
        }
        else if(n == 2)
        {
            printf("Enter the index of the set less than or equal to the number of sets : \n") ;
            scanf("%d",&e) ;
            if(e<=count)
            {
                if(is_empty(set_pptr,e) == 1) 
                {
                    printf("Empty\n") ; 
                }
                else 
                {
                    printf("Not Empty\n") ;
                }
            }
            else
            {
                printf("Enter within range !") ;
            }
        }
        else if (n == 3)
        {
            printf("Enter the index of set : \n") ;
            scanf("%d",&e) ;
            
            printf("Size of set index %d is %d",e,size(set_pptr,e)) ;
        }
        else if(n == 4)
        {
            printSet(set_pptr,count) ;
        }
        else if(n == 5)
        {
            set_pptr[count] = createSet(set_pptr[count]) ;
            count++ ;
            set_pptr = (node **)realloc(set_pptr,count+1) ;
        }
        else if(n == 6)
	    {
            printf("Enter set index to which you want to add an element : \n") ;
            scanf("%d",&ai) ;
            
            set_pptr[ai] = createNode(set_pptr[ai]) ;
	    }   
        
        
    }
    while(n!=100) ;
    
    
	return 0;
}
