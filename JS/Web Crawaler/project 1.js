// developing a web crawler here that filter the links of the webpage and finds out the links that have a particular keyword..
let a=document.links
Array.from(a).forEach(function(element){
    if(element.href.includes("contact"))
    console.log(element.href)
})
let a=Array.from(document.links)
a.forEach(function(element){
    if(element.href.includes("2002"))
    console.log(element.href)
})
//press shift+enter tp go to the next line in the console and not enter