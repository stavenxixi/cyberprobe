
////////////////////////////////////////////////////////////////////////////
//
// HTTP processing
//
////////////////////////////////////////////////////////////////////////////

#ifndef HTTP_H
#define HTTP_H

#include <stdint.h>

#include <set>

#include "context.h"
#include "manager.h"
#include "serial.h"
#include "protocol.h"

namespace analyser {
    
    // An HTTP context.
    class http_context : public context {
      public:
	
	// Constructor.
        http_context(manager& m) : context(m) {
	}

	// Constructor, describing flow address and parent pointer.
        http_context(manager& m, const flow& a, context_ptr p) : context(m) { 
	    addr = a; parent = p; 
	}

	// Type is "http".
	virtual std::string get_type() { return "http"; }
    };

    class http {

    public:

	// HTTP request processing function.
	static void process_request(manager&, context_ptr c, 
				    pdu_iter s, pdu_iter e);

	// HTTP response processing function.
	static void process_response(manager&, context_ptr c, pdu_iter s, 
				     pdu_iter e);

    };

};

#endif

