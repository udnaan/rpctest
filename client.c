#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rpc/rpc.h>
#include "testxdr.h"

int main(int argc, char *argv[]) {
	CLIENT *c1;
	char *server;

	char **sresult;

	if (argc != 2) {
		printf("usage: hostname\n");
		return EXIT_SUCCESS;
	}

  server = argv[1];

	if ((c1 = clnt_create(server, TEST_PROG, TEST_VERS, "udp")) == NULL) {
		clnt_pcreateerror(server);
		return EXIT_FAILURE;
	}

	testxdr xdrmessage; // structure testxdr defined in testxdr.x

	long temp_long = 1;
	char *temp_str = "Client is testing";

	// initialize xdrmessage
	xdrmessage.long_arg = temp_long;
	xdrmessage.string_arg = temp_str;

	if ((sresult = str_test_1(&xdrmessage, c1)) == NULL) {
		clnt_perror(c1, server);
		exit(4);
	}

	printf("Client call server successfully\n");
	printf("Server send message back:\n %s = %s\n", server, *sresult);

	clnt_destroy(c1);
	return EXIT_SUCCESS;
}
