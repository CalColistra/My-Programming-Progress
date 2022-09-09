public class MainTTT {
    public static void main ( String args[] ) {
        //Here are examples of how one may test their code.

    	
    	P b1[][] = {
                { P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty,},
                { P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, },
                { P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, },
                { P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, },
                { P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, },
            };
            System.out.println( TTT.tic_tac_crazy ( b1, 3 ) );
    	
    	
 
        P b2[][] = {
            { P.Empty, P.Empty, P.Empty, },
            { P.Empty, P.Empty, P.Empty, },
            { P.Empty, P.Empty, P.Empty, },
        };
        System.out.println( TTT.winner3x3(b2) );
        
        
        P b3[][] = {
                { P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, },
                { P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, },
                { P.Empty, P.Empty, P.X, P.X, P.X, },
            };
            System.out.println( TTT.winner3x5(b3) );

            
       P b4[][] = {
                    { P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, },
                    { P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, },
                    { P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, },
                    { P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, },
                    { P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.X, P.Empty, P.Empty, },
                    { P.Empty, P.Empty, P.Empty, P.Empty, P.Empty, P.O, P.Empty, P.Empty, P.Empty, },
                    { P.Empty, P.Empty, P.Empty, P.Empty, P.X, P.X, P.Empty, P.Empty, P.Empty, },
                };
                System.out.println( TTT.winner7x9(b4) );
    }
}