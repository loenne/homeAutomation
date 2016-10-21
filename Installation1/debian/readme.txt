Readme for Installation1/debian
----------------------


The rasperry pi is running debian linux

Connect using ssh
-----------------
> ssh pi@192.168.0.187 (pwd:topp-n+N+2019)
> ssh pi@TimmerAuto (pfd:topp-n+N+2019)

Rasperry pi is connected to a 7" screen.

Modification done to pi
--------------------------

Make ssh connection last longer
--------------------------------

Add the following to file : ~/.ssh/config
TCPKeepAlive no
ServerAliveInterval 20
ServerAliveCountMax 10

Install tightvncserver
-----------------------
>sudo apt-get install tightvncserver

start the server
> tightvncserver  (password : fleksnes + 020)

todo: Make it aoutstart after boot !!


Upgrade debian software
--------------------------------
> sudo apt-get update
> sudo apt-get dist-upgrade
> sudo apt-key list | grep expired
> sudo apt-key adv --recv-keys --keyserver keys.gnupg.net C7B2CAC3
> sudo apt-get update
> sudo apt-get upgrade
> sudo apt-get autoremove

