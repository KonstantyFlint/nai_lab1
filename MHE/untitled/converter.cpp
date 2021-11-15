#include <vector>
#include <utility>

#define very_long unsigned long long

bool get_bit(very_long num, int index){
    return num>>index & 1;
}

std::pair<very_long, very_long> convert(std::vector<bool> bits) {
    very_long first_num = 0;
    very_long second_num = 0;
    for (int i = 0; i < 64; i++) {
        first_num *= 2;
        first_num += bits[i];
    }
    for (int i = 64; i < 128; i++) {
        second_num *= 2;
        second_num += bits[i];
    }
    return std::make_pair(first_num, second_num);
}

std::vector<bool> convert(std::pair<very_long, very_long> pair){
    std::vector<bool> bits;
    for(int i=63;i>=0;i--){
        bits.push_back(get_bit(pair.second, i));
    }
    for(int i=63;i>=0;i--){
        bits.push_back(get_bit(pair.first, i));
    }
    return bits;
}

very_long BinaryToGray(very_long num)
{
    return num ^ (num >> 1);
}


very_long GrayToBinary(very_long num)
{
    very_long mask = num;
    while (mask) {
        mask >>= 1;
        num   ^= mask;
    }
    return num;
}