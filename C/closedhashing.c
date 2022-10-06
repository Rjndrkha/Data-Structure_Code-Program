#include<bits/stdc++.h>
using namespace std;

struct hash
{
    int *arr;
    int cap,size;
    
    MyHash(int c)
    {
        cap=c;
        size=0;
        arr=new int[cap];
        for(int i=0;i<cap;i++)
            arr[i]=-1;
    }
    
    int hash(int key){
        return key%cap;
    }
    bool insert(int key)
    {
        if(size==cap)
            return false;
        int i=hash(key);
        while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key)
            i=(i+1)%cap;
        if(arr[i]==key)
            return false;
        else{
            arr[i]=key;
            size++;
            return true;
        }
    }
    bool search(int key)
    {
        int h=hash(key);
        int i=h;
        while(arr[i]!=-1){
            if(arr[i]==key)
                return true;
            i=(i+1)%cap;
            if(i==h)
                return false;
        }
        return false;
    }
   
};

	int main() 
	{ 
	while (1) {
    printf("\nEnter \n 1. Insert \n 2. Display \n 3. Search \n 4.Exit : \n");
    scanf("%d", & opt);
    switch (opt) {
    case 1:
      printf("Enter a Value to Insert into the Hash Table : \n");
      scanf("%d", & key);
      insert(key);
      break;
    case 2:
      display();
      break;
    case 3:
      search();
      break;
    case 4:
      exit(0);
    }
  }
	} 
