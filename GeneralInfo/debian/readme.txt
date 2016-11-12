Operation system version
------------------------
The rasperry pi's are different versions of the raspbian linux OS.

Modification done to pi os
--------------------------

1. Make ssh connection last longer
----------------------------------
Add the following to file : ~/.ssh/config
TCPKeepAlive no
ServerAliveInterval 20
ServerAliveCountMax 10

2. Install tightvncserver
-------------------------
>sudo apt-get install tightvncserver

start the server
> tightvncserver  (password : fleksnes + 020)

todo: Make it autostart after boot !!

3. Upgrade Raspian software
---------------------------
> sudo apt-get update
> sudo apt-get dist-upgrade
> sudo apt-key list | grep expired
> sudo apt-key adv --recv-keys --keyserver keys.gnupg.net C7B2CAC3
> sudo apt-get update
> sudo apt-get upgrade
> sudo apt-get autoremove

