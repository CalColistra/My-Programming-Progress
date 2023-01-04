<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <title> Add Subject </title>
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
        display: inline-block;
        background-color:#fcfdff;
    }
    label, input {
        margin-left: auto;
        margin-right: auto;
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
    require 'cmd2web.php';
    parseNameEqualValue();
    echo "<h1>Add a New Subject</h1> </br>";
    echo "<strong>Enter the Demographics for the new subject:</strong></br></br>";
    ?>

    <form action="" method="POST">
        </br>
        <label>Enter a the <strong>Date of Birth</strong> here:</label>
        <input type="date"name="dob"/>
        <br><br>
        <label>Enter a the <strong>Time of Birth</strong> here:</label>
        <input type="text"name="tob" placeholder="hh:mm:ss"/>
        <br><br>
        <label>Enter the <strong>Sex</strong> here:</label>
        <input type="text"name="sex" placeholder="m for male or f for female"/>
        <br><br>
        <label>Enter the <strong>Race</strong> here:</label>
        <input type="text"name="race"/>
        <br><br>
        <label>Enter the <strong>Country</strong> here:</label>
        <input type="text"name="country"/>
        <br><br>
        <input id = "aButton" type="submit" name="submitButton" value="Submit"/>
        </br></br>
    </form>

    <?php
    $date= $_POST['dob'];
    $tob= $_POST['tob'];
    $dobString = $date . " " . $tob;
    $sex= $_POST['sex'];
    $race= $_POST['race'];
    $country= $_POST['country'];
    $submitButton= $_POST['submitButton'];
    if ($submitButton){
        if ( (!empty($date)) && (!empty($tob)) && (!empty($sex)) && (!empty($race)) && (!empty($country))){
            //insert a new subject into DM (via an assoc array)
            $dob = new DateTime( $dobString );
            $dm = array(
                'brthdtc'       => $dob->format( DateTime::ATOM ),  # ISO8601 format
                'sex'           => $sex,
                'race'          => $race,
                'country'       => $country,
                'last_visitnum' => 0,
                'last_coseq'    => 0
            );
            $usubjid = $redis->incr( "$me:$studyid:last_usubjid" );
            $key = "$me:DM:$studyid:$usubjid";
            $redis->hMset( $key, $dm );
            echo "<script>alert('Succesfully added the new subject!')</script>";
        }
        else {
            echo "<script>alert('Data fields were left empty. Please fill out all fields!')</script>";
        }
    }
  ?>
  </br></br>
  <a href="http://grevera.ddns.net/~thegreatgazoo/studyA.php"><button id = "aButton">Go back to Subjects</button></a>
  </br></br>
  <script>
    if ( window.history.replaceState ) {
        window.history.replaceState( null, null, window.location.href );
    }
</script>
</div>
</body>
</html>
