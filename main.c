#include "stdio.h"
#include "stdbool.h"
#include <string.h>

#define TEST_RESULT unsigned int

enum {
    TEST_PASS,
    TEST_FAIL
};

unsigned int numberOfCharacters(const char* string)
{
    unsigned int numCharacters;
    for (size_t i = 0; i < string[i] != '\0'; i++)
    {
        numCharacters++;
    }
    return numCharacters;
}

TEST_RESULT testNumberOfCharacters()
{
    const char* string = "hello";
    TEST_RESULT result;
    if (numberOfCharacters(string) == 5)
    {
        return TEST_PASS;
    } else 
    {
        return TEST_FAIL;
    }
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
    printTestResult("numberOfCharacters", testNumberOfCharacters());
}