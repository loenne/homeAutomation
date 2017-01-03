Installation
------------

1: Installera telldus-core
telldus-core behövs för att styra sin tellstick classic eller tellstick duo.

Börja med att lägga till källkodskälla telldus.list på en ny rad enligt nedan:
> sudo nano /etc/apt/sources.list.d/telldus.list
deb-src http://download.telldus.com/debian/ stable main

Ladda ner nyckelfilen som signerar denna källa från telldus:
> wget http://download.telldus.se/debian/telldus-public.key

Sedan lägg in nyckeln:
> sudo apt-key add telldus-public.key

Updatera sedan din paketlista:
> sudo apt-get update
Nu bör den updatera och lägga med telldus källkods paket.

Eventuellt måste build-essential installeras men kolla om det redan finns:
> sudo apt-get install build-essential

Installera alla beroenden
> sudo apt-get build-dep telldus-core

Nästa installera övriga beroenden
> sudo apt-get install cmake libconfuse-dev libftdi-dev help2man


ALTERNATIVT !!!

Skapa en temporär katalog du kan jobba i med telldus kompileringen exempelvis enligt nedan
> mkdir -p ~/telldus-temp
> cd ~/telldus-temp

Ladda ner källkoden och kompilera den.
> sudo apt-get –compile source telldus-core (ska vara ––compile detta syns inte som det ska i bloggen)

När kompileringen gått klart och allt förhoppningsvis gått bra kör nedan för att installera dom kompilerade paketen
> sudo dpkg –install *.deb (ska vara ––install detta syns inte som det ska i bloggen)

Nu kan man om man vill radera sin temp mapp man skapade för sin kompileringen gör enligt nedan isåfall
> cd ; rm ~/telldus-temp

Om alla punkter i steg 4 gått som dom ska har du nu installerat telldus-core och bör ha en demon som
autostartar under /etc/init.d/telldusd.
