#!/bin/bash

NAME="testi"                              	  # Nimi
DJANGODIR=/home/pi/servu/testi            	  # Djangoprojektin osoite
SOCKFILE=/home/pi/servu/run/gunicorn.sock         # SOCKFILE jonka avulla nginx-gunicorn-django kommunikaatio onnistuu
USER=pi                                           # käyttäjä 
GROUP=users                                       # käyttäjäryhmä
NUM_WORKERS=1                                     # worker prosessien määrä(kuinka paljon laskentatehoa palvelimelle
DJANGO_SETTINGS_MODULE=testi.settings             # Djangon asetukset
DJANGO_WSGI_MODULE=testi.wsgi                     # WSGI

echo "Starting $NAME as `whoami`"

# Virtual environment päälle
cd $DJANGODIR
source /home/pi/servu/venv/bin/activate
export DJANGO_SETTINGS_MODULE=$DJANGO_SETTINGS_MODULE
export PYTHONPATH=$DJANGODIR:$PYTHONPATH

# Luodaan ajettava hakemisto
RUNDIR=$(dirname $SOCKFILE)
test -d $RUNDIR || mkdir -p $RUNDIR

# Aktivoidaan django-gunicorn
exec /home/pi/servu/venv/bin/gunicorn ${DJANGO_WSGI_MODULE}:application \
  --name $NAME \
  --workers $NUM_WORKERS \
  --user $USER \
  --bind=unix:$SOCKFILE