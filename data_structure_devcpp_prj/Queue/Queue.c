/*  Queue.c  */
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"



/*  define function  */
Queue* Queue_Create(void)
{
	TQueue* ret = NULL;
	
	ret = (TQueue*)malloc(sizeof(TQueue));
	
	if(ret != NULL)
	{
		ret->header.next = NULL;
		ret->front = NULL;
		ret->rear = NULL;
		ret->len = 0;
	}
	
	
	return ret;
}

void Queue_Destroy(Queue* queue)
{
	TQueue* sQueue = (TQueue*)queue;
	
	if(sQueue != NULL)
	{
		free(sQueue);
	}
}

void Queue_Clear(Queue* queue)
{
	TQueue* sQueue = (TQueue*)queue;
	
	if(sQueue != NULL)
	{
		sQueue->header.next = NULL;
		sQueue->front = NULL;
		sQueue->rear = NULL;
		sQueue->len = 0;
	}	
}

QueueNode* Queue_In(Queue* queue, QueueNode* node)
{
	QueueNode* ret = NULL;
	QueueNode* current = NULL;
	TQueue* sQueue = (TQueue*)queue;
	uint16 i = 0;
	
	
	if( (sQueue != NULL) && (node != NULL) )
	{
		ret = node;
		
		ret->next = sQueue->header.next;
		sQueue->header.next = ret;
		sQueue->front = ret;
		sQueue->len++;
		
		current = (QueueNode*)sQueue;
		for(i=0; i<sQueue->len; i++)
		{
			current = current->next;
		}

		sQueue->rear = current;
		
	}
	
	return ret;
}

QueueNode* Queue_Out(Queue* queue)
{
	QueueNode* ret = NULL;
	QueueNode* pre = NULL;
	QueueNode* current = NULL;
	TQueue* sQueue = (TQueue*)queue;
	uint16 i = 0;
	
	if(sQueue == NULL)
	{
		return ret;
	}
	
	
	if( (sQueue->rear != NULL) && (sQueue->len > 0) )
	{
		
		ret = sQueue->rear;
		
		current = (QueueNode*)sQueue;
		for(i=0; i<(sQueue->len-1); i++)
		{
			current = current->next;
		}
		current->next = NULL;
		sQueue->rear = current;
		sQueue->len--;
		
		if(sQueue->len == 0)
		{
			sQueue->header.next = NULL;
			sQueue->front = NULL;
			sQueue->rear = NULL;
			sQueue->len = 0;				
		} 
	}
	
	
	return ret;
}

QueueNode* Queue_Get(Queue* queue)
{
	QueueNode* ret = NULL;
	TQueue* sQueue = (TQueue*)queue;
	
	if(sQueue == NULL)
	{
		return NULL;
	}
	
	if(sQueue->front != NULL)
	{
		ret = sQueue->front;
	}
	
	return ret;
}

uint16 Queue_Len(Queue* queue)
{
	uint16 ret = 0xFFFF;
	TQueue* sQueue = (TQueue*)queue;
	
	if(sQueue != NULL)
	{
		ret = sQueue->len;
	}
	
	return ret;
}
