#include "geral.h"
#include <random>



int main() {
    Jogo j{};
    UI interface(j);
    interface.menu();

    /*int t;

    for (int i = 0; i < 10; ++i) {
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<mt19937::result_type> dist6(0,5);
        t = dist6(rng);

        cout << t << endl;
    }*/

    return 0;
}
