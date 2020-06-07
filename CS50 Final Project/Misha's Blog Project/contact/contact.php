<?php

if($_POST) {
    $name = "";
    $email = "";
    $location= "";
    $subject = "";

    if(isset($_POST['name'])) {
        $name = filter_var($_POST['name'], FILTER_SANITIZE_STRING);
    }

    if(isset($_POST['email'])) {
        $email = str_replace(array("\r", "\n", "%0a", "%0d"), '', $_POST['email']);
        $email = filter_var($email, FILTER_VALIDATE_EMAIL);
    }


    if(isset($_POST['location'])) {
        $location = filter_var($_POST['location'], FILTER_SANITIZE_STRING);
    }

    if(isset($_POST['subject'])) {
        $subject = htmlspecialchars($_POST['subject']);
    }

    if($location == "USA") {
        $recipient = "michaelhodge20@gmail.com";
    }
    else if($location == "Europe") {
        $recipient = "michaelhodge20@gmail.com";
    }
    else if($location == "Asia") {
        $recipient = "michaelhodge20@gmail.com";
    }
    if($location == "Africa") {
        $recipient = "michaelhodge20@gmail.com";
    }
    else if($location == "South America") {
        $recipient = "michaelhodge20@gmail.com";
    }
    else if($location == "Austrailia") {
        $recipient = "michaelhodge20@gmail.com";
    }
    else if($location == "Other") {
        $recipient = "michaelhodge20@gmail.com";
    }
    else {
        $recipient = "michaelhodge20@gmail.com";
    }

    $headers  = 'MIME-Version: 1.0' . "\r\n"
    .'Content-type: text/html; charset=utf-8' . "\r\n"
    .'From: ' . $email . "\r\n";

    if(mail($recipient, $subject, $headers)) {
        echo "<p>Thank you for contacting me, $name. You will get a reply within 24 hours.</p>";
    } else {
        echo '<p>Im are sorry but the email did not go through.</p>';
    }

} else {
    echo '<p>Something went wrong!</p>';
}

?>
