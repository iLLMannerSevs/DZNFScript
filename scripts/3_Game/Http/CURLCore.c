
/** @file */


// -------------------------------------------------------------------------
/// tree traversal type, for more see http://en.wikipedia.org/wiki/Tree_traversal
enum ECURLResultState
{
	ECURL_EMPTY,				// not initialized
	ECURL_PENDING,				// awaiting processing
	ECURL_FEEDING,				// awaiting incoming data
	ECURL_SUCCESS,				// result and/ or data are ready (success), awaiting data processing to be finished (no longer blocking queue processing)
	ECURL_PROCESSED,			// finished (either successfully or with failure) and eill be removed ASAP

	ECURL_ERROR,				// (state >= ECURL_ERROR) == error happened
	ECURL_ERROR_CLIENTERROR,	//  (ECURL_ERROR == ECURL_ERROR_CLIENTERROR)
	ECURL_ERROR_SERVERERROR,
	ECURL_ERROR_APPERROR,
	ECURL_ERROR_TIMEOUT,
	ECURL_ERROR_NOTIMPLEMENTED,
	ECURL_ERROR_UNKNOWN,
};

// -------------------------------------------------------------------------
// object to be used from script for result binding
//
//	[Example:]
//
//		CURLCallback cbx1 = new CURLCallback;
//		CURLContext ctx = GetCURLCore().GetCURLContext("http://somethingsomewhere.com/path/");
//		ctx.GET(cbx1,"RequestPath?Argument=Something");
//
//		Event are then called upon CURLCallback()
//
class CURLCallback : Managed
{
	/**
	\brief Called in case request failed (ECURLResultState) - Note! May be called multiple times in case of (RetryCount > 1)
	*/
	void OnError( int errorCode )
	{
		// override this with your implementation
		Print(" !!! OnError() ");
	};

	/**
	\brief Called in case request timed out or handled improperly (no error, no success, no data)
	*/
	void OnTimeout()
	{
		// override this with your implementation
		Print(" !!! OnTimeout() ");
	};

	/**
	\brief Called when data arrived and/ or response processed successfully
	*/
	void OnSuccess( string data, int dataSize )
	{
		// override this with your implementation
		Print(" !!! OnSuccess() ");
		Print(dataSize);
		if( dataSize > 0 )
			Print(data);
	};

};


// -------------------------------------------------------------------------
// context API and request API
class CURLContext
{
	/**
	\brief Processes GET request and returns result (ECURLResultState) and/ or data (timeout, error) when finished
	*/
	proto native int GET( CURLCallback cb, string request );

	/**
	\brief Processes GET request and returns data immediately (thread blocking operation!)
	*/
	proto native string GET_now( string request );

	/**
	\brief Pushes POST request and returns result (ECURLResultState) and/ or data (timeout, error) when finished
	*/
	proto native int POST( string request, string data );

	/**
	\brief Processes POST request and returns data immediately (thread blocking operation!)
	*/
	proto native string POST_now( string request, string data );

	/**
	\brief Clear all pending requests and buffers
	*/
	proto native void reset();

};


// -------------------------------------------------------------------------
// CURL core for context create/ access + debug features
class CURLCore
{
	/**
	\brief Get new or existing context for http comm GetCURLContext("www.server915.com/interface/")
	*/
	proto native CURLContext GetCURLContext( string serverURL );
	
	/**
	\brief Get count of registered contexes
	*/
	proto native int GetContextCount();

	/**
	\brief Enable debug output to console (disabled by default)
	*/
	proto native void EnableDebug( bool bEnable );

	/**
	\brief List of all currently active contexes and processed (pending) requests
	*/
	proto native void DebugList();

};

// -------------------------------------------------------------------------
// CURL create/ access methods out of Hive initialization
proto native CURLCore CreateCURLCore();
proto native void DestroyCURLCore();
proto native CURLCore GetCURLCore();

