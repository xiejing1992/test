/* LinkList.c  */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "LinkList.h"


/* function define  */
LinkList* LinkList_Create(void)
{
	TLinkList* ret = NULL;
	
	ret = (TLinkList*)malloc(sizeof(TLinkList));
	
	if(ret != NULL)
	{
		ret->header.next = NULL;
		ret->len = 0;
	}
	
	return ret;
}

void LinkList_Destroy(LinkList* list)
{
	free(list);
}

void LinkList_Clear(LinkList* list)
{
	TLinkList* sList = (TLinkList*)list;
	
	if(sList != NULL)
	{
		sList->header.next = NULL;
		sList->len = 0;	
	}

}

uint16 LinkList_Length(LinkList* list)
{
	uint16 ret = 0;
	TLinkList* sList = (TLinkList*)list;
	
	if(sList != NULL)
	{
		ret = sList->len;	
	}	
	
	return ret;
}

uint16 LinkList_Insert(LinkList* list, LinkListNode* node, uint16 pos)
{
	uint16 i = 0;
	uint16 ret = 1;
	TLinkList* slist = (TLinkList*)list;
	LinkListNode* current = NULL;
	
	if(pos == 0)
	{
		return ret;
	}
	if(slist == NULL)
	{
		return ret;
	}
	
	pos--;
	if(pos >= slist->len)
	{
		pos = slist->len;
	}
	
	if(node != NULL)
	{
		current = (LinkListNode*)slist;
		for(i=0; i<pos; i++)
		{
		    current = current->next;
		}
		
		node->next = current->next;
		current->next = node;
		
		slist->len++;
	}
	
	return ret;
}

LinkListNode* LinkList_Get(LinkList* list, uint16 pos)
{
	uint16 i = 0;
	TLinkList* slist = (TLinkList*)list;
	LinkListNode* current = NULL;
	
	pos--;
	
	if( (slist != NULL) && (pos < slist->len) )
	{
		current = (LinkListNode*)slist;
		for(i=0; i<pos; i++)
		{
			current = current->next;
		}
		current = current->next;	
	}
	
	
	return current;
}

LinkListNode* LinkList_Delete(LinkList* list, uint16 pos)
{
	uint16 i = 0;
	TLinkList* slist = (TLinkList*)list;
	LinkListNode* ret = NULL;
	LinkListNode* current = NULL;
	
	if(slist == NULL)
	{
		return ret;
	}
	if(slist->len == 0)
	{
		return ret;
	}
	
	pos--;

	if(pos < slist->len)
	{
		current = (LinkListNode*)slist;
		for(i=0; i<pos-1; i++)
		{
			current = current->next;
		}
		
		ret = current->next;
		current->next = ret->next;
		
		slist->len--; 	
	}
	
	
	return ret;
}
 
