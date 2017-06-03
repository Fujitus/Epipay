//
// stoks.js for Epipay in /home/costa_d/Documents/Epipay/API/models
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//

const mongoose = require('mongoose');

//Include models
Log = require('./log');

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
      default: 0,
      required: true
    },
    consumed:
    {
      type: Number,
      default: 0,
      required: true
    },
    consumed_reset:
    {
      type: Number,
      default: 0,
      required: true
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

//Get Stock by codebar
module.exports.getStockById = function(codebar, callback){
  let query = {codebar: codebar};
  Stock.find(query, callback);
}

//Add Stock
module.exports.addStock = function(stock, callback){
  let updateStock = {
    action_name: "Add " + stock.name,
    type: "STOCK",
    nombre: stock.consumed
  };
  Stock.create(stock, callback);
  Log.addLog(updateStock);
}

//Update Stock by codebar
module.exports.updateStock = function(codebar, stock, option, callback){
  let query = {codebar: codebar};
  let update = {
    name: stock.name,
    type: stock.type,
    price: stock.price,
    price_bde: stock.price_bde,
    price_hub: stock.price_hub,
    codebar: stock.codebar,
    consumed: stock.consumed,
    consumed_reset: stock.consumed_reset,
    consumed_total: stock.consumed_total,
    last_refill: Date.now(),
  };
  let updateStock = {
    action_name: "Update " + stock.name,
    type: "RESTOCK",
    nombre: stock.consumed
  };
  Stock.findOneAndUpdate(query, update, option, callback);
  Log.addLog(updateStock);
}

//Delet Stock
module.exports.removeStock = function(id, callback){
  let query = {_id: id};
  /*
      TODO
      find a way to get the name
  */
  console.log(id);
  let updateStock = {
    action_name: "Remove " + id,
    type: "DELSTOCK",
    nombre: 0
  };
  Stock.remove(query, callback)
  Log.addLog(updateStock);
}
