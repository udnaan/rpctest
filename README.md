# rpctest

A simple test to verify that SUNRPC is working.

## Usage

```
1. clone the repo
2. mkdir build && cd build
3. cmake .. && make
4. ./server &
5. ./client
```

You should see something along the line of 

```
Message from client: Client is testing
Client call server successfully
Server send message back:
 localhost = Server say Hi to client!
 ```
 
 
 ## Credits
 Original code taken from [RPC Tutorial](https://web.cs.wpi.edu/~rek/DCS/D04/SunRPC.html) and cleaned up to compile using cmake
