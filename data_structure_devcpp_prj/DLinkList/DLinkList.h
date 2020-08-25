/* DLinkList.h  */
#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

/*  base type define */
typedef unsigned char 	uint8;
typedef unsigned short 	uint16;
typedef unsigned int	uint32;

/* bidirection link list  */
typedef void DLinkList;
typedef struct _tag_DLinkListNode DLinkListNode;
struct _tag_DLinkListNode
{
	DLinkListNode* pre;
	DLinkListNode* next;	
};

typedef struct
{
	DLinkListNode header;
	uint32 value;
}TDLinkListNode;

typedef struct
{
	DLinkListNode header;
	DLinkListNode* slider;
	uint16 len;
}TDLinkList;


/* function declare  */
DLinkList* TDLinkList_Create(void);

void DLinkList_Destroy(DLinkList* list);

void DLinkList_Clear(DLinkList* list);

uint16 DLinkList_Len(DLinkList* list);

uint16 DLinkList_Insert(DLinkList* list, DLinkListNode* node, uint16 pos);

DLinkListNode* DLinkList_Get(DLinkList* list, uint16 pos);

DLinkListNode* DLinkList_Delete(DLinkList* list, uint16 pos);

DLinkListNode* DLinkList_Reset(DLinkList* list);

DLinkListNode* DLinkList_Current(DLinkList* list);

DLinkListNode* DLinkList_Next(DLinkList* list);

DLinkListNode* DLinkList_Pre(DLinkList* list);




#endif /*  #ifndef _DLINKLIST_H_ */
