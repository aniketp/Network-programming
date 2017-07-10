# local-reverse-shell

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

### Credits
[TheNewBoston](https://thenewboston.com)
