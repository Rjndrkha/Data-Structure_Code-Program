require("dotenv").config();
const connectDB = require("./db/conn");

//async errors
require("express-async-errors"); 


const express = require("express");
const app=express();

const productRouter = require("./routes/products");

const notFoundMiddleware = require("./middleware/not-found");

const errorMiddleWare = require("./middleware/error-handler")


//middleware
app.use(express.json());

//routes
app.get("/",(req,res)=>{
    res.send('<h1>STORE API</h1><a href="/api/v1/products">Products Route</a>');
});

app.use("/api/v1/products",productRouter);

//products route
app.use(notFoundMiddleware);
app.use(errorMiddleWare);

const port = process.env.PORT || 8000;


const start = async()=>{
    try{
        await connectDB();
        app.listen(port,()=>{
            console.log(`Server running on port ${port}...`);
        })
    }catch(error){
        console.log(error);
    }
}

start();
