#include "converter.h"

int main(){

	// Test float data
	float data = 2.25125;

	// Convert float to unsigned integer
	uint32_t float_to_uint = float_to_uint32(data);
	printf("float to uint32_t: %d\n", float_to_uint);
	printf("uint32_t binary representation: ");
	// Print uint32_t in binary (big-endian)
	print_binary32(float_to_uint);
	printf("\n");

	// Convert unsigned integer to float
	float uint_to_float = uint32_to_float(float_to_uint);
	printf("uint32_t to float: %.5f\n", uint_to_float);

	// Convert unsigned integer into array of bytes (4 bytes for a uint32_t)
	uint8_t* uint32_to_batch = uint8_batch(float_to_uint);
	printf("uint8_t_batch batch binary:\n");
	print_binary8_batch(uint32_to_batch);
	printf("\n");

	// Reconstruct unsigned integer back to float
	uint32_t batch_to_uint = reconstruct_uint32(uint32_to_batch);
	float batch_float = uint32_to_float(batch_to_uint);
	printf("Reconstructed uint8_t batch to float: %.5f", batch_float);
	printf("\n");

	free(uint32_to_batch);
}