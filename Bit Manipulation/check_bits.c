#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*   ---------------
 *   |     AND     |
 *   | A | B | A&B |
 *   | 0 | 0 | 0   |
 *   | 0 | 1 | 0   |
 *   | 1 | 0 | 0   |
 *   | 1 | 1 | 1   |
 *   ---------------
 *   |     OR      |
 *   | A | B | A|B |
 *   | 0 | 0 | 0   |
 *   | 0 | 1 | 1   |
 *   | 1 | 0 | 1   |
 *   | 1 | 1 | 1   |
 *   ---------------
 *   |     XOR     |
 *   | A | B | A^B |
 *   | 0 | 0 | 0   |  
 *   | 0 | 1 | 1   |
 *   | 1 | 0 | 1   |
 *   | 1 | 1 | 0   |
 *   ---------------
 */

bool check_bit(uint8_t num, int bit) {
    // printf("%d %d\n", num, 1<<bit);
    if ((num) & (1 << bit)) {
        return true;
    }
    return false;
}

uint8_t set_bit(uint8_t num, int bit) {
    num = num | (1<<bit);
    return num;
}

uint8_t clear_bit(uint8_t num, int bit) {
    num = num & ~(1<<bit);
    return num;
}

uint8_t toggle_bit(uint8_t num, int bit) {
    num = num ^ (1<<bit);
    return num;
}

void check_all_set_bits(uint8_t num) {
    for(int i = 0; i< 8; i++) {
        if (num & (1<<i)) {
            printf("\n%d bit is set in %d", i, num);
        }
    }
    return;
}

/* power of 2 check
 * Unique property of power of 2 when for any power of 2 number n, 
 * n-1 will have all bits set right to the least significant bit
 * Example: 8 = 1000, 7 = 0111
 * 8 & 7 = 0
 */
bool powerof2(int num) {
    if (num == 0)
        return false;
    if (!(num & (num-1))) {
        return true;
    }
    return false;
}

uint32_t reverseBits(uint32_t n) {
    uint32_t result=0;
    for(int i = 0; i< 32; i++) {
        if((n >> i) & 1) {
            result |= 1 <<(31-i);
        }
    }
    return result;
}

/* power of 4 check
 * Unique property of power of 4 is that it has only one bit set and
 * all the bits to the right of it are set
 * also, bits does not and with 0xAAAAAAAA
 * Example: 4 = 00000000000000000000000000000100
 * For example: 16 (10000) is power of 4 because there is only one 
 * bit set and 0x10 & 0xAAAAAAAA is zero.
 */
bool powerof4(int num) {
    if (num == 0)
        return false;
    if (!(num & (num-1)) && !(num & 0xAAAAAAAA))
        return true;
    return false;
}

int main() {
    uint8_t num = 8;
    int bit = 3;
    if(check_bit(num, bit)) {
        printf("%d Bit is set in %d", bit, num);
    } else {
        printf("%d Bit is not set in %d", bit, num);
    }
    num = 1;
    num = set_bit(num, 1);
    printf("\nExpected 3, got %d", num);
    num = clear_bit(num, 1);
    printf("\nExpected 1, got %d", num);
    num = toggle_bit(num, 1);
    printf("\nExpected 3, got %d", num);
    check_all_set_bits(num);
    num = 8;
    if(powerof2(num)) {
        printf("\n%d is power of 2", num);
    } else {
        printf("\n%d is NOT a power of 2", num);
    }
    num = 16;
    if(powerof4(num)) {
        printf("\n%d is power of 4", num);
    } else {
        printf("\n%d is NOT a power of 4", num);
    }
    uint32_t n = 43261596;
    uint32_t result = reverseBits(n);
    printf("\nExpected 964176192, got %d", result);
    return 0;
}