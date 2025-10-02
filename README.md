# Relay Server Flowerpot

This project centers around an ESP32 acting as a relay server in a known network and assigned a port. A client ESP32 (in a flowerpot) can then connect to the relay server to receive and sent messages -> messages usually from a client PC. Both the Client PC and the flowerpot can be anywhere in the world as long as they have access to a wi-fi network.



Overall the general structure should be:

1. Client PC connects to the relay server and sends a message
2. The relay server then sends a received confirmation back to the client PC
3. The relay server then stores it until it can send it to the flowerpot (which Ideally should always be connected)
4. The flowerpot will poll every so often, when a message is received it will display it on an LCD screen, then send a confirmation back to the relay server (which passes it to the PC)



Both ESP files are in the "Relay Server ESP32" folder

* The relay ESP is in "main.cpp"
* the flowerpot ESP is in "client\_esp.cpp"



The Client PC is currently a Python script in the "PC\_client" folder. 



Flowerpot design: https://cad.onshape.com/documents/dcbf7473d9624d88a6184121/w/6561b9bebb71d81c9812ca94/e/3d1cca8f7061d0c65ad626b2 



Next Steps:

* Create a UI for the Client PC, I'm imagining something similar to the discord messaging layout, and it will display if the message has been received by the relay server, or by the flowerpot, or failed to send
