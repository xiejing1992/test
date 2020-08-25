/*  CircleList.c  */
#include"CircleList.h"
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>


/*  function define  */
CircleList* CircleList_Create(void)
{
	TCircleList* list = NULL;
	
	list = (TCircleList*)malloc(sizeof(TCircleList));
	
	if(list != NULL)
	{
		list->len = 0;
		list->header.next = NULL;
		list->slider = NULL;
	}
	
	return list;
}

void CircleList_Destroy(CircleList* list)
{
	free(list);	
}

void CircleList_Clear(CircleList* list)
{
	TCircleList* sList = (TCircleList*)list;
	
	if(sList != NULL)
	{
		sList->header.next = NULL;
		sList->slider = NULL;
		sList->len = 0;
	}
	
}

uint16 CircleList_Len(CircleList* list)
{
	uint16 len = 0;
	TCircleList* sList = (TCircleList*)list;
	
	if(sList != NULL)
	{
		len = sList->len;
	}
	
	return len;
}

uint16 CircleList_Insert(CircleList* list, CircleListNode* node, uint16 pos)
{
	uint16 ret = 1;
	uint16 i = 0;
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* current = NULL;
	
	ret &= (sList != NULL);
	ret &= (node != NULL);
	ret &= (pos > 0);
	
	pos--;
	
	if(ret)
	{
		current = (CircleListNode*)sList;
		
		for(i=0; (i<pos) && (current->next != NULL); i++)
		{
			current = current->next; 
		}
		
		node->next = current->next;
		current->next = node;
		
		if(sList->len == 0)
		{
			sList->slider = node;
			node->next = node;
		}
		
		sList->len++;
		
	}
	
	return 0;
}

CircleListNode* CircleList_Get(CircleList* list, uint16 pos)
{
	uint16 i = 0;
	CircleListNode* ret = NULL;
	CircleListNode* current = NULL;
	TCircleList* sList = (TCircleList*)list;
	
	
	if( (sList != NULL) && (pos > 0) )
	{
		pos--;
		
		current = (CircleListNode*)sList;
		for(i=0; (i<pos) && (current->next != NULL); i++)
		{
			current = current->next;
		}
		
		ret = current->next;
	}
	
	return ret;
}

CircleListNode* CircleList_Delete(CircleList* list, uint16 pos)
{
	CircleListNode* ret = NULL;
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* current = NULL;
	CircleListNode* first = NULL;
	CircleListNode* last = NULL;
	uint8 i = 0;
	
	
	if( (sList != NULL) && (pos > 0) )
	{
		pos--;
		
		current = (CircleListNode*)sList;
		first = current->next;
		last = (CircleListNode*)CircleList_Get(list, (sList->len));
		
		for(i=0; (i<pos) && (current->next != NULL); i++)
		{
			current = current->next;
		}
		
		ret = current->next;
		current->next = ret->next;
		
		sList->len--;
		
		if(ret == first)
		{
			last->next = ret->next;
		}
		
		if(ret == sList->slider)
		{
			sList->slider = ret->next;
		}
		
		if(sList->len == 0)
		{
			sList->header.next = NULL;
			sList->slider = NULL;
		}
		
	}
	
	return ret;
}

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node)
{
	CircleListNode* ret = NULL;
	CircleListNode* current = NULL;
	TCircleList* sList = (TCircleList*)list;
	uint8 i = 0;
	
	if( (sList != NULL) && (node != NULL) )
	{
		current = (CircleListNode*)sList;
		
		for(i=0; i<sList->len; i++)
		{
			if(current->next == node)
			{
				ret = node;
				break;
			}
			current = current->next; 
		}
		
		if(ret != NULL)
		{
			CircleList_Delete(list, i+1);
		}
		
	} 
	
	return ret;
}

CircleListNode* CircleList_Reset(CircleList* list)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;
	
	if(sList != NULL)
	{
		sList->slider = sList->header.next;
		ret = sList->slider;
	}
	
	return ret;
}

CircleListNode* CircleList_Current(CircleList* list)
{
	CircleListNode* ret = NULL;
	TCircleList* sList = (TCircleList*)list;
	
	if(sList != NULL)
	{
		ret = sList->slider; 
	}
	
	return ret;
}

CircleListNode* CircleList_Next(CircleList* list)
{
	CircleListNode* ret = NULL;
	TCircleList* sList = (TCircleList*)list;
	
	if( (sList != NULL) && (sList->slider != NULL) )
	{
		ret = sList->slider;
		sList->slider = ret->next;
	}
	
	return ret;
}
