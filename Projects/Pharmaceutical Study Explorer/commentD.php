<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <title>Comments</title>
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
    echo "<h1>Comments for Subject: $subID</h1>";

    $tableInit = "<table> <th>Comment Number</th> <th>Date of Comment</th><th>Comment</th>";
    echo $tableInit;
    $values = $redis->hGetAll("$me:DM:$studyid:$subID");
    $total = $values['last_coseq'];
    $k = "$me:CO:$studyid:$subID";
    for ($i = 1; $i <= $total; $i++) {
        if ($redis->exists("$k:$i")) {
            $values2 = $redis->hGetAll("$k:$i");
            echo "<tr>";
            echo "<td>";
            echo $i;
            echo "</td>";
            echo "<td>";
            echo $values2['codtc'];
            echo "</td>";
            echo "<td>";
            echo $values2['coval'];
            echo "</td>";
            echo "</tr>";
        }
    }
    echo "</table>";

    echo "</br></br>";
?>
    <form action="" method="POST">
        <label><strong>Enter a new Comment here:</strong></label>
        <input type="text"name="newComment" value=''/>
        <br><br>
        <input id = "aButton" type="submit" name="submitButton" value="Submit new comment"/>
    </form>

<?php
    $newComment= $_POST['newComment'];
    $submitButton= $_POST['submitButton'];
    if ($submitButton){
        if (!empty($newComment)) {
            //insert a new comment (CO) for the above subject
            $last_coseq = $redis->hIncrBy( "$me:DM:$studyid:$subID",'last_coseq', 1 );
            $now = new DateTime( date("Y-m-d H:i:s") );
            $co = array(
                'codtc' => $now->format( DateTime::ATOM ),  # ISO8601 format
                'coval' => $newComment
            );
            $key = "$me:CO:$studyid:$subID:$last_coseq";
            $redis->hMset( $key, $co );
            $newComment = null;
            $submitButton = null;
            $co = null;
        }
        else {
            echo "<script>alert('You did not enter a comment. Please enter a comment into the input field.')</script>";
        }
    }
    echo "<!-- closed: " . $redis->close() . ". --> \n";
    echo "</br><a href='http://grevera.ddns.net/~thegreatgazoo/commentD.php?subID=$subID'><button>Refresh Data</button></a>";
    echo "</br></br><a href='http://grevera.ddns.net/~thegreatgazoo/subjectC.php?subID=$subID'><button>Go back to Subject $subID</button></a>";
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
