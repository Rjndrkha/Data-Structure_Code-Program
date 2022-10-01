const observer0 = new IntersectionObserver(entries => {
                
    entries.forEach(entry => {
        entry.target.classList.toggle("f", entry.isIntersecting)
        if(entry.isIntersecting) observer0.unobserve(entry.target)
    })
},
{
    threshold: 0.3,
}
     
);

observer0.observe(document.querySelector('.num2'));


const observer1 = new IntersectionObserver(entries => {
    
    entries.forEach(entry => {
        entry.target.classList.toggle("f", entry.isIntersecting)
        if(entry.isIntersecting) observer1.unobserve(entry.target)
    })
},
{
    threshold: 0.3,
}
     
);

observer1.observe(document.querySelector('.num1'));



const observer2 = new IntersectionObserver(entries => {
                
    entries.forEach(entry => {
        entry.target.classList.toggle("f", entry.isIntersecting)
        if(entry.isIntersecting) observer2.unobserve(entry.target)
    })
},
{
    threshold: 0.3,
}
     
);

observer2.observe(document.querySelector('.num3'));




const observer3 = new IntersectionObserver(entries => {
                
    entries.forEach(entry => {
        entry.target.classList.toggle("f", entry.isIntersecting)
        if(entry.isIntersecting) observer3.unobserve(entry.target)
    })

},
{
    threshold: 0.3,
}
     
);

observer3.observe(document.querySelector('.num4'));