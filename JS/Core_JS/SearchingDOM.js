/** Searching the DOM functions
 * Use the following functions to search the DOM for elements. 
 * Each function returns a collection of elements that match the specified criteria.
 */

// Get elements by tag name
const paragraphs = document.getElementsByTagName('p');
console.log(paragraphs);

// Get elements by class name
const highlights = document.getElementsByClassName('highlight');
console.log(highlights);

// Get element by ID
const mainHeader = document.getElementById('main-header');
console.log(mainHeader);

// Get elements by name attribute
const inputs = document.getElementsByName('username');
console.log(inputs);

// Get elements using query selector (CSS selectors)
// Returns the first element that matches the specified CSS selector
// Efficient for selecting a single element instead of document.querySelectorAll('')[0]
const firstHighlight = document.querySelector('.highlight');
console.log(firstHighlight);

// Get all elements using query selector
const allHighlights = document.querySelectorAll('.highlight');
console.log(allHighlights);



