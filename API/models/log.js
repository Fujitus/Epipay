//
// operation.js for Epipay in /home/costa_d/Documents/Epipay/API/models
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//

const mongoose = require('mongoose');

//Log Schema
var logSchema = mongoose.Schema({
    action_name:{
      type: String,
      required: true
    },
    card_id:{
      type: String,
    },
    price:{
      type: Number,
    },
    type:{
      type: String,
      enum: ['BUY', 'STOCK','RESTOCK', 'DELSTOCK','ADDMONEY', 'NEWUSER'],
      required: true
    },
    nombre:{
      type: Number,
    },
    date:{
      type: Date,
      default: Date.now()
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
module.exports.addLog = function(newLog){
  Log.create(newLog);
}
