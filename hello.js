var http=require('http')
var server=http.createServer(function(req,res){
res.writeHead(200,{'Content-Type':'text/plain'})
res.end("\n Hello World!");
});
server.listen(8081);
console.log('Server has started');
