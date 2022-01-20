function func() {
    var result = 0;
    var ra1 = 2;
    var ra2 = 3;
    var ra3 = 4;
    var ra4 = 5;
    var ra5 = 6;
    var num1 = Number(document.getElementById("num1").value);
    var num2 = Number(document.getElementById("num2").value);
    var num3 = Number(document.getElementById("num3").value);
    var num4 = Number(document.getElementById("num4").value);
    var num5 = Number(document.getElementById("num5").value);

    if(num1 == ra1) {
        result += 20;
        document.getElementById("num1").classList.remove('red');
    }
    else
        document.getElementById("num1").classList.add('red');

    if(num2 == ra2) {
        result += 20;
        document.getElementById("num2").classList.remove('red');
    }
    else
        document.getElementById("num2").classList.add('red');

    if(num3 == ra3) {
        result += 20;
        document.getElementById("num3").classList.remove('red');
    }
    else
        document.getElementById("num3").classList.add('red');

    if(num4 == ra4) {
        result += 20;
        document.getElementById("num4").classList.remove('red');
    }
    else
        document.getElementById("num4").classList.add('red');

    if(num5 == ra5) {
        result += 20;
        document.getElementById("num5").classList.remove('red');
    }
    else{
        document.getElementById("num5").classList.add('red');
    }

    document.getElementById("result").innerHTML = "Верно решено " + result + " % заданий";
}