window.addEventListener('load', () => {
    const grid = document.querySelector(".grid");

    const cardarray = [
        {
            name: "borgir", img: "images/borgir.jpg"
        },
        {
            name: "book", img: "images/book.jpg"
        },
        {
            name: "cube", img: "images/cube.jpg"
        },
        {
            name: "fries", img: "images/fries.jpg"
        },
        {
            name: "borgir", img: "images/borgir.jpg"
        },
        {
            name: "book", img: "images/book.jpg"
        },
        {
            name: "cube", img: "images/cube.jpg"
        },
        {
            name: "fries", img: "images/fries.jpg"
        }
    ]
    cardarray.sort(function () { return 0.5 - Math.random() })
    let chosencard = [];
    let chosencardid = [];
    let score = 0
    const rdisp = document.querySelector("#result")
    const mdisp = document.querySelector("#fmsg")

    let timeinsec = 300
    let today = new Date()
    let cdtime = today.setSeconds(today.getSeconds + timeinsec)
    setInterval(() => {
        let now = new Date().getTime();
        let diff = cdtime - now;
        let hours = Math.floor(diff % (1000 * 60 * 60 * 60 * 24)) / (1000 * 60 * 60)
        let mins = Math.floor(diff % (1000 * 60 * 60)) / (1000 * 60)
        let secs = Math.floor(diff % (1000 * 60)) / (1000)
    }, 1000);
    let creategrid = () => {
        for (let i = 0; i < cardarray.length; i++) {
            const card = document.createElement("img");
            card.setAttribute("src", "images/gray.png")
            card.setAttribute("class", "hey")
            card.setAttribute("data-id", i)
            card.addEventListener("click", flip)
            grid.appendChild(card);
        }

    }
    const matchcards = () => {
        const cards = document.querySelectorAll("img")
        let oneid = chosencardid[0];
        let twoid = chosencardid[1];

        if (oneid == twoid) {
            alert("clicked on the same card twice")
            cards[oneid].setAttribute("src", "images/gray.png")
            cards[twoid].setAttribute("src", "images/gray.png")

        }
        else if (chosencard[0].name == chosencard[1].name) {
            cards[oneid].setAttribute("src", "images/white.jpg")
            cards[twoid].setAttribute("src", "images/white.jpg")
            cards[oneid].removeEventListener("click", flip)
            cards[twoid].removeEventListener("click", flip)

            score = score + 1;
        }
        else {
            cards[oneid].setAttribute("src", "images/gray.png")
            cards[twoid].setAttribute("src", "images/gray.png")
        }
        chosencard = [];
        chosencardid = [];
        rdisp.textContent = score;
        if (score == cardarray.length / 2) {
            alert("congrats you completed it")
            mdisp.textContent = "finished, found all of them"
        }

    }
    function flip() {
        let cardid = this.getAttribute("data-id");
        chosencard.push(cardarray[cardid]);
        chosencardid.push(cardid);
        console.log(cardarray[cardid].name, cardid)
        this.setAttribute("src", cardarray[cardid].img);
        if (chosencardid.length == 2) {
            setTimeout(matchcards, 500);
        }
    }

    creategrid()
});