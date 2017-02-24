#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import serial
import sqlite3
import time
from datetime import datetime

dbconnect = sqlite3.connect("db.sqlite3")
cursor = dbconnect.cursor()

bluetoothserial = serial.Serial( "/dev/rfcomm0", baudrate = 9600)
bluetoothserial.flushInput()

while 1:
    time.sleep(2)
    print("Odottaa dataa...")
    lampotila = bluetoothserial.readline()
    print(lampotila)
    kosteus = bluetoothserial.readline()
    print(kosteus)
    time.sleep(1)
    print("Kerätään dataa...")
    lampotila = float(lampotila)
    kosteus = float(kosteus)
    print("Siirretään dataa..")
    time.sleep(1)
    cursor.execute(" INSERT OR IGNORE INTO weather_weathers(temp, hum, date) VALUES (?, ?, ?);",
    (lampotila, kosteus, datetime.now()))
    dbconnect.commit()
