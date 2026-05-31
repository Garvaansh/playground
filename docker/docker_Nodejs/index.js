import express from 'express';
const app = express();
const port = 3000

app.get('/', (req, res) => {
  res.json({
    status: 'ok', 
    message: "App is successfully running in a docker container with nodejs",
  })
})

app.listen(port, () => {
  console.log(`app listening on port http://localhost:${port}`)
})