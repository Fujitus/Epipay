const Stock = require('../models/stocks');
const StockRules = require('../config/stocksRules');

/*
// ----------------------------------------------------------------------------
// ############################# - Stock rules - #############################
// -----------------------------------------------------------------------------
*/

module.exports = function(app) {

// Get Stock
app.get('/api/stock', function(req, res){
  StockRules.getStock(req, function(stock){
  res.json(stock);
  });
});

// Get Stock by codebar
app.get('/api/stock/:codebar', function(req, res){
  StockRules.getStockById(req, function(item){
  res.json(item);
  });
});

// Put Stock by codebar
app.post('/api/stock/:codebar', function(req, res){
  Stock.findOne({"codebar" : req.params.codebar}, function(err, item) {
    if (err)
      res.json({"Error" : err});
    else if (item == null)
      StockRules.addStock(req.body, function(err, done){
    if (err)
      res.json({"Error" : err});
    res.json(done);
    })
    else {
      StockRules.updateStock(req.params.codebar, req.body, function(err, done){
        if (err)
          res.json({"Error" : err});
        res.json(done);
      })
    }
  });
});

// Delet Stock
app.delete('/api/stock/:codebar', function(req, res){
  StockRules.removeStock(req.params.codebar, function(stock){
  res.json(stock);
  });
});

}
