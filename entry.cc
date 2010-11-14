#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <string>
#include <vector>
#include <unordered_map>
#include <boost/scoped_ptr.hpp>
#include <memory>
#include <ldap++.h>
#include <ldap.h>

namespace ldap_client
{
LDAPEntry::LDAPEntry(LDAPConnection* conn, LDAPMessage* entry)
: _conn(conn), _msg(entry)
{
	char *attr = ldap_get_dn(_conn->_ldap, _msg);
	char **vals;
	BerElement *ptr;

	_dn = std::string(attr);
	ldap_memfree(attr);

	for (attr = ldap_first_attribute(_conn->_ldap, _msg, &ptr);
		attr != 0; attr = ldap_next_attribute(_conn->_ldap, _msg, ptr))
	{
		std::vector<std::string>* values = new std::vector<std::string>;
		vals = ldap_get_values(_conn->_ldap, _msg, attr);

		for (int i = 0; vals[i] != NULL; i++)
			values->push_back(std::string(vals[i]));

		ldap_value_free(vals);
		ldap_memfree(attr);

		_data[attr] = values;
	}

	if (ptr != 0)
		ber_free(ptr, 0);
}

LDAPEntry::~LDAPEntry()
{
	std::unordered_map<std::string, std::vector<std::string>*>::iterator iter;

	for (iter = _data.begin(); iter != _data.end(); iter++)
		delete (*iter).second;
}

std::string LDAPEntry::GetDN()
{
	return _dn;
}
}
