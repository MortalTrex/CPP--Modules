#include "Serializer.hpp"

// Canonical form of Serializer class //

Serializer::Serializer()
{
   
}

Serializer::Serializer(const Serializer &other)
{
    (void)other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
    (void)other;
    return *this;
}

Serializer::~Serializer()
{

}

// Mandatory methods

uintptr_t Serializer::serialize(Data* ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
   return(reinterpret_cast<Data *>(raw));
}
