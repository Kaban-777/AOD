function onClick() {
    var p = document.getElementById("p");
    p.addEventListener("click", function () {
        p.style = "color: " + '#' + (Math.random().toString(16) + '000000').substring(2,8).toUpperCase();
    });
}