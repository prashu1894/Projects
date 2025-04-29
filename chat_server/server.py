import socket
import threading
import atexit
import subprocess
import platform
import os

# Server Configuration
HOST = '127.0.0.1'
PORT = 5555
log_file = './log.txt'

# Create a TCP/IP socket
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen()

clients = []
nicknames = []

def log_message(message):
    with open(log_file, 'a') as f:
        f.write(message + '\n')

def broadcast(message):
    """Send a message to all clients."""
    for client in clients:
        client.send(message)

def handle_client(client, nickname):
    """Handle incoming messages from a client."""
    while True:
        try:
            message = client.recv(1024)
            broadcast(message)
        except:
            index = clients.index(client)
            clients.remove(client)
            client.close()
            nickname = nicknames[index]
            broadcast(f'{nickname} left the chat.'.encode('utf-8'))
            nicknames.remove(nickname)
            log_message(f'{nickname} left the chat.')
            break

def reveive_connections():
    """
    Accepts incoming connections and starts a new thread for each client.
    """
    while True:
        client, address = server.accept()
        print(f"Connected with {str(address)}")
        log_message(f"Connected with {str(address)}")
        client.send("NICK".encode('utf-8'))
        nickname = client.recv(1024).decode('utf-8')
        nicknames.append(nickname)
        clients.append(client)
        print(f"Nickname of the client is {nickname}")
        log_message(f"Nickname of the client is {nickname}")
        broadcast(f"{nickname} joined the chat!".encode('utf-8'))
        client.send("Connected to the server!".encode('utf-8'))
        thread = threading.Thread(target=handle_client, args=(client, nickname))
        thread.start()


def kill_process_using_port(port):
    system = platform.system()

    try:
        if system == "Windows":
            # Get PID using port
            result = subprocess.check_output(f'netstat -ano | findstr :{port}', shell=True).decode()
            lines = result.strip().split('\n')
            pids = set()
            for line in lines:
                parts = line.strip().split()
                if len(parts) >= 5 and parts[1].endswith(f':{port}'):
                    pids.add(parts[-1])
            for pid in pids:
                print(f"[INFO] Killing PID {pid} on port {port}...")
                os.system(f"taskkill /F /PID {pid}")

        else:  # macOS or Linux
            result = subprocess.check_output(["lsof", "-i", f":{port}"]).decode()
            lines = result.strip().split("\n")[1:]  # skip header
            pids = set(line.split()[1] for line in lines)
            for pid in pids:
                print(f"[INFO] Killing PID {pid} on port {port}...")
                os.kill(int(pid), 9)

        print(f"[DONE] Port {port} is now free.")

    except subprocess.CalledProcessError:
        print(f"[OK] No process found using port {port}.")

    except Exception as e:
        print(f"[ERROR] {e}")

def on_exit():
    """
    Clean up resources and close the server.
    """
    print("Log: Closing server...")
    kill_process_using_port(PORT)
    print("Log: Server closed.")
    

if __name__ == '__main__':
    print("Log: Starting chat server...")
    reveive_connections()

