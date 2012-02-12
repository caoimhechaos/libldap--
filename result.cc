#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <string>
#include <vector>
#include "ldap++.h"
#include <ldap.h>

namespace ldap_client
{
/**
 * Used by LDAPClient::Search to create LDAPResult objects.
 *
 * @param conn Connection the object was fetched over.
 * @param msg  LDAPMessage containing the retrieved data.
 */
LDAPResult::LDAPResult(LDAPConnection* conn, LDAPMessage* msg)
: _conn(conn)
{
	LDAPMessage *e = ldap_first_entry(_conn->_ldap, msg);

	if (e != NULL) do
	{
		_entries.push_back(LDAPEntry(_conn, e));
	}
	while ((e = ldap_next_entry(_conn->_ldap, e)) != NULL);

	ldap_msgfree(msg);
}

/**
 * Get a vector of all entries in the LDAP result.
 *
 * @return Vector of all LDAPEntry objects in the result.
 */
std::vector<LDAPEntry>* LDAPResult::GetEntries()
{
	return &_entries;
}
}
