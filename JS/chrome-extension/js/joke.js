window.onload = async function lmao() {
    const res = await fetch('https://official-joke-api.appspot.com/jokes/random')
    const joke = await res.json();
    document.getElementById("setup").innerHTML = joke.setup
    document.getElementById("punchline").innerHTML = joke.punchline
   }