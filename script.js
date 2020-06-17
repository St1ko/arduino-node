const express = require("express");
const app = express();
var http = require("http").createServer(app);
var io = require("socket.io")(http);

const SerialPort = require("serialport");
const Readline = require("@serialport/parser-readline");
const port = new SerialPort("COM3", { baudRate: 9600 });
const parser = port.pipe(new Readline({ delimiter: "\n" }));

app.use(express.static(__dirname + "/client"));

app.get("/", (req, res) => {
  res.sendFile(__dirname + "/index.html");
});

io.on("connection", (socket) => {
  parser.on("data", (data) => {
    io.emit("news", 1);
  });
});

http.listen(3000, () => {
  console.log("listening on *:3000");
});
