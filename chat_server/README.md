A simple multi-client chat server built using Python TCP sockets and multi-threading.

📋 Project Overview
This project simulates a real-time chat room where multiple clients can connect to a server, choose a nickname, send messages, and receive broadcast messages from other users.

Built to demonstrate network programming fundamentals, concurrent client handling, and basic distributed messaging — similar to how large chat apps or microservices communicate internally.

Flow:
    1.Server accepts many clients.
    2.Client sends "Hello everyone!".
    3.Server broadcasts to all clients.
    4.Handle client disconnects cleanly.


+-----------+          +-----------+          +-----------+
|  Client 1 |          |  Client 2 |          |  Client N |
+-----------+          +-----------+          +-----------+
         \                   |                     /
          \                  |                    /
           \                 |                   /
            \           +--------------------+
             +--------->|    Chat Server      |
                        +--------------------+


A WebSocket is a communication protocol that enables real-time, two-way communication between a client (like a web browser) and a server over a single, long-lived connection

Multithreading is a programming technique that allows a single program to perform multiple tasks concurrently by creating and managing multiple threads of execution.

Web socket is created with the serve when any client is connected to the server.
Each Client will run on their own thread. When a client comes in or leaves, server will broadcast the message.
