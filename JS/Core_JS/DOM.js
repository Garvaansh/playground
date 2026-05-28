  /**
   * DOM (Document Object Model) is a programming interface for web documents. 
   * It represents the structure of a document as a tree of objects, allowing developers to manipulate the content, structure, and style of web pages dynamically using JavaScript.
   * The DOM provides methods and properties to access and modify elements, attributes, and events in an HTML or XML document.
   */

// Example: Accessing and modifying DOM elements

// Accessing an element by its ID
const myElement = document.getElementById('myElementId');
// Modifying the content of the element
myElement.textContent = 'Hello, World!';
// Accessing elements by their class name
const elements = document.getElementsByClassName('myClassName'); 
// Modifying the style of the first element with the class name
elements[0].style.color = 'red';
// Creating a new element and appending it to the DOM
const newElement = document.createElement('div');
newElement.textContent = 'This is a new element';
document.body.appendChild(newElement);

// Types of DOM Nodes
// Element Node
const elementNode = document.getElementById('myElementId');
// Text Node
const textNode = elementNode.firstChild; // Assuming the first child is a text node
// Comment Node
const commentNode = document.createComment('This is a comment');
document.body.appendChild(commentNode);


// Children and Parent Nodes
const parentElement = document.getElementById('parentElementId');
// Parent node
const parentNode = childElement.parentNode;
// First child
const childNode = parentElement.firstChild; 
// First Element child
//? return only an element node, while firstChild can return any type of node (element, text, comment, etc.)
const childElement = parentElement.firstElementChild; 
// Last child
const Lastnode = parentElement.lastChild;
// Last Element child
//? return only an element node, while firstChild can return any type of node (element, text, comment, etc.)
const lastChildElement = parentElement.lastElementChild;
// All child node
const allChildNodes = parentElement.childNodes;

// Siblings
// Next sibling
const nextSibling = childElement.nextElementSibling;
// Previous sibling
const previousSibling = childElement.previousElementSibling;