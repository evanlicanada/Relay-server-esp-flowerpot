import socket
import threading
from config_secret import RELAY_SERVER_IP, RELAY_SERVER_PORT


def receive_messages(sock):
    """Continuously receives messages from the server."""
    while True:
        try:
            data = sock.recv(1024)
            if data:
                print(f"\nReceived from ESP32: {data.decode().strip()}")
        except Exception as e:
            print(f"Error receiving data: {e}")
            break

def main():
    """Connects to the relay server and sends messages."""
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((RELAY_SERVER_IP, RELAY_SERVER_PORT))
            print("Connected to the relay server.")

            # Start a thread to listen for incoming messages
            listener_thread = threading.Thread(target=receive_messages, args=(s,))
            listener_thread.daemon = True
            listener_thread.start()

            while True:
                message = input("Enter a message to send to the ESP32: ")
                if not message:
                    continue
                s.sendall((message + "\n").encode('utf-8'))
                print("Message sent.")
                
    except ConnectionRefusedError:
        print("Connection failed. Check the IP and port of the relay server.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()