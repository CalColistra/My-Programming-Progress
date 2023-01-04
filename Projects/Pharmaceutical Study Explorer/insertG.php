<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <title> Insert Page </title>
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
    <h3>Insert Page</h3>
    </br>
    Click the insert button below to insert <strong>12 Subjects</strong> with <strong>2 comments</strong> and <strong>2 visits</strong> each
    </br> </br>
    <form action="" method="POST" style="display: inline-block;" id = "insertForm">
        <input id = "aButton" type="submit" name="insertButton" value="INSERT"/>
        </br>  
    </form>
    </br> </br>
<?php
    // https://phpredis.github.io/phpredis/Redis.html#method_scan
    require 'connect.php';
    $me = "thegreatgazoo";

    $insertButton= $_POST['insertButton'];
    if ($insertButton){
        for ($i = 1; $i <= 12; $i++) {
            //insert a new subject into DM (via an assoc array)
            $dob = new DateTime( '2010-12-30 23:21:46' );
            $dm = array(
                'brthdtc'       => $dob->format( DateTime::ATOM ),  # ISO8601 format
                'sex'           => 'f',
                'race'          => 'caucasian',
                'country'       => 'usa',
                'last_visitnum' => 0,
                'last_coseq'    => 0
            );
            $usubjid = $redis->incr( "$me:$studyid:last_usubjid" );
            $key = "$me:DM:$studyid:$usubjid";
            $redis->hMset( $key, $dm );
            for ($com = 1; $com <= 2; $com++) {
                //insert a new comment (CO) for the above subject
                $last_coseq = $redis->hIncrBy( "$me:DM:$studyid:$usubjid",'last_coseq', 1 );
                $now = new DateTime( date("Y-m-d H:i:s") );
                $co = array(
                    'codtc' => $now->format( DateTime::ATOM ),  # ISO8601 format
                    'coval' => "this is comment number $com"
                );
                $key = "$me:CO:$studyid:$usubjid:$last_coseq";
                $redis->hMset( $key, $co );
                //insert another new comment (CO) for the above subject
                $last_coseq = $redis->hIncrBy( "$me:DM:$studyid:$usubjid",'last_coseq', 1 );
                $now = new DateTime( date("Y-m-d H:i:s") );
                $co = array(
                    'codtc' => $now->format( DateTime::ATOM ),  # ISO8601 format
                    'coval' => 'this is my second comment'
                );
                $key = "$me:CO:$studyid:$usubjid:$last_coseq";
                $redis->hMset( $key, $co );
            }
            for ($vis=1; $vis<=2; $vis++) {
                //insert a new subject visit (SV) for the above subject
                $last_visitnum = $redis->hIncrBy( "$me:DM:$studyid:$usubjid",'last_visitnum', 1 );
                $start = new DateTime( date("Y-m-d H:i:s") );
                $end   = new DateTime( date("Y-m-d H:i:s") );
                $sv = array(
                    'svstdtc'  => $start->format( DateTime::ATOM ),   # ISO8601 format
                    'svendtc' => $end->format( DateTime::ATOM ),    # ISO8601 format
                    'visit'        => "this is a visit comment $vis"
                );
                $key = "$me:SV:$studyid:$usubjid:$last_visitnum";
                $redis->hMset( $key, $sv );
            }
        }
        echo "<script>alert('Insert Complete!')</script>";
    }

    echo "<!-- closed: " . $redis->close() . ". --> \n";
?>
<script>
    if ( window.history.replaceState ) {
        window.history.replaceState( null, null, window.location.href );
    }
  </script>

</div>
</body>
</html>
