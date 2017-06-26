cmake_minimum_required(VERSION 3.1)
project (rpc_test)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(RPCGEN_SRCS
	${CMAKE_CURRENT_BINARY_DIR}/testxdr.h
	${CMAKE_CURRENT_BINARY_DIR}/testxdr_xdr.c
	${CMAKE_CURRENT_BINARY_DIR}/testxdr_clnt.c
	${CMAKE_CURRENT_BINARY_DIR}/testxdr_svc.c
)

if(NOT WIN32)
add_custom_command(OUTPUT ${RPCGEN_SRCS}
	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/testxdr.x ${CMAKE_CURRENT_BINARY_DIR}/testxdr.x
	COMMAND rpcgen testxdr.x
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
endif()

add_executable(client
	${CMAKE_CURRENT_SOURCE_DIR}/client.c
	${CMAKE_CURRENT_BINARY_DIR}/testxdr_xdr.c
	${CMAKE_CURRENT_BINARY_DIR}/testxdr_clnt.c
)

add_executable(server
	${CMAKE_CURRENT_SOURCE_DIR}/server.c
	${CMAKE_CURRENT_BINARY_DIR}/testxdr_xdr.c
	${CMAKE_CURRENT_BINARY_DIR}/testxdr_svc.c
)
