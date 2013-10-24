#include "testUtils.h"
#include "arrayutil.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

ArrayUtil actual;
ArrayUtil util;


void tearDown(){
	free(util.base);
}

void test_1_array_has_element_size_for_int(){
	actual = create(sizeof(int),5);
	ASSERT(4==actual.typeSize);
}

void test_2_array_has_element_size_for_char(){
	actual = create(sizeof(char),5);
	ASSERT(1==actual.typeSize);
}

void test_3_array_has_element_size_for_double(){
	actual = create(sizeof(double),5);
	ASSERT(8==actual.typeSize);
}

void test_4_array_has_element_size_for_float(){
	actual = create(sizeof(float),5);
	ASSERT(4==actual.typeSize);
}

void test_5_array_have_5_elements(){
	actual = create(sizeof(int),5);
	ASSERT(5==actual.length);
}

void test_6_structure_has_an_array_of_elements(){
	int *arr;
	util = create(sizeof(int),5);
	arr=(int*)util.base;
	arr[0]=0;
	ASSERT(arr[0]==0);
}

void test_7_array_elements_should_be_increased(){
	util = create(sizeof(int),5);
	actual = resize(util ,10);
	ASSERT(10==actual.length);
}

void test_8_array_elements_should_be_trimed(){
	util = create(sizeof(int),5);
	actual = resize(util ,2);
	ASSERT(2==actual.length);
}

void test_9_array_elements_should_be_increased_with_float(){
	util = create(sizeof(float),5);
	actual = resize(util ,8);
	ASSERT(8==actual.length);
}

void test_10_finds_the_index_of_0_in_array(){
	int element=0,index;
	int* pItem = (int*)util.base;
	util = create(sizeof(int),5);
	pItem[0] = element;
 	index = findIndex(util,&element);
	ASSERT(index==0);
}

void test_11_finds_the_index_of_1_in_array(){
	int element=1,index;
	int* pItem = (int*)util.base;
	util = create(sizeof(int),5);
	pItem[4] = element;
 	index = findIndex(util,&element);
	ASSERT(index == 4);
}

void test_12_does_not_find_the_index_of_15_in_array(){
	int element=9,index;
	int* pItem = (int*)util.base;
	util = create(sizeof(int),5);
 	index = findIndex(util,&element);
	ASSERT(index == -1);
}

void test_13_finds_the_index_of_m_in_array(){
	char element='m';
	int index;
	char* pItem = (char*)util.base;
	util = create(sizeof(char),5);
	pItem[3] = element;
 	index = findIndex(util,&element);
	ASSERT(index == 3);
}

void test_14_finds_the_index_of_float_in_array(){
	float element=3.2;
	int index;
	util = create(sizeof(float),5);
	(*(float*)util.base)=element;
 	index = findIndex(util,&element);
	ASSERT(index == 0);
}

void test_15_finds_the_index_of_double_in_array(){
	double element=5.25;
	int index;
	util = create(sizeof(double),5);
	(*(double*)util.base)=element;
 	index = findIndex(util,&element);
	ASSERT(index == 0);
}

int isEven(void* hint,void *item){
	int number=*(int *)item;
	if(number%2==0)
		return 1;
	return 0;
	}

int isDivisible(void* hint,void *item){
	int dividend=*(int *)item;
	int divisor=*(int *)hint;
	if(dividend%divisor==0)
		return 1;
	return 0;
	}

int isMatched(void* hint,void *item){
	string *first,*second;
	first = (string*)item;
	second = (string*)hint;

	if(strcmp(*first,*second)==0)
		return 1;
	return 0;
}

void test_16_if_even_number_is_fond_from_frist_it_must_return_that_number(){
	int *ans;
	int* pItem;
	int i;
	util = create(sizeof(int),5);
	pItem = (int*)util.base;
	for(i=0;i<util.length;i++)
		pItem[i]=i+1;
	ans=findFirst(util,isEven,NULL);
	ASSERT(*ans==2);
}

void test_17_if_even_number_is_not_find_from_frist_it_must_return_null(){
	int *ans;
	int* pItem;
	util = create(sizeof(int),2);
	pItem = (int*)util.base;
	pItem[0]=3;pItem[1]=5;
	ans=findFirst(util,isEven,NULL);
	ASSERT(ans==NULL);
}

void test_18_if_divisible_by_2_from_frist_it_must_return_that_number(){
	int *ans,*pItem;
	int hint=2;
	util = create(sizeof(int),2);
	pItem = (int*)util.base;
	pItem[0]=3;pItem[1]=6;
	ans=findFirst(util,isDivisible,&hint);
	ASSERT(*ans==6);
}

void test_19_if_not_divisible_by_3_from_frist_it_must_return_null(){
	int *ans,*pItem;
	int hint=3;
	util = create(sizeof(int),2);
	pItem = (int*)util.base;
	pItem[0]=1;pItem[1]=5;
	ans=findFirst(util,isDivisible,&hint);
	ASSERT(ans==NULL);
}

void test_20_if_even_number_is_fond_from_last_it_must_return_that_number(){
	int *ans;
	int *pItem;
	util = create(sizeof(int),2);
	pItem = (int*)util.base;
	pItem[0]=6;pItem[1]=4;
	ans=findLast(util,isEven,NULL);
	ASSERT(*ans==4);
}

void test_21_if_number_is_divisible_by_2_it_must_return_its_value(){
	int *ans,*pItem;
	int hint=2;
	util = create(sizeof(int),2);
	pItem = (int*)util.base;
	pItem[0]=8;pItem[1]=11;
	ans=findLast(util,isEven,&hint);
	ASSERT(*ans==8);
}

