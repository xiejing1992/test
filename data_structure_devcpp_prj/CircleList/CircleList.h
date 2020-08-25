/*  CircleList.h  */
#ifndef _CIRCLELIST_H_
#define _CIRCLELIST_H_

/*  define base data type  */
typedef unsigned char	uint8;
typedef unsigned short 	uint16;
typedef unsigned int	uint32;

/* define circle list data type  */
typedef void CircleList;
typedef struct _tag_CirlceListNode CircleListNode;
struct  _tag_CirlceListNode
{
	CircleListNode* next;
};

typedef struct
{
	CircleListNode header;
	uint8 value; 
}TCircleListNode;

typedef struct 
{
	CircleListNode header;
	CircleListNode* slider;
	uint16 len;	
}TCircleList;

/* function declare  */
CircleList* CircleList_Create(void);

void CircleList_Destroy(CircleList* list);

void CircleList_Clear(CircleList* list);

uint16 CircleList_Len(CircleList* list);

uint16 CircleList_Insert(CircleList* list, CircleListNode* node, uint16 pos); 

CircleListNode* CircleList_Get(CircleList* list, uint16 pos);

CircleListNode* CircleList_Delete(CircleList* list, uint16 pos);

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node);

CircleListNode* CircleList_Reset(CircleList* list);

CircleListNode* CircleList_Current(CircleList* list);

CircleListNode* CircleList_Next(CircleList* list);



#endif /* #ifndef _CIRCLELIST_H_  */
