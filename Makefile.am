TESTS=			searchable_vector_test
check_PROGRAMS=		${TESTS}

library_includedir=	${includedir}/libldap++
library_include_HEADERS= ldap++.h

ACLOCAL_AMFLAGS=	-I m4
lib_LTLIBRARIES=	libldap++.la
libldap___la_SOURCES=	connection.cc entry.cc exceptions.cc result.cc \
		       	ldap_compat.cc
libldap___la_LDFLAGS=	-version-info ${LIBRARY_VERSION}

searchable_vector_test_SOURCES=	searchable_vector_test.cc
searchable_vector_test_LDADD=	-lcppunit
