#include <check.h>
#include "../src/subtractives.h"

//since these tests will look really familiar to the grouping tests, I will start htem off as a loop test
//some of this is duplciated from grouping tests but, following the "Rule of 3",
//I won't merge the code until I have 3 instances of it so I know for sure its actual duplication.
typedef struct  {
 char* input;
 char* expected;
} InputExpectedPair;

const InputExpectedPair substitute_out_scenarios[] = {
  {"IV", "IIII"},
  {"IX", "VIIII"},
  {"XL", "XXXX"},
  {"XC", "LXXXX"},
  {"CD", "CCCC"},
  {"CM", "DCCCC"},
  {"IVIV", "IIIIIIII"}
};

START_TEST(substitutes_out_properly)
{
  char buffer[4096];
  strcpy(buffer, substitute_out_scenarios[_i].input);
  substitute_out_subtractives(buffer);
  ck_assert_str_eq(substitute_out_scenarios[_i].expected, buffer);
}
END_TEST


const InputExpectedPair substitute_in_scenarios[] = {
 {"IIII", "IV"},
 {"VIIII", "IX"},
 {"XXXX", "XL"},
 {"LXXXX", "XC"},
 {"CCCC", "CD"},
 {"DCCCC", "CM"},
 {"DCCCCCCCC", "CMCD"}
};

START_TEST(substitutes_in_properly)
{
  char buffer[4096];
  strcpy(buffer, substitute_in_scenarios[_i].input);
  substitute_in_subtractives(buffer);
  ck_assert_str_eq(substitute_in_scenarios[_i].expected, buffer);
}
END_TEST

TCase* subtractive_tests(void)
{
  TCase* subtractives = tcase_create("subtractives out");
  size_t input_expected_len = sizeof(InputExpectedPair);
  tcase_add_loop_test(subtractives, substitutes_out_properly, 0, sizeof(substitute_out_scenarios)/input_expected_len);
  tcase_add_loop_test(subtractives, substitutes_in_properly, 0, sizeof(substitute_in_scenarios)/input_expected_len);
  return subtractives;
}


