<?php

include("config.php");

$name 			= $_GET['n']; 
$surname 		= $_GET['s']; 
$sql = "SELECT * FROM medicine_box WHERE `name` = \"$name\" AND `surname` = \"$surname\"";
$result = $db->query($sql);

if ($result->num_rows > 0) {
    // output data of each row
	echo "####";
    while($row = $result->fetch_assoc()) {
		if(($row["medicine_name"] != '-') && ($row["status"] == '1')){
                echo ">>" . $row["id"]. "|" . $row["name"]." ".$row["surname"]. "|" . $row["medicine_name"].
	"|" . $row["time"]."|" . $row["status"]."|" . $row["pin"]."";
		}
    }
	echo ">>";
} else {
    echo "0 results";
}
$db->close();
?>