#include "ByteSize.h"
#include <algorithm>
#define BITS_IN_BYTE 8UL
#define BYTES_IN_KIBIBYTE 1024UL
#define BYTES_IN_MEBIBYTE 1048576UL
#define BYTES_IN_GIBIBYTE 1073741824UL
#define BYTES_IN_TEBIBYTE 1099511627776UL
#define BYTES_IN_PEBIBYTE 1125899906842624UL
#define BYTES_IN_KILOBYTE 1000UL
#define BYTES_IN_MEGABYTE 1000000UL
#define BYTES_IN_GIGABYTE 1000000000UL
#define BYTES_IN_TERABYTE 1000000000000UL
#define BYTES_IN_PETABYTE 1000000000000000UL
#define BYTES_IN_KIBIBIT 128UL
#define BYTES_IN_MEBIBIT 131072UL
#define BYTES_IN_GIBIBIT 134217728UL
#define BYTES_IN_TEBIBIT 137438953472UL
#define BYTES_IN_PEBIBIT 140737488355328.5
#define BYTES_IN_KILOBIT 125UL
#define BYTES_IN_MEGABIT 125000UL
#define BYTES_IN_GIGABIT 125000000UL
#define BYTES_IN_TERABIT 125000000000UL
#define BYTES_IN_PETABIT 125000000000000UL

ByteSize::ByteSize(uint64_t bytes, ByteUnit unit, BytePrefix prefix) {

	_bytes = bytes;
	_unit = unit;
	_prefix = prefix;

}

uint64_t ByteSize::Bits() const {
	
	return _bytes + static_cast<uint64_t>(_bits);

}
double ByteSize::Bytes() const {

	return static_cast<double>(_bytes) + (_bits / static_cast<double>(BitsInByte(_unit)));

}
double ByteSize::Kilobytes() const {

	return Bytes() / static_cast<double>(BytesInKilobyte(_unit));

}
double ByteSize::Megabytes() const {

	return Bytes() / static_cast<double>(BytesInMegabyte(_unit));

}
double ByteSize::Gigabytes() const {

	return Bytes() / static_cast<double>(BytesInGigabyte(_unit));

}
double ByteSize::Terabytes() const {

	return Bytes() / static_cast<double>(BytesInTerabyte(_unit));

}
double ByteSize::Petabytes() const {

	return Bytes() / static_cast<double>(BytesInPetabyte(_unit));

}

double ByteSize::Kilobits() const {

	return Bytes() / static_cast<double>(BytesInKilobit(_unit));

}
double ByteSize::Megabits() const {

	return Bytes() / static_cast<double>(BytesInMegabit(_unit));

}
double ByteSize::Gigabits() const {

	return Bytes() / static_cast<double>(BytesInGigabit(_unit));

}
double ByteSize::Terabits() const {

	return Bytes() / static_cast<double>(BytesInTerabit(_unit));

}
double ByteSize::Petabits() const {

	return Bytes() / static_cast<double>(BytesInPetabit(_unit));

}

uint64_t ByteSize::BitsInByte(ByteUnit unit) {

	return BITS_IN_BYTE;

}
uint64_t ByteSize::BytesInKilobyte(ByteUnit unit) {

	switch (unit) {
	case ByteUnit::Binary:
		return BYTES_IN_KIBIBYTE;
	case ByteUnit::Decimal:
		return BYTES_IN_KILOBYTE;
	}

}
uint64_t ByteSize::BytesInMegabyte(ByteUnit unit) {

	switch (unit) {
	case ByteUnit::Binary:
		return BYTES_IN_MEBIBYTE;
	case ByteUnit::Decimal:
		return BYTES_IN_MEGABYTE;
	}

}
uint64_t ByteSize::BytesInGigabyte(ByteUnit unit) {

	switch (unit) {
	case ByteUnit::Binary:
		return BYTES_IN_GIBIBYTE;
	case ByteUnit::Decimal:
		return BYTES_IN_GIGABYTE;
	}

}
uint64_t ByteSize::BytesInTerabyte(ByteUnit unit) {

	switch (unit) {
	case ByteUnit::Binary:
		return BYTES_IN_TEBIBYTE;
	case ByteUnit::Decimal:
		return BYTES_IN_TERABYTE;
	}

}
uint64_t ByteSize::BytesInPetabyte(ByteUnit unit) {

	switch (unit) {
	case ByteUnit::Binary:
		return BYTES_IN_PEBIBYTE;
	case ByteUnit::Decimal:
		return BYTES_IN_PETABYTE;
	}
	
}

uint64_t ByteSize::BytesInKilobit(ByteUnit unit) {

	switch (unit) {
	case ByteUnit::Binary:
		return BYTES_IN_KIBIBIT;
	case ByteUnit::Decimal:
		return BYTES_IN_KILOBIT;
	}

}
uint64_t ByteSize::BytesInMegabit(ByteUnit unit) {

	switch (unit) {
	case ByteUnit::Binary:
		return BYTES_IN_MEBIBIT;
	case ByteUnit::Decimal:
		return BYTES_IN_MEGABIT;
	}

}
uint64_t ByteSize::BytesInGigabit(ByteUnit unit) {

	switch (unit) {
	case ByteUnit::Binary:
		return BYTES_IN_GIBIBIT;
	case ByteUnit::Decimal:
		return BYTES_IN_GIGABIT;
	}

}
uint64_t ByteSize::BytesInTerabit(ByteUnit unit) {

	switch (unit) {
	case ByteUnit::Binary:
		return BYTES_IN_TEBIBIT;
	case ByteUnit::Decimal:
		return BYTES_IN_TERABIT;
	}

}
uint64_t ByteSize::BytesInPetabit(ByteUnit unit) {

	switch (unit) {
	case ByteUnit::Binary:
		return (std::ceil)(BYTES_IN_PEBIBIT);
	case ByteUnit::Decimal:
		return BYTES_IN_PETABIT;
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

std::string ByteSize::KilobitSymbol(BytePrefix prefix = BytePrefix::IEC) {

	switch (prefix) {
	case BytePrefix::IEC:
		return "Kibit";
	case BytePrefix::JEDEC:
		return "Kbit";
	case BytePrefix::Metric:
		return "kbit";
	}

}
std::string ByteSize::MegabitSymbol(BytePrefix prefix = BytePrefix::IEC) {

	switch (prefix) {
	case BytePrefix::IEC:
		return "Mibit";
	case BytePrefix::JEDEC:
	case BytePrefix::Metric:
		return "Mbit";
	}


}
std::string ByteSize::GigabitSymbol(BytePrefix prefix = BytePrefix::IEC) {

	switch (prefix) {
	case BytePrefix::IEC:
		return "Gibit";
	case BytePrefix::JEDEC:
	case BytePrefix::Metric:
		return "Gbit";
	}

}
std::string ByteSize::TerabitSymbol(BytePrefix prefix = BytePrefix::IEC) {

	switch (prefix) {
	case BytePrefix::IEC:
		return "Tibit";
	case BytePrefix::JEDEC:
	case BytePrefix::Metric:
		return "Tbit";
	}

}
std::string ByteSize::PetabitSymbol(BytePrefix prefix = BytePrefix::IEC) {

	switch (prefix) {
	case BytePrefix::IEC:
		return "Pibit";
	case BytePrefix::JEDEC:
	case BytePrefix::Metric:
		return "Pbit";
	}

}