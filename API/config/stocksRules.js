const Log = require('../models/log');
const Stock = require('../models/stocks');

//Get Stocks
module.exports.getStock = function(req, callback){
  Stock.find({}, function(err, allStock){
    if (err){
      callback({"Error" : err});
    }
    else {
      callback({"Stock" : allStock});
    }
  });
}

//Get Stock by codebar
module.exports.getStockById = function(req, callback){
  Stock.findOne({"codebar" : req.params.codebar}, function(err, item){
    if (err){
      callback({"Error" : err});
    }
    else if (item == null)
      callback({"Error" : "No item find"})
    else {
      callback({"item" : item});
    }
  });
}

//Add Stock
module.exports.addStock = function(newItems, callback){
  let updateStock = {
    action_name: "Add " + newItems.name + " in stock",
    type: "STOCK",
    nombre: newItems.in_stock,
  };
  Stock.create(newItems, callback);
  Log.addLog(updateStock);
  callback({"Ok" : newItems.name + " is add in stock"});
}

//Update Stock by codebar
module.exports.updateStock = function(codebar, items, callback){
  let updateStock = {
    action_name: "Update " + items.name + " in stock",
    type: "RESTOCK",
    nombre: items.in_stock,
  };
  let newItems = {
    name: items.name,
    type: items.type,
    price: items.price,
    codebar: items.codebar,
    in_stock: items.in_stock,
    last_refill: Date.now(),
  };
  Stock.findOneAndUpdate({"codebar" : codebar}, newItems, {upsert:true}, function(err, doc){
    if (err)
      callback({"Error" : err});
    else {
      Log.addLog(updateStock);
      callback({"Ok" : newItems.name + " is update in stock"});
    }
});
}

//Delet Stock
module.exports.removeStock = function(codebar, callback){
  Stock.findOne({"codebar" : codebar}, function(err, item){
    if (item == null)
      callback({"Error" : "No item find"})
    else {
      let updateStock = {
        action_name: "Remove " + item.name + " in stock",
        type: "DELSTOCK",
        nombre: 0
      };
      Stock.remove({"codebar" : codebar}, callback);
      Log.addLog(updateStock);
      callback({"Ok" : "Item as be removed"});
    }
  })
}
