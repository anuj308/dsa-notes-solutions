from django.urls import path
from . import views

urlpatterns = [
    path('', views.allchai,name="allchaihome"),
    path('order', views.order,name="chaiorder"),
]
