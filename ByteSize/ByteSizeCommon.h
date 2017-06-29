#pragma once

namespace hvn3 {

	enum class ByteUnit {
		// One kilobyte is equal to 1000 bytes.
		Decimal,
		// One kilobyte is equal to 1024 bytes.
		Binary
	};

	enum class BytePrefix {
		Metric,
		IEC,
		JEDEC
	};

	double RoundBytesToNearestBit(double bytes);

}