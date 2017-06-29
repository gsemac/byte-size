#include "ByteSize.h"
#include <algorithm>
#include <limits>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <exception>

#define BITS_IN_BYTE 8.
#define BYTES_IN_KIBIBYTE 1024.
#define BYTES_IN_MEBIBYTE 1048576.
#define BYTES_IN_GIBIBYTE 1073741824.
#define BYTES_IN_TEBIBYTE 1099511627776.
#define BYTES_IN_PEBIBYTE 1125899906842624.
#define BYTES_IN_KILOBYTE 1000.
#define BYTES_IN_MEGABYTE 1000000.
#define BYTES_IN_GIGABYTE 1000000000.
#define BYTES_IN_TERABYTE 1000000000000.
#define BYTES_IN_PETABYTE 1000000000000000.

namespace hvn3 {

	ByteSize::ByteSize(double bytes, ByteUnit unit, BytePrefix prefix) {

		_bytes = RoundBytesToNearestBit(bytes);
		_unit = unit;

		if (unit == ByteUnit::Decimal)
			prefix = BytePrefix::Metric;

		_prefix = prefix;

	}

	double ByteSize::Bits() const {

		return _bytes * BITS_IN_BYTE;

	}
	double ByteSize::Bytes() const {

		return _bytes;

	}
	double ByteSize::Kilobytes() const {

		return Bytes() / BytesInKilobyte(_unit);

	}
	double ByteSize::Megabytes() const {

		return Bytes() / BytesInMegabyte(_unit);

	}
	double ByteSize::Gigabytes() const {

		return Bytes() / BytesInGigabyte(_unit);

	}
	double ByteSize::Terabytes() const {

		return Bytes() / BytesInTerabyte(_unit);

	}
	double ByteSize::Petabytes() const {

		return Bytes() / BytesInPetabyte(_unit);

	}

	std::string ByteSize::LargestUnitSymbol() const {

		if ((std::abs)(Petabytes()) >= 1.0)
			return PetabyteSymbol(_prefix);
		if ((std::abs)(Terabytes()) >= 1.0)
			return TerabyteSymbol(_prefix);
		if ((std::abs)(Gigabytes()) >= 1.0)
			return GigabyteSymbol(_prefix);
		if ((std::abs)(Megabytes()) >= 1.0)
			return MegabyteSymbol(_prefix);
		if ((std::abs)(Kilobytes()) >= 1.0)
			return KilobyteSymbol(_prefix);
		if ((std::abs)(Bytes()) >= 1.0)
			return ByteSymbol(_prefix);

		return BitSymbol(_prefix);

	}
	double ByteSize::LargestUnitValue() const {

		if ((std::abs)(Petabytes()) >= 1.0)
			return Petabytes();
		if ((std::abs)(Terabytes()) >= 1.0)
			return Terabytes();
		if ((std::abs)(Gigabytes()) >= 1.0)
			return Gigabytes();
		if ((std::abs)(Megabytes()) >= 1.0)
			return Megabytes();
		if ((std::abs)(Kilobytes()) >= 1.0)
			return Kilobytes();
		if ((std::abs)(Bytes()) >= 1.0)
			return Bytes();

		return Bits();

	}

	void ByteSize::AddBits(double size) {

		*this = ByteSize(Bytes() + BitsInByte(_unit) / size, _unit, _prefix);

	}
	void ByteSize::AddBytes(double size) {

		*this = ByteSize(Bytes() + size, _unit, _prefix);

	}
	void ByteSize::AddKilobytes(double size) {

		*this = ByteSize(Bytes() + size * BytesInKilobyte(_unit), _unit, _prefix);

	}
	void ByteSize::AddMegabytes(double size) {

		*this = ByteSize(Bytes() + size * BytesInMegabyte(_unit), _unit, _prefix);

	}
	void ByteSize::AddGigabytes(double size) {

		*this = ByteSize(Bytes() + size * BytesInGigabyte(_unit), _unit, _prefix);

	}
	void ByteSize::AddTerabytes(double size) {

		*this = ByteSize(Bytes() + size * BytesInTerabyte(_unit), _unit, _prefix);

	}
	void ByteSize::AddPetabytes(double size) {

		*this = ByteSize(Bytes() + size * BytesInPetabyte(_unit), _unit, _prefix);

	}

	std::string ByteSize::ToString(unsigned int precision) const {

		std::stringstream stream;

		stream << std::fixed << std::setprecision(precision) << LargestUnitValue() << ' ' << LargestUnitSymbol();

		return stream.str();

	}

