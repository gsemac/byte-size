#include "CppUnitTest.h"
#include "ByteSize.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests {

	TEST_CLASS(ByteSizeTests) {
public:

	TEST_METHOD(TestMethodBytesBinary) {
	
		hvn3::ByteSize bs(40.0);

		Assert::AreEqual(40.0, bs.Bytes());

	}
	TEST_METHOD(TestMethodKilobytesBinary) {

		hvn3::ByteSize bs(1536.0);

		Assert::AreEqual(1.5, bs.Kilobytes());

	}

	TEST_METHOD(TestMethodFromKilobytes) {

		hvn3::ByteSize bs = hvn3::ByteSize::FromKilobytes(1.5);

		Assert::AreEqual(1536.0, bs.Bytes());

	}

	TEST_METHOD(TestMethodToStringKilobytes) {

		hvn3::ByteSize bs = hvn3::ByteSize::FromKilobytes(1.5);

		Assert::AreEqual(std::string("1.5 KiB"), bs.ToString(2));

	}

	TEST_METHOD(TestMethodParseKilobytes) {

		hvn3::ByteSize bs = hvn3::ByteSize::Parse("1.5 KiB");

		Assert::AreEqual(std::string("1.5 KiB"), bs.ToString(2));

	}

	};

}