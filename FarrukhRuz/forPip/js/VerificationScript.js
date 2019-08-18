var app;

jQuery(document).ready(function(){
    app = new Vue({
        el : '#app',
        data : {
            loginMessage : '',
            passwordMessage : '',
            mailMessage : ''
        }
    });

    document.getElementById("ulogin").addEventListener("keyup", function (ev) {
        var userLogin = document.getElementById("ulogin").value;
        var loginChekingResult = "?";
        $.ajax({
            url : "../isUserWith/login",
            method : "GET",
            data : {
                ulogin : userLogin
            },
            success: function (response) {
                if(response.toString() == "1"){
                    app.loginMessage = "занято";
                    loginChekingResult = "true";
                }
                else {
                    loginChekingResult = "false";
                    app.loginMessage = "";
                }
            },
            error : function (response) {
                alert("Ошибка с сетью!");
            }
        });
    } ,false);

    document.getElementById("uemail").addEventListener("keyup", function (ev) {
        var userEmail = document.getElementById("uemail").value;
        var emailChekingResult = "?";
        $.ajax({
            url : "../isUserWith/email",
            method : "GET",
            data : {
                uemail : userEmail
            },
            success: function (response) {
                if(response.toString() == "1"){
                    app.mailMessage = "мэйл уже зарегистрирован";
                    emailChekingResult = "true";
                }
                else {
                    app.mailMessage = "";
                    emailChekingResult = "false";
                }
            },
            error : function (response) {
                alert("Ошибка с сетью!");
            }
        });
    } ,false);

});

function passwordHashing(password) {
   return password + "bubu";
}