Fetch key
---------
>wget http : //repo.mosquitto.org/debian/mosquitto-repo.gpg.key

Install key
-----------
>sudo apt-key add mosquitto-repo.gpg.key

Remove the key file
-------------------
>rm mosquitto-repo.gpg.key

>cd /etc/apt/sources.list.d/
>sudo wget http://repo.mosquitto.org/debian/mosquitto-jessie.list
>sudo apt-get update
>sudo apt-get install mosquitto mosquitto-clients

Test mosquitto
---------------
>mosquitto_sub -d -t hello/world

Open a second terminal and ssh in to the pi
-------------------------------------------
>ssh pi@<ip-address>
>mosquitto_pub -d -t hello/world -m "Hello from terminal window 2!"

