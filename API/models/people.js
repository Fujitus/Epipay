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
    }
  },
{
  versionKey: false
});

var People = module.exports = mongoose.model('People', peopleSchema);

//Get People
module.exports.getPeople = function(callback, limit){
  People.find(callback).limit(limit);
}

//Get People by card id
module.exports.getPeopleById = function(card_id, callback){
  let query = {card_id: card_id};
  People.find(query, callback);
}

//Add People
module.exports.addPeople = function(people, callback){
  People.create(people, callback);
}

//Update People by card id
module.exports.updatePeople = function(id, people, option, callback){
  let query = {card_id: id};
  let update = {
    firstname: people.firstname,
    lastname: people.lastname,
    balance: people.balance,
    email: people.email,
    card_id: people.card_id,
    privilege: people.privilege
  };
  People.findOneAndUpdate(query, update, option, callback);
}

//Delet People
module.exports.removePeople = function(id, callback){
  let query = {_id: id};
  People.remove(query, callback);
}
