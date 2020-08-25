/*  SeqList.c  */
#include "SeqList.h"
#include <malloc.h>


SeqList* SeqList_Create(uint16 capacity)
{
	TSeqList* ret = NULL;
	
	if(capacity <= SEQLIST_MAX_LEN)
	{
		ret = (TSeqList*)malloc(sizeof(TSeqList) + sizeof(TSeqListNode) * capacity);
	}
	
	if(ret != NULL)
	{
		ret->capacity = capacity;
		ret->len = 0;
		ret->node = (TSeqListNode*)(ret+1);
	} 
	
	return ret;
}

void SeqList_Destroy(SeqList* list)
{
	free(list);
}

SeqListErrRetType SeqList_Clear(SeqList* list)
{
	SeqListErrRetType ret = 0;
	TSeqList* sList = (TSeqList*)list;
	
	if(sList != NULL)
	{
		sList->len = 0;
	}
	else
	{
		ret = SEQLIST_LIST_NULL;
	}
	
	
	return ret;
}

uint16 SeqList_GetCurLen(SeqList* list)
{
	SeqListErrRetType ret = 0;
	TSeqList* sList = (TSeqList*)list;
	
	if(sList != NULL)
	{
		ret = sList->len;
	}
	else
	{
		ret = SEQLIST_LIST_NULL;
	}
	
	
	return ret;
}

uint16 SeqList_Capacity(SeqList* list)
{
	SeqListErrRetType ret = 0;
	TSeqList* sList = (TSeqList*)list;
	
	if(sList != NULL)
	{
		ret = sList->capacity;
	}
	else
	{
		ret = SEQLIST_LIST_NULL;
	}
	
	return ret;
}

SeqListErrRetType SeqList_Insert(SeqList* list, SeqListNode* node, uint16 pos)
{
	SeqListErrRetType ret = 0;
	TSeqList* sList = (TSeqList*)list;
	TSeqListNode* Tnode = (TSeqListNode*)node;
	uint16 i;

	pos--; //pos = (1,2,3,...,n)
	
	if(sList == NULL)
	{
		return SEQLIST_LIST_NULL;
	}
	if(Tnode == NULL)
	{
		return SEQLIST_NODE_NULL;
	}
	if(pos > sList->len)
	{
		pos = sList->len;
	}
	
	if( (sList->len + 1) <= (sList->capacity) )
	{

		for(i=sList->len; i>pos; i--)
		{
			sList->node[i] = sList->node[i-1];	
		}

		sList->node[pos] = *Tnode;

		sList->len++;
		
	}
	else
	{
		ret = SEQLIST_LIST_FULL;
	}
		
	
	return ret;
}

SeqListNode* SeqList_Get(SeqList* list, uint16 pos)
{
	TSeqListNode* ret = NULL;
	TSeqList* sList = (TSeqList*)list;
	
	pos--; //pos = (1,2,3,...,n)

	if( (sList != NULL) && (pos <= sList->len) )
	{
		ret =  (TSeqListNode*)(&(sList->node[pos]));
	}


	return ret;
}

SeqListErrRetType SeqList_Delete(SeqList* list, uint16 pos, uint8* node)
{
	SeqListNode* ret = SeqList_Get(list, pos);
	TSeqList* sList = (TSeqList*)list;
	uint16 i = 0;
	
	if(ret == NULL)
	{
		return SEQLIST_NODE_NULL;
	}
	
	*node = *( (uint8*)ret );
		
	pos--;  //pos = (1,2,3,...,n)
	

	for(i=pos; i<sList->len-1; i++)
	{
		sList->node[i] = sList->node[i+1];
	}
	sList->len--; 
	

	return 0;
}
