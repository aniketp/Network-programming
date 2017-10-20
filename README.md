# Python Networking Projects

## Reverse-Shell

A shell which can access information about any remote server. The interface looks like a bash terminal virtually running 
on your PC, although everything that is displayed is the content of the server. 

To access control, you need firewall permissions. So its best to try it out on your own server.

### Usage

Run `server.py` in the background (in your workstation). It will create a socket server and will be listening to the port `8888`

Now you need to run the file `client.py` in the device you want to control. On running it for the first time, a request 
will be sent to the server running on your machine. The server will acknowledge that request and will respond with bash commands
you enter in the shell. Same commands will be carried out in the client and the final response will be printed out on your shell.
Though it might look like you are running those commands on your machine but you have actually connected to the target (`client`)

Now you're all setup to ruin the device :smiling_imp:

## Packet-Sniffer

Packet Sniffer is a program to get access to the data flowing through your router/ethernet. Any kind of data can be sniffed from the
browser.

Needs Super-User permission for certain utilities to function.

### Description
The file `sniffer.py` when run with python 3 will listen to packets recieved from the socket connection. On receiving the ethernet frame, the program 
will break it into individual pieces to ascertain the kind of Protocols. i.e `IPv4/IPv6` and `ICMP,TCP,UDP` (`ICMP: Internet Control 
Message Protocol`, `TCP: Transmission Control Protocol (Most Common)`, `UDP: User Datagram Protocol`). Each protocol incorporates discrete 
byte information. So the method to unpack the data is distinct. In all the cases though, we'll get Source and Destination Ports (MAC Addresses).

Useful for finding out the bottlenecks in your network or just spying on someone :smiling_imp:

## Website-Scanner

A tool to scan a particular website and extract useful information out of it

### Description
Following information is obtained
* Nmap port scan
* IP Address
* Whois detail
* robots.txt

Input is expected as the name of project directory and the full Url of the website

**TODO**: Check for existence of robots.txt. Many websites allow full scraping access. 

### Credits:
[TheNewBoston](https://thenewboston.com)
