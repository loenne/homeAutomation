Readme for Installation2/openhab
---------------------------------

openhab installation
--------------------
is done to /opt/openhab

Download from 
-------------
http://www.openhab.org/getting-started/


Bindings
---------
tellstick bindings (.jar file) is copied to the subdirectory addons

Files stored in repo :
----------------------
  - subdirectory configuration


To make rule for sending mail to gmail work
-------------------------------------------
Need to turn off a security level in GMail that prevents unsecure app's to send mail to gmail.

The link: https://support.google.com/accounts/answer/6010255?hl=en


Handle service openhab
----------------------
> sudo service openhab status
> sudo service openhab stop
> sudo service openhab start
> sudo service openhab restart

Tellstick commands
------------------
> tdtool --help

Set logging level:
------------------
In file : /opt/openhab/configurations/logback.xml (row 40) 

INFO -> DEBUG

When site is stable it should be set to WARNING


Remote applications
-------------------

openHAB remote URL:
https://ingaro.pagekite.me

Alternative 2:
https://my.openHAB.org

Start openHAB on boot
---------------------

Unless running an old version of raspbian, don't use init.d. 
Diet-Pi and raspbian use systemd, which is is a linux init 
system to bootstrap user space and manage processes. 

To check if systemd is being used, enter the command:

> ps -p 1 -o comm=
systemd

Make system directory if it doesn't exist and create a start-up file

> sudo mkdir /usr/lib/systemd/system 
> sudo nano /usr/lib/systemd/system/openhab.service

And add:

[Unit]
Description=openHAB Home Automation Bus
Documentation=http://www.openhab.org
Wants=network-online.target
After=network-online.target

[Service]
Type=simple 
GuessMainPID=yes
User=pi
ExecStart=/opt/openhab/start.sh
ExecStop=kill -SIGINT $MAINPID
Restart=on-failure
WorkingDirectory=/opt/openhab

[Install]
WantedBy=multi-user.target


Change owner recursively on openhab.
------------------------------------
> sudo chown -R pi:pi /opt/openhab

Reload systemd to make the daemon aware of the new configuration.
-----------------------------------------------------------------
> sudo systemctl --system daemon-reload
> cd /usr/lib/systemd/system
> sudo systemctl enable openhab.service
> sudo systemctl start openhab.service 
> sudo reboot

Fix any issues in the logs. To see the log, enter the command:
--------------------------------------------------------------
> sudo journalctl -f -u openhab.service

CTRL-c to stop

> sudo reboot

openHAB takes about 5 minutes to start
--------------------------------------

In the browser, open a new tab and go to

http://<ip-address>:8080/openhab.app?sitemap=ingaro



