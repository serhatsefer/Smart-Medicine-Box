<?php
   include("config.php");
   session_start();
   
   if($_SERVER["REQUEST_METHOD"] == "POST") {
      // username and password sent from form 
      
      $myusername = mysqli_real_escape_string($db,$_POST['name']);
	  $mysurname = mysqli_real_escape_string($db,$_POST['surname']);
      $mypassword = mysqli_real_escape_string($db,$_POST['password']); 
      
      $sql = "SELECT id FROM admin WHERE name = '$myusername' and surname = '$mysurname' and passcode = '$mypassword'";
      $result = mysqli_query($db,$sql);
      $row = mysqli_fetch_array($result,MYSQLI_ASSOC);
      $active = $row['active'];
      
      $count = mysqli_num_rows($result);
      
      // If result matched $myusername and $mypassword, table row must be 1 row
		
      if($count == 1) {
         //session_register("myusername");
         $_SESSION['login_user'] 	= $myusername;
		 $_SESSION['login_surname'] = $mysurname;
         
         header("location: welcome.php");
      }else {
         $error = "Your Login Name or Password is invalid";
      }
   }
?>
<html>
   
   <head>
      <title>Login Page</title>
      
      <style type = "text/css">
         body {
            font-family:Arial, Helvetica, sans-serif;
            font-size:14px;
         }
         label {
            font-weight:bold;
            width:100px;
            font-size:14px;
         }
		 html {
		  text-align: center;
		 }
         .box {
            border:#666666 solid 1px;
			margin: auto;
         }
		 

	/* The hero image */
	.hero-image {
	  /* Use "linear-gradient" to add a darken background effect to the image (banner.jpg). This will make the text easier to read */
	  background-image: linear-gradient(rgba(0, 0, 0, 0.5), rgba(0, 0, 0, 0.5)), url("banner.jpg");

	  /* Set a specific height */
	  height: 40%;

	  /* Position and center the image to scale nicely on all screens */
	  background-position: center;
	  background-repeat: no-repeat;
	  background-size: cover;
	  position: relative;
	}

	/* Place text in the middle of the image */
	.hero-text {
	  text-align: center;
	  position: absolute;
	  top: 50%;
	  left: 50%;
	  transform: translate(-50%, -50%);
	  color: white;
	}

      </style>
      
   </head>
   
   <body bgcolor = "#626262">
	
		<div class="hero-image">
  <div class="hero-text">
	<h1><b>The Smart Medicine Box</b></h1>
    <p>Login Page</p>
  </div>
</div>
<br><br>
		<div align = "center">
         <div style = "width:300px; border: solid 1px #333333;background-color:#DBDBDB " align = "left">
            <div style = "background-color:#11C9EE; color:#FFFFFF; padding:3px;"><b>Login</b></div>
				
            <div style = "margin:30px">
               
               <form action = "" method = "post">
                  <label>Name:</label><br><input type = "text" name = "name" class = "box"/><br /><br />
				  <label>Surname:</label><br><input type = "text" name = "surname" class = "box"/><br /><br />
                  <label>Password:</label><br><input type = "password" name = "password" class = "box" /><br/><br />
                  <input type = "submit" value = "Login"/><br />
				  <h4>OR</h4>
				  <h4><a href = "create.php">Create An Account!</a></h4>
               </form>
               
               <div style = "font-size:11px; color:#cc0000; margin-top:10px"><?php echo $error; ?></div>
					
            </div>
				
         </div>
			
      </div>
	  <h3><b>2019 Serhat SEFER & Saim Buğrahan ÖZTÜRK</b></h3>
   </body>
</html>