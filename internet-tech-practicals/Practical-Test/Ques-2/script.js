$(document).ready(function () {
  const projectName = "Menu";
  console.log(projectName);

  const btnEl = $(".btn");
  btnEl.click(function () {
    const btnText = btnEl.text();

    const breakfastOL = $(".breakfast-ol");
    const breakfastLi = $(".breakfast-change");
    const lunchLi = $(".lunch-change");
    const dinnerOL = $(".dinner-ol");
    const dinnerLi = $(".dinner-change");

    if (btnText == "Switch to Non-veg") {
      breakfastOL.append("<li>Eggs</li>");
      breakfastLi.text("French Toast");

      lunchLi.text("Butter Chicken");

      dinnerOL.append("<li>Eggs</li>");
      dinnerLi.text("Pomfret");

      btnEl.text("Switch to Veg");
    } else if (btnText == "Switch to Veg") {
      breakfastLi.text(
        "Savory Porridge: Butternut Squash & Ginger + Miso Avocado"
      );
      lunchLi.text("Apple, Quinoa and Almond Kale Salad");
      dinnerLi.text("Potato and leek soup");

      //remove eggs elements from breakfast and dinner
      const liEls = $("li");
      liEls.each(function () {
        if ($(this).text() === "Eggs") $(this).remove();
      });

      // const liEl = $("li");
      // if (liEl.text() === "Eggs") liEl.remove();

      btnEl.text("Switch to Non-veg");
    }
  });
});
