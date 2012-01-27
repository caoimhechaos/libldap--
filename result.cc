#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <string>
#include <vector>
#include <ext/hash_map>
#include <ldap++.h>
#include <ldap.h>

namespace ldap_client
{
LDAPResult::LDAPResult(LDAPConnection* conn, LDAPMessage* msg)
: _conn(conn), _msg(msg)
{
	LDAPMessage *e = ldap_first_entry(_conn->_ldap, _msg);

	if (e != NULL) do
	{
		_entries.push_back(LDAPEntry(_conn, e));
	}
	while ((e = ldap_next_entry(_conn->_ldap, e)) != NULL);
}

LDAPResult::~LDAPResult()
{
	ldap_msgfree(_msg);
}

std::vector<LDAPEntry>* LDAPResult::GetEntries()
{
	return &_entries;
}
}
