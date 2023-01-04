<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <title> Delete Subjects </title>
</head>
  <style>
    table, td, tr, th {
      border-collapse: collapse; 
      border: 1px solid;
    }
    table {
      width: 65%;
      margin-left: auto;
      margin-right: auto;
      border: 1px solid black;
    }
    div {
      width: 95%;
      text-align: center;
      background-color: #ebedf0;
      margin-left: auto;
      margin-right: auto;
    }
    tr:nth-child(even) {
        background-color: #D6EEEE;
    }
    tr:nth-child(odd) {
      background-color: #fcfdff;
    }
    a {
      text-decoration: none;
    }
    form {
        border: 2px solid black;
        background-color:#fcfdff;
    }
    button:hover{
  		box-shadow: 0 12px 16px 0 rgba(0,0,0,0.24), 0 17px 50px 0 rgba(0,0,0,0.19);
	}
	button {
		border-radius: 12px;
		padding: 12px 28px;
		background-color: #cde7f1;
  		transition-duration: 0.4s;
        font-weight: bold;
	}	
    #aButton:hover{
  		box-shadow: 0 12px 16px 0 rgba(0,0,0,0.24), 0 17px 50px 0 rgba(0,0,0,0.19);
    }
    #aButton {
      border-radius: 12px;
      padding: 12px 28px;
      background-color: #cde7f1;
      transition-duration: 0.4s;
      font-weight: bold;
    }	
  </style>
<body>
<div>
  <?php
    // https://phpredis.github.io/phpredis/Redis.html#method_scan
    require 'connect.php';
    $me = "thegreatgazoo";
    echo "<h1>Delete Subjects</h1>";
    $values = $redis->hGetAll( $k );
    $totalSubjects = $redis->GET("$me:$studyid:last_usubjid");
    echo "<!-- closed: " . $redis->close() . ". --> \n";
  ?>
<?php
    echo "<button id = 'deleteButton' onclick = askDelete();>Delete ALL subjects</button>"
  ?>
    <script>
    function askDelete(){
      document.getElementById("deleteForm").style.display = "inline-block";
    }
    function hideDelete() {
      document.getElementById("deleteForm").style.display = "none";
    }
  </script>
  </br></br>
  <form action="" method="POST" style="display: none;" id = "deleteForm">
    <label>Are you sure you want to delete all subjects?</label> </br>
    <input id = "aButton" type="submit" name="deleteYes" value="Yes"/>
    <button id = "deleteNo" onclick = hideDelete()>No</button>
  </form>
  </br></br>
  <?php
    $deleteButton= $_POST['deleteYes'];
    if ($deleteButton){
        for ($subID = 1; $subID <= $totalSubjects; $subID++) {  //iterate through subjects
            $k = "$me:DM:$studyid:$subID";
            $values = $redis->hGetAll( $k );
            //delete all comments for current subject:
            $totalComments = $values['last_coseq'];
            $k = "$me:CO:$studyid:$subID";
            for ($i = 1; $i <= $totalComments; $i++) {
                if ($redis->exists("$k:$i")) {
                $redis->hdel("$k:$i", "codtc");
                $redis->hdel("$k:$i", "coval");
                }
            }
            $redis->del("$me:CO:$studyid:$subID");
            
            //delete all visits for current subject:
            $totalVisits = $values['last_visitnum'];
            $k = "$me:SV:$studyid:$subID";
            for ($i = 1; $i <= $totalVisits; $i++) {
                if ($redis->exists("$k:$i")) {
                $redis->hdel("$k:$i", "visit");
                $redis->hdel("$k:$i", "svstdtc");
                $redis->hdel("$k:$i", "svendtc");
                }
            }
            $redis->del("$me:SV:$studyid:$subID");
            //delete all DM info for current subject:
            $redis->hdel("$me:DM:$studyid:$subID", "brthdtc");
            $redis->hdel("$me:DM:$studyid:$subID", "sex");
            $redis->hdel("$me:DM:$studyid:$subID", "race");
            $redis->hdel("$me:DM:$studyid:$subID", "country");
            $redis->hdel("$me:DM:$studyid:$subID", "last_visitnum");
            $redis->hdel("$me:DM:$studyid:$subID", "last_coseq");
            $redis->del("$me:DM:$studyid:$subID");
        }
        echo "<script>alert('Succesfully deleted all subjects!')</script>";
    }
    echo "<a href ='http://grevera.ddns.net/~thegreatgazoo/studyA.php' > <button onclick>Go back to subjects</button> </a>";
  ?>
  </br>
  </br>
  <script>
    if ( window.history.replaceState ) {
        window.history.replaceState( null, null, window.location.href );
    }
  </script>
</div>
</body>
</html>
