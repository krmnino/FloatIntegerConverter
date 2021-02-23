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

