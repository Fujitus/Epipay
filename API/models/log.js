//
// operation.js for Epipay in /home/costa_d/Documents/Epipay/API/models
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//

var mongoose = require('mongoose');

//Log Schema
var logSchema = mongoose.Schema({
    action_name:{
      type: String,
      required: true
    },
    card_id:{
      type: String,
      required: false
    },
    price:{
      type: Number,
      default: 0
    },
    type:{
      type: String,
      enum: ['BUY', 'STOCK','RESTOCK', 'DELSTOCK','ADDMONEY'],
      required: true
    },
    nombre:{
      type: Number,
      required: true
    },
    date:{
      type: Date,
      default: Date.now
    }
  },
{
  versionKey: false
});

var Log = module.exports = mongoose.model('Log', logSchema);

// Get Log
module.exports.getLog = function(callback, limit){
  Log.find(callback).limit(limit);
}

//Add Log
module.exports.addLog = function(log){
  Log.create(log);
}

//Delet Log
module.exports.removeLog = function(id, callback){
  var query = {_id: id};
  Log.remove(query, callback);
}
