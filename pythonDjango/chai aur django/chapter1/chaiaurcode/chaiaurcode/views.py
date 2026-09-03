from django.http import HttpResponse
from django.shortcuts import render

def home(request):
    # return HttpResponse("this is home page")
    return render(request,'websites/index.html')

def about(request):
    return HttpResponse("this is about page")

def contact(request):
    return HttpResponse("this is contact page")

