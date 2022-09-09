
public class TTT {
  /**
  * Check for a 3-in-a-row winner on a 3x3 board.
  * @param board is the game board
  * @return true if there is a winner for either X or O; false otherwise
  */
  public static boolean winner3x3 ( P board[][] ) {
    //you can assume that you are given a 3x3 board
    assert board != null && board.length == 3 && board[0].length == 3;
    return tic_tac_crazy ( board, 3 );  //call & return ultimate TTT function
  }

  /**
  * Check for a 3-in-a-row winner on a 3x5 board.
  * @param board is the game board
  * @return true if there is a winner for either X or O; false otherwise
  */
  public static boolean winner3x5 ( P board[][] ) {
    //you can assume that you are given a 3x5 board
    assert board != null && board.length == 3 && board[0].length == 5;
    return tic_tac_crazy ( board, 3 );  //call & return ultimate TTT function
  }

  /**
  * Check for a 3-in-a-row winner on a 9x7 board.
  * @param board is the game board
  * @return true if there is a winner for either X or O; false otherwise
  */
  public static boolean winner7x9 ( P board[][] ) {
  //you can assume that you are given a 3x3 board
    assert board != null && board.length == 9 && board[0].length == 7;
    return tic_tac_crazy ( board, 3 );  //call & return ultimate TTT function
  }

  /**
  * extra credit challenge: Check for a winner of arbitrary length on a
  * board of arbitrary size.
  * @param board is the game board
  * @param howMany is the (minimum) number in a row for a winner
  * @return true if there is a winner for either X or O; false otherwise
  */
  public static boolean tic_tac_crazy ( P board[][], int howMany ) {
    //you can assume that you are given a board of arbitrary size.
    // you may assume that it is not "ragged/jagged"
    // (see https://www.geeksforgeeks.org/jagged-array-in-java/).
    assert board != null;
    
    if (howMany < 1) {  //check if howMany value is less than 1
      System.out.println("Invalid 'howMany' value.  Please set 'howMany' to a value > 0");
      return false;  //invalid howMany value
    }
    
    if (howMany == 1) {  //check if howMany = 1
      //any box that is not empty wins:
      for (int r = 0; r < board.length; r++) {  //iterate through rows
        for (int c = 0; c < board[0].length; c++) {  //iterate through columns of rows
          if (board[r][c] != P.Empty) return true;  //winner
        }
      }
	}
    
    //at this point we know howMany is greater than 1
    //check rows:
    for (int r = 0; r < board.length; r++) {  //iterate through rows
      for (int c = 0; c < board[0].length; c++) {  //iterate through columns
    	//check if there is room for a TTT and ensure current box is not empty
        if ( ( (c + (howMany - 1) ) < board[0].length ) && ( board[r][c] != P.Empty ) ) {
          int currentColumn = c + 1;  //set currentColumn to the right adjacent column
          int count = 1;  //count = how many in a row are equal
          //keep checking next column until 2 adjacent boxes are not equal:
          while (currentColumn < board[0].length) {
        	if (board[r][c] != board[r][currentColumn]) break;  //no TTT
        	count ++;  //current box is equal so increment count
        	if (count == howMany) return true;  //TTT has been achieved
            currentColumn++;  //increment currentColumn
          }
        }
      }
    }
    //check rows:
    for (int c = 0; c < board[0].length; c++) {  //iterate through rows
      for (int r = 0; r < board.length; r++) {  //iterate through columns
    	//check if there is room for a TTT and ensure current box is not empty
        if ( ( (r + (howMany - 1) ) < board.length ) && ( board[r][c] != P.Empty ) ) {
          int currentRow = r + 1;  //set currentRow to the row below current box
          int count = 1;  //count = how many in a row are equal
          //while loop to keep checking next column until 2 adjacent boxes 
          //are not equal & make sure we don't walk off edge of board:
          while (currentRow < board.length) {
        	if (board[r][c] != board[currentRow][c]) break;  //no TTT
        	count ++;  //current box is equal so increment count
        	if (count == howMany) return true;  //TTT has been achieved
            currentRow++;  //increment currentRow
          }
        }
      }
    }
    //check left to right diagonals:
    for (int c = 0; c < board[0].length; c++) {  //iterate through rows
      for (int r = 0; r < board.length; r++) {  //iterate through columns
    	//check if there is room for a TTT and ensure current box is not empty
        if ( ( (r + (howMany - 1) ) < board.length ) && ( (c + (howMany - 1) ) < board[0].length ) && 
           ( board[r][c] != P.Empty ) ) {
          int currentRow = r + 1;  //set currentRow to the row below current box
          int currentColumn = c + 1;  //set currentColumn to the right adjacent column
          int count = 1;  //count = how many in a row are equal
          //while loop to keep checking next left to right diagonal 
          //box until one is not equal & make sure we don't walk off edge of board:
          while ((currentRow < board.length) && (currentColumn < board[0].length)) {
            if (board[r][c] != board[currentRow][currentColumn]) break;  //if true then no TTT
            count ++;  //current box is equal so increment count
            if (count == howMany) return true;  //TTT has been achieved
            currentRow++;  //increment currentRow
            currentColumn++;  //increment currentColumn
          }
        }
      }
    }
    //check right to left diagonals:
    for (int c = 0; c < board[0].length; c++) {  //iterate through rows
      for (int r = 0; r < board.length; r++) {  //iterate through columns
    	//check if there is room for a TTT and ensure current box is not empty
        if ( ( (r + (howMany - 1) ) < board.length ) && ( (c - (howMany - 1) ) >= 0 ) && 
           ( board[r][c] != P.Empty ) ) {
          int currentRow = r + 1;  //set currentRow to the row below current box
          int currentColumn = c - 1;  //set currentColumn to the left adjacent column
          int count = 1;  //count = how many in a row are equal
          //while loop to keep checking next right to left diagonal box until
          //one is not equal & make sure we don't walk off edge of board:
          while ((currentRow < board.length) && (currentColumn >= 0)) {
            if (board[r][c] != board[currentRow][currentColumn]) break;  //if true then no TTT
            count ++;  //current box is equal so increment count
            if (count == howMany) return true;  //TTT has been achieved
            currentRow++;  //increment currentRow
            currentColumn--;  //decrement currentColumn
          }
        }
      }
    }
    return false;
  }

}
