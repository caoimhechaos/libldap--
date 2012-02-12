#include <ldap.h>
#include "ldap++.h"

namespace ldap_client
{
LDAPException::LDAPException()
: std::exception(), _reason(0)
{
}

LDAPException::LDAPException(const char *str)
: std::exception(), _reason(str)
{
}

const char* LDAPException::what() const throw()
{
	return _reason;
}

/**
 * Throw the appropriate exception for the given LDAP error code.
 * If LDAP_SUCCESS is passed, no error is thrown.
 *
 * @param errcode Valid LDAP error code.
 * @throw LDAPError Error corresponding to the error code.
 */
void LDAPErrCode2Exception(int errcode)
{
	switch (errcode)
	{
	case LDAP_SUCCESS:
		break;

	/* LDAP protocol result codes. */
	case LDAP_OPERATIONS_ERROR:
		throw LDAPErrOperationsError(ldap_err2string(errcode));
	case LDAP_PROTOCOL_ERROR:
		throw LDAPErrProtocolError(ldap_err2string(errcode));
	case LDAP_TIMELIMIT_EXCEEDED:
		throw LDAPErrTimelimitExceeded(ldap_err2string(errcode));
	case LDAP_SIZELIMIT_EXCEEDED:
		throw LDAPErrSizelimitExceeded(ldap_err2string(errcode));
	case LDAP_COMPARE_FALSE:
		throw LDAPErrCompareFalse(ldap_err2string(errcode));
	case LDAP_COMPARE_TRUE:
		throw LDAPErrCompareTrue(ldap_err2string(errcode));
	case LDAP_STRONG_AUTH_NOT_SUPPORTED:
		throw LDAPErrStrongAuthNotSupported(ldap_err2string(errcode));
	case LDAP_STRONG_AUTH_REQUIRED:
		throw LDAPErrStrongAuthRequired(ldap_err2string(errcode));
	case LDAP_PARTIAL_RESULTS:
		throw LDAPErrPartialResults(ldap_err2string(errcode));
	case LDAP_NO_SUCH_ATTRIBUTE:
		throw LDAPErrNoSuchAttribute(ldap_err2string(errcode));
	case LDAP_UNDEFINED_TYPE:
		throw LDAPErrUndefinedType(ldap_err2string(errcode));
	case LDAP_INAPPROPRIATE_MATCHING:
		throw LDAPErrInappropriateMatching(ldap_err2string(errcode));
	case LDAP_CONSTRAINT_VIOLATION:
		throw LDAPErrConstraintViolation(ldap_err2string(errcode));
	case LDAP_TYPE_OR_VALUE_EXISTS:
		throw LDAPErrTypeOrValueExists(ldap_err2string(errcode));
	case LDAP_INVALID_SYNTAX:
		throw LDAPErrInvalidSyntax(ldap_err2string(errcode));
	case LDAP_NO_SUCH_OBJECT:
		throw LDAPErrNoSuchObject(ldap_err2string(errcode));
	case LDAP_ALIAS_PROBLEM:
		throw LDAPErrAliasProblem(ldap_err2string(errcode));
	case LDAP_INVALID_DN_SYNTAX:
		throw LDAPErrInvalidDNSyntax(ldap_err2string(errcode));
	case LDAP_IS_LEAF:
		throw LDAPErrIsLeaf(ldap_err2string(errcode));
	case LDAP_ALIAS_DEREF_PROBLEM:
		throw LDAPErrAliasDerefProblem(ldap_err2string(errcode));
	case LDAP_INAPPROPRIATE_AUTH:
		throw LDAPErrInappropriateAuth(ldap_err2string(errcode));
	case LDAP_INVALID_CREDENTIALS:
		throw LDAPErrInvalidCredentials(ldap_err2string(errcode));
	case LDAP_INSUFFICIENT_ACCESS:
		throw LDAPErrInsufficientAccess(ldap_err2string(errcode));
	case LDAP_BUSY:
		throw LDAPErrBusy(ldap_err2string(errcode));
	case LDAP_UNAVAILABLE:
		throw LDAPErrUnavailable(ldap_err2string(errcode));
	case LDAP_UNWILLING_TO_PERFORM:
		throw LDAPErrUnwillingToPerform(ldap_err2string(errcode));
	case LDAP_LOOP_DETECT:
		throw LDAPErrLoopDetect(ldap_err2string(errcode));
	case LDAP_NAMING_VIOLATION:
		throw LDAPErrNamingViolation(ldap_err2string(errcode));
	case LDAP_OBJECT_CLASS_VIOLATION:
		throw LDAPErrObjectClassViolation(ldap_err2string(errcode));
	case LDAP_NOT_ALLOWED_ON_NONLEAF:
		throw LDAPErrNotAllowedOnNonleaf(ldap_err2string(errcode));
	case LDAP_NOT_ALLOWED_ON_RDN:
		throw LDAPErrNotAllowedOnRDN(ldap_err2string(errcode));
	case LDAP_ALREADY_EXISTS:
		throw LDAPErrAlreadyExists(ldap_err2string(errcode));
	case LDAP_NO_OBJECT_CLASS_MODS:
		throw LDAPErrNoObjectClassMods(ldap_err2string(errcode));
	case LDAP_OTHER:
		throw LDAPErrOther(ldap_err2string(errcode));

	/* API error codes. */
	case LDAP_SERVER_DOWN:
		throw LDAPErrServerDown(ldap_err2string(errcode));
	case LDAP_LOCAL_ERROR:
		throw LDAPErrLocalError(ldap_err2string(errcode));
	case LDAP_ENCODING_ERROR:
		throw LDAPErrEncodingError(ldap_err2string(errcode));
	case LDAP_DECODING_ERROR:
		throw LDAPErrDecodingError(ldap_err2string(errcode));
	case LDAP_TIMEOUT:
		throw LDAPErrTimeout(ldap_err2string(errcode));
	case LDAP_AUTH_UNKNOWN:
		throw LDAPErrAuthUnknown(ldap_err2string(errcode));
	case LDAP_FILTER_ERROR:
		throw LDAPErrFilterError(ldap_err2string(errcode));
	case LDAP_PARAM_ERROR:
		throw LDAPErrParamError(ldap_err2string(errcode));
	case LDAP_NO_MEMORY:
		throw LDAPErrNoMemory(ldap_err2string(errcode));
	case LDAP_USER_CANCELLED:
		throw LDAPErrUserCancelled(ldap_err2string(errcode));
	case LDAP_CONNECT_ERROR:
		throw LDAPErrConnectError(ldap_err2string(errcode));
	case LDAP_NOT_SUPPORTED:
		throw LDAPErrNotSupported(ldap_err2string(errcode));
	case LDAP_CONTROL_NOT_FOUND:
		throw LDAPErrControlNotFound(ldap_err2string(errcode));
	case LDAP_NO_RESULTS_RETURNED:
		throw LDAPErrNoResultsReturned(ldap_err2string(errcode));
	case LDAP_MORE_RESULTS_TO_RETURN:
		throw LDAPErrMoreResultsToReturn(ldap_err2string(errcode));
	case LDAP_CLIENT_LOOP:
		throw LDAPErrClientLoop(ldap_err2string(errcode));
	case LDAP_REFERRAL_LIMIT_EXCEEDED:
		throw LDAPErrReferralLimitExceeded(ldap_err2string(errcode));

	/* We don't know what went wrong. */
	default:
		throw LDAPException(ldap_err2string(errcode));
	}
}
}
