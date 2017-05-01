//
// stoks.js for Epipay in /home/costa_d/Documents/Epipay/API/models
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//

var mongoose = require('mongoose');

//Stock Shema
var stockSchema = mongoose.Schema({
    name:{
      type: String,
      required: true
    },
    type:{
      type: String,
      enum: ['DRINK', 'HOTDRINK', 'SNACK', 'EVENT', 'FOOD'],
      required: true
    },
    price:{
      type: Number,
      required: true
    },
    price_bde:{
      type: Number,
      required: true
    },
    price_hub:{
      type: Number,
      required: true
    },
    last_refill:{
      type: Date,
      default: Date.now
    },
    consumed_total:
    {
      type: Number,
      default: 0
    },
    consumed:
    {
      type: Number,
      default: 0
    },
    consumed_reset:
    {
      type: Number,
      default: 0
    },
    img_url:
    {
      type: String,
      required: false
    },
    codebar:
    {
      type: Number,
      required: true
    }
  },
{
  versionKey: false
});

var Stock = module.exports = mongoose.model('Stock', stockSchema);

//Get Stocks
module.exports.getStock = function(callback, limit){
  Stock.find(callback).limit(limit);
}

//Get Stock by id
module.exports.getStockById = function(id, callback){
  Stock.findById(id, callback);
}

//Add Stock
module.exports.addStock = function(stock, callback){
  Stock.create(stock, callback);
}

//Update Stock
module.exports.updateStock = function(id, stock, option, callback){
  var query = {_id: id};
  var update = {
    name: stock.name,
    type: stock.type,
    price: stock.price,
    price_bde: stock.price_bde,
    price_hub: stock.price_hub,
    codebar: stock.codebar,
    consumed: stock.consumed,
    consumed_reset: stock.consumed_reset,
    consumed_total: stock.consumed_total,
    last_refill: stock.last_refill,
  };
  Stock.findOneAndUpdate(query, update, option, callback);
}

//Delet Genre
module.exports.removeGenres = function(id, callback){
  var query = {_id: id};
  Stock.remove(query, callback);
}
