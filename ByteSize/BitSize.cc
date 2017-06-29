#include "BitSize.h"
#include <algorithm>
#include <limits>
#include <sstream>
#include <iomanip>

#define BITS_IN_BYTE 8.
#define BYTES_IN_KIBIBIT 128.
#define BYTES_IN_MEBIBIT 131072.
#define BYTES_IN_GIBIBIT 134217728.
#define BYTES_IN_TEBIBIT 137438953472.
#define BYTES_IN_PEBIBIT 140737488355328.5
#define BYTES_IN_KILOBIT 125.
#define BYTES_IN_MEGABIT 125000.
#define BYTES_IN_GIGABIT 125000000.
#define BYTES_IN_TERABIT 125000000000.
#define BYTES_IN_PETABIT 125000000000000.

namespace hvn3 {

	BitSize::BitSize(double bytes, ByteUnit unit, BytePrefix prefix) {

		_bytes = RoundBytesToNearestBit(bytes);
		_unit = unit;
		_prefix = prefix;

	}

	double BitSize::Bits() const {

		return _bytes * BITS_IN_BYTE;

	}
	double BitSize::Bytes() const {

		return _bytes;

	}
	double BitSize::Kilobits() const {

		return Bytes() / BytesInKilobit(_unit);

	}
	double BitSize::Megabits() const {

		return Bytes() / BytesInMegabit(_unit);

	}
	double BitSize::Gigabits() const {

		return Bytes() / BytesInGigabit(_unit);

	}
	double BitSize::Terabits() const {

		return Bytes() / BytesInTerabit(_unit);

	}
	double BitSize::Petabits() const {

		return Bytes() / BytesInPetabit(_unit);

	}

	std::string BitSize::LargestUnitSymbol() const {

		if (Petabits() >= 1.0)
			return PetabitSymbol(_prefix);
		if (Terabits() >= 1.0)
			return TerabitSymbol(_prefix);
		if (Gigabits() >= 1.0)
			return GigabitSymbol(_prefix);
		if (Megabits() >= 1.0)
			return MegabitSymbol(_prefix);
		if (Kilobits() >= 1.0)
			return KilobitSymbol(_prefix);
		if (Bytes() >= 1.0)
			return ByteSymbol(_prefix);

		return BitSymbol(_prefix);

	}
	double BitSize::LargestUnitValue() const {

		if (Petabits() >= 1.0)
			return Petabits();
		if (Terabits() >= 1.0)
			return Terabits();
		if (Gigabits() >= 1.0)
			return Gigabits();
		if (Megabits() >= 1.0)
			return Megabits();
		if (Kilobits() >= 1.0)
			return Kilobits();
		if (Bytes() >= 1.0)
			return Bytes();

		return Bits();

	}

	void BitSize::AddBits(double size) {

		*this = BitSize(Bytes() + BitsInByte(_unit) / size, _unit, _prefix);

	}
	void BitSize::AddBytes(double size) {

		*this = BitSize(Bytes() + size, _unit, _prefix);

	}
	void BitSize::AddKilobits(double size) {

		*this = BitSize(Bytes() + size * BytesInKilobit(_unit), _unit, _prefix);

	}
	void BitSize::AddMegabits(double size) {

		*this = BitSize(Bytes() + size * BytesInMegabit(_unit), _unit, _prefix);

	}
	void BitSize::AddGigabits(double size) {

		*this = BitSize(Bytes() + size * BytesInGigabit(_unit), _unit, _prefix);

	}
	void BitSize::AddTerabits(double size) {

		*this = BitSize(Bytes() + size * BytesInTerabit(_unit), _unit, _prefix);

	}
	void BitSize::AddPetabits(double size) {

		*this = BitSize(Bytes() + size * BytesInPetabit(_unit), _unit, _prefix);

	}

	std::string BitSize::ToString(unsigned int precision) const {

		std::stringstream stream;

		stream << std::setprecision(precision) << LargestUnitValue() << ' ' << LargestUnitSymbol();

		return stream.str();

	}

	BitSize BitSize::MinValue() {

		return BitSize(0);

	}
	BitSize BitSize::MaxValue() {

		return BitSize(DBL_MAX);

	}

