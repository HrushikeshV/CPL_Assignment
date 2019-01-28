#include <stdio.h>
#include <stdlib.h>

//creation of sets using linked lists

typedef struct node_tag{
  int data ;
  struct node_tag * next ;
}node;


//TYPICAL SET OPERATIONS
//1.

int is_element_of(int e,node * s)
{
	//node * nptr = s ;
	
	while(s != NULL)
	{
		if(s->data == e)
		return 1 ;
		s = s->next ;
	}
	
	return 0 ;
}

int is_empty(node * s)
{
	
	//Returns 1 if empty else 0
	//int si;
	//printf("Enter the set index for searching : ") ;
        //scanf("%d",&si) ;
	
	if(s == NULL)
	return 1 ;
	else
	return 0 ;
}

int size(node * s)
{
    //node * nptr = s ;
	int count = 0 ;
	while(s != NULL)
	{
		count++ ;
		s = s->next ;
	}
	
	return count ;
}

int check(node * list_ptr,int temp)
{
	while(list_ptr != NULL)
	{
		if(list_ptr->data == temp)
		return 0;

		list_ptr = list_ptr->next ;
	}

return 1;
}

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
	node * ptr1 = list_ptr;
	
	if(ptr1->next == NULL)
	{
		list_ptr = NULL ;
		free(ptr1) ;
	}
	else
	{
		//node * ptr2 = list_ptr ;
		
		while(ptr1->next->next != NULL)
		{
			ptr1 = ptr1->next ;
			 /*if(ptr1->next != NULL)
			 {
	 			ptr2 = ptr2->next ;
			 }*/	
		}
		
		free(ptr1->next) ;
		ptr1->next = NULL ;
		
	}
	

	return list_ptr ;	
}

void DeleteSet(node *list_ptr )
{
	/*int option ;
	printf("Press 1 to delete from start and 0 to delete from end : ") ;
	scanf("%d", &option) ;*/
	
	/*int num , i;
	printf("Enter no. of elements to be deleted : ") ;
	scanf("%d" , &num) ;*/
	
		if(list_ptr != NULL)
		{
			//if(option)
			//{
	
				list_ptr = DeleteFromStart(list_ptr) ;
			//}
			/*else
			{
				list_ptr = DeleteFromEnd(list_ptr) ;
		
			}*/
		}

}



node * createNode(node * list_ptr,int nu)
{
	node * nptr = (node *)malloc(sizeof(node))  ;
	int temp,l;
	node * ptr = list_ptr ;
	if(nu == 0)
	{
		
	
		again :

		printf("Enter data : ") ;
		scanf("%d" , &temp) ;
	
		if(check(list_ptr,temp) == 1) //returns 1 unique element 
		{	
			nptr->data = temp ;	
		
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

		}
		else 
		{
			printf("Please enter a unique element . To reenter type 1 else type 0 : \n") ;
			scanf("%d",&l) ;

			if(l == 1)
			goto again ;
		}
	}
	else
	{
		//again2 :

		//printf("Enter data : ") ;
		//scanf("%d" , &temp) ;
	
		if(check(list_ptr,nu) == 1) //returns 1 unique element 
		{	
			nptr->data = nu ;	
		
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

		}
		/*else 
		{
			printf("Please enter a unique element . To reenter type 1 else type 0 : \n") ;
			scanf("%d",&l) ;

			if(l == 1)
			goto again ;
		}*/
	}
	return list_ptr;
}


node * createSet(node * nptr,int nu)
{
    int c ;
	
    
	    printf("Do you want to create an empty set ?(1/0)\n") ;
	    scanf("%d",&c) ;
	    
	    if(c == 1)
	    {
		nptr = (node *)malloc(sizeof(node)) ;
	    }
	    else if(c == 0)
	    {
		int num,i ;
		printf("Enter number of elements to be entered in set : \n") ;
		scanf("%d",&num) ;
		
		for(i=0;i<num;i++)
		{
		    nptr = createNode(nptr,nu) ;
		}
	    }
   
    return nptr ;
}

void printSet(node ** set_pptr,int count)
{
    int si,c = 0,p;
    node * nptr ;
    re :
    printf("Enter set index to be printed : \n") ;
    scanf("%d",&si) ;

    if(si<=count)
    {
	nptr = set_pptr[si] ;
	    while(nptr != NULL)
	    {
		printf("%d ",nptr->data) ;
		nptr = nptr->next ;
	    }
	    //c++;
	    printf("Do you want to print more sets : (1/0)\n") ;
	    scanf("%d",&p) ;
	    
	    if(p == 1)
	    goto re ;
    }
    else
    printf("Sorry cannot print . Index is beyond range .") ;
    
}

