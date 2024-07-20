$(document).ready(function () {
  $(".design-button").click(function () {
    $("body").css({
      "background-color": "#f8f0fc",
      "font-family": "sans-serif",
      color: "#000",
      "font-size": "16px",
    });

    $(".container").css({
      width: "70%",
      margin: "0 auto",
      "margin-top": "64px",
      "line-height": "1.5",
    });

    $(".header").css({
      "background-color": "#862e9c",
      "margin-bottom": "96px",
    });

    $(".header h1").css({
      "text-align": "center",
      padding: "24px",
      "font-size": "42px",
      color: "#fff",
    });

    $(".grid-3-cols").css({
      display: "grid",
      "grid-template-columns": "repeat(3, 1fr)",
      "column-gap": "40px",
      "row-gap": "48px",
    });

    $(".fee").css({ "margin-bottom": "96px" });

    $(".eligibility").css({ "margin-bottom": "96px" });

    $(".future").css({ "margin-bottom": "96px" });

    $(".course-structure").css({ "margin-bottom": "96px" });

    $(".papers").css({ "margin-bottom": "96px" });

    $("a:link").css({
      "text-decoration": "none",
      color: "#fff",
      "background-color": "#9c36b5",
      padding: "10px",
      display: "inline-block",
      "border-radius": "10px",
      "margin-top": "12px",
      transition: "all 0.4s",
      "font-size": "16px",
    });

    $("a:visited").css({
      "text-decoration": "none",
      color: "#fff",
      "background-color": "#9c36b5",
      padding: "10px",
      display: "inline-block",
      "border-radius": "10px",
      "margin-top": "12px",
      transition: "all 0.4s",
      "font-size": "16px",
    });

    $(".btn").css({
      "text-decoration": "none",
      color: "#fff",
      "background-color": "#9c36b5",
      padding: "10px",
      display: "inline-block",
      "border-radius": "10px",
      "margin-top": "12px",
      transition: "all 0.4s",
      "font-size": "16px",
      cursor: "pointer",
      "text-transform": "uppercase",
      "letter-spacing": "0.5px",
      border: "0",
      "font-weight": "600",
    });

    $("a:hover").css({ "background-color": "#862e9c" });

    $("a:active").css({ "background-color": "#862e9c" });

    $(".btn:hover").css({ "background-color": "#862e9c" });

    $("h2").css({
      "font-size": "36px",
      "margin-bottom": "28px",
    });

    $(".eligibility p").css({
      "margin-bottom": "18px",
    });

    $(".eligibility li").css({
      "list-style": "none",
      "margin-bottom": "16px",
    });

    $(".eligibility li:last-child ").css({ "margin-bottom": "0" });

    $(".papers li").css({
      "margin-bottom": "12px",
      "padding-left": "12px",
      "margin-left": "24px",
    });

    $(".design-button ").css({ "margin-bottom": "96px" });

    $(".future-head").css({
      "font-size": "18px",
      "margin-bottom": "8px",
    });

    $(".future-icons").css({
      stroke: "#9c36b5",
      width: "24px",
      height: "24px",
      "margin-bottom": "12px",
    });

    $("table").css({
      "border-collapse": "collapse",
    });

    $("table td").css({
      padding: "16px 32px",
    });

    $("table table th").css({
      width: "40%",
    });

    $("thead tr:nth-child(2)").css({
      "text-align": "center",
    });

    $("tbody tr td:not(:first-child)").css({
      "text-align": "center",
    });

    $("tbody tr:nth-child(even)").css({
      "background-color": "#f3d9fa",
    });

    $("tbody tr:nth-child(odd)").css({
      "background-color": "#eeeeeefb",
    });

    $("thead tr").css({
      "background-color": "#9c36b5",
      color: "#fff",
    });

    $("table th").css({
      padding: "16px 32px",
    });

    $("footer").css({
      "text-align": "center",
      "border-bottom": "8px solid #9c36b5",
    });
  });
});
