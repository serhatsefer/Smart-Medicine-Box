<?php
   include('session.php');
   include('config.php');
?>
<html>
   
   <head>
      <title>Dashboard </title>
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
    <p>Dashboard</p>
  </div>
</div>
<br><br>
	  <div align = "center">
         <div style = "width:400px; border: solid 1px #333333;background-color:#DBDBDB " align = "left">
            <div style = "background-color:#11C9EE; color:#FFFFFF; padding:3px;"><b><h3>Welcome <?php echo $login_session; ?> <?php echo $login_session_surname; ?> </h3> </b></div>
			<h2><a href = "logout.php">Sign Out</a></h2>
			<h2><a href = "update.php">Update Value</a></h2>
			 <table border="0" cellspacing="2" cellpadding="2"> 
      <tr> 
		  <td> <font face="Arial"><b>ID</b></font> </td>
          <td> <font face="Arial"><b>Name</b></font> </td> 
          <td> <font face="Arial"><b>Surname</b></font> </td> 
          <td> <font face="Arial"><b>Medicine Name</b></font> </td> 
          <td> <font face="Arial"><b>Time</b></font> </td> 
          <td> <font face="Arial"><b>Pin</b></font> </td> 
		  <td> <font face="Arial"><b>Status</b></font> </td> 
      </tr>
	  <?php 
	  $sql = "SELECT * FROM medicine_box WHERE name = '$user_check' and surname = '$user_surname'";
      $result = mysqli_query($db,$sql);
      //$row = mysqli_fetch_array($result,MYSQLI_ASSOC);
	  while($row = $result->fetch_assoc()){
				 $field0name = $row["id"];
				 $field1name = $row["name"];
				 $field2name = $row["surname"];
				 $field3name = $row["medicine_name"];
				 $field4name = $row["time"];
				 $field5name = $row["pin"];
				 $field6name = $row["status"];
				 echo '<tr> 
				  <td>'.$field0name.'</td> 
                  <td>'.$field1name.'</td> 
                  <td>'.$field2name.'</td> 
                  <td>'.$field3name.'</td> 
                  <td>'.$field4name.'</td> 
                  <td>'.$field5name.'</td> 
				  <td>'.$field6name.'</td> 
              </tr>';
	  }
		?>
		</table>
			<h4><a href = "delete.php">Delete Account</a></h4>
            <div style = "margin:30px">
              
		
				
            
					
            </div>
				
         </div>
			
      </div>
	  <h3><b>2019 Serhat SEFER & Saim Buğrahan ÖZTÜRK</b></h3>
   </body>
</html>