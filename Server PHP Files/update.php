<?php
   include("config.php");
   include('session.php');
   session_start();

   $check = 0;
   
   if($_SERVER["REQUEST_METHOD"] == "POST") {
      // username and password sent from form 
      if (empty($_POST["name"]) || empty($_POST["time"])){
		  $error = "<b>Please Fill In The All Blanks!</b><br>";
	  }
	  
	  else{
	  $check = 1;
      $name = mysqli_real_escape_string($db,$_POST['name']);
	  $time = mysqli_real_escape_string($db,$_POST['time']);
	  $pin = mysqli_real_escape_string($db,$_POST['pin']);
	  $status = mysqli_real_escape_string($db,$_POST['status']);
	  $id = mysqli_real_escape_string($db,$_POST['id']);
	  
	   $sql = "SELECT * FROM medicine_box WHERE id = '$id' and name = '$user_check' and surname = '$user_surname'";
	   $result = $db->query($sql);
	   if (!($result->num_rows > 0))
		  $error = "<b>The ID Does Not Belong To This Account!</b><br>";
	else{
      $sql = "UPDATE medicine_box SET time='$time',medicine_name='$name',pin = '$pin',status = '$status' WHERE id='$id' AND name='$user_check' AND surname='$user_surname'";
      //$sql = "SELECT id FROM admin WHERE name = '$myusername' and surname = '$mysurname' and passcode = '$mypassword'";
      $result = mysqli_query($db,$sql);
      //$row = mysqli_fetch_array($result,MYSQLI_ASSOC);
	  
	  if ( $result === TRUE){
		  $success = "<b>Data Has Been Updated Successfully!</b><br>";
		echo "<meta http-equiv=\"refresh\" content=\"1;URL=http://serhatesp.dx.am/welcome.php\">";
	  }
	  else
		  $error = "<b>Data Has NOT Been Updated!</b><br>";
	}

	  
//}

$db->close();
   }

   }
?>
<html>
   
   <head>
      <title>Update Value</title>
      
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
    <p>Update Value For User <?php echo "$user_check $user_surname"; ?> </p>
  </div>
</div>
<br><br>
		<div align = "center">
         <div style = "width:300px; border: solid 1px #333333;background-color:#DBDBDB " align = "left">
            <div style = "background-color:#11C9EE; color:#FFFFFF; padding:3px;"><b>Update Value For User <?php echo "$user_check $user_surname"; ?></b></div>
				<h2><a href = "welcome.php">Dashboard</a></h2>
				<b>Please Enter The ID Number Which Is You Want To Change Then Fill The Other Values!</b> <br>
				<div style = "font-size:15px; color:#cc0000; margin-top:10px"><?php echo $error; ?></div>
				<div style = "font-size:15px; color:#006400; margin-top:10px"><?php echo $success; ?></div>
            <div style = "margin:30px">
               <form action = "" method = "post">
                  <label>ID:</label><br>
				  <select name="id">
				  <?php 
if ($check == 0){
$sql = mysqli_query($db, "SELECT id FROM medicine_box WHERE name = '$user_check' and surname = '$user_surname'");
while ($row = $sql->fetch_assoc()){
echo '<option value="'.$row['id'].'"> ' . $row['id'] . '</option>';}
}
?><br /><br />
				  </select><br/><br />
				  <label>Medicine Name:</label><br><input type = "text" name = "name" maxlength="20" class = "box"/><br /><br />
                  <label>Time(HHMMSS):</label><br><input type = "number" name = "time" max = "235959" minlength="6" maxlength="6" class = "box" /><br/><br />
				  <label>Pin:</label><br>
				  <select name="pin">
				  <option value="1">1</option><option value="2">2</option><option value="3">3</option><option value="4">4</option>
				  </select><br/><br /> 
				  <label>Status:</label><br>
				  <select name="status">
				  <option value="1">1</option><option value="0">0</option>
				  </select><br/><br />
				  <!--<label>Pin:</label><br><input type = "number" name = "pin" class = "box" /><br/><br /> -->
				  <!--<label>Status:</label><br><input type = "number" name = "status" class = "box" /><br/><br /> -->
                  <input type = "submit" value = "Update"/><br />
               </form>
               
            </div>
				
         </div>

      </div>
	  <h3><b>2019 Serhat SEFER & Saim Buğrahan ÖZTÜRK</b></h3>
   </body>
</html>
