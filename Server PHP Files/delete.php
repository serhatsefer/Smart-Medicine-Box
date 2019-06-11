<?php
   include("config.php");
   include('session.php');
   session_start();
   
   if($_SERVER["REQUEST_METHOD"] == "POST") {
      // username and password sent from form 
	  
	   $sql = "DELETE FROM medicine_box WHERE name = '$user_check' and surname = '$user_surname'";
	   $result = $db->query($sql);
	   if ($result != TRUE){
	   $error = "USER HAS NOT BEEN DELETED!";
	   }
	   else
	   {
	   $sql = "DELETE FROM admin WHERE name = '$user_check' and surname = '$user_surname'";
	   $result = $db->query($sql);
	   if ($result != TRUE){
		   $error = "USER HAS NOT BEEN DELETED!";
	   }
	   else
	   $success = "USER HAS BEEN DELETED SUCCESSFULLY!";
		echo "<meta http-equiv=\"refresh\" content=\"1;URL=http://serhatesp.dx.am/logout.php\">";
	   }

	  
//}

$db->close();
   }

  
?>
<html>
   
   <head>
      <title>DELETE ACCOUNT</title>
      
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
	<body bgcolor = "#626262">
   <div class="hero-image">
  <div class="hero-text">
	<h1><b>The Smart Medicine Box</b></h1>
    <p>DELETE ACCOUNT For User <?php echo "$user_check $user_surname"; ?> </p>
  </div>
</div>
<br><br>
	
		<div align = "center">
         <div style = "width:300px; border: solid 1px #333333;background-color:#DBDBDB " align = "left">
            <div style = "background-color:#11C9EE; color:#FFFFFF; padding:3px;"><b>DELETE ACCOUNT For User <?php echo "$user_check $user_surname"; ?></b></div>
				
				<b>Are You Sure Delete To Account <?php echo "$user_check $user_surname"?> ?</b> <br>
				<div style = "font-size:15px; color:#cc0000; margin-top:10px"><?php echo $error; ?></div>
				<div style = "font-size:15px; color:#006400; margin-top:10px"><?php echo $success; ?></div>
            <div style = "margin:30px">
               <form action = "" method = "post">
      
                  <input type = "submit" value = "Yes"/><br />
					<br> OR
				  <h2><a href = "welcome.php">No,Return To Dashboard</a></h2>
               </form>
               
            </div>
				
         </div>

      </div>
	  <h3><b>2019 Serhat SEFER & Saim Buğrahan ÖZTÜRK</b></h3>
   </body>
</html>
