from django.urls import path
from users import views
urlpatterns = [
    path("users/",views.UserView,name='users'),
    path("users/create/",views.CreateUser,name='users_create'),
    path("users/retrieve/<int:id>",views.RetrieveUser,name='users_retrieve'),
    path("users/update/<int:id>",views.UpdateUser,name='users_update'),
    path("users/<int:id>/delete/",views.DeleteUser,name='users_delete'),
]