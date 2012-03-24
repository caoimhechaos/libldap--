/*
 * LDAP compatibility methods for older versions. Mostly taken from OpenLDAP.
 */
#include <ldap.h>
#include <lber.h>

#ifndef HAVE_LDAP_ALLOC_BER_WITH_OPTIONS
BerElement*
ldap_alloc_ber_with_options(LDAP* ld)
{
	return ber_alloc();
}
#endif /* HAVE_LDAP_ALLOC_BER_WITH_OPTIONS */

#ifndef HAVE_LDAP_CREATE_PAGE_CONTROL_VALUE
/* ---------------------------------------------------------------------------
   ldap_create_page_control_value

   Create and encode the value of the paged results control (RFC 2696).

   ld          (IN) An LDAP session handle
   pagesize    (IN) Page size requested
   cookie      (IN) Opaque structure used by the server to track its
   location in the search results.  NULL on the
   first call.
   value      (OUT) Control value, SHOULD be freed by calling
   ldap_memfree() when done.

   pagedResultsControl ::= SEQUENCE {
   controlType     1.2.840.113556.1.4.319,
   criticality     BOOLEAN DEFAULT FALSE,
   controlValue    searchControlValue }

   searchControlValue ::= SEQUENCE {
   size            INTEGER (0..maxInt),
   -- requested page size from client
   -- result set size estimate from server
   cookie          OCTET STRING }

   ---------------------------------------------------------------------------*/
int
ldap_create_page_control_value(
		LDAP *ld,
		ber_int_t pagesize,
		struct berval	*cookie,
		struct berval	*value )
{
	BerElement	*ber = NULL;
	ber_tag_t	tag;
	struct berval	null_cookie = { 0, NULL };

	if ( ld == NULL || value == NULL ||
			pagesize < 1 || pagesize > LDAP_MAXINT )
	{
		return LDAP_PARAM_ERROR;
	}

	value->bv_val = NULL;
	value->bv_len = 0;

	if ( cookie == NULL ) {
		cookie = &null_cookie;
	}

	ber = ldap_alloc_ber_with_options( ld );
	if ( ber == NULL ) {
		return LDAP_NO_MEMORY;
	}

	tag = ber_printf( ber, "{iO}", pagesize, cookie );
	if ( tag == LBER_ERROR ) {
		ber_free( ber, 1 );
		return LDAP_ENCODING_ERROR;
	}

	if ( ber_flatten2( ber, value, 1 ) == -1 ) {
		return LDAP_NO_MEMORY;
		if ( ber != NULL ) {
			ber_free( ber, 1 );
		}
	}

done:;

	return LDAP_SUCCESS;
}
#endif /* HAVE_LDAP_CREATE_PAGE_CONTROL_VALUE */

#ifndef HAVE_LDAP_PARSE_PAGERESPONSE_CONTROL
/* ---------------------------------------------------------------------------
    ldap_parse_pageresponse_control

    Decode a page control.

    ld          (IN) An LDAP session handle
    ctrl        (IN) The page response control
    count      (OUT) The number of entries in the page.
    cookie     (OUT) Opaque cookie.  Use ldap_memfree() to
                     free the bv_val member of this structure.

   ---------------------------------------------------------------------------*/

int
ldap_parse_pageresponse_control(
		LDAP *ld,
		LDAPControl *ctrl,
		ber_int_t *countp,
		struct berval *cookie )
{
	int ld_errno;
	BerElement *ber;
	ber_tag_t tag;
	ber_int_t count;

	if ( ld == NULL || ctrl == NULL || cookie == NULL ) {
		return LDAP_PARAM_ERROR;
	}

	/* Create a BerElement from the berval returned in the control. */
	ber = ber_init( &ctrl->ldctl_value );

	if ( ber == NULL ) {
		return LDAP_NO_MEMORY;
	}

	/* Extract the count and cookie from the control. */
	tag = ber_scanf( ber, "{io}", &count, cookie );
	ber_free( ber, 1 );

	if ( tag == LBER_ERROR ) {
		ld_errno = LDAP_DECODING_ERROR;
	} else {
		ld_errno = LDAP_SUCCESS;

		if ( countp != NULL ) {
			*countp = (unsigned long)count;
		}
	}

	return ld_errno;
}
#endif /* HAVE_LDAP_PARSE_PAGERESPONSE_CONTROL */

#ifndef HAVE_LDAP_CONTROL_FIND
/*
 * Find a LDAPControl
 */
LDAPControl *
ldap_control_find(
		LDAP_CONST char *oid,
		LDAPControl **ctrls,
		LDAPControl ***nextctrlp )
{
	if ( oid == NULL || ctrls == NULL || *ctrls == NULL ) {
		return NULL;
	}

	for( ; *ctrls != NULL; ctrls++ ) {
		if( strcmp( (*ctrls)->ldctl_oid, oid ) == 0 ) {
			if ( nextctrlp != NULL ) {
				*nextctrlp = ctrls + 1;
			}

			return *ctrls;
		}
	}

	if ( nextctrlp != NULL ) {
		*nextctrlp = NULL;
	}

	return NULL;
}
#endif /* HAVE_LDAP_CONTROL_FIND */
