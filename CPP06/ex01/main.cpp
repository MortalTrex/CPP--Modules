#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data original;
    uintptr_t raw;

    //Proof it's not instantiated
    // Serializer serializer;
    // Serializer test2(serializer);
    // serializer = test2;

    original.value = 57;
    original.fvalue = 57.5f;
    original.dvalue = 51;
    original.word = "Hello"; 

    raw = Serializer::serialize(&original);
    Data *test = Serializer::deserialize(raw);

    std::cout << test->value << std::endl;
    std::cout << test->fvalue << std::endl;
    std::cout << test->dvalue << std::endl;
    std::cout << test->word << std::endl;
}