var url = "https://api.dictionaryapi.dev/api/v2/entries/en_US"
var input = document.getElementById("input");
var button = document.getElementById("btn");
var mat = document.getElementById("material");


if(button !== null){
    button.addEventListener("click", async function(){
        mat.innerHTML = "";
        var val = input.value;
        if(val !== ""){
            var temp_url = url + "/" + val;
            var json_data = await httpGet(temp_url);

            
            var data = JSON.parse(json_data);
            if(data.title){
                mat.innerHTML = data.message;
                return;
            }

            var l = data[0].meanings.length;
            for(var i=0;i<l;i++){
                var len = ((data[0].meanings[i]).definitions).length;
                part_of_speech = (data[0].meanings[i]).partOfSpeech;
                var h1 = document.createElement("h2");
                var list = document.createElement("ol");
                h1.innerHTML = part_of_speech;
                mat.appendChild(h1);

                for(var j=0;j<len;j++){
                    var def = (data[0].meanings[i]).definitions[j].definition;
                    var li = document.createElement("li");
                    li.innerHTML = def;
                    list.appendChild(li);
                }
                mat.appendChild(list);
            }
        }
    });
}



function httpGet(theUrl) {
    return new Promise((resolve, reject) => {
      var xmlHttp = new XMLHttpRequest();
      xmlHttp.onload = function () {
          if (this.status >= 200 && this.status < 300) {
              resolve(xmlHttp.response);
          }
          if (this.status == 404) {
              resolve(xmlHttp.response);
          }
      };
      xmlHttp.open("GET", theUrl, true); // true for asynchronous request
      xmlHttp.send(null);
    });
}




