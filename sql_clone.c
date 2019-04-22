#include <stdio.h>
#include <stdlib.h>

// solves ssize_t not being recognized in windows
#if defined(_MSC_VER)
#include <BaseTsd.h>
    typedef SSIZE_T ssize_t;
#endif

#define true 1
#define false 0

struct InputBuffer {
    char* buffer;
    // returns a size in bytes (unsigned type)
    size_t buffer_length;
    // can return a size in bytes or a negative error value (signed type)
    ssize_t input_length;
};

// struct constructor
struct InputBuffer* new_input_buffer()
{
    struct InputBuffer* input_buffer = malloc(sizeof(struct InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;

    // returns a pointer
    return input_buffer;
}

void print_prompt()
{
    printf("db> ");
}

void read_input(struct InputBuffer* input_buffer)
{
}

int main()
{
    struct InputBuffer* input_buffer = new_input_buffer();
    while(true)
    {
        print_prompt();
        read_input(input_buffer);
    }
}