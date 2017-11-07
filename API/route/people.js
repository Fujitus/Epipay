const People = require('../models/people');
const PeopleRules = require('../config/peopleRules');

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
  People.findOne({"card_id" : req.params.card_id}, function (err, user) {
    if (err || user == null)
      res.json({"Error" : "No user find"});
    else {
      PeopleRules.updatePeople(req.params.card_id, req.body.price, req.body.action_type, user, function(err, people){
        if (err){
          res.json({"Error" : err});
        }
        else {
          res.json(people);
        }
      });
    }
  })
});

}
