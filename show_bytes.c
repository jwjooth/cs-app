#include <stdio.h>

// fungsi untuk mencetak byte memory dalam format hexadecimal
void print_bytes(unsigned char *start, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf("%.2x", start[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int integer_val = 12345;
    float float_val = 12345.0f;
    char string_val[] = "hello";

    printf("representation of int 12345 (4 bytes):");
    print_bytes((unsigned char *)&integer_val, sizeof(integer_val));

    printf("representation of float 12345.0f (4 bytes):");
    print_bytes((unsigned char *)&float_val, sizeof(float_val));

    printf("representation of string hello (6 bytes):");
    print_bytes((unsigned char *)&string_val, sizeof(string_val));

    return 0;
}
