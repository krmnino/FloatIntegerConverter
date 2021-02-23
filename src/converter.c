#include "converter.h"

int main(){

	// Test float data
	float data = 2.25125;

	// Convert float to unsigned integer
	uint32_t float_to_uint = float_to_int(data);
	printf("float to uint32_t: %d\n", float_to_uint);
	printf("uint32_t binary representation: ");
	// Print uint32_t in binary (big-endian)
	print_binary32(float_to_uint);
	printf("\n");

	// Convert unsigned integer to float
	float uint_to_float = int_to_float(float_to_uint);
	printf("uint32_t to float: %.5f\n", uint_to_float);

	// Convert integer into array of bytes (4 bytes for a uint32_t)
	uint8_t* uint32_batch = uint32_t_batch(float_to_uint);
	printf("uint32_t batch binary:\n");
	print_integer32_batch(uint32_batch);
	printf("\n");
	free(uint32_batch);
	
}