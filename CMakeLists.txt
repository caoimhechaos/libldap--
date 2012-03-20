cmake_minimum_required (VERSION 2.6) 
project (ldap++) 

set(ldap++_library_type SHARED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
add_library (ldap++ SHARED connection.cc entry.cc exceptions.cc result.cc)
target_link_libraries(ldap++ ldap)

install(TARGETS ldap++
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
install(FILES ldap++.h
  DESTINATION include)

# Package managemenet
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "libldap++")
set(CPACK_PACKAGE_VERSION "0.9")
set(CPACK_PACKAGE_CONTACT "tonnerre@ancient-solutions.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "C++ client library for LDAP")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libldap-2.4-2")
set(CPACK_RPM_PACKAGE_REQUIRES "libldap >= 2.4")

include(CPack)
