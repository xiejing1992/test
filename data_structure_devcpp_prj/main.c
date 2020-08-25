/* main.c  */
#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"
#include "LinkList.h"
#include "CircleList.h"
#include "Stack.h"
#include "Queue.h"

//#define DEBUG_SEQLIST
//#define DEBUG_LINKLIST
//#define DEBUG_CIRCLELIST
//#define DEBUG_STACK
//#define DEBUG_QUEUE
#define DEBUG_NQUEUE


/* function statement  */
#ifdef DEBUG_SEQLIST
void Debug_SeqList(void);
#endif
#ifdef DEBUG_LINKLIST
void Debug_LinkList(void);
#endif
#ifdef DEBUG_CIRCLELIST
void Debug_CircleList(void);
#endif
#ifdef DEBUG_STACK
void Debug_Stack(void);
#endif
#ifdef DEBUG_QUEUE
void Debug_Queue(void);
#endif
#ifdef DEBUG_NQUEUE
void Debug_nQueue(void);
#endif


int main(int argc, char *argv[]) 
{

#ifdef DEBUG_SEQLIST
	Debug_SeqList();
#endif
#ifdef DEBUG_LINKLIST
	Debug_LinkList();
#endif
#ifdef DEBUG_CIRCLELIST
	Debug_CircleList();
#endif
#ifdef DEBUG_STACK
	Debug_Stack();
#endif
#ifdef DEBUG_QUEUE
	Debug_Queue();
#endif
#ifdef DEBUG_NQUEUE
	Debug_nQueue();
#endif	
	return 0;
}


#ifdef DEBUG_NQUEUE
void Debug_nQueue(void)
{
	uint8 node1[5] = {1,2,3,4,5};
	uint8 node2[3] = {6,7,8};
	uint8 node3[8] = {9,10,11,12,13,14,15,16};
	uint8 node[10] = {0};
	uint16 len = 0;
	uint16 i = 0;
	
	Queue_Init();
	
	Queue_Push(node1, sizeof(node1)/sizeof(uint8));
	Queue_Push(node2, sizeof(node2)/sizeof(uint8));
	Queue_Push(node3, sizeof(node3)/sizeof(uint8));
	
	while(Queue_Pop(node, &len))
	{
		for(i=0; i<len; i++)
		{
			printf("%d, ", node[i]);
		}
		printf("\n");		
	}
		
//	Queue_Pop(node, &len);
//	for(i=0; i<len; i++)
//	{
//		printf("%d, ", node[i]);
//	}
//	printf("\n");
//	Queue_Pop(node, &len);
//	for(i=0; i<len; i++)
//	{
//		printf("%d, ", node[i]);
//	}
//	printf("\n");
//	Queue_Pop(node, &len);
//	for(i=0; i<len; i++)
//	{
//		printf("%d, ", node[i]);
//	}
//	printf("\n");
	
}
#endif


#ifdef DEBUG_QUEUE
#define NODE_NUM 10 
void Debug_Queue(void)
{
	uint16 i = 0;
	TQueueNode node[NODE_NUM];
	TQueueNode* node_ptr;
	Queue* queue = NULL;
	uint16 len = 0;
	
	for(i=0; i<NODE_NUM; i++)
	{
		node[i].value = i+1;
	}
	
	queue = Queue_Create();
	
	for(i=0; i<NODE_NUM; i++)
	{
		Queue_In(queue, (QueueNode*)&node[i]);
	}
	
//	len = Queue_Len(queue);
//	printf("current queue len=%d\n", len);
	
	for(i=0; i<NODE_NUM; i++)
	{
		node_ptr = (TQueueNode*)Queue_Out(queue);
		printf("%d\n", node_ptr->value);
		
		len = Queue_Len(queue);
		printf("current queue len=%d\n", len);
	}
	
	Queue_Destroy(queue);
	
} 
#endif

