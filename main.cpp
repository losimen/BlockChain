#include <iostream>
#include <map>

int main()
{

    time_t now = time(nullptr);
    char* dt = ctime(&now);

    std::cout << dt << std::endl;

    return 0;
}
