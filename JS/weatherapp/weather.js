//start the demo server at https://cors-anywhere.herokuapp.com/
window.addEventListener("load", () => {
    let lat;
    let long;
    let tempdeg = document.querySelector(".tempdeg");
    let tempdesc = document.querySelector(".tempdesc");
    let loctime = document.querySelector(".loctime");
    let tempsec = document.querySelector(".temperature");
    let tempspan = document.querySelector(".temperature span");
    if (navigator.geolocation) {
        navigator.geolocation.getCurrentPosition(position => {
            long = position.coords.longitude;
            lat = position.coords.latitude;
            console.log(lat)
            console.log(long)
            const proxy = "https://cors-anywhere.herokuapp.com/";
            const weatherapi = `${proxy}https://api.darksky.net/forecast/fd9d9c6418c23d94745b836767721ad1/${lat},${long} `;

            fetch(weatherapi)
                .then(response => {
                    return response.json();
                })
                .then(data => {
                    console.log(data);
                    const { temperature, summary, icon } = data.currently;
                    tempdeg.textContent = temperature;
                    tempdesc.textContent = summary;
                    loctime.textContent = data.timezone;
                    setIcons(icon, document.querySelector(".icon"));

                    let celsius = ((temperature - 32) * (5 / 9));

                    tempsec.addEventListener("click", () => {
                        if (tempspan.textContent == "F") {
                            tempspan.textContent = "C";
                            tempdeg.textContent = Math.floor(celsius);
                        }
                        else {
                            tempspan.textContent = "F";
                            tempdeg.textContent = temperature;
                        }
                    })
                });
        });
    }
    else {
        document.write("gimme permissions first");
    }
    const setIcons = (icon, iconID) => {
        const skycons = new Skycons({ color: "gray" });
        const currentIcon = icon.replace(/-/g, "_").toUpperCase();
        skycons.play();
        return skycons.set(iconID, Skycons[currentIcon]);
    }

});
