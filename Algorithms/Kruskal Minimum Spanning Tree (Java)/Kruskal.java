import java.io.File;
import java.util.PriorityQueue;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
/*
file  :  Kruskal.java
author:  Cal Colistra + george j. grevera, ph.d.
desc. :  this file contains the definition of the Kruskal class.
         an outline of this algorithm from the Cormen book is below.
         \TODOs: makeSet, sameSet, vertexSetUnion, process, getMSTCost

         MST-KRUSKAL ( G, w )
         1    A = empty-set
         2    for each vertex v in G.V
         3        MAKE-SET( v )
         4    sort the edges of G.E into nondecreasing order by weight w
         5    for each edge (u,v) in G.E, taken in nondecreasing order by weight
         6        if (!sameSet(u, v))         //was: if FIND-SET( u ) != FIND-SET( v )
         7            insert( A, u, v )       //was:     A = union( A, {(u,v)} )  //add edge (u,v) to MST edge set A
         8            vertexSetUnion( u, v )  //was:     UNION( u, v )            //union of sets of vertices
         9    return A

         Note: i used vertexSetUnion instead of union because i originally
               wrote this in C++ and union is a keyword.

Copyright (c) George J. Grevera, 2021.  All rights reserved.
*/
public class Kruskal {
  private int mVertexCount = 0;    //number of nodes/vertices (0..mVertexCount-1)
  boolean[][] mVertexSet;  //2d array indicating what is in each set
  private PriorityQueue< Edge > mSortedEdges = new PriorityQueue<>( new Edge() );  //edges sorted by weight
  private HashSet< Edge > mA = new HashSet<>();  //result set of edges in MST
  Queue<Integer> q = new LinkedList<>();  //queue for vertex set union
  
