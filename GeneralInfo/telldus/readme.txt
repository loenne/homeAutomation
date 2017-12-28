Installation
------------

1: Installera telldus-core
telldus-core behövs för att styra sin tellstick classic eller tellstick duo.

Lägg till källkodskälla telldus.list
>sudo sh -c 'echo "deb-src http://download.telldus.com/debian/ stable main" > /etc/apt/sources.list.d/telldus.list'

Ladda ner nyckelfilen som signerar denna källa från telldus:
> wget http://download.telldus.se/debian/telldus-public.key

Sedan lägg in nyckeln:
> sudo apt-key add telldus-public.key

Updatera sedan din paketlista:
> sudo apt-get update

Eventuellt måste build-essential installeras men kolla om det redan finns:
> sudo apt-get install build-essential

Installera alla beroenden
> sudo apt-get build-dep telldus-core

Nästa installera övriga beroenden
> sudo apt-get install cmake libconfuse-dev libftdi-dev help2man


Skapa temp katalog 
> mkdir -p ~/telldus-temp
> cd ~/telldus-temp

Ladda ner källkoden och kompilera den.
> sudo apt-get -–compile source telldus-core

Installera
> sudo dpkg -–install *.deb

Radera temp
> cd ; rm ~/telldus-temp

Om alla punkter i steg 4 gått som dom ska har du nu installerat telldus-core och bör ha en demon som
autostartar under /etc/init.d/telldusd.

>sudo service telldusd status

