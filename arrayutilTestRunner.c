#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_1_array_has_element_size_for_int");
	setup();
		test_1_array_has_element_size_for_int();
	tearDown();
	testEnded();
	testStarted("test_2_array_has_element_size_for_char");
	setup();
		test_2_array_has_element_size_for_char();
	tearDown();
	testEnded();
	testStarted("test_3_array_has_element_size_for_double");
	setup();
		test_3_array_has_element_size_for_double();
	tearDown();
	testEnded();
	testStarted("test_4_array_has_element_size_for_float");
	setup();
		test_4_array_has_element_size_for_float();
	tearDown();
	testEnded();
	testStarted("test_5_array_have_5_elements");
	setup();
		test_5_array_have_5_elements();
	tearDown();
	testEnded();
	testStarted("test_6_structure_has_an_array_of_elements");
	setup();
		test_6_structure_has_an_array_of_elements();
	tearDown();
	testEnded();
	testStarted("test_7_array_elements_should_be_increased");
	setup();
		test_7_array_elements_should_be_increased();
	tearDown();
	testEnded();
	testStarted("test_8_array_elements_should_be_trimed");
	setup();
		test_8_array_elements_should_be_trimed();
	tearDown();
	testEnded();
	testStarted("test_9_array_elements_should_be_increased_with_float");
	setup();
		test_9_array_elements_should_be_increased_with_float();
	tearDown();
	testEnded();
	testStarted("test_10_finds_the_index_of_0_in_array");
	setup();
		test_10_finds_the_index_of_0_in_array();
	tearDown();
	testEnded();
	testStarted("test_11_finds_the_index_of_1_in_array");
	setup();
		test_11_finds_the_index_of_1_in_array();
	tearDown();
	testEnded();
	testStarted("test_12_does_not_find_the_index_of_15_in_array");
	setup();
		test_12_does_not_find_the_index_of_15_in_array();
	tearDown();
	testEnded();
	testStarted("test_13_finds_the_index_of_m_in_array");
	setup();
		test_13_finds_the_index_of_m_in_array();
	tearDown();
	testEnded();
	testStarted("test_14_finds_the_index_of_float_in_array");
	setup();
		test_14_finds_the_index_of_float_in_array();
	tearDown();
	testEnded();
	testStarted("test_15_finds_the_index_of_double_in_array");
	setup();
		test_15_finds_the_index_of_double_in_array();
	tearDown();
	testEnded();
	testStarted("test_16_if_even_number_is_fond_from_frist_it_must_return_that_number");
	setup();
		test_16_if_even_number_is_fond_from_frist_it_must_return_that_number();
	tearDown();
	testEnded();
	testStarted("test_17_if_even_number_is_not_find_from_frist_it_must_return_null");
	setup();
		test_17_if_even_number_is_not_find_from_frist_it_must_return_null();
	tearDown();
	testEnded();
	testStarted("test_18_if_divisible_by_2_from_frist_it_must_return_that_number");
	setup();
		test_18_if_divisible_by_2_from_frist_it_must_return_that_number();
	tearDown();
	testEnded();
	testStarted("test_19_if_not_divisible_by_3_from_frist_it_must_return_null");
	setup();
		test_19_if_not_divisible_by_3_from_frist_it_must_return_null();
	tearDown();
	testEnded();
	testStarted("test_20_if_even_number_is_fond_from_last_it_must_return_that_number");
	setup();
		test_20_if_even_number_is_fond_from_last_it_must_return_that_number();
	tearDown();
	testEnded();
	testStarted("test_21_if_number_is_divisible_by_2_it_must_return_its_value");
	setup();
		test_21_if_number_is_divisible_by_2_it_must_return_its_value();
	tearDown();
	testEnded();
	testStarted("test_22_if_even_number_is_not_found_from_last_it_must_return_null");
	setup();
		test_22_if_even_number_is_not_found_from_last_it_must_return_null();
	tearDown();
	testEnded();
	testStarted("test_23_if_string_is_matched_from_frist_it_must_return_it");
	setup();
		test_23_if_string_is_matched_from_frist_it_must_return_it();
	tearDown();
	testEnded();
	testStarted("test_24_if_string_is_matched_from_frist_it_must_return_it");
	setup();
		test_24_if_string_is_matched_from_frist_it_must_return_it();
	tearDown();
	testEnded();
	testStarted("test_25_counts_even_numbers");
	setup();
		test_25_counts_even_numbers();
	tearDown();
	testEnded();
	testStarted("test_26_counts_no_even_numbers_in_a_collection_of_odds");
	setup();
		test_26_counts_no_even_numbers_in_a_collection_of_odds();
	tearDown();
	testEnded();
	testStarted("test_27_filter_must_return_the_total_numbers_which_matches_the_criteria");
	setup();
		test_27_filter_must_return_the_total_numbers_which_matches_the_criteria();
	tearDown();
	testEnded();
	testStarted("test_28_filter_must_return_the_total_numbers_which_matches_the_criteria");
	setup();
		test_28_filter_must_return_the_total_numbers_which_matches_the_criteria();
	tearDown();
	testEnded();
	testStarted("test_29_filter_must_put_all_matched_element_address_in_array");
	setup();
		test_29_filter_must_put_all_matched_element_address_in_array();
	tearDown();
	testEnded();
	testStarted("test_30_filter_must_return_the_total_strings_which_matches_the_criteria");
	setup();
		test_30_filter_must_return_the_total_strings_which_matches_the_criteria();
	tearDown();
	testEnded();
	testStarted("test_31_filter_must_return_the_total_strings_which_matches_the_criteria");
	setup();
		test_31_filter_must_return_the_total_strings_which_matches_the_criteria();
	tearDown();
	testEnded();
	testStarted("test_32_map_must_multiply_two_to_each_element_of_data");
	setup();
		test_32_map_must_multiply_two_to_each_element_of_data();
	tearDown();
	testEnded();
	testStarted("test_33_map_must_give_each_element_0_if_there_is_nothing_to_multiply");
	setup();
		test_33_map_must_give_each_element_0_if_there_is_nothing_to_multiply();
	tearDown();
	testEnded();
	testStarted("test_35_foreach_must_multiply_two_to_each_element_of_data");
	setup();
		test_35_foreach_must_multiply_two_to_each_element_of_data();
	tearDown();
	testEnded();
	testStarted("test_36_foreach_must_subtract_two_to_each_element_of_data");
	setup();
		test_36_foreach_must_subtract_two_to_each_element_of_data();
	tearDown();
	testEnded();
	testStarted("test_37_foreach_must_add_surname_to_each_name");
	setup();
		test_37_foreach_must_add_surname_to_each_name();
	tearDown();
	testEnded();
	testStarted("test_28_to_find_the_greatest_number_in_float_array_by_reduce_method");
	setup();
		test_28_to_find_the_greatest_number_in_float_array_by_reduce_method();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
