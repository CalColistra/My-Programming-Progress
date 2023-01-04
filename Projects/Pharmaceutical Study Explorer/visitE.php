<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <title>Visits</title>
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
        display: inline-block;
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
    $subID = $_GET['subID'];
    // https://phpredis.github.io/phpredis/Redis.html#method_scan
    require 'connect.php';
    require 'cmd2web.php';
    parseNameEqualValue();
    $me = "thegreatgazoo";
    echo "<h1>Visits for Subject: $subID</h1>";

    $tableInit = "<table> <th>Visit Number</th><th>Visit</th><th>Start Date</th><th>End Date</th>";
    echo $tableInit;
    $values = $redis->hGetAll("$me:DM:$studyid:$subID");
    $total = $values['last_visitnum'];
    $k = "$me:SV:$studyid:$subID";
    for ($i = 1; $i <= $total; $i++) {
        if ($redis->exists("$k:$i")) {
            $values2 = $redis->hGetAll("$k:$i");
            echo "<tr>";
            echo "<td>";
            echo $i;
            echo "</td>";
            echo "<td>";
            echo $values2['visit'];
            echo "</td>";
            echo "<td>";
            echo $values2['svstdtc'];
            echo "</td>";
            echo "<td>";
            echo $values2['svendtc'];
            echo "</td>";
            echo "</tr>";
        }
    }
    echo "</table>";

    echo "</br></br>";
    echo "<strong>Add a new Vist for subject #$subID below:</strong></br></br>";
?>  
    
    <form action="" method="POST">
        </br>
        <label><strong>Start date of visit:</strong></label>
        <input type="date" name="startDate"/>
        <br><br>
        <label><strong>Start time of visit:</strong></label>
        <input type="text" name="startTime" placeholder="hh:mm:ss"/>
        <br><br>
        <label><strong>End date of visit:</strong></label>
        <input type="date"name="endDate"/>
        <br><br>
        <label><strong>End time of visit:</strong></label>
        <input type="text"name="endTime" placeholder="hh:mm:ss"/>
        <br><br>
        <label><strong>What was the visit for:</strong></label>
        <input type="text"name="newVisit" value=''/>
        <br><br>
        <input id = "aButton" type="submit" name="submitButton" value="Submit"/>
        </br></br>
    </form>
    </br>
<?php
    echo "</br><a href='http://grevera.ddns.net/~thegreatgazoo/visitE.php?subID=$subID'><button>Refresh Data</button></a>";
    echo "</br></br><a href='http://grevera.ddns.net/~thegreatgazoo/subjectC.php?subID=$subID'><button>Go back to subject $subID</button></a>";
    $submitButton= $_POST['submitButton'];
    if ($submitButton){
        $startTime= $_POST['startTime'];
        $startDate= $_POST['startDate'];
        $endTime= $_POST['endTime'];
        $endDate= $_POST['endDate'];
        $startString = $startDate . " " . $startTime;
        $endString = $endDate . " " . $endTime;
        $newVisit= $_POST['newVisit'];
        if ((!empty($newVisit)) && (!empty($startTime))&&(!empty($startDate))&& (!empty($endTime))&&(!empty($endDate))) {
            //insert a new subject visit (SV) for the above subject
            $start = new DateTime( date("$startString") );
            $end = new DateTime( date("$endString") );
            $last_visitnum = $redis->hIncrBy( "$me:DM:$studyid:$subID",'last_visitnum', 1 );
            $sv = array(
                'svstdtc'  => $start->format( DateTime::ATOM ),   # ISO8601 format
                'svendtc' => $end->format( DateTime::ATOM ),    # ISO8601 format
                'visit'        => $newVisit
            );
            $key = "$me:SV:$studyid:$subID:$last_visitnum";
            $redis->hMset( $key, $sv );
        }
        else {
          echo "<script>alert('You did not enter a visit. Please enter a visit into the input field.')</script>";
        }
    }
    echo "<!-- closed: " . $redis->close() . ". --> \n";
   
?>
</br></br>
<script>
    if ( window.history.replaceState ) {
        window.history.replaceState( null, null, window.location.href );
    }
</script>
</div>
</body>
</html>
