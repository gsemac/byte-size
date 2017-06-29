#include "CppUnitTest.h"
#include "ByteSize.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests {

	TEST_CLASS(ByteSizeTests) {
public:

	TEST_METHOD(TestMethodBytes) {
	
		hvn3::ByteSize bs(40.0);

		Assert::AreEqual(40.0, bs.Bytes());

	}

	};

}