/*
@             GEBZE TECHNICAL UNIVERSITY
@       DEPARTMENT OF ELECTRONICS ENGINEERING
@
@                   ELEC458
@           Embedded System Design
@                  - 2019 - 
@
@                | Project 3 |
@
@		   ~  SMART MEDICINE BOX  ~
@
@      - Serhat SEFER         --> 141024040
@      - Saim Buğrahan ÖZTÜRK --> 151024011
@
@      INSTRUCTOR : Furkan Çaycı
@
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @

These files are uploaded to serhatesp.dx.am


If you want to upload PHP files in your server, follow these steps:
	* Create 2 tables in your MySQL databes which is named admin and medicine_box
	* The admin table has field id (int255 , autoincrement) , name(varchar20) , surname(varchar20) and passcode(varchar20).
	* The medicine_box table has field id(int255,autoincrement) , name(varchar20) , surname(varchar20) ,
	  medicine_name(varchar20) , time(mediumint6,UNSIGNED ZEROFILL) , pin(int11) , status(tinyint1)
	* Update DB_SERVER,DB_USERNAME,DB_PASSWORD,DB_DATABASE in config.php
