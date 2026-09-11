from django.urls import path
from . import views

urlpatterns = [
    path('', views.allchai,name="allchaihome"),
    path('<int:chai_id>/', views.chai_detail,name="chai_detail"),
    path('order', views.order,name="chaiorder"),
]
