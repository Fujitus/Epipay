var mongoose = require('mongoose');

//Books Schema
var bookSchema = mongoose.Schema({
  title:{
    type: String,
    required: true
  },
  genre:{
    type: String,
    required: true
  },
  description:{
    type: String,
    required: true
  },
  auther:{
    type: String,
    required: true
  },
  publisher:{
    type: String,
    required: true
  },
  pages:{
    type: String,
  },
  img_url:{
    type: String,
    required: true
  },
  create_data:{
    type: Date,
    default: Date.now
  }
});

var Book = module.exports = mongoose.model('Book', bookSchema);

//Get Books
module.exports.getBooks = function(callback, limit){
  Book.find(callback).limit(limit);
}

//Get Books by id
module.exports.getBooksById = function(id, callback){
  Book.findById(id, callback);
}

//Add Book
module.exports.addBooks = function(book, callback){
  Book.create(book, callback);
}

//Update Book
module.exports.updateBooks = function(id, book, option, callback){
  var query = {_id: id};
  var update = {
    name: book.title,
    genre: book.genre,
    description: book.description,
    auther: book.auther,
    publisher: book.publisher,
    pages: book.pages,
    img_url: book.img_url
  };
  Books.findOneAndUpdate(query, update, option, callback);
}

//Delet Book
module.exports.removeBooks = function(id, callback){
  var query = {_id: id};
  Books.remove(query, callback);
}
