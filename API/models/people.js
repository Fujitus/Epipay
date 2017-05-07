//
// people.js for Epipay in /home/costa_d/Documents/Epipay/API/models
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//

const mongoose = require('mongoose');

//People Schema
let peopleSchema = mongoose.Schema({
    firstname:{
      type: String,
      required: true
    },
    lastname:{
      type: String,
      required: true
    },
    balance:{
      type: Number,
      default: 0
    },
    email:{
      type: String,
      required: true
    },
    card_id:{
      type: String,
      required: true
    },
    privilege:{
      type: String,
      enum: ['ADMIN', 'BDE', 'HUB', 'USER'],
      required: true
    }
  },
{
  versionKey: false
});

let People = module.exports = mongoose.model('People', peopleSchema);

//Get People
module.exports.getPeople = function(callback, limit){
  People.find(callback).limit(limit);
}

//Get People by id
module.exports.getPeopleById = function(id, callback){
  People.findById(id, callback);
}

//Add People
module.exports.addPeople = function(people, callback){
  People.create(people, callback);
}

//Update People
module.exports.updatePeople = function(id, people, option, callback){
  let query = {_id: id};
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
