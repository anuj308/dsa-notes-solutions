

function validateForm() {
    let name = document.getElementById("name")
    let email = document.getElementById("email")
    let password = document.getElementById("password")
    let male = document.getElementById("male")
    let female = document.getElementById("female")
    let country = document.getElementById("country")
    let terms = document.getElementById("terms")


    document.getElementById("nameError").innerText = ""
    document.getElementById("emailError").innerText = ""
    document.getElementById("passwordError").innerText = ""
    document.getElementById("genderError").innerText = ""
    document.getElementById("countryError").innerText = ""
    document.getElementById("termsError").innerText = ""



    let isValid = true;
    if (name.value.trim() == "") {
        document.getElementById("nameError").innerText = "Name is required"
        isValid = false
    }

    if (email.value.trim() == "") {
        document.getElementById("emailError").innerText = "Email is required"
        isValid = false
    }

    if (password.value.trim() == "") {
        document.getElementById("passwordError").innerText = "Password is required"
        isValid = false
    }

    if (!male.checked && !female.checked) {
        document.getElementById("genderError").innerText = "Gender is required"
        isValid = false
    }

    if (country.value == "") {
        document.getElementById("countryError").innerText = "Country is required"
        isValid = false
    }

    if (!terms.checked) {
        document.getElementById("termsError").innerText = "Terms is required"
        isValid = false
    }
    return isValid
}