#include <string>
#include <ldap++.h>
#include <ldap.h>

namespace ldap
{
LDAPConnection::LDAPConnection(std::string uri)
{
	int rc;

	rc = ldap_initialize(&this->_ldap, uri.c_str());
	if (rc)
		LDAPErrCode2Exception(rc);
}
}
