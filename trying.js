var http=require('http')
var fs=require('fs')
var readdata=fs.readFileSync('input.html')
var server=http.createServer(function(req,res){
res.writeHead(200,{'Content-Type':'text/html'})
res.write(readdata)
res.end("\n Hello World!");
});
server.listen(8081);
console.log('Server has started');
