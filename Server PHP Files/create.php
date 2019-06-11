<?php
   include("config.php");
   session_start();
   
   if($_SERVER["REQUEST_METHOD"] == "POST") {
      // username and password sent from form 
      
      $myusername = mysqli_real_escape_string($db,$_POST['name']);
	  $mysurname = mysqli_real_escape_string($db,$_POST['surname']);
      $mypassword = mysqli_real_escape_string($db,$_POST['password']); 
      if (empty($_POST["name"]) || empty($_POST["surname"]) || empty($_POST["password"])){
		  $error = "<b>Please Fill In The All Blanks!</b><br>";
	  }
	  else
	  {
	   $sql = "SELECT * FROM admin WHERE name = '$myusername' and surname = '$mysurname'";
	   $result = $db->query($sql);
	   if (!($result->num_rows > 0))
	   {
		   $sql = "INSERT INTO admin (name,surname,passcode) VALUES ('$myusername','$mysurname','$mypassword')";
		   $result = $db->query($sql);
		   if($result === TRUE)
		   {
			   for($x = 0 ; $x < 4 ; $x ++){
			   $sql = "INSERT INTO medicine_box (name,surname,medicine_name,time,pin,status) VALUES ('$myusername','$mysurname','-','0','0','0')";
			   $result = $db->query($sql);
			   if($result === TRUE)
			   {
				   $success = "USER HAS BEEN REGISTERED SUCCESSFULLY!";
				   echo "<meta http-equiv=\"refresh\" content=\"1;URL=http://serhatesp.dx.am/login.php\">";
			   }
			   else
				   $error = "Error While Creating Account!";
			   }
		   }
		   else{
			   $error = "Error While Creating Account!";
		   }
	   }
	   else
	   {
		   $error = "The User Has Already Registered!";
		   
	   }
	  }
      // If result matched $myusername and $mypassword, table row must be 1 row

   }
?>
<html>
   
   <head>
      <title>Create New Account</title>
      
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
    <p>Create An Account</p>
  </div>
</div>
<br><br>
		<div align = "center">
         <div style = "width:300px; border: solid 1px #333333;background-color:#DBDBDB " align = "left">
            <div style = "background-color:#11C9EE; color:#FFFFFF; padding:3px;"><b>Create An Account</b></div>
			<h2><a href = "login.php">Login</a></h2>
            <div style = "margin:30px">
               <form action = "" method = "post">
                  <label>Name:</label><br><input type = "text" name = "name" maxlength="20" class = "box"/><br /><br />
				  <label>Surname:</label><br><input type = "text" name = "surname" maxlength="20" class = "box"/><br /><br />
                  <label>Password:</label><br><input type = "password" name = "password" minlength=6 maxlength="20" class = "box" /><br/><br />
                  <input type = "submit" value = "Create"/><br />
               </form>
               
               <div style = "font-size:15px; color:#cc0000; margin-top:10px"><?php echo $error; ?></div>
			   <div style = "font-size:15px; color:#006400; margin-top:10px"><?php echo $success; ?></div>
					
            </div>
				
         </div>
			
      </div>
	  <h3><b>2019 Serhat SEFER & Saim Buğrahan ÖZTÜRK</b></h3>
   </body>
</html>