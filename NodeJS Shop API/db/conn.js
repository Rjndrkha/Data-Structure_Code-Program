const mongoose = require("mongoose");

const connectDB = ()=>{
    mongoose.connect("mongodb://localhost:27017/storeAPI",{
    useNewUrlParser:true,
    useUnifiedTopology:true
}).then(()=>{
    console.log("Connected to DB");
}).catch((err)=>{
    console.log(err);
})
}

module.exports = connectDB;