#include <stdio.h>

int testCount=0;
int passCount=0;

void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();

void testStarted(char* name){
	printf("\t%s\n",name);
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests , passed:-  %d ,  failed :-  %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber){
	printf("\t\t*** failed at %s:%d\n",fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	setup();
		test_1_array_has_element_size_for_int();
	tearDown();

	setup();
		test_2_array_has_element_size_for_char();
	tearDown();

	setup();
		test_3_array_has_element_size_for_double();
	tearDown();

	setup();
		test_4_array_has_element_size_for_float();
	tearDown();

	setup();
		test_5_array_have_5_elements();
	tearDown();

	setup();
		test_6_structure_has_an_array_of_elements();
	tearDown();

	setup();
		test_7_array_elements_should_be_increased();
	tearDown();

	setup();
		test_8_array_elements_should_be_trimed();
	tearDown();

	setup();
		test_9_array_elements_should_be_increased_with_float();
	tearDown();

	setup();
		test_10_finds_the_index_of_0_in_array();
	tearDown();

	setup();
		test_11_finds_the_index_of_1_in_array();
	tearDown();

	setup();
		test_12_does_not_find_the_index_of_15_in_array();
	tearDown();

	setup();
		test_13_finds_the_index_of_m_in_array();
	tearDown();

	setup();
		test_14_finds_the_index_of_float_in_array();
	tearDown();

	setup();
		test_15_finds_the_index_of_double_in_array();
	tearDown();

	setup();
		test_16_if_even_number_is_fond_from_frist_it_must_return_that_number();
	tearDown();

	setup();
		test_17_if_even_number_is_not_find_from_frist_it_must_return_null();
	tearDown();

	setup();
		test_18_if_divisible_by_2_from_frist_it_must_return_that_number();
	tearDown();

	setup();
		test_19_if_not_divisible_by_3_from_frist_it_must_return_null();
	tearDown();

	setup();
		test_20_if_even_number_is_fond_from_last_it_must_return_that_number();
	tearDown();

	setup();
		test_21_if_number_is_divisible_by_2_it_must_return_its_value();
	tearDown();

	setup();
		test_22_if_even_number_is_not_found_from_last_it_must_return_null();
	tearDown();

	setup();
		test_23_if_string_is_matched_from_frist_it_must_return_it();
	tearDown();

	setup();
		test_24_if_string_is_matched_from_frist_it_must_return_it();
	tearDown();

	setup();
		test_25_counts_even_numbers();
	tearDown();

	setup();
		test_26_counts_no_even_numbers_in_a_collection_of_odds();
	tearDown();

	setup();
		test_27_filter_must_return_the_total_numbers_which_matches_the_criteria();
	tearDown();

	setup();
		test_28_filter_must_return_the_total_numbers_which_matches_the_criteria();
	tearDown();

	setup();
		test_29_filter_must_put_all_matched_element_address_in_array();
	tearDown();

	setup();
		test_30_filter_must_return_the_total_strings_which_matches_the_criteria();
	tearDown();

	setup();
		test_31_filter_must_return_the_total_strings_which_matches_the_criteria();
	tearDown();

	setup();
		test_32_map_must_multiply_two_to_each_element_of_data();
	tearDown();

	setup();
		test_33_map_must_not_multiply_if_there_is_nothing_to_multiply();
	tearDown();


	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
