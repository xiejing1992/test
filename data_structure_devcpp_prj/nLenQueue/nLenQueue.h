/*   nLenQueue.h  */
#ifndef _NLENQUEUE_H_
#define _NLENQUEUE_H_

#define MAX_NODE_NUM 	32
#define MAX_QUEUE_SIZE 	4096  


/*  base type  */
typedef unsigned char	uint8;
typedef unsigned short	uint16;
typedef unsigned int	uint32;

/*  queue type  */
typedef uint8 QueueNode;
typedef struct
{
	QueueNode* fifo;
	uint16 capacity;
	uint16 len;
	uint8 node_num;
	uint16 node_len[MAX_NODE_NUM];
}TQueue;


/* function declare  */

void Queue_Init(void);

uint8 Queue_Push(QueueNode* node, uint16 node_len);

uint8 Queue_Pop(QueueNode* node, uint16* len);

#endif /* #ifndef _NLENQUEUE_H_   */