void test_22_if_even_number_is_not_found_from_last_it_must_return_null(){
	int *ans;
	int *pItem;
	util = create(sizeof(int),2);
	pItem = (int*)util.base;
	pItem[0]=5;pItem[1]=11;
	ans=findLast(util,isEven,NULL);
	ASSERT(ans==NULL);
}

int stringCompare(char* ans,string hint){
	return strcmp(*(string*)ans,hint);
}

void test_23_if_string_is_matched_from_frist_it_must_return_it(){
	char *ans;
	int compare;
	string hint="manish",*pItem;
	util = create(sizeof(string),2);
	pItem = (string*)util.base;
	strcpy(pItem[0],"manish");
	strcpy(pItem[1],"yogesh");
	ans=findLast(util,isMatched,&hint);
	compare=stringCompare(ans,hint);
	ASSERT(compare==0);
}

void test_24_if_string_is_matched_from_frist_it_must_return_it(){
	char *ans;
	int compare;
	string hint="yogesh",*pItem;
	util = create(sizeof(string),2);
	pItem = (string*)util.base;
	strcpy(pItem[0],"manish");
	strcpy(pItem[1],"yogesh");
	ans=findFirst(util,isMatched,&hint);
	compare=stringCompare(ans,hint);
	ASSERT(compare==0);
}

void test_25_counts_even_numbers(){
	int ans;
	int* pItem;
	util = create(sizeof(int),4);
	pItem = (int*)util.base;
	pItem[0]=4;pItem[1]=6;pItem[2]=1;pItem[3]=2;
	ans=count(util,isEven,NULL);
	ASSERT(ans==3);
}

void test_26_counts_no_even_numbers_in_a_collection_of_odds(){
	int ans;
	int* pItem;
	util = create(sizeof(int),2);
	pItem = (int*)util.base;
	pItem[0]=1;pItem[1]=9;
	ans=count(util,isEven,NULL);
	ASSERT(ans==0);
}

void test_27_filter_must_return_the_total_numbers_which_matches_the_criteria(){
	int ans,hint=2;
	int* pItem;
	void* chootaArray[3];
	util = create(sizeof(int),4);
	pItem= (int*)util.base;
	pItem[0]=4;pItem[1]=8;pItem[2]=1;pItem[3]=6;
	ans=filter(util,isDivisible,&hint,chootaArray,3);
	ASSERT(ans==3);
}

void test_28_filter_must_return_the_total_numbers_which_matches_the_criteria(){
	int ans,hint=2;
	int* pItem;
	void* chootaArray[4];
	util = create(sizeof(int),5);
	pItem= (int*)util.base;
	pItem[0]=4;pItem[1]=8;pItem[2]=1;pItem[3]=6;pItem[4]=10;
	ans=filter(util,isDivisible,&hint,chootaArray,4);
	ASSERT(ans==4);
}

void test_29_filter_must_put_all_matched_element_address_in_array(){
	int ans,hint=2,sum=0;
	int* pItem;
	void* chootaArray[4];
	util = create(sizeof(int),5);
	pItem= (int*)util.base;
	pItem[0]=4;pItem[1]=8;pItem[2]=1;pItem[3]=6;pItem[4]=10;
	ans=filter(util,isDivisible,&hint,chootaArray,4);
	for(ans=0;ans<4;ans++){
		sum+=*(int*)chootaArray[ans];
	}
	ASSERT(sum==28);
}

void test_30_filter_must_return_the_total_strings_which_matches_the_criteria(){
	int compare,ans;
	string hint="yogesh",*pItem;
	void* chootaArray[3];
	util = create(sizeof(string),3);
	pItem= (string*)util.base;
	strcpy(pItem[0],"manish");
	strcpy(pItem[1],"yogesh");
	strcpy(pItem[2],"prateek");
	ans=filter(util,isMatched,&hint,chootaArray,4);
	compare=stringCompare(chootaArray[0],hint);
	ASSERT(compare==0);
}

void test_31_filter_must_return_the_total_strings_which_matches_the_criteria(){
	int ans;
	string hint="yogesh",*pItem;
	void* chootaArray[3];
	util = create(sizeof(string),3);
	pItem= (string*)util.base;
	strcpy(pItem[0],"manish");
	strcpy(pItem[1],"yogesh");
	strcpy(pItem[2],"manish");
	ans=filter(util,isMatched,&hint,chootaArray,4);
	ASSERT(ans==1);
}

void multiplyFrom(void* hint, void* sourceItem, void* destinationItem){
	int multiplyer=*(int*)hint;
	int source=*(int*)sourceItem;
	int *dstptr=destinationItem;
	*dstptr=source*multiplyer;
}

void test_32_map_must_multiply_two_to_each_element_of_data(){
	int i,*ptrsrc,hint=2,*ptrdst;
	ArrayUtil destination = create(sizeof(int), 5);
	ptrdst=(int*)destination.base;
	util=create(sizeof(int),5);
	ptrsrc=(int*)util.base;
	for(i=0;i<5;i++){
		ptrsrc[i]=i+1;
	}
	map(util,destination,multiplyFrom,&hint);
	ASSERT(ptrdst[0]==2);
	ASSERT(ptrdst[1]==4);
	ASSERT(ptrdst[2]==6);

}

void test_33_map_must_not_multiply_if_there_is_nothing_to_multiply(){
	int i,*ptrsrc,hint=0,*ptrdst;
	ArrayUtil destination = create(sizeof(int), 5);
	ptrdst=(int*)destination.base;
	util=create(sizeof(int),5);
	ptrsrc=(int*)util.base;
	for(i=0;i<5;i++){
		ptrsrc[i]=i+1;
	}
	map(util,destination,multiplyFrom,&hint);
	ASSERT(ptrdst[0]==0);
	ASSERT(ptrdst[1]==0);
	ASSERT(ptrdst[2]==0);
}


