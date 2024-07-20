console.log("hello");
const tableEl = document.querySelector(".table");
var num = 2;
var className = "row-1";
function mulTable() {
  const arr = new Array();
  for (let i = 1; i <= 10; i++) {
    arr.push(num * i);
  }
  var newRow = document.createElement("tr");
  for (let i = 0; i < 10; i++) {
    var newData = document.createElement("td");
    newData.appendChild(document.createTextNode(arr[i]));
    newRow.appendChild(newData);
  }
  newRow.classList.add(className);
  tableEl.appendChild(newRow);

  num = num + 1;
  let row = num - 1;
  className = "row-" + row;
}

const intervalId = window.setInterval(mulTable, 5000);
const lastRow = document.querySelector(".row-9");
if (lastRow != null) {
  clearInterval(intervalId);
}
