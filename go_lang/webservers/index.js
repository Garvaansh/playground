const express = require("express");
const app = express();
const PORT = 3000;

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.get("/", (req, res) => {
  res.send("Hello from Express!");
});

app.get('/get', (req, res)  => {
  res.status(200).json({message: "GET request received"});
})

app.post('/post', (req, res) => {
  let myJson = req.body; // JSON Body

  res.status(200).json({message: "POST request received", data: myJson});
})

app.post('/postform', (req, res) => {
  res.status(200).send(JSON.stringify(req.body)); // Form Data
})

app.listen(PORT, () => {
  console.log(`Server running on port http://localhost:${PORT}`);
});