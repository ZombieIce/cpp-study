#include <iostream>
import A;

using namespace std;

int main(int argc, char** argv)
{
    auto sec1 = getSecret();
    using secretType = decltype(getSecret());
    secretType sec3{2};
    cout << sec3._a << endl;
    return 0;
}
