jQuery(document).ready(function(){

    document.getElementById("showURL").onclick = function (ev) {
        var newWin = window.open("https://oauth.vk.com/authorize?client_id=7101802&display=page&redirect_uri=http://localhost:8080/JavaEEtest_war_exploded/project/OAuthJSP.jsp&scope=friends,email,pages&response_type=token&v=5.52", "JSSite",
        "width=420,height=230,resizable=yes,scrollbars=yes,status=yes");
    };

    document.getElementById("getMyMail").onclick = function (ev) {
         $.ajax({
             url : "http://localhost:8080/JavaEEtest_war_exploded/getUserMail",
             method : "POST",
             data : {
                 
             },
             success : function (response) {
                 alert("Yur mail = " + response.toString() );
             },
             error : function (response) {
                 alert("Some error =( " + response.toString());
             }
         });
    };


});
