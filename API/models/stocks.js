//
// stoks.js for Epipay in /home/costa_d/Documents/Epipay/API/models
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//

const mongoose = require('mongoose');

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
    last_refill:{
      type: Date,
      default: Date.now
    },
    consumed:
    {
      type: Number,
      default: 0,
      required: true
    },
    in_stock:
    {
      type: Number,
      default: 0,
      required: true
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
