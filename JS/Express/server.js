// ES6 Syntax to import modules
import express from "express";
import path from "path";
import { fileURLToPath } from "url"; // This is needed to use __dirname in ES6 modules

import posts from "./routes/posts.js";
import logger from "./middleware/logger.js";
import {errorHandler, Notfound} from "./middleware/errorHandler.js";

// Common JS Syntax to import modules
// const express = require("express");
// const path = require("path");
// const posts = require('./routes/posts');

const PORT = process.env.PORT || 8000;
const app = express();

//* Upload/sends a file to the browser.

//! Setup static folder as middleware
//! __dirname is the current directory of this file (server.js)
//! we don't have to manually specify each file to be sent to the browser
//! we can just put all the files in a folder and specify that folder as static
//! express.static is a built-in middleware function in Express. It serves static files and is based on serve-static.
//! path.join is used to join multiple path segments into a single path. It takes care of the correct path separators for different operating systems.

// Module EJs method
const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
app.use(express.static(path.join(__dirname, "public")));


//? Manual example of sending files
// app.get("/", (req, res) => {
//   res.sendFile(path.join(__dirname, "public", "index.html"));
// });

// app.get("/about", (req, res) => {
//   res.sendFile(path.join(__dirname, "public", "about.html"));
// });

//? Body Parser Middleware
app.use(express.json());
app.use(express.urlencoded({ extended: false }));

//? logger middleware
app.use(logger);

//! Routes
app.use("/api/posts", posts);


//? Error Handler
app.use(Notfound);
app.use(errorHandler);

app.listen(PORT, () =>
  console.log(`server is running on http://localhost:${PORT}`)
);
