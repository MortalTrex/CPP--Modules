#include "MutantStack.hpp"

int main()
{
    /// Main Test for MutantStack
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "top : " << mstack.top() << std::endl;
    std::cout << "size before pop : " << mstack.size() << std::endl;
    mstack.pop();
    std::cout << "size after pop : " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // Check no mumber function
    std::stack<int> s(mstack);
    //it = s.begin();

    std::cout << "----------------" << std::endl;
    // Check reverse
    MutantStack<int> s2(mstack);
    MutantStack<int>::reverse_iterator rit = s2.rbegin();
    MutantStack<int>::reverse_iterator rite = s2.rend();

    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    s2 = mstack;

    std::cout << "----------------" << std::endl;
    // Test with string
    MutantStack<std::string> mstackStr;
    mstackStr.push("Hello");
    mstackStr.push("World");
    mstackStr.push("!");

    const MutantStack<std::string>::iterator cit = mstackStr.begin();

    std::cout << *cit << std::endl;

    // Remplace with std::list to compare result

    std::cout << "----------------" << std::endl;

    std::list<int> list;

    list.push_back(5);
    list.push_back(17);

    std::cout << "top : " << list.back() << std::endl;
    std::cout << "size before pop : " << list.size() << std::endl;
    list.pop_back();
    std::cout << "size after pop : " << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    std::list<int>::iterator lit = list.begin();
    std::list<int>::iterator lite = list.end();

    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    return 0;
}