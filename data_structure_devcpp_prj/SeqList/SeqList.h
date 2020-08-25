/* SeqList.h  */
#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include <stdio.h>
#include <stdlib.h>


/* define type  */
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int   uint32; 

typedef void SeqList;
typedef void SeqListNode;

typedef uint32 TSeqListNode;
typedef struct
{
	uint16 capacity;
	uint16 len;
	TSeqListNode* node;	
}TSeqList;

/* define list max len  */
#define SEQLIST_MAX_LEN		0xFF00

typedef uint16 SeqListErrRetType;
#define SEQLIST_LIST_NULL	0xFFFF
#define SEQLIST_NODE_NULL	0xFFFE
#define SEQLIST_POS_ERR 	0xFFFD
#define SEQLIST_LIST_FULL   0xFFFC



/* function declare  */
SeqList* SeqList_Create(uint16 capacity);

void SeqList_Destroy(SeqList* list);

SeqListErrRetType SeqList_Clear(SeqList* list);

uint16 SeqList_GetCurLen(SeqList* list);

uint16 SeqList_Capacity(SeqList* list);

SeqListErrRetType SeqList_Insert(SeqList* list, SeqListNode* node, uint16 pos);

SeqListNode* SeqList_Get(SeqList* list, uint16 pos);

SeqListErrRetType SeqList_Delete(SeqList* list, uint16 pos, uint8* node);

 
#endif
