const mongoose = require("mongoose");

//defining schema
const productSchema = mongoose.Schema({
      name:{
        type:String,
        required:[true,"Product name must be provided"]
      },
      price:{
        type:Number,
        required:[true,"Price must be provided"]
      },
      featured:{
        type:Boolean,
        default:false
      },
      price:{
        type:Number,
        required:[true,"Price must be provided"]
      },
      rating:{
        type:Number,
        default:4.5
      },
      createdAt:{
        type:Date,
        default:Date.now(),
      },
      company:{
        type:String,
        enum:{
            values:['ikea','liddy','caressa','marcos'],
            message:"{VALUE} is not supported"
        },
      },
})

module.exports = mongoose.model("Product",productSchema);

