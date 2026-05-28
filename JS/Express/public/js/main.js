const output = document.querySelector("#output");
const btn = document.querySelector("#get-posts-btn");
const form = document.querySelector("#post-form");

async function showPosts() {
  try {
    const res = await fetch("http://localhost:5000/api/posts");
    if (!res.ok) {
      throw new Error("Network response was not ok");
    }

    const posts = await res.json();
    output.innerHTML = "";

    posts.forEach((post) => {
      const postEl = document.createElement("div");
      postEl.textContent = post.title;
      output.appendChild(postEl);
    });
  } catch (error) {
    output.innerHTML = "Error fetching posts";
    console.error("There has been a problem with your fetch operation:", error);
  }
}

async function addPost(e) {
  e.preventDefault();
  const formData = new FormData(this);
  const title = formData.get("title");

  try {
    const res = await fetch("http://localhost:5000/api/posts", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({ title }),
    });

    if (!res.ok) {
      throw new Error("Network response was not ok");
    }

    const newPost = await res.json();

    const postEl = document.createElement("div");
    postEl.textContent = newPost[newPost.length - 1].title;
    output.appendChild(postEl);
    showPosts();
  } catch (error) {
    console.error("There has been a problem with your fetch operation:", error);
  }
}

// Event listener for button click
btn.addEventListener("click", showPosts);
form.addEventListener("submit", addPost);
