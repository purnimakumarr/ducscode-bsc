// ARRAY FOR PRINTING QUOTES
const quotes = [
  '"The ones who are crazy enough to think they xan change the world are the ones that do"',
  '"Sometimes life is going to hit you in the brick. Don\'t loose faith"',
  '"If you are working on something that you really care about, you don\'t have to be pushed. The vision pulls you."',
  '"It doesn\'t make sense to hire smart people and then tell them what to do; we hire smart people so they can tell us what to do"',
  '"The design is not just what it looks like, a design is how it works."',
];

//FUNCTION TO GENERATE A RANDOM INTEGER
function getRandowInt(max) {
  return Math.floor(Math.random() * max);
}

//CHANGES THE QUOTE ON THE WEBPAGE
var btn_next = document.getElementById("btn-next");
btn_next.addEventListener("click", function () {
  var index = getRandowInt(quotes.length);
  let quote = document.getElementById("quote-text");

  while (index != -1) {
    if (quote.textContent != quotes[index]) {
      quote.textContent = quotes[index];
      index = -1;
    } else {
      index = getRandowInt(quotes.length);
    }
  }
});

//OPENS A NEW BLANK WINDOW
var btn_new_window = document.getElementById("btn-new-window");
btn_new_window.addEventListener("click", function () {
  window.open();
});

//OPENS ALERT DIALOGUE
var btn_alert = document.getElementById("btn-alert");
btn_alert.addEventListener("click", function () {
  window.alert("This is an alert");
});

//EXECUTES PRINT COMMAND TO PRINT CONTENTS OF THE WEBPAGE
var btn_print = document.getElementById("btn-print");
btn_print.addEventListener("click", function () {
  window.print();
});
