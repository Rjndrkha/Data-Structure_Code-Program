<?php 
    if(isset($_POST['submit'])) {
        $res = strrev($_POST['string']);
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>String Reverser</title>
</head>
<body>
    <form action="stringReverser.php" method="POST">
        <?php if(isset($res)) { ?>
            <input type="text" name="string">
            <input type="submit" name="submit" value="reverse">
        <?php } else { ?>
            <p><?php $res ?></p>
        <?php } ?>
    </form>
</body>
</html>