const observer0 = new IntersectionObserver(entries => {
                
    entries.forEach(entry => {
        entry.target.classList.toggle("f", entry.isIntersecting)
        if(entry.isIntersecting) observer0.unobserve(entry.target)
    })
},
{
    threshold: 1,
}
     
);

observer0.observe(document.querySelector('.pythonbar'));


const observer1 = new IntersectionObserver(entries => {
                
    entries.forEach(entry => {
        entry.target.classList.toggle("f", entry.isIntersecting)
        if(entry.isIntersecting) observer1.unobserve(entry.target)
    })
},
{
    threshold: 1,
}
     
);

observer1.observe(document.querySelector('.cppbar'));

const observer2 = new IntersectionObserver(entries => {
                
    entries.forEach(entry => {
        entry.target.classList.toggle("f", entry.isIntersecting)
        if(entry.isIntersecting) observer2.unobserve(entry.target)
    })
},
{
    threshold: 1,
}
     
);

observer2.observe(document.querySelector('.htmlbar'));

const observer3 = new IntersectionObserver(entries => {
                
    entries.forEach(entry => {
        entry.target.classList.toggle("f", entry.isIntersecting)
        if(entry.isIntersecting) observer3.unobserve(entry.target)
    })
},
{
    threshold: 1,
}
     
);

observer3.observe(document.querySelector('.cssbar'));

const observer4 = new IntersectionObserver(entries => {
                
    entries.forEach(entry => {
        entry.target.classList.toggle("f", entry.isIntersecting)
        if(entry.isIntersecting) observer4.unobserve(entry.target)
    })
},
{
    threshold: 1,
}
     
);

observer4.observe(document.querySelector('.jsbar'));