/* Stack.h */
#ifndef _STACK_H_
#define _STACK_H_

/*  define base type  */
typedef unsigned char	uint8;
typedef unsigned short	uint16;
typedef unsigned int 	uint32;

/*  define stack type */
typedef void Stack;
typedef struct _tag_StackElement StackElement;
struct _tag_StackElement
{
	StackElement* next;
	StackElement* pre;
};
typedef struct
{
	StackElement  header;
	uint32 value;
}TElement;

typedef struct
{
	StackElement header;
	StackElement* top;
	uint16 size;
}TStack;

/* declare function  */

Stack* Stack_Create(void);

void Stack_Destroy(Stack* stack);

void Stack_Clear(Stack* stack);

StackElement* Stack_Push(Stack* stack, StackElement* element);

StackElement* Stack_Pop(Stack* stack);

StackElement* Stack_GetTop(Stack* stack);

uint16 Stack_GetSize(Stack* stack);

#endif /* #ifndef _STACK_H_  */
