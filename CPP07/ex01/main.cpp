#include "iter.hpp"

class awesome
{    
    private:
        int _n;
    public:
        awesome(): _n(42) {
            return;
        }
        ~awesome() {
        }
        
        int get() const {
            return _n;
        }
};

std::ostream &operator<<(std::ostream &o, awesome const& rhs) {
    return o << rhs.get();
    
}

template<typename T>

void print(T const& x) {
    std::cout << x << std::endl;
    return;
}


int main() {
    int tab[] = {0, 1, 2, 3, 4};
    awesome tab2[5];
    
    iter(tab, 5, print<int>);
    iter(tab2, 5, print<awesome>);

    return 0;
}
