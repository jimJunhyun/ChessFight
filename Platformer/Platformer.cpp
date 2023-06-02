#include <iostream>
#include "Core.h"

using namespace std;

int main()
{
    if (!(Core::GetInstance())->Init()) {
        cout << "초기화 실패";
        return -1;
    }
    (Core::GetInstance())->Run();

    return 0;
}
