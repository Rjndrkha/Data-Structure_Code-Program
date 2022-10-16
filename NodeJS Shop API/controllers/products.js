const Product = require("../models/products");

//for testing
const getAllProductsStatic = async (req,res)=>{
    
    const products = await Product.find({price:{$gt:30}}).sort("price").select("name price").limit(10)
    res.status(200).json({products , noHits:products.length});
}


//get all products from here
const getAllProducts = async (req,res)=>{
    const { featured,company,name,sort,fields,numericFilters } = req.query;
    const  queryObject = {};

    //search based on featured attribute of the product
    if(featured){
        queryObject.featured = featured === 'true'?true:false;
    }

    //search based on company name attribute of the product
    if(company){
        queryObject.company = company; 
    }

    //search based on name attribute of the product
    if(name){
        queryObject.name = {$regex:name,$options:"i"};
    }

    //search based on numeric filters
    if(numericFilters){
        const operatormap={
            '>':'$gt',
            '>=':'$gte',
            '<':'$lt',
            '<=':'$lte',
            '=':'$eq'
        }

        const regEx = /\b(<|>=|>|<=|=)\b/g
        let filters = numericFilters.replace(regEx,(match)=>
            `-${operatormap[match]}-`
        )
        const options = ['price','rating'];
        filters = filters.split(',').forEach((item)=>{
            const[field,operator,value] = item.split('-');
            if(options.includes(field)){
                queryObject[field] = {[operator]:Number(value)}
            }
        })
    }


    console.log(queryObject);
    //made it let because user may not pass the sort 
    let result = Product.find(queryObject);


     //await removed in order to fetch the products from filter and then sort and get the sorted products
    if(sort){
        const sortList = sort.split(',').join(' ');
        result=result.sort(sortList);
    }
    else{
        result=result.sort('createAt')
    }


    ///to view only few selected features of the product


    if(fields){
        const fieldList = fields.split(',').join(' ');
        result = result.select(fieldList);
    }

    //to limit the number of products displayed
    const page = Number(req.query.page) || 1
    const limit  =  Number(req.query.limit) || 10
    const skip = (page-1)*limit;
    result = result.skip(skip).limit(limit); 


    const products = await result;
    res.status(200).json({products,noHits:products.length});
}

module.exports = {getAllProducts,getAllProductsStatic}