node * unionOfSets(node ** set_pptr , int count)
{
	node * nptr = NULL , *ptr;
	int si ;

	again2 :
	printf("Enter the set index which you want to do union with : \n") ;
	scanf("%d",&si) ;
	
	if(si <= count)
	{
		ptr = set_pptr[si] ;
		while(ptr != NULL)
		{
			if(check(nptr,ptr->data) == 1)
			{
				nptr = createNode(nptr,ptr->data) ;
			}
			ptr = ptr->next ;
		}
	}
	else
	{
		printf("Out of range index . Please Enter Set Index in range .") ;
	}
	printf("Do you want to do union with more sets ? (1/0)\n") ;
	scanf("%d",&si) ;

	if(si == 1)
	goto again2 ;
	
	return nptr ;
}

node * intersectionOfSets(node ** set_pptr , int count,int nu)
{
	node * nptr2 = NULL , *ptr2;
	int si ;
	
	again3 :

	if(nu != 0)
	{
		
		printf("Enter the set index which you want to do intersection with : \n") ;
		scanf("%d",&si) ;
	
		if(si <= count)
		{
			ptr2 = set_pptr[si] ;
			while(ptr2 != NULL)
			{
				if(check(nptr2,ptr2->data) == 0)
				{
					nptr2 = createNode(nptr2,ptr2->data) ;
				}
				ptr2 = ptr2->next ;
			}
		}
		else
		{
			printf("Out of range index . Please Enter Set Index in range .") ;
		}
		//printf("Do you want to do intersection with more sets ? (1/0)\n") ;
		//scanf("%d",&si) ;

		//if(si == 1)
		//goto again3 ;
	}
	else if(nu == 0)
	{ 
		
		node * ptr3 = NULL;
		int s1,s2 ;
		printf("Enter the set indices whose intersection you want to do : \n") ;
		scanf("%d %d",&s1,&s2) ;

		if(s1 <= count && s2 <= count)
		{
			ptr2 = set_pptr[s1] ;
			ptr3 = set_pptr[s2] ;
			while(ptr3 != NULL)
			{
				if(check(ptr2,ptr3->data) == 0)
				{
					nptr2 = createNode(nptr2,ptr3->data) ;
				}
				ptr3 = ptr3->next ;
			}
		}
		else
		{
			printf("Out of range index . Please Enter Set Index in range .") ;
		}
		
		nu = 10 ;
			
	}

	printf("Do you want to do intersection with more sets ? (1/0)\n") ;
	scanf("%d",&si) ;

	if(si == 1)
	goto again3 ;
	
	return nptr2 ;
}

node * differenceBetweenSets(node ** set_pptr , int count,int nu)
{
	node * nptr2 = NULL , *ptr2;
	int si ;
	
	again3 :

	if(nu != 0)
	{
		
		printf("Enter the set index which you want to delete from existing set : \n") ;
		scanf("%d",&si) ;
	
		if(si <= count)
		{
			ptr2 = set_pptr[si] ;
			while(ptr2 != NULL)
			{
				if(check(nptr2,ptr2->data) == 0)
				{
					nptr2 = createNode(nptr2,ptr2->data) ;
				}
				ptr2 = ptr2->next ;
			}
		}
		else
		{
			printf("Out of range index . Please Enter Set Index in range .") ;
		}
		//printf("Do you want to do intersection with more sets ? (1/0)\n") ;
		//scanf("%d",&si) ;

		//if(si == 1)
		//goto again3 ;
	}
	else if(nu == 0)
	{ 
		
		node * ptr3 = NULL;
		int s1,s2 ;
		printf("Enter the set indices whose difference you want to do : \n") ;
		scanf("%d %d",&s1,&s2) ;

		if(s1 <= count && s2 <= count)
		{
			ptr2 = set_pptr[s1] ;
			ptr3 = set_pptr[s2] ;
			while(ptr2 != NULL)
			{
				if(check(ptr3,ptr2->data) == 1)
				{
					nptr2 = createNode(nptr2,ptr2->data) ;
				}
				ptr2 = ptr2->next ;
			}
		}
		else
		{
			printf("Out of range index . Please Enter Set Index in range .") ;
		}
		
		nu = 10 ;
			
	}

	printf("Do you want to do intersection with more sets ? (1/0)\n") ;
	scanf("%d",&si) ;

	if(si == 1)
	goto again3 ;
	
	return nptr2 ;
}

