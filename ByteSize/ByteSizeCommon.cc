#include "ByteSizeCommon.h"
#include <algorithm>
#define BYTES_IN_BIT 0.125

namespace hvn3 {

	double RoundBytesToNearestBit(double bytes) {

		double remainder = (std::fmod)(bytes, BYTES_IN_BIT);

		bytes -= remainder;

		if (remainder > 0.0)
			bytes += BYTES_IN_BIT;
		else if (remainder < 0.0)
			bytes -= BYTES_IN_BIT;

		return bytes;

	}

}