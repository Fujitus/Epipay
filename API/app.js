//
// app.js for Epipay in /home/costa_d/Documents/Epipay/API/
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//

var express = require('express');
var app = express();
var bodyParser = require('body-parser');
var mongoose = require('mongoose');

// init bodyParser
app.use(bodyParser.json());

//Include models
Stock = require('./models/stocks');
People = require('./models/people');

// Connect to MongooseDB
mongoose.connect('mongodb://epipay:epipay@ds127341.mlab.com:27341/epipay');
var db = mongoose.connection;

// Get '/' func
app.get('/', function(req, res){
  res.send('Welcome Please use /ap/people or /api/stock');
});

/*
// ----------------------------------------------------------------------------
// ############################# - Stock rules - #############################
// -----------------------------------------------------------------------------
*/

// Get Stock
app.get('/api/stock', function(req, res){
  Stock.getStock(function(err, stock){
    if (err){
      throw err;
    }
  res.json(stock);
  });
});

// Get Stock by Id
app.get('/api/stock/:_id', function(req, res){
  Stock.getStockById(req.params._id, function(err, stock){
    if (err){
      throw err;
    }
  res.json(stock);
  });
});

// Post Stock
app.post('/api/stock', function(req, res){
  var stock = req.body;
  Stock.addStock(stock, function(err, stock){
    if (err){
        res.status(416).send("[API - Error] stock Shema not correct");
        console.log("[API - Error] stock Shema not correct");
      //throw err;
    }
  res.json(stock);
  });
});

// Put Stock
app.put('/api/stock/:_id', function(req, res){
  var id = req.params._id;
  var stock = req.body;
  Stock.updateStock(id, stock, {}, function(err, stock){
    if (err){
      throw err;
    }
  res.json(stock);
  });
});

// Delet Stock
app.delete('/api/stock/:_id', function(req, res){
  var id = req.params._id;
  Stock.removeStock(id, function(err, stock){
    if (err){
      throw err;
    }
  res.json(stock);
  });
});

/*
// ----------------------------------------------------------------------------
// ############################# - People rules - #############################
// -----------------------------------------------------------------------------
*/

// Get People
app.get('/api/people', function(req, res){
  People.getPeople(function(err, people){
    if (err){
      throw err;
    }
  res.json(people);
  });
});

// Get People by Id
app.get('/api/people/:_id', function(req, res){
  People.getPeopleById(req.params._id, function(err, people){
    if (err){
      throw err;
    }
  res.json(people);
  });
});

// Post People
app.post('/api/people', function(req, res){
  var people = req.body;
  People.addPeople(people, function(err, people){
    if (err){
      res.status(416).send("[API - Error] people Shema not correct");
      console.log("[API - Error] people Shema not correct");
      //throw err;
    }
  res.json(people);
  });
});

// Put People by id
app.put('/api/people/:_id', function(req, res){
  var id = req.params._id;
  var people = req.body;
  People.updatePeople(id, people, {}, function(err, people){
    if (err){
      throw err;
    }
  res.json(people);
  });
});

// Delet People
app.delete('/api/people/:_id', function(req, res){
  var id = req.params._id;
  People.removePeople(id, function(err, people){
    if (err){
      throw err;
    }
  res.json(people);
  });
});

// Listen func
app.listen(3042);
console.log('Epipay - API Working and Running on port 3042');
