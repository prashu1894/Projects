#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

/*
 * Given a 16-bit hardware register value, extract:
 * bits 0–3 (mode)
 * bits 4–7 (status)
 * bits 8–15 (data)
 */
#define MODE_MASK    0x000F
#define STATUS_MASK  0x00F0
#define DATA_MASK    0xFF00
void parse_register(uint16_t reg, uint8_t* mode, uint8_t* status, uint8_t* data) {
    if (reg == 0)
        return;
    *mode = reg & MODE_MASK;
    *status = (reg & STATUS_MASK) >> 4;
    *data = (reg & DATA_MASK)>> 8;
    return;
}
// Simulate a Software Watchdog Timer
void watchdog() {
    time_t current;
    current = time(NULL);
    printf("Current time in seconds : %s", ctime(&current));
}

// void handle_watchdog() {
    // pthread_t* t1;
    // pthread_create
// }
#define ENDINAESS_MASK 0x000000FF
void find_endinannes() {
    uint32_t var = 0xABCD1234;
    uint8_t result = var & ENDINAESS_MASK;
    printf("%X\n", result);
    if (result == 0x34) {
        printf("Little Endianesss");
    } else {
        printf("Big Endianesss");
    }
    return;
}

/* Endianess problem: If two embedded systems communicate with each other
 *    A (Big) --------- (Little) B
 *    A will start sending from MSB as it is big Endian,
 *    but B will interpret it as LSB since it is little Endian.
 *    In this scenario, we should perform a byte swap before sending out
 *    A --- (Byte swap) --- B
 */
void byte_swap(uint32_t * ptr) {
    if (ptr == NULL)
        return;
    uint8_t temp;
    uint8_t start, end;
    start = 0;
    end = 3;
    while (start < end) {
        temp = *((uint8_t *)ptr + end);
        *((uint8_t *)ptr + end) = *((uint8_t *)ptr + start);
        *((uint8_t *)ptr + start) = temp;
        start++;
        end--;
    }
    return;
}

char * swap_order(char input[]) {
    if (input == NULL)
        return NULL;
    char *arr = strtok(input, " ");
    int size = 0;
    char *words[100];
    while (arr)
    {
        words[size] = arr;
        arr = strtok(NULL, " ");
        size++;
    }
    char *ret = (char*)malloc(sizeof(char) *100);
    for(int j = size-1; j>=0; j--) {
        strcat(ret, words[j]);
        if(j!=0)
            strcat(ret, " ");
    }
    return ret;
}

int main() {
    uint8_t mode;
    uint8_t status;
    uint8_t data;
    uint16_t reg = 1028;
    watchdog();
    parse_register(reg, &mode, &status, &data);
    printf("mode - %u, status - %u, data - %u", mode, status, data);
    char* buf = (char*)malloc(sizeof(35));
    snprintf(buf, 35, "%s", "This string is too long for buffer");
    printf("\n%s\n", buf);
    find_endinannes();
    uint32_t var = 0xABCD1234;
    printf("Before byte swap: %X\n", var);
    byte_swap(&var);
    printf("After byte swap: %X\n", var);
    char *input1 = (char *)malloc(sizeof(char) * 100);
    char input[] = "Hello world, Welcome to Class.";
    input1 = swap_order(input);
    printf("After word swap:  %s", input1);
    return 0;
}

