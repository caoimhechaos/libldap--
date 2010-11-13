#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <string>
#include <vector>
#include <ldap++.h>
#include <ldap.h>

namespace ldap_client
{
LDAPResult::LDAPResult(LDAPConnection* conn, LDAPMessage* msg)
: _conn(conn), _msg(msg)
{
}
}
