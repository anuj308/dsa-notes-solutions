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
    if (name == "") {
        showError(nameInput, "nameError", "Name is required")
        return false
    }

    if (name.length < 3) {
        showError(nameInput, "nameError", "Minimum 3 characters required")
        return false
    }
    showSuccess(nameInput, "nameError")
    return true
}



function validateEmail() {

    const email = emailInput.value.trim();
    if (email == "") {
        showError(emailInput, "emailError", "Email is required")
        return false
    }

    showSuccess(emailInput, "emailError")
    return true
}

nameInput.addEventListener('input', validateName)
emailInput.addEventListener('input', validateEmail)


form.addEventListener("submit", function (e) {
    e.preventDefault()
    const isNameValid = validateName();
    const isEmailValid = validateEmail();

    if (isNameValid && isEmailValid) {
        alert("form submitted")
        form.reset()
        nameInput.classList.remove("success")
        emailInput.classList.remove("success")
    }
})