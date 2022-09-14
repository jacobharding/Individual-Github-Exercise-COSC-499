#include "stdio.h"
#include "stdbool.h"
#include <string.h>

#define TEST_RESULT unsigned int

enum {
    TEST_PASS,
    TEST_FAIL
};

bool containsSubstring(const char* string, const char* substring)
{
    for (size_t i = 0; string[i] != '\0'; i++)
    {
        bool matchesSubstring = true;
        for (size_t j = 0; j < strlen(substring); j++)
        {
            if (string[i+j] != substring[j])
            {
                matchesSubstring = false;
                break;
            }
        }
        if (matchesSubstring)
        {
            return true;
        }
    }
    return false;
}

TEST_RESULT testContainsSubstring()
{
    const char* testString1    = "Hello World";
    const char* testSubstring1 = "or";
    TEST_RESULT test1Result;

    const char* testString2    = "abCDefGH";
    const char* testSubstring2 = "aC";
    TEST_RESULT test2Result;

    if (containsSubstring(testString1, testSubstring1))
    {
        test1Result = TEST_PASS;
    } else 
    {
        test1Result = TEST_FAIL;
    }

    if (containsSubstring(testString2, testSubstring2))
    {
        test2Result = TEST_FAIL;
    } else 
    {
        test2Result = TEST_PASS;
    }

    return test1Result && test2Result;
}

void printTestResult(const char* functionName, TEST_RESULT result)
{
    if (result == TEST_PASS)
    {
        printf("%s: PASS\n", functionName);
    } else {
        printf("%s: FAIL\n", functionName);
    }
}


int main(int argc, char** argv)
{
    printf("'Hello World contains 'or': %d\n", containsSubstring("Hello World", "or"));
    printf("Number of character in 'Hello': %d\n", numberOfCharacters("Hello"));
    // Test cases
    printTestResult("containsSubstring", testContainsSubstring());
    printTestResult("numberOfCharacters", testNumberOfCharacters());
    return 0;
}