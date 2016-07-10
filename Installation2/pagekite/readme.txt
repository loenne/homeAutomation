Readme for Installation2/pagekite
----------------------

Installation that worked
----------------------------------------
> more /etc/apt/sources.list
> echo deb http://pagekite.net/pk/deb/ pagekite main | sudo tee -a /etc/apt/sources.list
> more /etc/apt/sources.list
> sudo apt-key adv --recv-keys --keyserver keys.gnupg.net AED248B1C7B2CAC3
> sudo apt-get update
> sudo apt-get install pagekite
> sudo service pagekite status

Installation that did not work: 
--------------------------------
> curl -s https://pagekite.net/pk/ |sudo bash
> pagekite.py 80 ingaro.pagekite.me

(Did probobly not work because of wrong port !! 80 instead of 8080)


Running pagekite in shell to find out what is wrong !!
---------------------------------------------
> sudo pagekite --clean --optdir=/etc/pagekite.d


Check log files
---------------
> more /var/log/pagekite/


