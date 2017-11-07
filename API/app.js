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

app.use(bodyParser.urlencoded({ extended: false }))
app.use(bodyParser.json());

// Connect to MongooseDB
mongoose.createConnection('mongodb://epipay:epipay@ds127341.mlab.com:27341/epipay');

require('./route/stocks')(app);
require('./route/people')(app);

/*
// ----------------------------------------------------------------------------
// ############################# - Log rules - #############################
// -----------------------------------------------------------------------------
*/

// Get Operation
app.get('/api/log', (req, res) => {
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
