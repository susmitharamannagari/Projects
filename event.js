var events=require('events')
var eventemitter=new events.EventEmitter()
var eventlisteners=require('events').EventEmitter.listenerCount
var listen1=function(){
  console.log("listener 1 is executed")
}
var listen2=function(){
  console.log("listener 2 is executed")
}
eventemitter.on("connection",listen1)
eventemitter.addListener("connection",listen2)
console.log(eventlisteners(eventemitter,'connection')+" listeners are listening to connection")
eventemitter.emit('connection')
eventemitter.removeListener('connection',listen1)
console.log(eventlisteners(eventemitter,'connection')+" listeners are listening to connection")
eventemitter.emit('connection')
console.log("program has ended")
