import java.util.Comparator;
//
//file  :  Edge.java    ***no changes are necessary***
//author:  george j. grevera, ph.d.
//desc. :  this file contains the definition of the Edge class.
//         an edge consists of a u, a v, and a weight.
//
//Copyright (c) George J. Grevera, 2021.  All rights reserved.
//
public class Edge implements Comparator< Edge > {
  int     mFrom   = -1;    //'from' vertex (i.e., u in )
  int     mTo     = -1;    //'to'   vertex (i.e., v in )
  double  mWeight = -1;    //weight associated with this edge
  //-----------------------------------------------------------------------
  public Edge ( int from, int to, double weight ) {
    mFrom   = from;
    mTo     = to;
    mWeight = weight;
  }
  //-----------------------------------------------------------------------
  //getters:
  public double getW    ( ) {  return mWeight;  }
  public int    getFrom ( ) {  return mFrom;    }
  public int    getTo   ( ) {  return mTo;      }
  //-----------------------------------------------------------------------
  //allow one to pretty format the contents of the Edge object.
  @Override
  public String toString ( ) {
    return "edge: f=" + this.mFrom + " t=" + this.mTo + " w=" + this.mWeight;
  }
  //-----------------------------------------------------------------------
  //do not use (used for priority queue sorting only)!
  public Edge ( ) { }
  //-----------------------------------------------------------------------
  //do not use (used for priority queue sorting only)!
  @Override
  public int compare ( Edge e1, Edge e2 ) {
    if (e1.mWeight < e2.mWeight)    return -1;
    if (e1.mWeight > e2.mWeight)    return 1;
    return 0;
  }

} 