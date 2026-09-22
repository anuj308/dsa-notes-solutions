const form = document.getElementById("myForm")
const nameInput = document.getElementById("name")
const emailInput = document.getElementById("email")
const passwordInput = document.getElementById("password")


function showError(input, errorID, message) {
    input.classList.add("invalid")
    input.classList.remove("success")
    document.getElementById(errorID).innerText = message
}


function showSuccess(input, errorID) {
    input.classList.add("success")
    input.classList.remove("invalid")
    document.getElementById(errorID).innerText = ""
}


function validateName() {

    const name = nameInput.value.trim();
    const regexName = /^[A-Za-z ._@0-9]{3,30}$/;
    if (name == "") {
        showError(nameInput, "nameError", "Name is required")
        return false
    }

    if (!regexName.test(name)) {
        showError(nameInput, "nameError", "Minimum 3 characters required and max 30 1 special 1 numeric with space")
        return false
    }
    // if (name.length < 3) {
    //     showError(nameInput, "nameError", "Minimum 3 characters required")
    //     return false
    // }


    showSuccess(nameInput, "nameError")
    return true
}



function validateEmail() {

    const email = emailInput.value.trim();
    const regexEmail = /[A-Za-z#_.0-9]{3,30}@[A-Za-z.]{1,15}.[A-Za-z]/gm;
    if (email == "") {
        showError(emailInput, "emailError", "Email is required")
        return false
    }

    if (!regexEmail.test(email)) {
        showError(emailInput, "emailError", "Email format is incorrect")
        return false
    }

    showSuccess(emailInput, "emailError")
    return true
}


function validatePassword() {

    const password = passwordInput.value.trim();
    const regexPass = /[A-Za-z_.0-9#@]{8,30}/;

    if (!regexPass.test(password)) {
        showError(passwordInput, "passwordError", "Password format is incorrect")
        return false
    }

    showSuccess(passwordInput, "passwordError")
    return true
}


nameInput.addEventListener('input', validateName)
emailInput.addEventListener('input', validateEmail)
passwordInput.addEventListener('input', validatePassword)

form.addEventListener("submit", function (e) {
    e.preventDefault()
    const isNameValid = validateName();
    const isEmailValid = validateEmail();
    const isPassValid = validatePassword();

    if (isNameValid && isEmailValid && isPassValid) {
        alert("form submitted")
        form.reset()
        nameInput.classList.remove("success")
        emailInput.classList.remove("success")
        passwordInput.classList.remove("success")
    }
})

///^ (?=.* [a - z])(?=.* [A - Z])(?=.*\d)(?=.* [@$! %*?&])[A - Za - z\d@$!%*?&]{ 8,} $ /; 