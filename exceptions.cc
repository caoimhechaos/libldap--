#include <ldap.h>
#include <ldap++.h>

namespace ldap
{
void LDAPErrCode2Exception(int errcode)
{
	switch (errcode)
	{
	case LDAP_SUCCESS:
		break;

	/* LDAP protocol result codes. */
	case LDAP_OPERATIONS_ERROR:
		throw LDAPErrOperationsError();
	case LDAP_PROTOCOL_ERROR:
		throw LDAPErrProtocolError();
	case LDAP_TIMELIMIT_EXCEEDED:
		throw LDAPErrTimelimitExceeded();
	case LDAP_SIZELIMIT_EXCEEDED:
		throw LDAPErrSizelimitExceeded();
	case LDAP_COMPARE_FALSE:
		throw LDAPErrCompareFalse();
	case LDAP_COMPARE_TRUE:
		throw LDAPErrCompareTrue();
	case LDAP_STRONG_AUTH_NOT_SUPPORTED:
		throw LDAPErrStrongAuthNotSupported();
	case LDAP_STRONG_AUTH_REQUIRED:
		throw LDAPErrStrongAuthRequired();
	case LDAP_PARTIAL_RESULTS:
		throw LDAPErrPartialResults();
	case LDAP_NO_SUCH_ATTRIBUTE:
		throw LDAPErrNoSuchAttribute();
	case LDAP_UNDEFINED_TYPE:
		throw LDAPErrUndefinedType();
	case LDAP_INAPPROPRIATE_MATCHING:
		throw LDAPErrInappropriateMatching();
	case LDAP_CONSTRAINT_VIOLATION:
		throw LDAPErrConstraintViolation();
	case LDAP_TYPE_OR_VALUE_EXISTS:
		throw LDAPErrTypeOrValueExists();
	case LDAP_INVALID_SYNTAX:
		throw LDAPErrInvalidSyntax();
	case LDAP_NO_SUCH_OBJECT:
		throw LDAPErrNoSuchObject();
	case LDAP_ALIAS_PROBLEM:
		throw LDAPErrAliasProblem();
	case LDAP_INVALID_DN_SYNTAX:
		throw LDAPErrInvalidDNSyntax();
	case LDAP_IS_LEAF:
		throw LDAPErrIsLeaf();
	case LDAP_ALIAS_DEREF_PROBLEM:
		throw LDAPErrAliasDerefProblem();
	case LDAP_INAPPROPRIATE_AUTH:
		throw LDAPErrInappropriateAuth();
	case LDAP_INVALID_CREDENTIALS:
		throw LDAPErrInvalidCredentials();
	case LDAP_INSUFFICIENT_ACCESS:
		throw LDAPErrInsufficientAccess();
	case LDAP_BUSY:
		throw LDAPErrBusy();
	case LDAP_UNAVAILABLE:
		throw LDAPErrUnavailable();
	case LDAP_UNWILLING_TO_PERFORM:
		throw LDAPErrUnwillingToPerform();
	case LDAP_LOOP_DETECT:
		throw LDAPErrLoopDetect();
	case LDAP_NAMING_VIOLATION:
		throw LDAPErrNamingViolation();
	case LDAP_OBJECT_CLASS_VIOLATION:
		throw LDAPErrObjectClassViolation();
	case LDAP_NOT_ALLOWED_ON_NONLEAF:
		throw LDAPErrNotAllowedOnNonleaf();
	case LDAP_NOT_ALLOWED_ON_RDN:
		throw LDAPErrNotAllowedOnRDN();
	case LDAP_ALREADY_EXISTS:
		throw LDAPErrAlreadyExists();
	case LDAP_NO_OBJECT_CLASS_MODS:
		throw LDAPErrNoObjectClassMods();
	case LDAP_OTHER:
		throw LDAPErrOther();

	/* API error codes. */
	case LDAP_SERVER_DOWN:
		throw LDAPErrServerDown();
	case LDAP_LOCAL_ERROR:
		throw LDAPErrLocalError();
	case LDAP_ENCODING_ERROR:
		throw LDAPErrEncodingError();
	case LDAP_DECODING_ERROR:
		throw LDAPErrDecodingError();
	case LDAP_TIMEOUT:
		throw LDAPErrTimeout();
	case LDAP_AUTH_UNKNOWN:
		throw LDAPErrAuthUnknown();
	case LDAP_FILTER_ERROR:
		throw LDAPErrFilterError();
	case LDAP_PARAM_ERROR:
		throw LDAPErrParamError();
	case LDAP_NO_MEMORY:
		throw LDAPErrNoMemory();
	case LDAP_USER_CANCELLED:
		throw LDAPErrUserCancelled();
	case LDAP_CONNECT_ERROR:
		throw LDAPErrConnectError();
	case LDAP_NOT_SUPPORTED:
		throw LDAPErrNotSupported();
	case LDAP_CONTROL_NOT_FOUND:
		throw LDAPErrControlNotFound();
	case LDAP_NO_RESULTS_RETURNED:
		throw LDAPErrNoResultsReturned();
	case LDAP_MORE_RESULTS_TO_RETURN:
		throw LDAPErrMoreResultsToReturn();
	case LDAP_CLIENT_LOOP:
		throw LDAPErrClientLoop();
	case LDAP_REFERRAL_LIMIT_EXCEEDED:
		throw LDAPErrReferralLimitExceeded();

	/* We don't know what went wrong. */
	default:
		throw LDAPException();
	}
}
}
