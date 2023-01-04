<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <title> List of Subjects </title>
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
      display: block;
    }
    td {
      display: block;
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
  </style>
<body>
<div>
  <h1> Subjects </h1>
  <?php
    // https://phpredis.github.io/phpredis/Redis.html#method_scan
    require 'connect.php';
    $me = "thegreatgazoo";
    // Get the stored keys and print it 
    $n = $redis->GET("$me:$studyid:last_usubjid");
    $tableInit = "<table> <th>Select a subject below:</th>";
    echo $tableInit;
    for ($i = 1; $i <= $n; $i++) {  //iterate through subjects
      $k = "$me:DM:$studyid:$i";
      if ($redis->exists("$k")) {
        $values = $redis->hGetAll( $k );
        echo "<tr>";
        echo "<td><a href='http://grevera.ddns.net/~thegreatgazoo/subjectC.php?subID=$i'> $i </a></td>";
        echo "</tr>";
      }
    }
    echo "</table>";
    echo "<!-- closed: " . $redis->close() . ". --> \n";
  ?>
  </br>
  <a href='http://grevera.ddns.net/~thegreatgazoo/addB.php'><button>Add A Subject</button></a>
  </br>
  <button><a href='http://grevera.ddns.net/~thegreatgazoo/studyA.php'>Refresh Data</a></button>
  </br></br>
</div>
</body>
</html>
