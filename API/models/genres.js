var mongoose = require('mongoose');

//Genre Shema
var genreSchema = mongoose.Schema({
  name:{
    type: String,
    required: true
  },
  create_data:{
    type: Date,
    default: Date.now
  }
});

var Genre = module.exports = mongoose.model('Genre', genreSchema);

//Get Genres
module.exports.getGenres = function(callback, limit){
  Genres.find(callback).limit(limit);
}

//Add Genre
module.exports.addGenres = function(genre, callback){
  Genres.create(genre, callback);
}
//Update Genre
module.exports.updateGenres = function(id, genre, option, callback){
  var query = {_id: id};
  var update = {
    name: genre.name
  };
  Genres.findOneAndUpdate(query, update, option, callback);
}

//Delet Genre
module.exports.removeGenres = function(id, callback){
  var query = {_id: id};
  Genres.remove(query, callback);
}
