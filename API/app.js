//
// app.js for Epipay in /home/costa_d/Documents/Epipay/API/
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//

const express = require('express');
const app = express();
const bodyParser = require('body-parser');
const mongoose = require('mongoose');

// init bodyParser
app.use(bodyParser.json());

//Include models
Stock = require('./models/stocks');
People = require('./models/people');

// Connect to MongooseDB
mongoose.connect('mongodb://epipay:epipay@ds127341.mlab.com:27341/epipay');

// Get '/' func
app.get('/', function(req, res){
  res.send('Welcome Please use /api/people - /api/stock - /api/log');
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

// Get Stock by codebar
app.get('/api/stock/:codebar', function(req, res){
  Stock.getStockById(req.params.codebar, function(err, stock){
    if (err){
      throw err;
    }
  res.json(stock);
  });
});

// Post Stock
app.post('/api/stock', function(req, res){
  let stock = req.body;
  Stock.addStock(stock, function(err, stock){
    if (err){
        res.status(416).send("[API - Error] stock Shema not correct");
        console.log("[API - Error] stock Shema not correct");
    }
  res.json(stock);
  });
});

// Put Stock
app.put('/api/stock/:_id', function(req, res){
  let id = req.params._id;
  let stock = req.body;
  Stock.updateStock(id, stock, {}, function(err, stock){
    if (err){
      throw err;
    }
  res.json(stock);
  });
});

// Delet Stock
app.delete('/api/stock/:_id', function(req, res){
  let id = req.params._id;
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

// Get People by Card Id
app.get('/api/people/:card_id', function(req, res){
  People.getPeopleById(req.params.card_id, function(err, people){
    if (err){
      throw err;
    }
  res.json(people);
  });
});

// Post People
app.post('/api/people', function(req, res){
  let people = req.body;
  People.addPeople(people, function(err, people){
    if (err){
      res.status(416).send("[API - Error] people Shema not correct");
      console.log("[API - Error] people Shema not correct");
      res.status(416).send(people);
    }
  res.json(people);
  });
});

// Put People by card id
app.put('/api/people/:card_id', function(req, res){
  let card_id = req.params.card_id;
  let people = req.body;
  People.updatePeople(card_id, people, {}, function(err, people){
    if (err){
      throw err;
    }
  res.json(people);
  });
});

// Delet People
app.delete('/api/people/:_id', (req, res) => {
  let id = req.params._id;
  People.removePeople(id, (err, people) => {
    if (err){
      throw err;
    }
  res.json(people);
  });
});

/*
// ----------------------------------------------------------------------------
// ############################# - Log rules - #############################
// -----------------------------------------------------------------------------
*/

// Get Operation
app.get('/api/log', function(req, res){
  Log.getLog(function(err, log){
    if (err){
      throw err;
    }
  res.json(log);
  });
});

app.set("port", 3000);

// Listen func
const server = app.listen(app.get('port'), () => {
  console.log('Epipay - API Working and Running on port ' + server.address().port);
});
