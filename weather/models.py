from __future__ import unicode_literals
from django.db import models
from django.db.models.signals import post_save
from django.dispatch import receiver

import datetime

# Create your models here.

def my_handler(sender, instance, **kwargs):
    qs = Weathers.objects.order_by('created')
    if qs.count() > 5:
        qs[0].delete()

class Weathers(models.Model):
    temp = models.FloatField()
    hum = models.FloatField()
    date = models.DateTimeField(default=datetime.datetime.now, blank=False)

post_save.connect(my_handler, sender=Weathers)

def _str_(self):
    return self.date