	ByteSize ByteSize::MinValue() {

		return ByteSize(0);

	}
	ByteSize ByteSize::MaxValue() {

		return ByteSize(DBL_MAX);

	}

	ByteSize ByteSize::Parse(const std::string& string) {

		return Parse(string.c_str());

	}
	ByteSize ByteSize::Parse(const char* string) {

		ByteSize object(0);

		if (!TryParse(string, object))
			throw std::invalid_argument("The input string was not in the correct format.");

		return object;

	}
	bool ByteSize::TryParse(const std::string& string, ByteSize& object) {

		return TryParse(string.c_str(), object);

	}
	bool ByteSize::TryParse(const char* string, ByteSize& object) {

		std::stringstream stream(string);
		double size = 0.0;
		std::string suffix;

		// Read the size and suffix.
		stream >> size >> suffix;

		// If this fails, return false.
		if (stream.fail())
			return false;

		// Compare the string to known suffixes.
		if (suffix == BitSymbol())
			object = ByteSize::FromBits(size);
		else if (suffix == ByteSymbol())
			object = ByteSize::FromBytes(size);

		else if (suffix == KilobyteSymbol(BytePrefix::IEC))
			object = ByteSize::FromKilobytes(size, ByteUnit::Binary, BytePrefix::IEC);
		else if (suffix == KilobyteSymbol(BytePrefix::JEDEC))
			object = ByteSize::FromKilobytes(size, ByteUnit::Binary, BytePrefix::JEDEC);
		else if (suffix == KilobyteSymbol(BytePrefix::Metric))
			object = ByteSize::FromKilobytes(size, ByteUnit::Decimal, BytePrefix::Metric);

		else if (suffix == MegabyteSymbol(BytePrefix::IEC))
			object = ByteSize::FromMegabytes(size, ByteUnit::Binary, BytePrefix::IEC);
		else if (suffix == MegabyteSymbol(BytePrefix::Metric))
			object = ByteSize::FromMegabytes(size, ByteUnit::Decimal, BytePrefix::Metric);

		else if (suffix == GigabyteSymbol(BytePrefix::IEC))
			object = ByteSize::FromGigabytes(size, ByteUnit::Binary, BytePrefix::IEC);
		else if (suffix == GigabyteSymbol(BytePrefix::Metric))
			object = ByteSize::FromGigabytes(size, ByteUnit::Decimal, BytePrefix::Metric);

		else if (suffix == TerabyteSymbol(BytePrefix::IEC))
			object = ByteSize::FromTerabytes(size, ByteUnit::Binary, BytePrefix::IEC);
		else if (suffix == TerabyteSymbol(BytePrefix::Metric))
			object = ByteSize::FromTerabytes(size, ByteUnit::Decimal, BytePrefix::Metric);

		else if (suffix == PetabyteSymbol(BytePrefix::IEC))
			object = ByteSize::FromPetabytes(size, ByteUnit::Binary, BytePrefix::IEC);
		else if (suffix == PetabyteSymbol(BytePrefix::Metric))
			object = ByteSize::FromPetabytes(size, ByteUnit::Decimal, BytePrefix::Metric);
		else
			object = ByteSize::FromBits(size);

		return true;

	}

	ByteSize ByteSize::FromBits(double size, ByteUnit unit, BytePrefix prefix) {

		return ByteSize(size / BitsInByte(unit), unit, prefix);

	}
	ByteSize ByteSize::FromBytes(double size, ByteUnit unit, BytePrefix prefix) {

		return ByteSize(size, unit, prefix);

	}
	ByteSize ByteSize::FromKilobytes(double size, ByteUnit unit, BytePrefix prefix) {

		return ByteSize(size * BytesInKilobyte(unit), unit, prefix);

	}
	ByteSize ByteSize::FromMegabytes(double size, ByteUnit unit, BytePrefix prefix) {

		return ByteSize(size * BytesInMegabyte(unit), unit, prefix);

	}
	ByteSize ByteSize::FromGigabytes(double size, ByteUnit unit, BytePrefix prefix) {

		return ByteSize(size * BytesInGigabyte(unit), unit, prefix);

	}
	ByteSize ByteSize::FromTerabytes(double size, ByteUnit unit, BytePrefix prefix) {

		return ByteSize(size * BytesInTerabyte(unit), unit, prefix);

	}
	ByteSize ByteSize::FromPetabytes(double size, ByteUnit unit, BytePrefix prefix) {

		return ByteSize(size * BytesInPetabyte(unit), unit, prefix);

	}

