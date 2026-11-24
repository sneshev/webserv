#include "webserv.hpp"

#include "HttpTypes.hpp"
#include "HttpRequest.hpp"
#include "HttpRequestParser.hpp"
#include "HttpResponse.hpp"
#include "HttpHandler.hpp"

void httpLoop()
{
	HttpRequestParser parser;
	HttpHandler handler(/*config*/);

	//LOOP
	{
		HttpRequest request;
		eParseResult result = parser.parseRequest(request);
		if (result == PARSE_SUCCESS)
		{
			parser.removeBytesParsed();

			HttpResponse response;
			handler.handleRequest(request, response);
			handler.prepareResponse(request, response);

			response.build();
		}
		else if (result == PARSE_ERROR)
		{
			int statusCode = parser.getErrorStatusCode();
			//break loop and create response. close connection
		}
		else if (result == PARSE_INCOMPLETE)
		{
			//parser.appendRawRequest(nextPacket);
		}
	}
}


int main()
{

	httpLoop();

}