#ifdef DEBUG_STACK
#define ELEMENT_NUM 10
void Debug_Stack(void)
{
	uint16 i = 0;
	TElement element[ELEMENT_NUM];
	Stack* stack = NULL;
	TElement* cur_element;
	TElement* temp_element;
	uint16 size = 0;
	
	for(i=0; i<ELEMENT_NUM; i++)
	{
		element[i].value = i+1;
	}
	
	stack = Stack_Create();
	
	for(i=0; i<ELEMENT_NUM; i++)
	{
		Stack_Push(stack, (StackElement*)&element[i]);
	}
	
//	size = Stack_GetSize(stack);
//	printf("stack size is %d\n", size);
	
	for(i=0; i<ELEMENT_NUM; i++)
	{
		temp_element = (TElement*)Stack_Pop(stack);
		if(temp_element != NULL)
		{
			cur_element = temp_element;
			printf("%d\n", cur_element->value);
			
//			size = Stack_GetSize(stack);
//			printf("stack size is %d\n", size);
		}
		
	}
	
	Stack_Destroy(stack);
	
}
#endif

#ifdef DEBUG_CIRCLELIST
#define NODE_NUM	5 
#define DEBUG_CIRCLELIST_CASE1
void Debug_CircleList(void)
{
#ifdef DEBUG_CIRCLELIST_CASE1
	uint8 i = 0;
	TCircleListNode node[NODE_NUM];
	TCircleListNode* node_ptr = NULL;
	CircleList * list = CircleList_Create();
	
	/* insert node  */
	for(i=0; i<NODE_NUM; i++)
	{
		node[i].value = i+1;
		
		CircleList_Insert(list, (CircleListNode*)&(node[i]), i+1);
		
	}
	
	/* get node  */
	printf("current list node value: ");
	for(i=0; i<NODE_NUM*3; i++)
	{
		node_ptr = (TCircleListNode*)CircleList_Get(list, i+1);
		printf("%d, ", node_ptr->value);
	}
	printf("\n");
	
	/* delete node by pos  */
	printf("delete list node value: ");
	for(i=0; i<2; i++)
	{
		node_ptr = (TCircleListNode*)CircleList_Delete(list, 1);
		printf("%d, ", node_ptr->value);
	}
	printf("\n");
	
	/* get node  */
	printf("current list node value: ");
	for(i=0; i<(NODE_NUM-2)*3; i++)
	{
		node_ptr = (TCircleListNode*)CircleList_Get(list, i+1);
		printf("%d, ", node_ptr->value);
	}
	printf("\n");
	
	CircleList_Destroy(list);

#endif /*  #ifdef DEBUG_CIRCLELIST_CASE1  */
}
#endif	/*  #ifdef DEBUG_CIRCLELIST */


