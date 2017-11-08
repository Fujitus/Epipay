const PeopleRules = require('../config/peopleRules');
const StockRules = require('../config/stocksRules');
const People =require('../models/people');
/*
// ----------------------------------------------------------------------------
// ############################# - People rules - #############################
// -----------------------------------------------------------------------------
*/

module.exports = function(app) {

// Get People
app.get('/api/people', function(req, res){
  PeopleRules.getPeople(req, function(people){
  res.json(people);
  });
});

// Get People by Card Id
app.get('/api/people/:card_id', function(req, res){
  PeopleRules.getPeopleById(req.params.card_id, function(people){
  res.json(people);
  });
});

// Post People
app.post('/api/people', function(req, res){
  let people = req.body;
  PeopleRules.addPeople(people, function(err, people){
    if (err){
      res.json({"Error" : "people Shema not correct"});
    }
    else {
      res.json(people);
    }
  });
});

// Post People by card id
app.post('/api/people/:card_id', function(req, res){
  if (req.body.codebar_array == null)
    res.json({"Error" : "codebar_array is not set corectli"});
  else {
    let codebarArray = req.body.codebar_array;
    People.findOne({"card_id" : req.params.card_id}, function (err, user) {
      if (err || user == null)
        res.json({"Error" : "No user find"});
      else {
        PeopleRules.updatePeople(req.params.card_id, req.body.price, req.body.action_type, user, function(err, people){
          if (err){
            res.json({"Error" : err});
          }
          else {
            for (var i = 0; i < codebarArray.length; i++) {
              console.log(codebarArray[i].codebar);
              StockRules.deStock(codebarArray[i].codebar, function(err, stock){
                if (err)
                  res.json(stock);
              });
            }
            res.json(people);
          }
        });
      }
    })
  }
});

}
