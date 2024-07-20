const btnSubmit = document.querySelector(".submit-button");
btnSubmit.addEventListener("click", function (e) {
  e.preventDefault();

  var petInfo = {
    name: document.querySelector(".name").value,
    age: document.querySelector(".age").value,
    weight: document.querySelector(".weight").value,
    breed: document.querySelector(".breed").value,
    hobbies: document.querySelector(".hobbies").value,
  };

  console.log(petInfo);
});
