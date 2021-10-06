#include <tuple>

using namespace std;

int globalInt = 0;

auto findMax = [](auto fitness, auto supplier, int iterations) {
    auto max_x = supplier();
    auto max_y = fitness(max_x);
    for (int i = 1; i < iterations; i++) {
        auto new_x = supplier();
        auto new_y = fitness(new_x);
        if (new_y > max_y) {
            max_x = new_x;
            max_y = new_y;
        }
    }
    return make_pair(max_x, max_y);
};

int ascendingIntSupplier() {
    return globalInt++;
}

double distanceFrom7(int x) {
    return 1000 - abs(x - 7);
}

int main() {
    findMax(distanceFrom7, ascendingIntSupplier, 10);
}
