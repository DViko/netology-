#include <iostream>
#include <cstdlib>
#include <cstring>

char*   ReadValue(char*& value, const char* message);
char*   TryAllocMemory(size_t capacity);
char*   TryReallocMemory(char* old_pointer, size_t new_capacity);
char*   ConstructString(const char* first_name, const char* last_name, const char* message);
char*   ClearMemory(char* pointer);

int main()
{
    char* first_name { nullptr }, * last_name { nullptr };

    char messages [3][24]
    {
        "Insert your name: ",
        "Insert your surname: ",
        "Hello "
    };

    if (ReadValue(first_name, messages[0]) && ReadValue(last_name, messages[1]))
    {
        char* output { ConstructString(first_name, last_name, messages[2]) };

        std::cout << output << std::endl;

        ClearMemory(first_name);
        ClearMemory(last_name);
        ClearMemory(output);

        return EXIT_SUCCESS;
    }

    std::cout << "Memory error \n";

    return EXIT_FAILURE;
}

char* ReadValue(char*& value, const char* message)
{
    size_t capacity { 1 }, length { 0 };
    char buffer;
    char* new_pointer { nullptr };

    value = TryAllocMemory(capacity);

    if (!value)
    {
        return ClearMemory(value);
    }

    std::cout << message;

    while (std::cin.get(buffer) && buffer != '\n')
    {
        if (length + 1 >= capacity)
        {
            capacity *= 2;

            new_pointer = TryReallocMemory(value, capacity);

            if (!new_pointer)
            {
                return ClearMemory(value);
            }

            value = new_pointer;
        }

        value[length ++] = buffer;
    }

    value[length] = '\0';
    return value;
}

char* TryAllocMemory(size_t capacity)
{
    return (char*)malloc(capacity);
}

char* TryReallocMemory(char* pointer, size_t capacity)
{
    return (char*)realloc(pointer, capacity);
}

char* ConstructString(const char* first_name, const char* last_name, const char* message)
{
    size_t total = std::strlen(first_name) + std::strlen(last_name) + 10;

    char* full_name { TryAllocMemory(total) };

    std::strcpy(full_name, message);
    std::strcat(full_name, first_name);
    std::strcat(full_name, " ");
    std::strcat(full_name, last_name);

    return full_name;
}

char* ClearMemory(char* value)
{
    if (value)
    {
        free(value);
        value = nullptr;
    }

    return value;
}