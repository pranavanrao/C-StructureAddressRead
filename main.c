#include <stdio.h>
#include <stdbool.h>

struct MyStruct
{
    int a;
    float b;
    double c;
    char d;
    bool e;
};

int main()
{
    struct MyStruct str;

    str.a = 10;
    str.b = 3.1f;
    str.c = 3.14159;
    str.d = 'a';
    str.e = true;

    printf("a : %d\n", str.a);
    printf("b : %f\n", str.b);
    printf("c : %lf\n", str.c);
    printf("d : %c\n", str.d);
    printf("e : %s\n\n", str.e ? "true" : "flase");

    int* intPtr = &str.a;
    float* floatPtr = &str.b;
    double* doublePtr = &str.c;
    char* charPtr = &str.d;
    bool* boolPtr = &str.e;

    printf("Address of a : %d\n", &intPtr);
    printf("Address of b : %d\n", &floatPtr);
    printf("Address of c : %d\n", &doublePtr);
    printf("Address of d : %d\n", &charPtr);
    printf("Address of e : %d\n\n", &boolPtr);

    char* strPtr = (char*)(&str);
    printf("Address of structure : %d\n", &strPtr);

    size_t size = sizeof(struct MyStruct);

    for (size_t i = 0; i < size; i++) {
        printf("Byte %zu: %02X\n", i, (unsigned char)strPtr[i]);
    }

    return 0;
}
