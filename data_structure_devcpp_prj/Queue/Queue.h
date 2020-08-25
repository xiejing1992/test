/*  Queue.h */
#ifndef _QUEUE_H_
#define _QUEUE_H_


/*  define base type  */
typedef unsigned char	uint8;
typedef unsigned short	uint16;
typedef unsigned int	uint32;


/* define queue type  */
typedef void Queue;
typedef struct _tag_QueueNode QueueNode;
struct _tag_QueueNode
{
	QueueNode* next;	
};

typedef struct
{
	QueueNode header;
	uint32 value;
}TQueueNode;

typedef struct
{
	QueueNode header;
	QueueNode* front;
	QueueNode* rear;
	uint16 len; 
}TQueue;

/* define function  */
Queue* Queue_Create(void);

void Queue_Destroy(Queue* queue);

void Queue_Clear(Queue* queue);

QueueNode* Queue_In(Queue* queue, QueueNode* node);

QueueNode* Queue_Out(Queue* queue);

QueueNode* Queue_Get(Queue* queue);

uint16 Queue_Len(Queue* queue);

#endif /* #ifndef _QUEUE_H_  */
