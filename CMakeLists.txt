cmake_minimum_required (VERSION 2.6) 
project (ldap++) 

set(ldap++_library_type SHARED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
add_library (ldap++ SHARED connection.cc entry.cc exceptions.cc result.cc)
target_link_libraries(ldap++ ldap)