  public boolean verbose = false;  //turn info messages on/off
  //-----------------------------------------------------------------------
  //allocate memory for the 2d array representing sets of vertices.
  private void initSet ( int vCount ) {
    mVertexCount = vCount;

    //allocate & init memory for the 2d array
    // old fashioned (single 2D array): mVertexSet = new boolean[vCount][vCount];
    // new fashioned (a 2D array as an array of arrays):
    mVertexSet = new boolean[vCount][];
    for (int i = 0; i < vCount; i++) {
      mVertexSet[ i ] = new boolean[ vCount ];
    }
  }
  //-----------------------------------------------------------------------
  //ctor which simply sets the numbers of vertices and puts each one in its
  // own set.  if you use this, you will have to add edges on your own and
  // one at a time.
  public Kruskal ( int vCount ) {
    assert( vCount > 0 );
      if (vCount < 1)    return;
      initSet( vCount );
      makeSet( vCount );
  }
  //-----------------------------------------------------------------------
  //ctor which loads vertices and edges (and their weights) from an input
  // file.
  public Kruskal ( String fname ) {
    if (verbose)
      System.out.println( "reading input from: " + fname );
    //open the input file
    Scanner in;
    try {
      in = new Scanner( new File(fname) );
    } catch (Exception e) {
        System.err.println( "Kruskal: can't read input file " + fname );
        return;
      }
    //read the number of vertices
    int vertices = in.nextInt();
    //read the number of edges
    int edges = in.nextInt();
    if (verbose)
      System.out.println( "  vertices=" + vertices + ", edges=" + edges );
    //put each vertex in its own separate set
    initSet( vertices );
    makeSet( vertices );

    //load the edges and their weights
    for (int i = 0; i < edges; i++) {
      int u = in.nextInt();
      int v = in.nextInt();
      double w = in.nextDouble();
      addEdge( u, v, w );
      //print something every once in a while when processing large
      // input files.
      if (verbose && i>0) {
        if (i % 1000000 == 0) {
          System.out.print( "!" );
          System.out.flush();
        } else if (i %  100000 == 0) {
            System.out.print( "*" );
            System.out.flush();
        } else if (i %   10000 == 0) {
            System.out.print( "." );
            System.out.flush();
        }
      }
    }

    in.close();
    if (verbose)
      System.out.println( "finished reading input from: " + fname );
  }
  //-----------------------------------------------------------------------
  //add the edge  with its weight to the automagically sorted set of edges.
  void addEdge ( int u, int v, double w ) {
    if (u < 0 || u >= mVertexCount) {
      System.err.println( "Kruskal:addEdge(u,v,w): bad u " + u + "\n" );
        return;
    }
    if (v < 0 || v >= mVertexCount) {
      System.err.println( "Kruskal:addEdge(u,v,w): bad v " + v + "\n" );
      return;
    }

    Edge e = new Edge( u, v, w );
      mSortedEdges.add( e );
  }
  //-----------------------------------------------------------------------
  //(public for testing.)
  // put each vertex in an individual set.
  public void makeSet ( int vCount ) {
    for (int i = 0; i < vCount; i++) {
      //give each vertex a true value where it points to itself:
      mVertexSet[i][i] = true;
    }
  }
  //-----------------------------------------------------------------------
  //(public for testing.)
  //this function returns true if the vertices specified are in the same set,
  // and false otherwise.
  public boolean sameSet ( int u, int v ) {
	//if u and v are directly connected:
    if (mVertexSet[u][v] == true) return true;  //return true
    //if u and v are directly connected:
    if (mVertexSet[v][u] == true) return true;  //return true
    return false;  //if this line is reached then they are not connected
  }
  //-----------------------------------------------------------------------
  //(public for testing.)
  //create the union of two sets.
  public void vertexSetUnion ( int u, int v ) {
	mVertexSet[u][v] = true;  //connect two vertexes directly
	mVertexSet[v][u] = true;  //connect two vertexes directly
	for (int i = 0; i < mVertexCount; i++) {  //iterate through all possible edges
	  if (mVertexSet[v][i] == true)  {  //if i is connected
	    mVertexSet[u][i] = true;  //put v's edges into u
	    q.add(i);  //add connected vertexes to the queue
	  }
	  if (mVertexSet[u][i] == true)  {  //if i is an edge
	    mVertexSet[v][i] = true;  //put u's edges into v
	    q.add(i);  //add connected vertexes to the queue
	  }
	}
	
	while (q.isEmpty() == false) {  //iterate through the queue
	  for (int i = 0; i < mVertexCount; i++) {  //iterate through each possible edge
	    if (mVertexSet[v][i] == true) {  //if there are edges on the original v
	    	mVertexSet[q.peek()][i] = true;  //add the edge to the connected set
	    }
	  }
	  q.remove();  //get rid of vertex that was previously connected
	}
  }
  //-----------------------------------------------------------------------
  //(public for testing.)
  //implement the algorithm (lines 5 through 9 above).
  //upon return, this.mA should contain the MST.
  public HashSet< Edge > process ( ) {
	makeSet(mVertexCount);  //make the initial sets
	Edge e;  //make a new edge variable to check each edge in A
	while (!mSortedEdges.isEmpty()) {  //keep going while there are still nodes in A
	  e = mSortedEdges.peek();  //set e equal to the edge at the top of the queue
	  //check if the vertex is already connected to the tree:
	  if (sameSet( e.getFrom(), e.getTo() ) == false) {  //if they are not already connected:
		vertexSetUnion(e.getFrom(), e.getTo());  //union of sets of vertexes
	    mA.add( mSortedEdges.poll() );  //add edges to mA and remove them from queue
	  }
	  else {  //its already connected to tree:
	    vertexSetUnion(e.getFrom(), e.getTo());  //union of sets of vertexes
		mSortedEdges.poll();  //remove from queue
	  }
	}
    return this.mA;  //return the tree
  }
  //-----------------------------------------------------------------------
  //return the cost of the MST by summing all of the weights of its edges.
  public double getMSTCost ( ) {
	double sum = 0;  //initialize sum
	Edge p;  //initialize edge variable
	Iterator<Edge> it = mA.iterator();  //initialize iterator
	while (it.hasNext()) {  //keep going while mA has a next element
	  p = it.next();  //set edge p equal to next element
	  sum = sum + p.getW();  //add p's weight to the sum
	}
    return sum;  //return the total cost
  }
  //-----------------------------------------------------------------------
  //getter for private vertex count
  public int getVertexCount ( )  {  return mVertexCount;  }
  //-----------------------------------------------------------------------
  @Override
  public String toString ( ) {
    String s = "-------------------- \n";
    s += "Kruskal: \n";
    s += "    mVertexCount=" + this.mVertexCount;
    if (this.mVertexSet != null)
      s += "    mVertexSet=0x" + Integer.toHexString(this.mVertexSet.hashCode()) + "\n";
    else
      s += "    mVertexSet=null \n";

    //output contents of vertex sets
    if (this.mVertexSet != null) {
      for (int r = 0; r < this.mVertexCount; r++) {
        s += "        " + r + ": ";
        if (this.mVertexSet[ r ] == null) {
          s += "  null";
        } else {
            for (int c = 0; c < this.mVertexCount; c++) {
              s += (this.mVertexSet[r][c]) ? 1 : 0;
              s += " ";
            }
          }
        s += "\n";
      }
    }

    //output contents (edges) in A (the MST)
    s += "    mA.length=" + this.mA.size() + "\n";
    for (Edge e : this.mA) {
      s += "       " + e + "\n";
    }

    //output the contents of the edge set sorted by edge weight.
    // since the only way to traverse a priority queue is to "destroy" it,
    // we'll make a copy of it and destroy the copy.
    s += "   mSortedEdges.size=" + this.mSortedEdges.size() +  "\n";
    PriorityQueue<Edge> tmp = new PriorityQueue<>( this.mSortedEdges );  //edges sorted by weight
      while (!tmp.isEmpty()) {
        Edge e = tmp.remove();
        s += "        " + e + "\n";
      }

    s += "--------------------";
    return s;
  }

}
