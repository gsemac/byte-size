#include "ByteSize.h"
#include <algorithm>
#include <limits>
#include <sstream>
#include <iomanip>

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

		_bytes = bytes;
		_unit = unit;
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

		if (Petabytes() >= 1.0)
			return PetabyteSymbol(_prefix);
		if (Terabytes() >= 1.0)
			return TerabyteSymbol(_prefix);
		if (Gigabytes() >= 1.0)
			return GigabyteSymbol(_prefix);
		if (Megabytes() >= 1.0)
			return MegabyteSymbol(_prefix);
		if (Kilobytes() >= 1.0)
			return KilobyteSymbol(_prefix);
		if (Bytes() >= 1.0)
			return ByteSymbol(_prefix);

		return BitSymbol(_prefix);

	}
	double ByteSize::LargestUnitValue() const {

		if (Petabytes() >= 1.0)
			return Petabytes();
		if (Terabytes() >= 1.0)
			return Terabytes();
		if (Gigabytes() >= 1.0)
			return Gigabytes();
		if (Megabytes() >= 1.0)
			return Megabytes();
		if (Kilobytes() >= 1.0)
			return Kilobytes();
		if (Bytes() >= 1.0)
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

		stream << std::setprecision(precision) << LargestUnitValue() << ' ' << LargestUnitSymbol();

		return stream.str();

	}

	ByteSize ByteSize::MinValue() {

		return ByteSize(0);

	}
	ByteSize ByteSize::MaxValue() {

		return ByteSize(DBL_MAX);

	}

	ByteSize ByteSize::FromBits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC) {

		return ByteSize(size / BitsInByte(unit), unit, prefix);

	}
	ByteSize ByteSize::FromBytes(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC) {

		return ByteSize(size, unit, prefix);

	}
	ByteSize ByteSize::FromKilobytes(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC) {

		return ByteSize(size * BytesInKilobyte(unit), unit, prefix);

	}
	ByteSize ByteSize::FromMegabytes(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC) {

		return ByteSize(size * BytesInMegabyte(unit), unit, prefix);

	}
	ByteSize ByteSize::FromGigabytes(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC) {

		return ByteSize(size * BytesInGigabyte(unit), unit, prefix);

	}
	ByteSize ByteSize::FromTerabytes(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC) {

		return ByteSize(size * BytesInTerabyte(unit), unit, prefix);

	}
	ByteSize ByteSize::FromPetabytes(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC) {

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

	}
	ByteSize& ByteSize::operator-=(const ByteSize& rhs) {

		_bytes -= rhs._bytes;

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