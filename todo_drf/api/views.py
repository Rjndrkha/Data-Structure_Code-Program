from rest_framework import serializers
from .models import Task
from django.shortcuts import render
from django.http import JsonResponse
# Create your views here.

from rest_framework.decorators import api_view
from rest_framework.response import Response
from .serializers import TaskSerializers

@api_view(['GET'])
def apiOverview(request):
    api_urls = {
        'List':'/task-list/',
        'Detail View':'/task-detail/<str:pk>/',
        'Create':'/task-create/',
        'Update':'/task-update/<str:pk>/',
        'Delete':'/task-delete/<str:pk>/',
    }
    return Response(api_urls)

@api_view(['GET'])
def taskList(request):
    tasks = Task.objects.all().order_by('-id');
    serializer = TaskSerializers(tasks, many = True)
    return Response(serializer.data)

@api_view(['GET'])
def taskDetail(request, pk):
    tasks = Task.objects.get(id=pk)
    serializer = TaskSerializers(tasks, many = False)
    return Response(serializer.data)

@api_view(['POST'])
def taskCreate(request):
    serializer = TaskSerializers(data=request.data)
    if serializer.is_valid():
        serializer.save()
    return Response(serializer.data)


@api_view(['POST'])
def taskUpdate(request, pk):
    task = Task.objects.get(id=pk)
    serializer = TaskSerializers(instance=task, data=request.data)
    if serializer.is_valid():
        serializer.save()
    return Response(serializer.data)


@api_view(['DELETE'])
def taskDelete(request, pk):
    task = Task.objects.get(id=pk)
    task.delete();
    return Response("Item deleted Successfully")