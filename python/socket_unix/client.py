import socket  
 
# sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)  
sock = socket.socket(socket.AF_UNIX)  
sock.connect('./tt.d')  
sock.send('Hello Socket')  
sock.close()
