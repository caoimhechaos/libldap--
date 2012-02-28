/*
 * searchable_vector_test.cc
 *
 *  Created on: Feb 28, 2012
 *      Author: Caoimhe Clausen
 */
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "ldap++.h"

using namespace std;

namespace testing {
class SearchableVectorTest : public CppUnit::TestCase {
	CPPUNIT_TEST_SUITE(SearchableVectorTest);
	CPPUNIT_TEST(testSearchableVector);
	CPPUNIT_TEST_SUITE_END();

public:
	void testSearchableVector();
};

void
SearchableVectorTest::testSearchableVector()
{
	ldap_client::SearchableVector<string> v;

	v.push_back("Hello");

	CPPUNIT_ASSERT(v.Contains("Hello"));
	CPPUNIT_ASSERT_ASSERTION_FAIL(CPPUNIT_ASSERT(v.Contains("Otto")));
}

CPPUNIT_TEST_SUITE_REGISTRATION(SearchableVectorTest);

};

int main( int argc, char **argv)
{
  CppUnit::TextUi::TestRunner runner;
  CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
  runner.addTest( registry.makeTest() );
  bool wasSuccessful = runner.run( "", false );
  return !wasSuccessful;
}
