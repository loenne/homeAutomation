Readme for Installation3/telldus
--------------------------------

Files stored in repo

The configuration file /etc/tellstick.conf


Installation
------------

Steg 1: Installera telldus-core
Nu är det daxs att fixa in telldus-core som är det paket som behövs för att styra
sin tellstick classic eller tellstick duo. Jag letade en del innan jag hittade
hur man gör då det vanliga sättet inte fungerar då det är fel arkitektur så
man måste kompilera paketet från källkod.

Börja med att lägga till kälkodskälla i din /etc/apt/sources.list.d/telldus.list på en ny rad enligt nedan
> sudo nano /etc/apt/sources.list.d/telldus.list
deb-src http://download.telldus.com/debian/ stable main

Nu måste vi ladda ner nyckeln som signerar denna källa från telldus. Ladda ner nyckelfilen med nedan kommando.
> wget http://download.telldus.se/debian/telldus-public.key

Sedan lägg in nyckeln med nedan kommando.
> sudo apt-key add telldus-public.key

Efter detta kör nedan komando för att updatera din paketlista.

sudo apt-get update
Nu bör den updatera och lägga med telldus källkods paket.

Nu bör man installera build-essential dock bör redan detta vara installerat men kör kommandot för att dubbelkolla så ni har paketen installerade
sudo apt-get install build-essential

Installera alla beroenden
sudo apt-get build-dep telldus-core

Nästa installera övriga beroenden
sudo apt-get install cmake libconfuse-dev libftdi-dev help2man

Skapa nu en temporär katalog du kan jobba i med telldus kompileringen exempelvis enligt nedan
mkdir -p ~/telldus-temp
cd ~/telldus-temp

Nästa steg nu är att ladda ner källkoden och kompilera den. Detta moment kommer ta en del tid då Raspberry Pi som känt inte har så snabb CPU 🙂 så en fika kan vara på sin plats.
sudo apt-get –compile source telldus-core (ska vara ––compile detta syns inte som det ska i bloggen)

När kompileringen gått klart och allt förhoppningsvis gått bra kör nedan för att installera dom kompilerade paketen
sudo dpkg –install *.deb (ska vara ––install detta syns inte som det ska i bloggen)

Nu kan man om man vill radera sin temp mapp man skapade för sin kompileringen gör enligt nedan isåfall
cd ; rm ~/telldus-temp

Om alla punkter i steg 4 gått som dom ska har du nu installerat telldus-core och bör ha en demon som autostartar under /etc/init.d/telldusd.
