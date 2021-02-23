#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Convert float to unsigned integer (uint32_t)
uint32_t float_to_int(float input){
    int* int_cast = (int*)&input;
	uint32_t out = 0;
	for (int i = 31; i >= 0; i--) {
		int temp = *int_cast & 1 << i;
		if (temp == 0) {
			out = out << 1;
			out = out | 0;
		}
		else {
			out = out << 1;
			out = out | 1;
		}
	}
	return out;
}

// Convert unsigned integer (uint32_t) to float
float int_to_float(uint32_t input){
    float* out = (float*)&input;
	return *out;
}

// Convert integer into array of bytes for serial communication
uint8_t* uint32_t_batch(uint32_t input){
    uint8_t* output = (uint8_t*)calloc(4, sizeof(uint8_t));
    uint8_t byte_counter = 0;
    uint8_t bit;
    for(int i = 31; i >= 0; i--){
        // Extract i-th bit and shift it right i times
        bit = (input & 1 << i) >> i;
        // Added to array
        output[byte_counter] = output[byte_counter] << 1;
        output[byte_counter] = output[byte_counter] | bit;
        if(i % 8 == 0){
            byte_counter++;
        }
    }
    return output;
}

// Print uint8_t in binary (big-endian)
void print_binary8(uint8_t input){
    uint8_t bit;
    for(int i = 7; i >= 0; i--){
        // Extract i-th bit and shift it right i times
        bit = (input & 1 << i) >> i;
        printf("%d", bit);
    }
}

// Print uint32_t in binary (big-endian)
void print_binary32(uint32_t input){
    uint8_t bit;
    for(int i = 31; i >= 0; i--){
        // Extract i-th bit and shift it right i times
        bit = (input & 1 << i) >> i;
        printf("%d", bit);
        if(i % 8 == 0 && i != 0){
            printf("_");
        }
    }
}

// Print uint32_t batch in binary (big-endian)
void print_integer32_batch(uint8_t* input){
    for(int i = 0; i < 4; i++){
        uint8_t byte = input[i];
        printf("Byte[%d]:", i);
        print_binary8(byte);
        if(i != 4){
            printf("\n");
        }
    }
}
