Readme for Installation1/pagekite
---------------------------------

Config
-------
>cd /etc/pagekite.d

- Update 10_account.rc
  - Set kitename to timmerman.pagekite.me
  - Set correct secret (from secret on paccount at pagekite homepage accoutn
- Rename 80_httpd.rc.sample 80_httpd.rc
- Update 80_httpd.rc
  - Set localhost:8080 

Rename 
>sudo nan
Logging
--------
>tail -f /var/log/pagekite/pagekite.log


Restart service
---------------
>sudo service pagekite status
>sudo service pagekite restart


