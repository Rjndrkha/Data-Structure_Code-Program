


function myFunction(){
  var x = document.getElementById('start').value;
  var y = document.getElementById('marks').value;
 var z=0,g=0 ,k=0;
 var arr1 ="";
 var arr2 = "";
  for( var i=x;i<=y;i++){

    if(i%2==0){
      z+=+i;
      arr1+=i+" "
    }

    else if(i%2==1){
      g+=+i;
     arr2+=i+" ";
    }
    
    
  }
  
  document.getElementById('odd').innerHTML="odd values from " +x  + "  to "+ y + " are "+arr2;
  document.getElementById('odd1').innerHTML="Sum values from " +x +"  to "+ y + " are " + g ;
 
 document.getElementById('even').innerHTML="Even values from " +x  + "  to "+ y + " are "+arr1;
  document.getElementById('even1').innerHTML="Sum values from " +x +"  to "+ y + " are " + z;

}

  