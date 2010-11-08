#ifndef INCLUDED_LDAPXX_H
#define INCLUDED_LDAPXX_H 1

#include <string>
#include <ldap.h>

namespace ldap
{

class LDAPException : public std::exception {};

/* LDAP protocol result codes. */
class LDAPErrOperationsError : public LDAPException {};
class LDAPErrProtocolError : public LDAPException {};
class LDAPErrTimelimitExceeded : public LDAPException {};
class LDAPErrSizelimitExceeded : public LDAPException {};
class LDAPErrCompareFalse : public LDAPException {};
class LDAPErrCompareTrue : public LDAPException {};
class LDAPErrStrongAuthNotSupported : public LDAPException {};
class LDAPErrStrongAuthRequired : public LDAPException {};
class LDAPErrPartialResults : public LDAPException {};
class LDAPErrNoSuchAttribute : public LDAPException {};
class LDAPErrUndefinedType : public LDAPException {};
class LDAPErrInappropriateMatching : public LDAPException {};
class LDAPErrConstraintViolation : public LDAPException {};
class LDAPErrTypeOrValueExists : public LDAPException {};
class LDAPErrInvalidSyntax : public LDAPException {};
class LDAPErrNoSuchObject : public LDAPException {};
class LDAPErrAliasProblem : public LDAPException {};
class LDAPErrInvalidDNSyntax : public LDAPException {};
class LDAPErrIsLeaf : public LDAPException {};
class LDAPErrAliasDerefProblem : public LDAPException {};
class LDAPErrInappropriateAuth : public LDAPException {};
class LDAPErrInvalidCredentials : public LDAPException {};
class LDAPErrInsufficientAccess : public LDAPException {};
class LDAPErrBusy : public LDAPException {};
class LDAPErrUnavailable : public LDAPException {};
class LDAPErrUnwillingToPerform : public LDAPException {};
class LDAPErrLoopDetect : public LDAPException {};
class LDAPErrNamingViolation : public LDAPException {};
class LDAPErrObjectClassViolation : public LDAPException {};
class LDAPErrNotAllowedOnNonleaf : public LDAPException {};
class LDAPErrNotAllowedOnRDN : public LDAPException {};
class LDAPErrAlreadyExists : public LDAPException {};
class LDAPErrNoObjectClassMods : public LDAPException {};
class LDAPErrOther : public LDAPException {};

/* API error codes. */
class LDAPErrServerDown : public LDAPException {};
class LDAPErrLocalError : public LDAPException {};
class LDAPErrEncodingError : public LDAPException {};
class LDAPErrDecodingError : public LDAPException {};
class LDAPErrTimeout : public LDAPException {};
class LDAPErrAuthUnknown : public LDAPException {};
class LDAPErrFilterError : public LDAPException {};
class LDAPErrParamError : public LDAPException {};
class LDAPErrNoMemory : public LDAPException {};
class LDAPErrUserCancelled : public LDAPException {};
class LDAPErrConnectError : public LDAPException {};
class LDAPErrNotSupported : public LDAPException {};
class LDAPErrControlNotFound : public LDAPException {};
class LDAPErrNoResultsReturned : public LDAPException {};
class LDAPErrMoreResultsToReturn : public LDAPException {};
class LDAPErrClientLoop : public LDAPException {};
class LDAPErrReferralLimitExceeded : public LDAPException {};

void LDAPErrCode2Exception(int errcode);

class LDAPConnection
{
    public:
	LDAPConnection(std::string uri);

	void SetDebuglevel(int newlevel);
	void SimpleBind(std::string user, std::string password);

    private:
	LDAP *_ldap;
};

}

#endif /* INCLUDED_LDAPXX_H */
