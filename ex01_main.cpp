#include "Data.hpp"
#include <stdint.h>
#include <iostream>
#include <iomanip>

// ! Serialization: take your data structure and "flatten it out" to a stream of bits. Then sending it over. 
// ? JSON, YAML, XML, markup language...
// ! Deserialization: take the stream of bits then reconstruct it to the original data structure.

// ? why: deep copy, write data structure to a file, sending information...

// ! reinterpret_cast: convert 1) pointer of a data type to a pointer of other type. 2) From pointer of one class to other unrelated class (unsafe). Or 3)integral to any pointer type.
// reinterpret_cast<new_type>(expression);

uintptr_t serialize(Data* ptr) 
{
    return (reinterpret_cast<uintptr_t>(ptr)); // ! Doc nguoc: convert pointer to int
}

Data* deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw)); // ! Doc nguoc: convert int to pointer
}

std::ostream&   operator<<(std::ostream&    COUT, const Data& data)
{
    std::cout << data.getName() << ", Age: " << data.getAge();
    return (COUT);
}

int main(void)
{
    {
        Data		*data_ptr = new Data(42, "Harry Potter");
        uintptr_t	ptr = serialize(data_ptr);
        Data		*data_received = deserialize(ptr);

        std::cout << "Data address: " << data_ptr << " -- Value: " << data_ptr << std::endl;
        std::cout << "Serialized value (base 10): " << ptr << " -- base(16): " << std::setbase(16) << ptr << std::setbase(10) << std::endl;
		std::cout << "Information before: " << *data_ptr << std::endl;
        std::cout << "Data deserialized address: " << data_received << " -- Value: " << data_received << std::endl;
		std::cout << "Information after: " << *data_received << std::endl;
        delete data_ptr;
    }
}