	double ByteSize::BitsInByte(ByteUnit unit) {

		return BITS_IN_BYTE;

	}
	double ByteSize::BytesInKilobyte(ByteUnit unit) {

		switch (unit) {
		case ByteUnit::Binary:
			return BYTES_IN_KIBIBYTE;
		case ByteUnit::Decimal:
			return BYTES_IN_KILOBYTE;
		}

	}
	double ByteSize::BytesInMegabyte(ByteUnit unit) {

		switch (unit) {
		case ByteUnit::Binary:
			return BYTES_IN_MEBIBYTE;
		case ByteUnit::Decimal:
			return BYTES_IN_MEGABYTE;
		}

	}
	double ByteSize::BytesInGigabyte(ByteUnit unit) {

		switch (unit) {
		case ByteUnit::Binary:
			return BYTES_IN_GIBIBYTE;
		case ByteUnit::Decimal:
			return BYTES_IN_GIGABYTE;
		}

	}
	double ByteSize::BytesInTerabyte(ByteUnit unit) {

		switch (unit) {
		case ByteUnit::Binary:
			return BYTES_IN_TEBIBYTE;
		case ByteUnit::Decimal:
			return BYTES_IN_TERABYTE;
		}

	}
	double ByteSize::BytesInPetabyte(ByteUnit unit) {

		switch (unit) {
		case ByteUnit::Binary:
			return BYTES_IN_PEBIBYTE;
		case ByteUnit::Decimal:
			return BYTES_IN_PETABYTE;
		}

	}

	std::string ByteSize::BitSymbol(BytePrefix prefix) {

		return "b";

	}
	std::string ByteSize::ByteSymbol(BytePrefix prefix) {

		return "B";

	}
	std::string ByteSize::KilobyteSymbol(BytePrefix prefix) {

		switch (prefix) {
		case BytePrefix::IEC:
			return "KiB";
		case BytePrefix::JEDEC:
			return "KB";
		case BytePrefix::Metric:
			return "kB";
		}

	}
	std::string ByteSize::MegabyteSymbol(BytePrefix prefix) {

		switch (prefix) {
		case BytePrefix::IEC:
			return "MiB";
		case BytePrefix::JEDEC:
		case BytePrefix::Metric:
			return "MB";
		}

	}
	std::string ByteSize::GigabyteSymbol(BytePrefix prefix) {

		switch (prefix) {
		case BytePrefix::IEC:
			return "GiB";
		case BytePrefix::JEDEC:
		case BytePrefix::Metric:
			return "GB";
		}

	}
	std::string ByteSize::TerabyteSymbol(BytePrefix prefix) {

		switch (prefix) {
		case BytePrefix::IEC:
			return "TiB";
		case BytePrefix::JEDEC:
		case BytePrefix::Metric:
			return "TB";
		}

	}
	std::string ByteSize::PetabyteSymbol(BytePrefix prefix) {

		switch (prefix) {
		case BytePrefix::IEC:
			return "PiB";
		case BytePrefix::JEDEC:
		case BytePrefix::Metric:
			return "PB";
		}

	}

	ByteSize& ByteSize::operator+=(const ByteSize& rhs) {

		_bytes += rhs._bytes;

		return *this;

	}
	ByteSize& ByteSize::operator-=(const ByteSize& rhs) {

		_bytes -= rhs._bytes;

		return *this;

	}

	bool operator==(const ByteSize& lhs, const ByteSize& rhs) {

		return (std::abs)(lhs.Bytes() - rhs.Bytes()) < 0.125; // difference of less than 1 bit

	}
	bool operator!=(const ByteSize& lhs, const ByteSize& rhs) {

		return !(lhs == rhs);

	}
	bool operator<(const ByteSize& lhs, const ByteSize& rhs) {

		return lhs.Bytes() < rhs.Bytes();

	}
	bool operator<=(const ByteSize& lhs, const ByteSize& rhs) {

		return (lhs.Bytes() < rhs.Bytes()) || (lhs == rhs);

	}
	bool operator>(const ByteSize& lhs, const ByteSize& rhs) {

		return lhs.Bytes() > rhs.Bytes();

	}
	bool operator>=(const ByteSize& lhs, const ByteSize& rhs) {

		return (lhs.Bytes() > rhs.Bytes()) || (lhs == rhs);

	}
	ByteSize operator+(const ByteSize& lhs, const ByteSize& rhs) {

		return(ByteSize(lhs.Bytes() + rhs.Bytes(), lhs._unit, lhs._prefix));

	}
	ByteSize operator-(const ByteSize& lhs, const ByteSize& rhs) {

		return(ByteSize(lhs.Bytes() - rhs.Bytes(), lhs._unit, lhs._prefix));

	}

}