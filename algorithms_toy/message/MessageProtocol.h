//
// Created by 陈树沛 on 14/06/2018.
//

#ifndef TOY_MESSAGEPROTOCOL_H
#define TOY_MESSAGEPROTOCOL_H

#include <iostream>
#include <bitset>
#include <vector>
namespace supi {
    int Encodezigzag(int o){
        if (o >= 0) return 2*o;
            else
                return (-2)*o-1;
    }

    int VarintLength(uint64_t v) {
        int len = 1;
        while (v >= 128) {
            v >>= 7;
            len++;
        }
        return len;
    }

    // 将一个32位无符号int进行编码保存到dst指向的空间
    char* EncodeVarint32(char* dst, uint32_t v) {
        // Operate on characters as unsigneds
        unsigned char* ptr = reinterpret_cast<unsigned char*>(dst);
        static const int B = 128;
        if (v < (1<<7)) {
            *(ptr++) = v;
        } else if (v < (1<<14)) {
            *(ptr++) = v | B;
            *(ptr++) = v>>7;
        } else if (v < (1<<21)) {
            *(ptr++) = v | B;
            *(ptr++) = (v>>7) | B;
            *(ptr++) = v>>14;
        } else if (v < (1<<28)) {
            *(ptr++) = v | B;
            *(ptr++) = (v>>7) | B;
            *(ptr++) = (v>>14) | B;
            *(ptr++) = v>>21;
        } else {
            *(ptr++) = v | B;
            *(ptr++) = (v>>7) | B;
            *(ptr++) = (v>>14) | B;
            *(ptr++) = (v>>21) | B;
            *(ptr++) = v>>28;
        }
        return reinterpret_cast<char*>(ptr);
    }

    void testEncodeVarint32(int b) {
        char* a;
        std::bitset<32> d(b);
        std::cout << "Before:" << d << std::endl;
        std::cout << "After Byte:" << supi::VarintLength(b) << "\n" << "After:";
        supi::EncodeVarint32(a, b);

        for (int i = 0; i < supi::VarintLength(b); ++i) {
            std::bitset<8> c(*a);
            std::cout << c << " ";
            a++;
        }
        std::cout << "\n";
    }

    void testEncodezigzag(int a) {
        std::cout << "Before: " << a << "\n";
        std::cout << "After: " << Encodezigzag(a) << "\n";
    }
}
#endif //TOY_MESSAGEPROTOCOL_H
