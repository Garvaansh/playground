const errorHandler = (err, req, res, next) => {
  if (err.status) {
    res.status(err.status).json({ error: err.message });
  } else {
    res.status(500).json({ error: "Server Error" });
  }
};

const Notfound = (req, res, next) => {
  const error = new Error("Not Found");
  error.status = 404;
  next(error);
};

export { errorHandler, Notfound };
