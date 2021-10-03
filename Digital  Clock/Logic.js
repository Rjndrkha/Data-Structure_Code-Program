function updateClock(){

    var now = new Date();
    var dname = now.getDay(),
        mo = now.getMonth(),
        dnum = now.getDate(),
        yr  = now.getFullYear(),
        hou = now.getHours(),
        min = now.getMinutes(),
        sec = now.getSeconds(),
        pe = "AM";
        if(hou==0){
            hou=12;
        }
        if(hou>12){
            hou = hou - 12;
            pe = "PM";
        }
        Number.prototype.pad=function(digit){
            for(var n = this.toString(); n.length < digit; n = 0 + n );
            return n;
        }
