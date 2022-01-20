let captcha = new Array();

document.ondragstart = noselect;
// запрет на перетаскивание
document.onselectstart = noselect;
// запрет на выделение элементов страницы
document.oncontextmenu = noselect;
// запрет на выведение контекстного меню
function noselect() {return false;}

function createCaptcha() {
    const activeCaptcha = document.getElementById("captcha");
    for (q = 0; q < 6; q++) {
        if (q % 2 == 0) {
            captcha[q] = String.fromCharCode(Math.floor(Math.random() * 26 + 65));
        } else {
            captcha[q] = Math.floor(Math.random() * 10 + 0);
        }
    }
    theCaptcha = captcha.join("");
    activeCaptcha.innerHTML = `${theCaptcha}`;
}

function validateCaptcha() {
    const errCaptcha = document.getElementById("errCaptcha");
    const reCaptcha = document.getElementById("reCaptcha");
    recaptcha = reCaptcha.value;
    let validateCaptcha = 0;
    for (var z = 0; z < 6; z++) {
        if (recaptcha.charAt(z) != captcha[z]) {
            validateCaptcha++;
        }
    }
    if (recaptcha == "") {
        errCaptcha.innerHTML = "Re-Captcha must be filled";
    } else if (validateCaptcha > 0 || recaptcha.length > 6) {
        errCaptcha.innerHTML = "Wrong captcha";
    } else {
        errCaptcha.innerHTML = "Done";
    }
}