	BitSize BitSize::FromBits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC) {

		return BitSize(size / BitsInByte(unit), unit, prefix);

	}
	BitSize BitSize::FromBytes(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC) {

		return BitSize(size, unit, prefix);

	}
	BitSize BitSize::FromKilobits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC) {

		return BitSize(size * BytesInKilobit(unit), unit, prefix);

	}
	BitSize BitSize::FromMegabits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC) {

		return BitSize(size * BytesInMegabit(unit), unit, prefix);

	}
	BitSize BitSize::FromGigabits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC) {

		return BitSize(size * BytesInGigabit(unit), unit, prefix);

	}
	BitSize BitSize::FromTerabits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC) {

		return BitSize(size * BytesInTerabit(unit), unit, prefix);

	}
	BitSize BitSize::FromPetabits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC) {

		return BitSize(size * BytesInPetabit(unit), unit, prefix);

	}

	double BitSize::BitsInByte(ByteUnit unit) {

		return BITS_IN_BYTE;

	}
	double BitSize::BytesInKilobit(ByteUnit unit) {

		switch (unit) {
		case ByteUnit::Binary:
			return BYTES_IN_KIBIBIT;
		case ByteUnit::Decimal:
			return BYTES_IN_KILOBIT;
		}

	}
	double BitSize::BytesInMegabit(ByteUnit unit) {

		switch (unit) {
		case ByteUnit::Binary:
			return BYTES_IN_MEBIBIT;
		case ByteUnit::Decimal:
			return BYTES_IN_MEGABIT;
		}

	}
	double BitSize::BytesInGigabit(ByteUnit unit) {

		switch (unit) {
		case ByteUnit::Binary:
			return BYTES_IN_GIBIBIT;
		case ByteUnit::Decimal:
			return BYTES_IN_GIGABIT;
		}

	}
	double BitSize::BytesInTerabit(ByteUnit unit) {

		switch (unit) {
		case ByteUnit::Binary:
			return BYTES_IN_TEBIBIT;
		case ByteUnit::Decimal:
			return BYTES_IN_TERABIT;
		}

	}
	double BitSize::BytesInPetabit(ByteUnit unit) {

		switch (unit) {
		case ByteUnit::Binary:
			return BYTES_IN_PEBIBIT;
		case ByteUnit::Decimal:
			return BYTES_IN_PETABIT;
		}

	}

	std::string BitSize::BitSymbol(BytePrefix prefix) {

		return "b";

	}
	std::string BitSize::ByteSymbol(BytePrefix prefix) {

		return "B";

	}
	std::string BitSize::KilobitSymbol(BytePrefix prefix = BytePrefix::IEC) {

		switch (prefix) {
		case BytePrefix::IEC:
			return "Kibit";
		case BytePrefix::JEDEC:
			return "Kbit";
		case BytePrefix::Metric:
			return "kbit";
		}

	}
	std::string BitSize::MegabitSymbol(BytePrefix prefix = BytePrefix::IEC) {

		switch (prefix) {
		case BytePrefix::IEC:
			return "Mibit";
		case BytePrefix::JEDEC:
		case BytePrefix::Metric:
			return "Mbit";
		}


	}
	std::string BitSize::GigabitSymbol(BytePrefix prefix = BytePrefix::IEC) {

		switch (prefix) {
		case BytePrefix::IEC:
			return "Gibit";
		case BytePrefix::JEDEC:
		case BytePrefix::Metric:
			return "Gbit";
		}

	}
	std::string BitSize::TerabitSymbol(BytePrefix prefix = BytePrefix::IEC) {

		switch (prefix) {
		case BytePrefix::IEC:
			return "Tibit";
		case BytePrefix::JEDEC:
		case BytePrefix::Metric:
			return "Tbit";
		}

	}
	std::string BitSize::PetabitSymbol(BytePrefix prefix = BytePrefix::IEC) {

		switch (prefix) {
		case BytePrefix::IEC:
			return "Pibit";
		case BytePrefix::JEDEC:
		case BytePrefix::Metric:
			return "Pbit";
		}

	}

	BitSize& BitSize::operator+=(const BitSize& rhs) {

		_bytes += rhs._bytes;

	}
	BitSize& BitSize::operator-=(const BitSize& rhs) {

		_bytes -= rhs._bytes;

	}

	bool operator==(const BitSize& lhs, const BitSize& rhs) {

		return (std::abs)(lhs.Bytes() - rhs.Bytes()) < 0.125; // difference of less than 1 bit

	}
	bool operator!=(const BitSize& lhs, const BitSize& rhs) {

		return !(lhs == rhs);

	}
	bool operator<(const BitSize& lhs, const BitSize& rhs) {

		return lhs.Bytes() < rhs.Bytes();

	}
	bool operator<=(const BitSize& lhs, const BitSize& rhs) {

		return (lhs.Bytes() < rhs.Bytes()) || (lhs == rhs);

	}
	bool operator>(const BitSize& lhs, const BitSize& rhs) {

		return lhs.Bytes() > rhs.Bytes();

	}
	bool operator>=(const BitSize& lhs, const BitSize& rhs) {

		return (lhs.Bytes() > rhs.Bytes()) || (lhs == rhs);

	}
	BitSize operator+(const BitSize& lhs, const BitSize& rhs) {

		return(BitSize(lhs.Bytes() + rhs.Bytes(), lhs._unit, lhs._prefix));

	}
	BitSize operator-(const BitSize& lhs, const BitSize& rhs) {

		return(BitSize(lhs.Bytes() - rhs.Bytes(), lhs._unit, lhs._prefix));

	}

}