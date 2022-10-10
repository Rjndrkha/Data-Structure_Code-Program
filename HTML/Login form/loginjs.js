
const userBtn= document.querySelector(".userBtn");
const adminBtn= document.querySelector(".adminBtn");
const moveBtn= document.querySelector(".moveBtn");
const user= document.querySelector(".user");
const admin= document.querySelector(".admin");

adminBtn.addEventListener('click',()=>{
    moveBtn.classList.add("rigthBtn");
    admin.classList.add("adminForm");
    user.classList.remove("userForm");
    moveBtn.innerHTML="Admin";

});
userBtn.addEventListener('click',()=>{
    moveBtn.classList.remove("rigthBtn");
    admin.classList.remove("adminForm");
    user.classList.add("userForm");
    moveBtn.innerHTML="User";
});