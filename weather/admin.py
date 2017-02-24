from django.contrib import admin

# Register your models here.

from .models import Weathers

class WeathersAdmin(admin.ModelAdmin):
    date_hierarchy = 'date'
    list_display = ('temp', 'hum', 'date')

admin.site.register(Weathers, WeathersAdmin)
