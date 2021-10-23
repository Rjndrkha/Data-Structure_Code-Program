const quoteContainer = document.getElementById('quote-container');
const quoteText = document.getElementById('quote');
const authorText = document.getElementById('author');
const twitterBtn = document.getElementById('twitter');
const facebookBtn = document.getElementById('facebook');
const instagramBtn = document.getElementById('instagram');
const newQuoteBtn = document.getElementById('new-quote');
const loader = document.getElementById('loader');

let apiQuotes = [];


//  *Get Quote Fromo API  throughing CORS error
//  const getQuote= async function()
//  {
//      const proxyUrl='https://cors-anywhere.herokuapp.com/'
//  const apiUrl='http://api.forismatic.com/api/1.0/?method=getQuote&lang=en&fromat=json';
//  try{
// const response=await fetch(proxyUrl+apiUrl);
// const data=await response.json();
// console.log(data);
//  }
//  catch(err)
//  {

//  }
//  }



//  *Show Loading
const loading = function () {
    loader.hidden = false;
    quoteContainer.hidden = true;
}

//  *Hide Loading
const complete = function () {
    loader.hidden = true;
    quoteContainer.hidden = false;
}

//  *Get Quotes From API
const newRandomQuote = function () {

    // * Pick a random quote from apiQuotes array
    const quote = apiQuotes[Math.floor(Math.random() * apiQuotes.length)];


    // *Check if Author Field is blank and replace it with unknown
    if (!quote.author)
        authorText.textContent = 'Unknown';
    else
        authorText.textContent = quote.author;

    // * Check Quote length to determine styling
    if (quote.text.length > 120)
        quoteText.classList.add('long-quote');
    else
        quoteText.classList.remove('long-quote');

    // * Set Quote, Hide Loader
    quoteText.textContent = quote.text;
    complete();
}

const getQuotes = async function () {
    loading();
    const apiUrl = 'https://type.fit/api/quotes';
    try {
        const response = await fetch(apiUrl);
        apiQuotes = await response.json();
        newRandomQuote();
    }
    catch (err) {
      
    }
}


// *Tweet a quote
const tweetQuote = function () {
    const twitterUrl = `https://twitter.com/intent/tweet?text=${quoteText.textContent}  -  ${authorText.textContent}`;
    window.open(twitterUrl, '_blank');
}

// * Event Listeners
newQuoteBtn.addEventListener('click', newRandomQuote);
twitterBtn.addEventListener('click', tweetQuote);

//  *On Load
getQuotes();