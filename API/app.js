var express = require('express');
var app = express();
var bodyParser = require('body-parser');
var mongoose = require('mongoose');

// init bodyParser
app.use(bodyParser.json());

//Include models
Genres = require('./models/genres');
Books = require('./models/books');

// Connect to MongooseDB
mongoose.connect('mongodb://epipay:epipay@ds127341.mlab.com:27341/epipay');
var db = mongoose.connection;

// get / func
app.get('/', function(req, res){
  res.send('Welcome Please use /ap/books or /api/genres');
});

// Get Genre
app.get('/api/genres', function(req, res){
  Genres.getGenres(function(err, genres){
    if (err){
      throw err;
    }
  res.json(genres);
  });
});

// Post Genre
app.post('/api/genres', function(req, res){
  var genre = req.body;
  Genres.addGenres(genre, function(err, genre){
    if (err){
      throw err;
    }
  res.json(genre);
  });
});

// Put genre
app.put('/api/genres/:_id', function(req, res){
  var id = req.params._id;
  var genre = req.body;
  Genres.updateGenres(id, genre, {}, function(err, genre){
    if (err){
      throw err;
    }
  res.json(genre);
  });
});

// Delet Genres
app.delete('/api/genres/:_id', function(req, res){
  var id = req.params._id;
  Genres.removeGenres(id, function(err, genre){
    if (err){
      throw err;
    }
  res.json(genre);
  });
});

// Get Book
app.get('/api/books', function(req, res){
  Books.getBooks(function(err, books){
    if (err){
      throw err;
    }
  res.json(books);
  });
});

// Get Book by Id
app.get('/api/books/:_id', function(req, res){
  Books.getBooksById(req.params._id, function(err, book){
    if (err){
      throw err;
    }
  res.json(book);
  });
});

// Post Books
app.post('/api/books', function(req, res){
  var book = req.body;
  Books.addBooks(book, function(err, book){
    if (err){
      throw err;
    }
  res.json(book);
  });
});

// Put Books
app.put('/api/books/:_id', function(req, res){
  var id = req.params._id;
  var book = req.body;
  Books.updateBooks(id, book, {}, function(err, book){
    if (err){
      throw err;
    }
  res.json(book);
  });
});

// Delet Books
app.delete('/api/books/:_id', function(req, res){
  var id = req.params._id;
  Books.removeBooks(id, function(err, book){
    if (err){
      throw err;
    }
  res.json(book);
  });
});

// listen func
app.listen(3042);
console.log('API Working and Running on port 3042');
