<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <title> Subject Information </title>
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
    $subID = $_GET['subID'];
    echo "<h1>Subject $subID - Demographics</h1>";
    $tableInit = "<table><th>DOB</th><th>Sex</th><th>Race</th><th>Country</th><th>last_visitnum</th><th>last_coseq</th>";
    echo $tableInit;
    $k = "$me:DM:$studyid:$subID";
    if ($redis->exists("$k")) {
        $values = $redis->hGetAll( $k );
        echo "<tr>";

        echo "<td>";
        echo $values['brthdtc'];
        echo "</td>";
        echo "<td>";
        echo $values['sex'];
        echo "</td>";
        echo "<td>";
        echo $values['race'];
        echo "</td>";
        echo "<td>";
        echo $values['country'];
        echo "</td>";
        echo "<td>";
        echo $values['last_visitnum'];
        echo "</td>";
        echo "<td>";
        echo $values['last_coseq'];
        echo "</td>";

        echo "</tr>";
    }
    echo "</table>";
    echo "<!-- closed: " . $redis->close() . ". --> \n";
    echo "</br>";
    echo "<a href='http://grevera.ddns.net/~thegreatgazoo/commentD.php?subID=$subID'><button>Comments</button></a>";
    echo "<a href='http://grevera.ddns.net/~thegreatgazoo/visitE.php?subID=$subID'><button>Visits</button></a>";
  ?>
  </br>
  <script>
    function showUpdate() {
      document.getElementById("updateForm").style.display = "inline-block";
      document.getElementById("updateFormTitle").style.display = "inline-block";
      document.getElementById("updateButton").style.display = "none";
    }
    function askDelete(){
      document.getElementById("deleteForm").style.display = "inline-block";
    }
    function hideDelete() {
      document.getElementById("deleteForm").style.display = "none";
    }
  </script>
  </br>
  <button id = "updateButton" onclick = showUpdate()>Update Demographic Information</button>
  <p id = "updateFormTitle" style="display: none;"><strong>Enter new demographic information below:</strong></p></br>
 
  <?php 
  $countryString = $values['country'];
  $countryString = str_replace(' ', '', $countryString);
  ?>
  <form action="" method="POST" style="display: none;" id = "updateForm">
    </br>
        <label><strong>Date of Birth</strong></label>
        <input type="date"name="dob"/>
        <br><br>
        <label><strong>Time of Birth</strong></label>
        <input type="text"name="tob" placeholder="hh:mm:ss"/>
        <br><br>
        <label><strong>Sex: </strong></label>
        <input type="text"name="sex" placeholder= <?php echo $values['sex'];?> />
        <br><br>
        <label><strong>Race: </strong></label>
        <input type="text"name="race" placeholder= <?php echo $values['race'];?> />
        <br><br>
        <label><strong>Country: </strong></label>
        <input type="text"name="country" placeholder= <?php echo $countryString;?>>
        <br><br>
        <input id = "aButton" type="submit" name="submitButton" value="Update"/>
        </br></br>
    </form>
    </br>

    <?php
    $date= $_POST['dob'];
    $tob= $_POST['tob'];
    $dobString = $date . " " . $tob;
    $sex= $_POST['sex'];
    $race= $_POST['race'];
    $country= $_POST['country'];
    $submitButton= $_POST['submitButton'];
    echo "</br>";
    echo "<button><a href='http://grevera.ddns.net/~thegreatgazoo/subjectC.php?subID=$subID'>Refresh Data</a></button>";
    echo "</br></br>";
    if ($submitButton){
        if ( (!empty($date)) && (!empty($tob)) && (!empty($sex)) && (!empty($race)) && (!empty($country))){
            //insert a new subject into DM (via an assoc array)
            $dob = new DateTime( $dobString );
            $dm = array(
                'brthdtc'       => $dob->format( DateTime::ATOM ),  # ISO8601 format
                'sex'           => $sex,
                'race'          => $race,
                'country'       => $country
            );
            $key = "$me:DM:$studyid:$subID";
            $redis->hMset( $key, $dm );
            echo "<script>alert('Succesfully updated DM for subject: $subID!')</script>";
        }
        else {
            echo "<script>alert('Data fields were left empty. Please fill out all fields!')</script>";
        }
    }
    
  ?>
  <button id = "deleteButton" onclick = askDelete()>Delete this subject</button>
  </br></br>
  <form action="" method="POST" style="display: none;" id = "deleteForm">
    <label>Are you sure you want to delete this subject?</label> </br>
    <input id = "aButton" type="submit" name="deleteYes" value="Yes"/>
    <button id = "deleteNo" onclick = hideDelete()>No</button>
  </form>
  </br>
  <?php
    $deleteButton= $_POST['deleteYes'];
    if ($deleteButton){
      $totalComments = $values['last_coseq'];
      $k = "$me:CO:$studyid:$subID";
      for ($i = 1; $i <= $totalComments; $i++) {
        if ($redis->exists("$k:$i")) {
          $redis->hdel("$k:$i", "codtc");
          $redis->hdel("$k:$i", "coval");
        }
      }
      $redis->del("$me:SV:$studyid:$subID");

      $totalVisits = $values['last_visitnum'];
      $k = "$me:SV:$studyid:$subID";
      for ($i = 1; $i <= $totalVisits; $i++) {
        if ($redis->exists("$k:$i")) {
          $redis->hdel("$k:$i", "visit");
          $redis->hdel("$k:$i", "svstdtc");
          $redis->hdel("$k:$i", "svendtc");
        }
      }
      $redis->del("$me:CO:$studyid:$subID");

      $redis->hdel("$me:DM:$studyid:$subID", "brthdtc");
      $redis->hdel("$me:DM:$studyid:$subID", "sex");
      $redis->hdel("$me:DM:$studyid:$subID", "race");
      $redis->hdel("$me:DM:$studyid:$subID", "country");
      $redis->hdel("$me:DM:$studyid:$subID", "last_visitnum");
      $redis->hdel("$me:DM:$studyid:$subID", "last_coseq");
      $redis->del("$me:DM:$studyid:$subID");
      echo "<script> document.getElementById('deleteButton').style.display='none';</script>";
      echo "<strong>Subject Deleted!</strong></br></br>";
    }
  ?>
  </br>
  <a href='http://grevera.ddns.net/~thegreatgazoo/studyA.php'><button>Go back to all subjects</button>
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
