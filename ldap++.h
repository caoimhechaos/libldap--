#ifndef INCLUDED_LDAPXX_H
#define INCLUDED_LDAPXX_H 1

#include <string>
#include <vector>
#include <unordered_map>
#include <ldap.h>

namespace ldap_client
{
const std::vector<std::string> kLdapFilterAll = { "+" };

class LDAPConnection;

class LDAPException : public std::exception {
    public:
	LDAPException();
	LDAPException(const char *str);

	virtual const char* what() const throw();

    protected:
	const char *_reason;
};

/* LDAP protocol result codes. */
class LDAPErrOperationsError : public LDAPException
{
    public:
	LDAPErrOperationsError() : LDAPException() {}
	LDAPErrOperationsError(const char *str) : LDAPException(str) {}
};

class LDAPErrProtocolError : public LDAPException
{
    public:
	LDAPErrProtocolError() : LDAPException() {}
	LDAPErrProtocolError(const char *str) : LDAPException(str) {}
};

class LDAPErrTimelimitExceeded : public LDAPException
{
    public:
	LDAPErrTimelimitExceeded() : LDAPException() {}
	LDAPErrTimelimitExceeded(const char *str) : LDAPException(str) {}
};

class LDAPErrSizelimitExceeded : public LDAPException
{
    public:
	LDAPErrSizelimitExceeded() : LDAPException() {}
	LDAPErrSizelimitExceeded(const char *str) : LDAPException(str) {}
};

class LDAPErrCompareFalse : public LDAPException
{
    public:
	LDAPErrCompareFalse() : LDAPException() {}
	LDAPErrCompareFalse(const char *str) : LDAPException(str) {}
};

class LDAPErrCompareTrue : public LDAPException
{
    public:
	LDAPErrCompareTrue() : LDAPException() {}
	LDAPErrCompareTrue(const char *str) : LDAPException(str) {}
};

class LDAPErrStrongAuthNotSupported : public LDAPException
{
    public:
	LDAPErrStrongAuthNotSupported() : LDAPException() {}
	LDAPErrStrongAuthNotSupported(const char *str) : LDAPException(str) {}
};

class LDAPErrStrongAuthRequired : public LDAPException
{
    public:
	LDAPErrStrongAuthRequired() : LDAPException() {}
	LDAPErrStrongAuthRequired(const char *str) : LDAPException(str) {}
};

class LDAPErrPartialResults : public LDAPException
{
    public:
	LDAPErrPartialResults() : LDAPException() {}
	LDAPErrPartialResults(const char *str) : LDAPException(str) {}
};

class LDAPErrNoSuchAttribute : public LDAPException
{
    public:
	LDAPErrNoSuchAttribute() : LDAPException() {}
	LDAPErrNoSuchAttribute(const char *str) : LDAPException(str) {}
};

class LDAPErrUndefinedType : public LDAPException
{
    public:
	LDAPErrUndefinedType() : LDAPException() {}
	LDAPErrUndefinedType(const char *str) : LDAPException(str) {}
};

class LDAPErrInappropriateMatching : public LDAPException
{
    public:
	LDAPErrInappropriateMatching() : LDAPException() {}
	LDAPErrInappropriateMatching(const char *str) : LDAPException(str) {}
};

class LDAPErrConstraintViolation : public LDAPException
{
    public:
	LDAPErrConstraintViolation() : LDAPException() {}
	LDAPErrConstraintViolation(const char *str) : LDAPException(str) {}
};

class LDAPErrTypeOrValueExists : public LDAPException
{
    public:
	LDAPErrTypeOrValueExists() : LDAPException() {}
	LDAPErrTypeOrValueExists(const char *str) : LDAPException(str) {}
};

class LDAPErrInvalidSyntax : public LDAPException
{
    public:
	LDAPErrInvalidSyntax() : LDAPException() {}
	LDAPErrInvalidSyntax(const char *str) : LDAPException(str) {}
};

class LDAPErrNoSuchObject : public LDAPException
{
    public:
	LDAPErrNoSuchObject() : LDAPException() {}
	LDAPErrNoSuchObject(const char *str) : LDAPException(str) {}
};

class LDAPErrAliasProblem : public LDAPException
{
    public:
	LDAPErrAliasProblem() : LDAPException() {}
	LDAPErrAliasProblem(const char *str) : LDAPException(str) {}
};

class LDAPErrInvalidDNSyntax : public LDAPException
{
    public:
	LDAPErrInvalidDNSyntax() : LDAPException() {}
	LDAPErrInvalidDNSyntax(const char *str) : LDAPException(str) {}
};

class LDAPErrIsLeaf : public LDAPException
{
    public:
	LDAPErrIsLeaf() : LDAPException() {}
	LDAPErrIsLeaf(const char *str) : LDAPException(str) {}
};

class LDAPErrAliasDerefProblem : public LDAPException
{
    public:
	LDAPErrAliasDerefProblem() : LDAPException() {}
	LDAPErrAliasDerefProblem(const char *str) : LDAPException(str) {}
};

class LDAPErrInappropriateAuth : public LDAPException
{
    public:
	LDAPErrInappropriateAuth() : LDAPException() {}
	LDAPErrInappropriateAuth(const char *str) : LDAPException(str) {}
};

class LDAPErrInvalidCredentials : public LDAPException
{
    public:
	LDAPErrInvalidCredentials() : LDAPException() {}
	LDAPErrInvalidCredentials(const char *str) : LDAPException(str) {}
};

class LDAPErrInsufficientAccess : public LDAPException
{
    public:
	LDAPErrInsufficientAccess() : LDAPException() {}
	LDAPErrInsufficientAccess(const char *str) : LDAPException(str) {}
};

class LDAPErrBusy : public LDAPException
{
    public:
	LDAPErrBusy() : LDAPException() {}
	LDAPErrBusy(const char *str) : LDAPException(str) {}
};

class LDAPErrUnavailable : public LDAPException
{
    public:
	LDAPErrUnavailable() : LDAPException() {}
	LDAPErrUnavailable(const char *str) : LDAPException(str) {}
};

class LDAPErrUnwillingToPerform : public LDAPException
{
    public:
	LDAPErrUnwillingToPerform() : LDAPException() {}
	LDAPErrUnwillingToPerform(const char *str) : LDAPException(str) {}
};

class LDAPErrLoopDetect : public LDAPException
{
    public:
	LDAPErrLoopDetect() : LDAPException() {}
	LDAPErrLoopDetect(const char *str) : LDAPException(str) {}
};

class LDAPErrNamingViolation : public LDAPException
{
    public:
	LDAPErrNamingViolation() : LDAPException() {}
	LDAPErrNamingViolation(const char *str) : LDAPException(str) {}
};

class LDAPErrObjectClassViolation : public LDAPException
{
    public:
	LDAPErrObjectClassViolation() : LDAPException() {}
	LDAPErrObjectClassViolation(const char *str) : LDAPException(str) {}
};

class LDAPErrNotAllowedOnNonleaf : public LDAPException
{
    public:
	LDAPErrNotAllowedOnNonleaf() : LDAPException() {}
	LDAPErrNotAllowedOnNonleaf(const char *str) : LDAPException(str) {}
};

class LDAPErrNotAllowedOnRDN : public LDAPException
{
    public:
	LDAPErrNotAllowedOnRDN() : LDAPException() {}
	LDAPErrNotAllowedOnRDN(const char *str) : LDAPException(str) {}
};

class LDAPErrAlreadyExists : public LDAPException
{
    public:
	LDAPErrAlreadyExists() : LDAPException() {}
	LDAPErrAlreadyExists(const char *str) : LDAPException(str) {}
};

class LDAPErrNoObjectClassMods : public LDAPException
{
    public:
	LDAPErrNoObjectClassMods() : LDAPException() {}
	LDAPErrNoObjectClassMods(const char *str) : LDAPException(str) {}
};

class LDAPErrOther : public LDAPException
{
    public:
	LDAPErrOther() : LDAPException() {}
	LDAPErrOther(const char *str) : LDAPException(str) {}
};

/* API error codes. */
class LDAPErrServerDown : public LDAPException
{
    public:
	LDAPErrServerDown() : LDAPException() {}
	LDAPErrServerDown(const char *str) : LDAPException(str) {}
};

class LDAPErrLocalError : public LDAPException
{
    public:
	LDAPErrLocalError() : LDAPException() {}
	LDAPErrLocalError(const char *str) : LDAPException(str) {}
};

class LDAPErrEncodingError : public LDAPException
{
    public:
	LDAPErrEncodingError() : LDAPException() {}
	LDAPErrEncodingError(const char *str) : LDAPException(str) {}
};

class LDAPErrDecodingError : public LDAPException
{
    public:
	LDAPErrDecodingError() : LDAPException() {}
	LDAPErrDecodingError(const char *str) : LDAPException(str) {}
};

class LDAPErrTimeout : public LDAPException
{
    public:
	LDAPErrTimeout() : LDAPException() {}
	LDAPErrTimeout(const char *str) : LDAPException(str) {}
};

class LDAPErrAuthUnknown : public LDAPException
{
    public:
	LDAPErrAuthUnknown() : LDAPException() {}
	LDAPErrAuthUnknown(const char *str) : LDAPException(str) {}
};

class LDAPErrFilterError : public LDAPException
{
    public:
	LDAPErrFilterError() : LDAPException() {}
	LDAPErrFilterError(const char *str) : LDAPException(str) {}
};

class LDAPErrParamError : public LDAPException
{
    public:
	LDAPErrParamError() : LDAPException() {}
	LDAPErrParamError(const char *str) : LDAPException(str) {}
};

class LDAPErrNoMemory : public LDAPException
{
    public:
	LDAPErrNoMemory() : LDAPException() {}
	LDAPErrNoMemory(const char *str) : LDAPException(str) {}
};

class LDAPErrUserCancelled : public LDAPException
{
    public:
	LDAPErrUserCancelled() : LDAPException() {}
	LDAPErrUserCancelled(const char *str) : LDAPException(str) {}
};

class LDAPErrConnectError : public LDAPException
{
    public:
	LDAPErrConnectError() : LDAPException() {}
	LDAPErrConnectError(const char *str) : LDAPException(str) {}
};

class LDAPErrNotSupported : public LDAPException
{
    public:
	LDAPErrNotSupported() : LDAPException() {}
	LDAPErrNotSupported(const char *str) : LDAPException(str) {}
};

class LDAPErrControlNotFound : public LDAPException
{
    public:
	LDAPErrControlNotFound() : LDAPException() {}
	LDAPErrControlNotFound(const char *str) : LDAPException(str) {}
};

class LDAPErrNoResultsReturned : public LDAPException
{
    public:
	LDAPErrNoResultsReturned() : LDAPException() {}
	LDAPErrNoResultsReturned(const char *str) : LDAPException(str) {}
};

class LDAPErrMoreResultsToReturn : public LDAPException
{
    public:
	LDAPErrMoreResultsToReturn() : LDAPException() {}
	LDAPErrMoreResultsToReturn(const char *str) : LDAPException(str) {}
};

class LDAPErrClientLoop : public LDAPException
{
    public:
	LDAPErrClientLoop() : LDAPException() {}
	LDAPErrClientLoop(const char *str) : LDAPException(str) {}
};

class LDAPErrReferralLimitExceeded : public LDAPException
{
    public:
	LDAPErrReferralLimitExceeded() : LDAPException() {}
	LDAPErrReferralLimitExceeded(const char *str) : LDAPException(str) {}
};

void LDAPErrCode2Exception(int errcode);

class LDAPEntry
{
    public:
	LDAPEntry(LDAPConnection *conn, LDAPMessage *entry);
	~LDAPEntry();

