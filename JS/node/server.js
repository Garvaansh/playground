import http from "http"; // Import the HTTP module to create a web server
import fs from "fs/promises"; // Import the file system promises module for async file operations
import path from "path"; // Import the path module to handle file paths
import url from "url"; // Import the URL module to work with URLs
const PORT = 3000; // Define the port number where the server will listen

// Get the current file's path and directory (needed for ES modules)
const __filename = url.fileURLToPath(import.meta.url); // Convert the module URL to a file path
const __dirname = path.dirname(__filename); // Get the directory of the current file

// Create an HTTP server that handles requests asynchronously
const server = http.createServer(async (req, res) => {
  try {
    // Check if the request method is not GET (only allow GET requests)
    if (req.method !== "GET") {
      res.writeHead(405, { "Content-Type": "text/html" }); // Send 405 Method Not Allowed status
      res.end("<h1>405 Method Not Allowed</h1>"); // Respond with an error message
      return; // Stop further processing
    }

    let filepath; // Variable to store the path to the file to serve

    // Determine which file to serve based on the requested URL
    if (req.url === "/") {
      filepath = path.join(__dirname, "public", "index.html"); // Serve index.html for the root URL
    } else if (req.url === "/about") {
      filepath = path.join(__dirname, "public", "about.html"); // Serve about.html for /about
    } else {
      res.writeHead(404, { "Content-Type": "text/html" }); // Send 404 Not Found status for other URLs
      res.end("<h1>404 Not Found</h1>"); // Respond with a not found message
      return; // Stop further processing
    }

    // Read the file asynchronously and get its content as a string
    const data = await fs.readFile(filepath, "utf-8");

    // Set the response header to indicate we're sending HTML content
    res.setHeader("Content-Type", "text/html");

    // Write the file content to the response
    res.write(data);

    // End the response (send it to the client)
    res.end();
  } catch (error) {
    // If an error occurs (e.g., file not found), send a 500 Internal Server Error
    res.writeHead(500, { "Content-Type": "text/plain" });
    res.end(`<h1>500 Internal Server Error</h1><p>${error.message}</p>`); // Include the error message
  }
});

// Start the server and listen on the specified port
server.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`); // Log a message when the server starts
});
