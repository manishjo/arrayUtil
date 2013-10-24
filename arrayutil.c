#include "arrayutil.h"

ArrayUtil create(int elementSize,int elements){
	ArrayUtil util;
	void *data=calloc(elements, sizeof(elementSize));
	util.base=data;
	util.typeSize=elementSize;
	util.length=elements;
	return util;
}

ArrayUtil resize(ArrayUtil util,int elements){
	int oldSize = util.typeSize*util.length;
	int newSize = util.typeSize*elements;
	int difference = newSize - oldSize;
	util.base=realloc(util.base,newSize);
	if(difference>0)
		memset(util.base+oldSize,0,difference);
	util.length=elements;
	return util;
}

int findIndex(ArrayUtil util, void* element){
	int i;
	for(i=0;i<util.length*util.typeSize;i=i+util.typeSize){
		if(0==memcmp(util.base+i*util.typeSize,element,util.typeSize)){
			return i;
		}
	}
	return -1;
}

void dispose(ArrayUtil util){
	free(util.base);
}

int lessThan(int item,int limit){
	return limit > item;
}

int greaterThan(int item,int limit){
	return limit < item;
}

typedef int predict(int item,int limit);
typedef struct{
	int start;
	predict* test;
	int end;
	int step;
}LOOP;

void* find(LOOP loop,ArrayUtil util, MatchFunc match, void* hint){
	int index = 0;
	for(index = loop.start ; loop.test(index,loop.end) ; index += loop.step){
		if(match(hint,util.base+(index * util.typeSize)))
			return util.base+(index * util.typeSize);
	}
	return NULL;
}

void* findFirst(ArrayUtil util, MatchFunc match, void* hint){
	LOOP loop = {0,lessThan,util.length,1};
	return find(loop,util,match,hint);
}

void* findLast(ArrayUtil util, MatchFunc match, void* hint){
	LOOP loop = {util.length-1,greaterThan,-1,-1};
	return find(loop,util,match,hint);
}

int count(ArrayUtil util, MatchFunc match, void* hint){
	int index = 0,count=0;
	for(index = 0 ; index < util.length ; index ++)
		count += match(hint,util.base+(index * util.typeSize));
	return count;
}

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
 	int i,count=0,upto=util.length*util.typeSize;
	void *p;	
	for(i=0;(i<upto && count < maxItems);i=i+util.typeSize){
		p=util.base+i;			
		if(match(hint,p)==1){			
			destination[count]=p;
			count=count+1;
		}
	}	
	return count;
}

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
	int index;
	for(index = 0 ; index < source.length ; index ++)
		convert(hint,source.base+(index * source.typeSize),destination.base+(index * destination.typeSize));
}



