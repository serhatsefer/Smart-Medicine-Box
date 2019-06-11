<?php
   include('config.php');
   session_start();
   
   $user_check 	 = $_SESSION['login_user'];
   $user_surname = $_SESSION['login_surname'];
   
   $ses_sql = mysqli_query($db,"select * from admin where name = '$user_check' and surname = '$user_surname' ");
   
   $row = mysqli_fetch_array($ses_sql,MYSQLI_ASSOC);
   
   $login_session = $row['name'];
   $login_session_surname = $row['surname'];
   
   if(!isset($_SESSION['login_user'])){
      header("location:login.php");
      die();
   }
?>