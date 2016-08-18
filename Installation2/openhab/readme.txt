Readme for Installation2/openhab
---------------------------------

openhab installation
--------------------
is done to /opt/openhab

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




