#include "converter.h"

uint32_t float_to_int(float input) {
	float a = -118.625;
	int* b = (int*)& input;
	uint32_t out = 0;
	int out2 = 0;
	for (int i = 31; i >= 0; i--) {
		int temp = *b & 1 << i;
		if (temp == 0) {
			out = out << 1;
			out = out | 0;
			//out2 = out2 << 1;
			//out2 = out2 | 0;
		}
		else {
			out = out << 1;
			out = out | 1;
			//out2 = out2 << 1;
			//out2 = out2 | 1;
		}
	}
	printf("%d", out2);
	return out;
}