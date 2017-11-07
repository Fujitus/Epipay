//
// people.js for Epipay in /home/costa_d/Documents/Epipay/API/models
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//

const mongoose = require('mongoose');

//People Schema
var   peopleSchema = mongoose.Schema({
    email:{
      type: String,
      required: true
    },
    card_id:{
      type:   String,
      required: true
    },
    privilege:{
      type: String,
      enum: ['ADMIN', 'USER','BDE', 'HUB'],
      required: true
    },
    balance:{
      type:   Number,
      required: true
    },
    last_transaction:{
      type: Date,
      default: Date.now()
    }
  },
{
  versionKey: false
});

var People = module.exports = mongoose.model('People', peopleSchema);
