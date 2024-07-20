const projectName = "BookForm";
console.log(projectName);
const btnEl = document.querySelector(".btn");
let bookName, authorName, price, publisherName, category;

btnEl.addEventListener("click", function (e) {
  e.preventDefault();
  bookName = document.querySelector(".book-name").value;
  authorName = document.querySelector(".author-name").value;
  price = document.querySelector(".book-price").value;
  publisherName = document.querySelector(".publisher-name").value;
  category = document.querySelector("#category").value;

  const bookObj = {
    book: bookName,
    author: authorName,
    price: price,
    publisher: publisherName,
    category: category,
  };

  console.log("JavaScript Object: ", bookObj);

  const bookArr = [];
  bookArr.push(bookObj);
  const JSON = { books: bookArr[0] };

  console.log("JSON: ", JSON);
});
