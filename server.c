#include <stdio.h>
#include <rpc/rpc.h> //* standard RPC include file */
#include <string.h>

#include "testxdr.h"

/*
 * Accept and print out client message and return a server string
 */

char **str_test_1_svc(testxdr *xdrm, struct svc_req * req) {
	static char *ptr = (char *)"Server say Hi to client!"; /* must be static */

	printf("Message from client: %s\n", xdrm->string_arg);

	return (&ptr);
}
