from users.serializers import UserSerializer
from rest_framework.response import Response
from rest_framework.decorators import api_view
from django.contrib.auth.models import User
# Create your views here.
    
@api_view(['GET'])
def UserView(request):
    users = User.objects.all()
    serializer = UserSerializer(users,many=True)
    return Response(serializer.data)

@api_view(['POST'])    
def CreateUser(request):
        # data = request.data
    user = User(username = request.data['username'], email = request.data['email'])
    user.set_password(request.data['password'])
    user.save()
    return Response({'status' : 200 ,  'message' : 'User successfully registered'})

@api_view(['GET'])
def RetrieveUser(request, id):
    user = User.objects.get(id=id)
    serializer = UserSerializer(user)
    return Response(serializer.data)

@api_view(['PATCH'])
def UpdateUser(request, id):
    user = User.objects.get(id=id)
    serializer =UserSerializer(user, data=request.data, partial=True)
    if not serializer.is_valid():
        return Response({'status': 403 , 'message' : 'Something went wrong'})
    serializer.save()
    return Response({'status' : 200 , 'payload' : serializer.data, 'message' : 'User  data successfully updated'})

@api_view(['DELETE'])
def DeleteUser(request, id):
    user = User.objects.get(id=id)
    user.delete()
    return Response({'status' : 200, 'message' : 'User successfully deleted'})