void subsetCheck(node ** set_pptr , int count, int nu)
{
	node * nptr2 = NULL , *ptr2;
	int si ;
		
		node * ptr3 = NULL;
		int s1,s2,flag = 0 ;
		printf("Enter the super set index and subset index : \n") ;
		scanf("%d %d",&s1,&s2) ;

		if(s1 <= count && s2 <= count)
		{
			ptr2 = set_pptr[s1] ;
			ptr3 = set_pptr[s2] ;
			while(ptr3 != NULL)
			{
				if(check(ptr2,ptr3->data) == 1)
				{
					//nptr2 = createNode(nptr2,ptr3->data) ;
					flag = 1;
				}
				ptr3 = ptr3->next ;
			}
		}
		else
		{
			printf("Out of range index . Please Enter Set Index in range .") ;
		}

		if(flag == 0)
		printf("Set index %d is a subset of set index %d . \n",s2,s1 ) ;
		else if(flag == 1)
		printf("Set index %d is NOT a subset of set index %d . \n",s2,s1 ) ;
		
		nu = 10 ;
	
	
	
}


int main() 
{
    node ** set_pptr ;
    int count = 0;
    set_pptr = (node **)malloc(sizeof(node *)) ;
    
    int nu = 0;

    int n , ai, p;
    printf("enter 1 to create list . 3 to see list .") ;
    char c;
    int e,si;
        printf("For Typical Operations:\n Type 1 for is_element_of \nType 2 for is_empty \nType 3 for size\nType 4 for printing any list\nType 5 for set creation\n");
        
        printf("For Other Operations:\nType 6 for add if not already present \nType 7 for remove any element from list \n");
        
        printf("For Operations on 2 sets:\nType 8 for union of 2 sets \nType 9 for intersection of 2 sets \nType 10 for difference between 2 sets\nType 11 for whether checking set A is subset of set \n");
   
    do
    {     
        scanf("%d",&n) ;
        if(n == 1)
        {
            printf("Enter the element you want to check : \n") ;
            scanf("%d",&e) ;
            printf("Enter the set index for searching : ") ;
            scanf("%d",&si) ;
            if(is_element_of(e,set_pptr[si]) == 1)
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
                if(is_empty(set_pptr[e]) == 1) 
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
            
            printf("Size of set index %d is %d",e,size(set_pptr[e])) ;
        }
        else if(n == 4)
        {
            printSet(set_pptr,count) ;
        }
        else if(n == 5)
        {
            set_pptr[count] = createSet(set_pptr[count],nu) ;
            count++ ;
            set_pptr = (node **)realloc(set_pptr,count+1) ;
        }
        else if(n == 6)
	    {
            printf("Enter set index to which you want to add an element : \n") ;
            scanf("%d",&ai) ;
            
            set_pptr[ai] = createNode(set_pptr[ai],nu) ;
	    }   
	 else if(n == 7)
	    {
            printf("Enter set index from which you want to remove an element : \n") ;
            scanf("%d",&ai) ;
	    printf("Do you want to remove from start or end ? (1/0)\n") ;
	    scanf("%d",&p) ;
            
	    if(p == 1)
            set_pptr[ai] = DeleteFromStart(set_pptr[ai]) ;
	    else if(p == 2)
	    set_pptr[ai] = DeleteFromEnd(set_pptr[ai]) ;
	    } 
	else if(n == 8)  
	{
		node * u = unionOfSets(set_pptr,count);
		node * t = u ;
		while(t!=NULL)
		{
			printf("%d ",t->data) ;
			t = t->next ;
		}

		printf("Do you save the set ? (1/0)") ;
		scanf("%d",&p) ;

		if(p == 1)
		{
			
			set_pptr[count] = u ;
			count++;
			set_pptr = (node **)realloc(set_pptr,count+1) ;
		}

	}
	else if(n == 9)
	{
		node * in = intersectionOfSets(set_pptr,count,nu) ;
		node * q = in ;
		while(q!=NULL)
		{
			printf("%d ",q->data) ;
			q = q->next ;
		}

		printf("Do you save the set ? (1/0)") ;
		scanf("%d",&p) ;

		if(p == 1)
		{
			
			set_pptr[count] = in ;
			count++;
			set_pptr = (node **)realloc(set_pptr,count+1) ;
			
		}
	}
	else if(n == 10)
	{
		node * d = differenceBetweenSets(set_pptr,count,nu) ;
		node * r = d ;
		while(r!=NULL)
		{
			printf("%d ",r->data) ;
			r = r->next ;
		}

		printf("Do you save the set ? (1/0)") ;
		scanf("%d",&p) ;

		if(p == 1)
		{
			
			set_pptr[count] = d ;
			count++ ;
			set_pptr = (node **)realloc(set_pptr,count+1) ;
		}
	}
	else if(n == 11)
	{
		subsetCheck(set_pptr,count,nu) ;
	}
	
        
        
    }
    while(n!=100) ;
    
    
	return 0;
}
