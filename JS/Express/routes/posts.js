import express from "express";
const router = express.Router();

// const express = require("express");
// const router = express.Router();

//* Creating a json api -->

let posts = [
  { id: 1, title: "Post One" },
  { id: 2, title: "Post two" },
  { id: 3, title: "Post three" },
];

// Get All posts
// router.get("/", (req, res) => {
//   res.json(posts);
// });

// Take queries from the url
router.get("/", (req, res) => {
  const limit = parseInt(req.query.limit);

  if (!isNaN(limit) && limit > 0) {
    res.status(200).json(posts.slice(0, limit));
  } else {
    res.status(200).json(posts);
  }
});

//Get single post
router.get("/:id", (req, res, next) => {
  const id = parseInt(req.params.id);
  if (posts.findIndex((post) => post.id === id) === -1) {
    const error = new Error("A post with this ID was not found");
    error.status = 404;
    return next(error);
  } else {
    res.status(200).json(posts.filter((post) => post.id === id));
  }
});

// Create a post request
router.post("/", (req, res, next) => {
  const newPost = {
    id: posts.length + 1,
    title: req.body.title,
  };

  if (!newPost.title) {
    const error = new Error("Post title is required");
    error.status = 400;
    return next(error);
  }
  posts.push(newPost);
  res.status(201).json(posts);
});

// Update Post
router.put("/:id", (req, res, next) => {
  const id = parseInt(req.params.id);
  const post = posts.find((post) => post.id === id);

  if (!post) {
    const error = new Error("Invalid post ID");
    error.status = 404;
    return next(error);
  }

  post.title = req.body.title;
  res.status(200).json(posts);
});

// Delete post
router.delete("/:id", (req, res, next) => {
  const id = parseInt(req.params.id);
  const post = posts.find((post) => post.id === id);

  if (!post) {
    const error = new Error("Invalid post ID");
    error.status = 404;
    return next(error);
  }

  posts = posts.filter((post) => post.id !== id);
  res.status(200).json(posts);
});

// CommonJS export
// module.exports = router;
//Module export
export default router;
