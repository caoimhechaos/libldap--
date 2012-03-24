/*
 * LDAP compatibility methods for older versions.
 *
 *  Created on: Mar 23, 2012
 *      Author: Caoimhe Clausen
 */

#ifndef LDAP_COMPAT_H_
#define LDAP_COMPAT_H_

#include <ldap.h>
#include <lber.h>

#ifndef HAVE_LDAP_CREATE_PAGE_CONTROL_VALUE
int
ldap_create_page_control_value(
		LDAP *ld,
		ber_int_t pagesize,
		struct berval	*cookie,
		struct berval	*value );
#endif
#ifndef HAVE_LDAP_PARSE_PAGERESPONSE_CONTROL
int
ldap_parse_pageresponse_control(
		LDAP *ld,
		LDAPControl *ctrl,
		ber_int_t *countp,
		struct berval *cookie );
#endif
#ifndef HAVE_LDAP_CONTROL_FIND
LDAPControl *
ldap_control_find(
		LDAP_CONST char *oid,
		LDAPControl **ctrls,
		LDAPControl ***nextctrlp );
#endif

#endif /* LDAP_COMPAT_H_ */
