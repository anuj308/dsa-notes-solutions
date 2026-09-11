from django.shortcuts import render
from .models import ChaiVarity
from django.shortcuts import get_object_or_404

# Create your views here.
def allchai(request):
    chais = ChaiVarity.objects.all()
    return render(request, 'chai/allchai.html',{'chais': chais})
    
def order(request):
    return render(request, 'chai/order.html')

def chai_detail(request,chai_id):
    chai = get_object_or_404(ChaiVarity,pk=chai_id)

    return render(request,'chai/chai_details.html',{'chai':chai})