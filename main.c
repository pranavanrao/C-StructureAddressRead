#include "MyStruct.h"

#include <stdio.h>

int main()
{
    struct MyStruct str;

    str.m_character = 'a';
    str.m_integer = 10;
    str.m_double = 3.141597;
    str.m_floating = 3.141;
    str.m_boolean = true;

    printf("Direct access of the structure members : ");
    printf("a : %c\n", str.m_character);
    printf("b : %d\n", str.m_integer);
    printf("c : %f\n", str.m_floating);
    printf("d : %lf\n", str.m_double);
    printf("e : %s\n\n", str.m_boolean ? "true" : "flase");

    char* charPtr = &str.m_character;
    int* intPtr = &str.m_integer;
    float* floatPtr = &str.m_floating;
    double* doublePtr = &str.m_double;
    bool* boolPtr = &str.m_boolean;

    printf("Address of a : %d\n", &intPtr);
    printf("Address of b : %d\n", &floatPtr);
    printf("Address of c : %d\n", &doublePtr);
    printf("Address of d : %d\n", &charPtr);
    printf("Address of e : %d\n\n", &boolPtr);

    char* strPtr = (char*)(&str);
    printf("Address of structure : %d\n", &strPtr);

    size_t size = sizeof(struct MyStruct);

    printf("Size of the structure : %d\n", size);

    for (size_t i = 0; i < size; i++) {
        printf("Byte %zu: %02X ", i, (unsigned char)strPtr[i]);

        // Determine the type of the current byte
        if (strPtr + i >= (char*)&str.m_character && strPtr + i < (char*)&str.m_character + sizeof(str.m_character)) {
            printf("(char)\n");
        } else if (strPtr + i >= (char*)&str.m_integer && strPtr + i < (char*)&str.m_integer + sizeof(str.m_integer)) {
            printf("(int)\n");
        } else if (strPtr + i >= (char*)&str.m_double && strPtr + i < (char*)&str.m_double + sizeof(str.m_double)) {
            printf("(double)\n");
        } else if (strPtr + i >= (char*)&str.m_floating && strPtr + i < (char*)&str.m_floating + sizeof(str.m_floating)) {
            printf("(float)\n");
        } else if (strPtr + i >= (char*)&str.m_boolean && strPtr + i < (char*)&str.m_boolean + sizeof(str.m_boolean)) {
            printf("(bool)\n");
        } else {
            printf("(unknown)\n");
        }
    }

    return 0;
}
