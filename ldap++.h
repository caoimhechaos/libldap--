#ifndef INCLUDED_LDAPXX_H
#define INCLUDED_LDAPXX_H 1

#include <string>
#include <vector>
#include <map>
#include <ldap.h>

namespace ldap_client
{
const std::vector<std::string> kLdapFilterAll = { "+" };

template<class T>
class SearchableVector : public std::vector<T> {
public:
	bool Contains(T val) {
		typename std::vector<T>::const_iterator it;

		for (it = this->begin(); it != this->end(); it++)
			if (*it == val)
				return true;

		return false;
	}
};

class LDAPConnection;

class LDAPException : public std::exception {
    public:
	LDAPException();
	LDAPException(const char* str);
	LDAPException(const char* what, const std::string& diag);
	virtual ~LDAPException() throw() {};

	virtual const char* what() const throw();
	virtual const std::string diag() const throw();

    protected:
	const std::string _reason;
	const std::string _diag;
};

/* LDAP protocol result codes. */
class LDAPErrOperationsError : public LDAPException
{
    public:
	LDAPErrOperationsError() : LDAPException() {}
	LDAPErrOperationsError(const char *str) : LDAPException(str) {}
	LDAPErrOperationsError(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrProtocolError : public LDAPException
{
    public:
	LDAPErrProtocolError() : LDAPException() {}
	LDAPErrProtocolError(const char *str) : LDAPException(str) {}
	LDAPErrProtocolError(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrTimelimitExceeded : public LDAPException
{
    public:
	LDAPErrTimelimitExceeded() : LDAPException() {}
	LDAPErrTimelimitExceeded(const char *str) : LDAPException(str) {}
	LDAPErrTimelimitExceeded(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrSizelimitExceeded : public LDAPException
{
    public:
	LDAPErrSizelimitExceeded() : LDAPException() {}
	LDAPErrSizelimitExceeded(const char *str) : LDAPException(str) {}
	LDAPErrSizelimitExceeded(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrCompareFalse : public LDAPException
{
    public:
	LDAPErrCompareFalse() : LDAPException() {}
	LDAPErrCompareFalse(const char *str) : LDAPException(str) {}
	LDAPErrCompareFalse(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrCompareTrue : public LDAPException
{
    public:
	LDAPErrCompareTrue() : LDAPException() {}
	LDAPErrCompareTrue(const char *str) : LDAPException(str) {}
	LDAPErrCompareTrue(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrStrongAuthNotSupported : public LDAPException
{
    public:
	LDAPErrStrongAuthNotSupported() : LDAPException() {}
	LDAPErrStrongAuthNotSupported(const char *str) : LDAPException(str) {}
	LDAPErrStrongAuthNotSupported(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrStrongAuthRequired : public LDAPException
{
    public:
	LDAPErrStrongAuthRequired() : LDAPException() {}
	LDAPErrStrongAuthRequired(const char *str) : LDAPException(str) {}
	LDAPErrStrongAuthRequired(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrPartialResults : public LDAPException
{
    public:
	LDAPErrPartialResults() : LDAPException() {}
	LDAPErrPartialResults(const char *str) : LDAPException(str) {}
	LDAPErrPartialResults(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrNoSuchAttribute : public LDAPException
{
    public:
	LDAPErrNoSuchAttribute() : LDAPException() {}
	LDAPErrNoSuchAttribute(const char *str) : LDAPException(str) {}
	LDAPErrNoSuchAttribute(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrUndefinedType : public LDAPException
{
    public:
	LDAPErrUndefinedType() : LDAPException() {}
	LDAPErrUndefinedType(const char *str) : LDAPException(str) {}
	LDAPErrUndefinedType(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrInappropriateMatching : public LDAPException
{
    public:
	LDAPErrInappropriateMatching() : LDAPException() {}
	LDAPErrInappropriateMatching(const char *str) : LDAPException(str) {}
	LDAPErrInappropriateMatching(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrConstraintViolation : public LDAPException
{
    public:
	LDAPErrConstraintViolation() : LDAPException() {}
	LDAPErrConstraintViolation(const char *str) : LDAPException(str) {}
	LDAPErrConstraintViolation(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrTypeOrValueExists : public LDAPException
{
    public:
	LDAPErrTypeOrValueExists() : LDAPException() {}
	LDAPErrTypeOrValueExists(const char *str) : LDAPException(str) {}
	LDAPErrTypeOrValueExists(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrInvalidSyntax : public LDAPException
{
    public:
	LDAPErrInvalidSyntax() : LDAPException() {}
	LDAPErrInvalidSyntax(const char *str) : LDAPException(str) {}
	LDAPErrInvalidSyntax(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrNoSuchObject : public LDAPException
{
    public:
	LDAPErrNoSuchObject() : LDAPException() {}
	LDAPErrNoSuchObject(const char *str) : LDAPException(str) {}
	LDAPErrNoSuchObject(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrAliasProblem : public LDAPException
{
    public:
	LDAPErrAliasProblem() : LDAPException() {}
	LDAPErrAliasProblem(const char *str) : LDAPException(str) {}
	LDAPErrAliasProblem(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrInvalidDNSyntax : public LDAPException
{
    public:
	LDAPErrInvalidDNSyntax() : LDAPException() {}
	LDAPErrInvalidDNSyntax(const char *str) : LDAPException(str) {}
	LDAPErrInvalidDNSyntax(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrIsLeaf : public LDAPException
{
    public:
	LDAPErrIsLeaf() : LDAPException() {}
	LDAPErrIsLeaf(const char *str) : LDAPException(str) {}
	LDAPErrIsLeaf(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrAliasDerefProblem : public LDAPException
{
    public:
	LDAPErrAliasDerefProblem() : LDAPException() {}
	LDAPErrAliasDerefProblem(const char *str) : LDAPException(str) {}
	LDAPErrAliasDerefProblem(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrInappropriateAuth : public LDAPException
{
    public:
	LDAPErrInappropriateAuth() : LDAPException() {}
	LDAPErrInappropriateAuth(const char *str) : LDAPException(str) {}
	LDAPErrInappropriateAuth(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrInvalidCredentials : public LDAPException
{
    public:
	LDAPErrInvalidCredentials() : LDAPException() {}
	LDAPErrInvalidCredentials(const char *str) : LDAPException(str) {}
	LDAPErrInvalidCredentials(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrInsufficientAccess : public LDAPException
{
    public:
	LDAPErrInsufficientAccess() : LDAPException() {}
	LDAPErrInsufficientAccess(const char *str) : LDAPException(str) {}
	LDAPErrInsufficientAccess(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrBusy : public LDAPException
{
    public:
	LDAPErrBusy() : LDAPException() {}
	LDAPErrBusy(const char *str) : LDAPException(str) {}
	LDAPErrBusy(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrUnavailable : public LDAPException
{
    public:
	LDAPErrUnavailable() : LDAPException() {}
	LDAPErrUnavailable(const char *str) : LDAPException(str) {}
	LDAPErrUnavailable(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrUnwillingToPerform : public LDAPException
{
    public:
	LDAPErrUnwillingToPerform() : LDAPException() {}
	LDAPErrUnwillingToPerform(const char *str) : LDAPException(str) {}
	LDAPErrUnwillingToPerform(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrLoopDetect : public LDAPException
{
    public:
	LDAPErrLoopDetect() : LDAPException() {}
	LDAPErrLoopDetect(const char *str) : LDAPException(str) {}
	LDAPErrLoopDetect(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrNamingViolation : public LDAPException
{
    public:
	LDAPErrNamingViolation() : LDAPException() {}
	LDAPErrNamingViolation(const char *str) : LDAPException(str) {}
	LDAPErrNamingViolation(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrObjectClassViolation : public LDAPException
{
    public:
	LDAPErrObjectClassViolation() : LDAPException() {}
	LDAPErrObjectClassViolation(const char *str) : LDAPException(str) {}
	LDAPErrObjectClassViolation(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrNotAllowedOnNonleaf : public LDAPException
{
    public:
	LDAPErrNotAllowedOnNonleaf() : LDAPException() {}
	LDAPErrNotAllowedOnNonleaf(const char *str) : LDAPException(str) {}
	LDAPErrNotAllowedOnNonleaf(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrNotAllowedOnRDN : public LDAPException
{
    public:
	LDAPErrNotAllowedOnRDN() : LDAPException() {}
	LDAPErrNotAllowedOnRDN(const char *str) : LDAPException(str) {}
	LDAPErrNotAllowedOnRDN(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrAlreadyExists : public LDAPException
{
    public:
	LDAPErrAlreadyExists() : LDAPException() {}
	LDAPErrAlreadyExists(const char *str) : LDAPException(str) {}
	LDAPErrAlreadyExists(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrNoObjectClassMods : public LDAPException
{
    public:
	LDAPErrNoObjectClassMods() : LDAPException() {}
	LDAPErrNoObjectClassMods(const char *str) : LDAPException(str) {}
	LDAPErrNoObjectClassMods(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrOther : public LDAPException
{
    public:
	LDAPErrOther() : LDAPException() {}
	LDAPErrOther(const char *str) : LDAPException(str) {}
	LDAPErrOther(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

/* API error codes. */
class LDAPErrServerDown : public LDAPException
{
    public:
	LDAPErrServerDown() : LDAPException() {}
	LDAPErrServerDown(const char *str) : LDAPException(str) {}
	LDAPErrServerDown(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrLocalError : public LDAPException
{
    public:
	LDAPErrLocalError() : LDAPException() {}
	LDAPErrLocalError(const char *str) : LDAPException(str) {}
	LDAPErrLocalError(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrEncodingError : public LDAPException
{
    public:
	LDAPErrEncodingError() : LDAPException() {}
	LDAPErrEncodingError(const char *str) : LDAPException(str) {}
	LDAPErrEncodingError(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrDecodingError : public LDAPException
{
    public:
	LDAPErrDecodingError() : LDAPException() {}
	LDAPErrDecodingError(const char *str) : LDAPException(str) {}
	LDAPErrDecodingError(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrTimeout : public LDAPException
{
    public:
	LDAPErrTimeout() : LDAPException() {}
	LDAPErrTimeout(const char *str) : LDAPException(str) {}
	LDAPErrTimeout(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrAuthUnknown : public LDAPException
{
    public:
	LDAPErrAuthUnknown() : LDAPException() {}
	LDAPErrAuthUnknown(const char *str) : LDAPException(str) {}
	LDAPErrAuthUnknown(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrFilterError : public LDAPException
{
    public:
	LDAPErrFilterError() : LDAPException() {}
	LDAPErrFilterError(const char *str) : LDAPException(str) {}
	LDAPErrFilterError(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrParamError : public LDAPException
{
    public:
	LDAPErrParamError() : LDAPException() {}
	LDAPErrParamError(const char *str) : LDAPException(str) {}
	LDAPErrParamError(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrNoMemory : public LDAPException
{
    public:
	LDAPErrNoMemory() : LDAPException() {}
	LDAPErrNoMemory(const char *str) : LDAPException(str) {}
	LDAPErrNoMemory(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrUserCancelled : public LDAPException
{
    public:
	LDAPErrUserCancelled() : LDAPException() {}
	LDAPErrUserCancelled(const char *str) : LDAPException(str) {}
	LDAPErrUserCancelled(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrConnectError : public LDAPException
{
    public:
	LDAPErrConnectError() : LDAPException() {}
	LDAPErrConnectError(const char *str) : LDAPException(str) {}
	LDAPErrConnectError(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrNotSupported : public LDAPException
{
    public:
	LDAPErrNotSupported() : LDAPException() {}
	LDAPErrNotSupported(const char *str) : LDAPException(str) {}
	LDAPErrNotSupported(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrControlNotFound : public LDAPException
{
    public:
	LDAPErrControlNotFound() : LDAPException() {}
	LDAPErrControlNotFound(const char *str) : LDAPException(str) {}
	LDAPErrControlNotFound(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrNoResultsReturned : public LDAPException
{
    public:
	LDAPErrNoResultsReturned() : LDAPException() {}
	LDAPErrNoResultsReturned(const char *str) : LDAPException(str) {}
	LDAPErrNoResultsReturned(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrMoreResultsToReturn : public LDAPException
{
    public:
	LDAPErrMoreResultsToReturn() : LDAPException() {}
	LDAPErrMoreResultsToReturn(const char *str) : LDAPException(str) {}
	LDAPErrMoreResultsToReturn(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrClientLoop : public LDAPException
{
    public:
	LDAPErrClientLoop() : LDAPException() {}
	LDAPErrClientLoop(const char *str) : LDAPException(str) {}
	LDAPErrClientLoop(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

class LDAPErrReferralLimitExceeded : public LDAPException
{
    public:
	LDAPErrReferralLimitExceeded() : LDAPException() {}
	LDAPErrReferralLimitExceeded(const char *str) : LDAPException(str) {}
	LDAPErrReferralLimitExceeded(const char *str, std::string& diag) : LDAPException(str, diag) {}
};

void LDAPErrCode2Exception(LDAP* ldap, int errcode);

class LDAPEntry
{
    public:
	LDAPEntry(LDAPConnection *conn, LDAPMessage *entry);
	LDAPEntry(LDAPConnection *conn, std::string dn);
	~LDAPEntry();

	std::string GetDN();
	SearchableVector<std::string>* GetKeys();
	std::string GetFirstValue(std::string key);
	SearchableVector<std::string>* GetValue(std::string key);

	void AddValue(std::string key, std::string value);
	void RemoveValue(std::string key, std::string value);
	void RemoveAllValues(std::string attribute);
	void Sync();

#ifdef HAVE_LDIF_H
	void Output(std::ostream& out);
#endif /* HAVE_LDIF_H */

    private:
	LDAPConnection *_conn;
	std::string _dn;
	std::map<std::string, SearchableVector<std::string>*> _data;
	bool _isnew;

	std::map<std::string, SearchableVector<std::string>*> _added;
	std::map<std::string, SearchableVector<std::string>*> _removed;
};

class LDAPResult
{
    public:
	LDAPResult(LDAPConnection* conn, std::vector<LDAPMessage*> msg);
	~LDAPResult() {};

	std::vector<LDAPEntry>* GetEntries();

    private:
	LDAPConnection* _conn;
	std::vector<LDAPEntry> _entries;
};

void LDAPSetDebuglevel(int newlevel);
void LDAPSetCACert(std::string path);

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
	void SetResultSizeLimit(int limit);

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
	int _size_limit;
};

}

#endif /* INCLUDED_LDAPXX_H */
