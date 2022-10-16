const connectDB = require("./db/conn");
const Product  = require("./models/products");

const jsonProducts = require("./products.json");

const start = async () =>{
    try{
        //connect to the database
        await connectDB();

        //to delete the previos cluster
        await Product.deleteMany(); 

        //add the products to the database
        await Product.create(jsonProducts); 
        console.log("Success...");

        //exiting the process
        process.exit(0);
    }catch(error){
        console.log(error);
        process.exit(1);
    }
}

start();