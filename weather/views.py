from django.shortcuts import render
from .models import Weathers

# Create your views here.

def index(request):
    weather = Weathers.objects.all()
    return render(request, "index.html", {'weather': weather})


     