#ifdef DEBUG_LINKLIST
#define LINKLIST_NODE_NUM	20
//#define DEBUG_LINKLIST_CASE1
#define DEBUG_LINKLIST_CASE2
void Debug_LinkList(void)
{
#ifdef 	DEBUG_LINKLIST_CASE1
	
	uint16 i = 0;
	uint16 len = 0;
	LinkList* list = NULL;
	TLinkListNode node[LINKLIST_NODE_NUM];
	TLinkListNode* node_ptr = NULL;
	
	/*  init node */
	for(i=0; i<LINKLIST_NODE_NUM; i++)
	{
		node[i].value = 0;
		node[i].value = i+1;
	}
	
	/*  new link list  */
	list = LinkList_Create();
	
	/* insert node  */
	for(i=0; i<LINKLIST_NODE_NUM; i++)
	{
		LinkList_Insert(list, (LinkListNode*)&(node[i]), i+1);
	}
	
	/*  get node */
	for(i=0; i<LINKLIST_NODE_NUM; i++)
	{
		node_ptr = (TLinkListNode*)LinkList_Get(list, i+1);
		printf("%d\n", node_ptr->value);
	}
	
	/* get link list len  */
	len = LinkList_Length(list);
	printf("cur link list len: %d\n", len);
	
	/* clear link list  */
	LinkList_Clear(list);
	len = LinkList_Length(list);
	printf("cur link list len: %d\n", len);
	
	/*  destroy link list */
	LinkList_Destroy(list);
	
#endif /* #ifdef DEBUG_LINKLIST_CASE1  */

#ifdef 	DEBUG_LINKLIST_CASE2

	uint16 i = 0;
	uint16 len = 0;
	LinkList* list = NULL;
	TLinkList* slist = NULL;
	TLinkListNode node[LINKLIST_NODE_NUM];
	TLinkListNode* node_ptr = NULL;

	/*  init node */
	for(i=0; i<LINKLIST_NODE_NUM; i++)
	{
		node[i].value = 0;
		node[i].value = i+1;
	}
	
	/*  new link list  */
	list = LinkList_Create();
	
	/* insert node  */
	for(i=0; i<LINKLIST_NODE_NUM; i++)
	{
		LinkList_Insert(list, (LinkListNode*)&(node[i]), i+1);
	}
	
	/*  get node */
	slist = (TLinkList* )list;
	len = slist->len;
	printf("cur node value: ");
	for(i=0; i<len; i++)
	{
		node_ptr = (TLinkListNode*)LinkList_Get(list, i+1);
		printf("%d, ", node_ptr->value);
	}
	printf("\n");	
	
	/* delete node  */
	slist = (TLinkList* )list;
	len = (slist->len)/2;
	printf("delete node value: ");
	for(i=0; i<len; i++)
	{
		node_ptr = (TLinkListNode*)LinkList_Delete(list, 1);
		printf("%d, ", node_ptr->value);
	}
	printf("\n");
	
	/*  get node */
	slist = (TLinkList* )list;
	len = slist->len;
	printf("cur node value: ");
	for(i=0; i<len; i++)
	{
		node_ptr = (TLinkListNode*)LinkList_Get(list, i+1);
		printf("%d, ", node_ptr->value);
	}
	printf("\n");	
	
	/*  destroy link list */
	LinkList_Destroy(list);
	
#endif /* #ifdef 	DEBUG_LINKLIST_CASE2 */

}
#endif  /* #ifdef DEBUG_LINKLIST */


#ifdef DEBUG_SEQLIST
#define NODE_NUM	20
void Debug_SeqList(void)
{
	TSeqList* list = NULL;
	TSeqListNode* node = NULL;
	uint16 len = 0;
	uint8 i = 0;
	uint8 temp_u8 = 0;
	
	/*  1. create sequeue  */ 
	list = SeqList_Create(NODE_NUM);
	
	/*  2. get capacity  */
	len = SeqList_Capacity((void*)list);
	printf("SeqList capacity = %d\n", len);
	
	/* 3. insert node  */
	for(i=1; i<=NODE_NUM; i++)
	{
		SeqList_Insert((void*)list, (void*)&i, i);
	}
	
	/*  4. get len */
	printf("cur len = %d\n", list->len);
	
	/*  5. get node */
	printf("seqence list element is ");
	for(i=1; i<=NODE_NUM; i++)
	{
		node = SeqList_Get((void*)list, i); 
		if(node == NULL)
		{
			printf("node is null\n");
		}
		else
		{
			printf( "%d, ", *((uint8*)node) );
		}
		
	}
	printf("\n");	
	
	/*  delete node  */
	printf("delete node element is ");
	for(i=1; i<=5; i++)
	{
		SeqList_Delete((void*)list, i, &temp_u8);
		printf( "%d, ", temp_u8 );
	}
	printf("\n");
	
	/*  cur len  */
	printf("len = %d\n", list->len);
	
	/*  print rev node  */
	printf("resv seqence list element is ");
	for(i=1; i<=list->len; i++)
	{
		node = SeqList_Get((void*)list, i); 
		if(node == NULL)
		{
			printf("node is null\n");
		}
		else
		{
			printf( "%d, ", *((uint8*)node) );
		}
		
	}
	printf("\n");	
	
	
	/*  6. clear list */
	SeqList_Clear(list);
	printf("cur len = %d\n", list->len);
	
	
	/*  destroy sequeue */
	SeqList_Destroy(list);
}
#endif


