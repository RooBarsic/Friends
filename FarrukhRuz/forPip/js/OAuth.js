jQuery(document).ready(function () {

//    alert(window.location.href);
    var url = window.location.hash;
    var token = "";
    var flag = 0;
    for(var i = 0; i < url.length; i++){
        if(url[i] == '#') flag++;
        else if(url[i] == "=") flag++;
        else if((flag == 2) && (url[i] == "&")) flag++;
        else if(flag == 2){
            token += url[i];
        }
    }
   // http://localhost:8080/JavaEEtest_war_exploded/project/OAuthJSP.jsp#access_token=512d30ed1ba377fbf68ef951239a8c710dd01dd188b0606cdbca78f74292219526bcaf70a58b9f7d1663e&expires_in=86400&user_id=415938349&email=Karimov.farrux@list.ru

        $.ajax({
        url: "http://localhost:8080/JavaEEtest_war_exploded/VKServlet",
        method: "POST",
        data: {
            token : token,
            email : getElement("email", url),
            login : getElement("user_id", url)
        },
            success : function (response) {
                alert(url);
                window.close();
            }
    });
});

function getElement( el, text) {
    var start_id = -1;
    for(var i = 0; i < text.length; i++){
        var text_id = i;
        var el_id = 0;
        while((text_id < text.length) && (el_id < el.length) && (text[text_id] == el[el_id])){
            text_id++;
            el_id++;
        }
        if(el_id == el.length){
            start_id = i;
            break;
        }
    }
    if(start_id != -1){
        var val = "";
        var startflag = false;
        for(var i = start_id; i < text.length; i++){
            if(startflag){
                if(text[i] == '&') break;
                else val += text[i];
            }
            else if(text[i] == '=') startflag = true;
        }
        return val;
    }
    return "";
}