#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int MatchFunc(void*, void*);
typedef void ConvertFunc(void*,void*,void*);
typedef void OperationFunc(void*,void*);
typedef char string[256];
typedef struct{
	void *base;
	int typeSize;
	int length;
}ArrayUtil;

ArrayUtil create(int elementSize,int elements);
ArrayUtil resize(ArrayUtil util,int elements);
int findIndex(ArrayUtil util, void* element);
void dispose(ArrayUtil util);
void* findFirst(ArrayUtil util,MatchFunc* match,void* hint);
void* findLast(ArrayUtil util,MatchFunc* match,void* hint);
int count(ArrayUtil util, MatchFunc* match, void* hint);
int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems );
void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint);
void forEach(ArrayUtil util, OperationFunc* operation, void* hint);