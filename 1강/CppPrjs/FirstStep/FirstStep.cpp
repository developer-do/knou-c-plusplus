/* #include <iostream>

int main()
{
    // ǥ�� ��� ��Ʈ������ ������ �����
    std::cout << "���� ù ���� C++���α׷�" << std::endl;
    return 0;
} */

/* #include <iostream>

namespace myNSp1 { int n = 10; }
namespace myNSp2 { int n = 20; }
int n = 30;

int main()
{
    int n = 40;
    std::cout << myNSp1::n << std::endl;
    std::cout << myNSp2::n << std::endl;
    std::cout << ::n << std::endl; 
    std::cout << n << std::endl;
    return 0;
}
*/


/* #include <iostream>
using namespace std;
namespace myNSp1 { int n = 10; }
namespace myNSp2 { int n = 20; }
int n = 30;

int main()
{
    int n = 40;
    cout << myNSp1::n << endl;
    cout << myNSp2::n << endl;
    cout << ::n << endl;
    cout << n << endl;
    return 0;

}*/


using namespace::std;
#include <iostream>

int main()
{
    // ǥ�� ��� ��Ʈ������ ������ ����� <- �ּ�
    std::cout << "���� ù ���� C++���α׷�" << std::endl;
        return 0;
}
