/*  Stack.c */
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"



/* function define  */

Stack* Stack_Create(void)
{
	TStack* ret = (TStack*)malloc(sizeof(TStack));
	
	if(ret != NULL)
	{
		ret->header.next = NULL;
		ret->header.pre = NULL;
		ret->top = NULL;
		ret->size = 0;
	}
	
	return ret;
}

void Stack_Destroy(Stack* stack)
{
	TStack* sStack = (TStack*)stack;
	
	if(sStack != NULL)
	{
		free(sStack);
	}	
}

void Stack_Clear(Stack* stack)
{
	
	TStack* sStack = (TStack*)stack;
	
	if(sStack != NULL)
	{
		sStack->header.next = NULL;
//		sStack->header.pre = NULL;
		sStack->top = NULL;
		sStack->size = 0;		
	}	
}

StackElement* Stack_Push(Stack* stack, StackElement* element)
{
	StackElement* ret = NULL;
	TStack* sStack = (TStack*)stack;
	
	if( (sStack != NULL) && (element != NULL) )
	{
		
		if(sStack->size == 0)
		{
			sStack->header.next = element;
			element->pre = NULL;
		}
		else
		{
			sStack->top->next = element;
			element->pre = sStack->top;
		}	
		
		
		element->next = NULL;
		sStack->top = element;
		ret = sStack->top;
		sStack->size++;
	} 
	
	return ret;
}

StackElement* Stack_Pop(Stack* stack)
{
	StackElement* ret = NULL;
	StackElement* pre = NULL;
	TStack* sStack = (TStack*)stack;
	
	if(sStack == NULL)
	{
		return ret;
	}
	
	if( sStack->top != NULL )
	{
		if(sStack->size == 0)
		{
			sStack->header.next = NULL;
//			sStack->header.pre = NULL;
			sStack->top = NULL;			
		}
		else
		{
			ret = sStack->top;
			pre = sStack->top->pre;
			if(pre != NULL)
			{
				pre->next = NULL;
			}	
			sStack->top = pre;
			sStack->size--;			
		}
		
	} 
	
	return ret;
}

StackElement* Stack_GetTop(Stack* stack)
{
	StackElement* ret = NULL;
	TStack* sStack = (TStack*)stack;
	
	if(sStack == NULL)
	{
		return ret;
	}
	
	if(sStack->top != NULL)
	{
		ret = sStack->top;
	}
	
	return ret;
}

uint16 Stack_GetSize(Stack* stack)
{
	uint16 ret = 0xFFFF;
	TStack* sStack = (TStack*)stack;
	
	if(sStack != NULL)
	{
		ret = sStack->size;
	}
	
	return ret;
}
