/*  LinkList.h */
#ifndef _LINKLIST_H_
#define  _LINKLIST_H_

/*  general type */
typedef unsigned char	uint8;
typedef unsigned short	uint16;
typedef unsigned int	uint32;

/* LinkList type  */
typedef void LinkList;

typedef struct _tag_LinkListNode LinkListNode;
struct _tag_LinkListNode
{
	LinkListNode* next;
};

typedef struct
{
	LinkListNode header;
	uint32 value;
}TLinkListNode;

typedef struct
{
	LinkListNode header;
	uint16 len;	
}TLinkList;


/* function declare  */
LinkList* LinkList_Create(void);

void LinkList_Destroy(LinkList* list);

void LinkList_Clear(LinkList* list);

uint16 LinkList_Length(LinkList* list); 

uint16 LinkList_Insert(LinkList* list, LinkListNode* node, uint16 pos);

LinkListNode* LinkList_Get(LinkList* list, uint16 pos);

LinkListNode* LinkList_Delete(LinkList* list, uint16 pos);

#endif