	std::string GetDN();
	std::vector<std::string>* GetKeys();
	std::string* GetFirstValue(std::string key);
	std::vector<std::string>* GetValue(std::string key);

    private:
	LDAPConnection *_conn;
	LDAPMessage *_msg;
	std::string _dn;
	std::unordered_map<std::string, std::vector<std::string>*> _data;
};

class LDAPResult
{
    public:
	LDAPResult(LDAPConnection* conn, LDAPMessage* msg);
	~LDAPResult();

	std::vector<LDAPEntry>* GetEntries();

    private:
	LDAPConnection* _conn;
	LDAPMessage* _msg;
	std::vector<LDAPEntry> _entries;
};

void LDAPSetDebuglevel(int newlevel);

class LDAPConnection
{
	friend class LDAPResult;
	friend class LDAPEntry;

    public:
	LDAPConnection(std::string uri, int version = LDAP_VERSION3);
	~LDAPConnection();

	std::string GetLastError();
	void SetVersion(int newversion);
	void SimpleBind(std::string user, std::string password);
	void SASLBind(std::string user, std::string password);

	LDAPResult* Search(const std::string base, const std::string filter);
	LDAPResult* Search(const std::string base, const std::string filter,
		long timeout);
	LDAPResult* Search(const std::string base, int scope,
		const std::string filter);
	LDAPResult* Search(const std::string base, int scope,
		const std::string filter, long timeout);
	LDAPResult* Search(const std::string base, int scope,
		const std::string filter, const std::vector<std::string> attrs);
	LDAPResult* Search(const std::string base, int scope,
		const std::string filter,
		const std::vector<std::string> attrs, long timeout);

    protected:
	LDAP *_ldap;
};

}

#endif /* INCLUDED_LDAPXX_H */
