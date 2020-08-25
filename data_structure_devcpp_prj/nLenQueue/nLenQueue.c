/*  nLenQueue.c  */
#include <stdio.h>
#include <stdlib.h>
#include "nLenQueue.h"

/* queue fifo define  */
QueueNode Fifo[MAX_QUEUE_SIZE];

/*  queue define  */
TQueue Queue;


/*  function define  */
void Queue_Init(void)
{
	uint8 i = 0;
	
	Queue.fifo = Fifo;
	Queue.capacity = MAX_QUEUE_SIZE;
	Queue.len = 0;
	Queue.node_num = 0;
	
	for(i=0; i<MAX_NODE_NUM; i++)
	{
		Queue.node_len[i] = 0;
	}
	 
}

uint8 Queue_Push(QueueNode* node, uint16 node_len)
{
	uint8 ret = 1;
	uint16 i = 0;
	
	ret &= (node != NULL);
	ret &= (node_len > 0);
	ret &= ( (Queue.node_num + 1) <= MAX_NODE_NUM );
	ret &= ( (Queue.len + node_len) <= Queue.capacity );
	
	if(ret)
	{
		for(i=Queue.len; i<(node_len+Queue.len); i++)
		{
			Queue.fifo[i] = node[i-Queue.len];		
		}
		
		Queue.len += node_len;
		Queue.node_len[Queue.node_num] = node_len;
		Queue.node_num++;
		
	}
	
	
	return ret;
}

uint8 Queue_Pop(QueueNode* node, uint16* len)
{
	uint8 ret = 1;
	uint16 i = 0;
	uint16 len_remain = 0;
	
	ret &= (node != NULL);
	ret &= (Queue.node_num > 0);
	
	if(ret)
	{
		/*  copy node data, len  */
		for(i=0; i<Queue.node_len[0]; i++)
		{
			node[i] = Queue.fifo[i];
		}
		*len = Queue.node_len[0];
		
		/*  move fifo node  */
		len_remain = Queue.len - Queue.node_len[0];
		for(i=0; i<len_remain; i++)
		{
			Queue.fifo[i] = Queue.fifo[i+Queue.node_len[0]];
		}
		for(; i<Queue.len; i++)
		{
			Queue.fifo[i] = 0;
		}
		
		/*  queue current len */
		Queue.len -=  Queue.node_len[0];
		
		/*  move node len  */
		for(i=0; i<(Queue.node_num-1); i++)
		{
			Queue.node_len[i] = Queue.node_len[i+1];
		}
		Queue.node_len[i] = 0;
		
		/* queue node num  */
		Queue.node_num--;
		
	}
	
	return ret;
}

