
 var x =document.getElementById("btn1")

 x.addEventListener('click',()=>alert_fun())

function alert_fun(){

    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("new_data").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "Tut39NewForm.html", true);
  xhttp.send();

  
}





// <script>
// function loadDoc() {
//   var xhttp = new XMLHttpRequest();
//   xhttp.onreadystatechange = function() {
//     if (this.readyState == 4 && this.status == 200) {
//       document.getElementById("demo").innerHTML = this.responseText;
//     }
//   };
//   xhttp.open("GET", "ajax_info.txt", true);
//   xhttp.send();
// }
// </script>