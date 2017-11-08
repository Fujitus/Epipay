const Log = require('../models/log');
const People = require('../models/people');

//Get People
module.exports.getPeople = function(req, callback){
  People.find({}, function(err, allUser){
    if (err){
      callback({"Error" : err});
    }
    else {
      callback({"Peoples" : allUser});
    }
  });
}

//Get People by card id
module.exports.getPeopleById = function(card_id, callback){
  People.findOne({"card_id" : card_id}, function(err, user){
    if (err){
      callback({"Error" : err});
    }
    else if (user == null)
      callback({"Error" : "No user find"})
    else {
      callback({"User" : user});
    }
  });
}

//Add People
module.exports.addPeople = function(people, callback){
  let updatePeople = {
    action_name: "Add " + people.email + " in the DB",
    type: "NEWUSER",
  };
  People.create(people, callback);
  Log.addLog(updatePeople);
  callback({"Ok" : people.email + " is add in DB"});
}

//Update People by card id
module.exports.updatePeople = function(card_id, price, action_type, user, callback) {
  let tmp_price;
  if (action_type == "BUY") {
    tmp_price = user.balance - price;
  }
  else if (action == "ADDMONEY") {
    tmp_price = user.balance + price;
  }
  let updatePeople = {
    action_name: "OK " + user.email + " transaction",
    type: action_type,
    price: price
  };
  let update = {
    balance: tmp_price,
    last_transaction: Date.now(),
  }
  if (update.balance < 0.0) {
    callback({"Error" : user.email + " transaction fail balance is or will be at 0", balance : 0});
  }
  else {
    People.findOneAndUpdate({"card_id" : card_id}, update, {upsert:true},function(err, doc){
      if (err)
      callback({"Error" : err});
      else {
        Log.addLog(updatePeople);
        callback({"Ok" : user.email + " transaction"});
      }
    });
  }
}
