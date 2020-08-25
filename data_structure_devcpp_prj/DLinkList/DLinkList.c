/* DLinkList.c  */
#include <stdio.h>
#include <stdlib.h>
#include "DLinkList.h"


/* function define  */
DLinkList* TDLinkList_Create(void)
{
	TDLinkList* ret = (TDLinkList*)malloc(sizeof(TDLinkList));
	
	if(ret != NULL)
	{
		ret->header.next = NULL;
		ret->header.pre = NULL;
		ret->slider = NULL;
		ret->len = 0;
	}
	
	return ret;
}

void DLinkList_Destroy(DLinkList* list)
{
	TDLinkList* ret = (TDLinkList*)list;
	
	if(ret != NULL)
	{
		free(list);
	}

}

void DLinkList_Clear(DLinkList* list)
{
	TDLinkList* ret = (TDLinkList*)list;
	
	if(ret != NULL)
	{
		ret->header.next = NULL;
		ret->header.pre = NULL;
		ret->len = 0;
	}	
}

uint16 DLinkList_Len(DLinkList* list)
{
	uint16 ret = 0;
	TDLinkList* sList = (TDLinkList*)list;
	
	if(sList != NULL)
	{
		ret = sList->len;
	}
	
	return ret;
}

uint16 DLinkList_Insert(DLinkList* list, DLinkListNode* node, uint16 pos)
{
	uint16 ret = 1;
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* current = NULL;
	DLinkListNode* next = NULL;
	uint16 i = 0;
	
	
	ret &= (sList != NULL);
	ret &= (node != NULL);
	ret &= (pos > 0);
	
	if(ret)
	{
		current = (DLinkListNode*)sList;	
		for(i=0; i<pos; i++)
		{
			current = current->next;
		}
		next = current->next;
		
		current->next = node;
		node->next = next;
		if(next != NULL)
		{
			next->pre = node;
		}
		if(pos == 1)
		{
			node->pre = NULL;
		}
		else
		{
			node->pre = current;			
		}
		
		if(sList->len == 0)
		{
			sList->slider = node;	
		} 
		
		sList->len++;

	}
	
	return ret;
}

DLinkListNode* DLinkList_Get(DLinkList* list, uint16 pos)
{
	uint16 i = 0;
	DLinkListNode* current = NULL;
	DLinkListNode* ret = NULL;
	TDLinkList* sList = (TDLinkList*)list;
	
	if( (sList != NULL) && (pos > 0) )
	{
		if(pos > sList->len)
		{
			pos = sList->len;
		}
		
		current = (DLinkListNode*)sList;
		for(i=1; i<pos; i++)
		{
			current = current->next;
		}
		
		ret = current->next;
	}
	
	return ret;
}

DLinkListNode* DLinkList_Delete(DLinkList* list, uint16 pos)
{
	uint16 i = 0;
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* current = NULL;
	DLinkListNode* next = NULL;
	DLinkListNode* ret = NULL;
	uint16 rslt = 1;
	
	if(sList == NULL)
	{
		return NULL;
	}
	
	rslt &= (pos > 0); 
	rslt &= (pos <= sList->len); 
	
	if( rslt )
	{
		if(pos > sList->len)
		{
			pos = sList->len;
		}
		
		current = (DLinkListNode*)sList;
		for(i=1; i<pos; i++)
		{
			current = current->next;
		}
		ret = current->next;
		next = ret->next;
		
		current->next = next;		
		if(pos == 1)
		{
			next->pre = NULL;
		}
		else if(pos == sList->len)
		{

		}
		else
		{
			next->pre = current;
		}
		
		sList->len--;
		if(sList->slider == ret)
		{
			sList->slider = next;
		}
	}
		
	return ret;
}


DLinkListNode* DLinkList_Reset(DLinkList* list)
{
	DLinkListNode* ret = NULL;
	TDLinkList* sList = (TDLinkList*)list;
	
	if(sList != NULL)
	{
		ret = sList->header.next;
	}
	
	return ret;
}

DLinkListNode* DLinkList_Current(DLinkList* list)
{
	DLinkListNode* ret = NULL;
	TDLinkList* sList = (TDLinkList*)list;
	
	if(sList != NULL)
	{
		ret = sList->slider;
	}
	
	return ret;	
}

DLinkListNode* DLinkList_Next(DLinkList* list)
{
	DLinkListNode* ret = NULL;
	TDLinkList* sList = (TDLinkList*)list;
	
	if( (sList != NULL) && (sList->slider != NULL) )
	{
		ret = sList->slider->next;
	}
	
	return ret;		
}

DLinkListNode* DLinkList_Pre(DLinkList* list)
{
	DLinkListNode* ret = NULL;
	TDLinkList* sList = (TDLinkList*)list;
	
	if( (sList != NULL) && (sList->slider != NULL) )
	{
		ret = sList->slider->pre;
	}
	
	return ret;		
}
