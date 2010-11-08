#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <string>
#include <ldap++.h>
#include <ldap.h>

namespace ldap
{
LDAPConnection::LDAPConnection(std::string uri)
{
	int rc = ldap_initialize(&this->_ldap, uri.c_str());
	if (rc)
		LDAPErrCode2Exception(rc);
}

void LDAPConnection::SetDebuglevel(int newlevel)
{
	int rc = ldap_set_option(this->_ldap, LDAP_OPT_DEBUG_LEVEL, &newlevel);
	if (rc)
		LDAPErrCode2Exception(rc);
}

void LDAPConnection::SimpleBind(std::string user, std::string password)
{
	int rc = ldap_simple_bind_s(this->_ldap, user.c_str(), password.c_str());
	if (rc)
		LDAPErrCode2Exception(rc);
}
}
