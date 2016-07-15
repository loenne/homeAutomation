Readme for Installation1/debian
----------------------


The rasperry pi is running debian linux

Connect using ssh
-----------------
> ssh pi@192.168.0.118 (pwd:topp-n+N+2020)

Modification done to pi
--------------------------

Make ssh connection last longer
--------------------------------

Add the following to file : ~/.ssh/config
TCPKeepAlive no
ServerAliveInterval 20
ServerAliveCountMax 10




