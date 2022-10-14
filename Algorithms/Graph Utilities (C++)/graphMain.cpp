#include <iostream>

using namespace std;

#define N 10

extern bool hasSelfLoops(bool G[N][N]);
extern bool isEmpty(bool G[N][N]);
extern bool isDigraph(bool G[N][N]);
extern bool hasCycle(bool G[N][N]);

//----------------------------------------------------------------------
int main(int argc, char* argv[]) {

bool G[N][N] = {
    //    0  1  2  3  4  5  6  7  8  9
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },//0
        { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },//1
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//2
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//3
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//4
        { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },//5
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//6
        { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },//7
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//8
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } //9
    };

/*
  bool G[N][N] = {
     //   0  1  2  3  4
        { 0, 1, 0, 0, 0 }, //0
        { 0, 0, 0, 1, 0 }, //1
        { 0, 0, 0, 0, 0 }, //2
        { 0, 0, 0, 0, 1 }, //3
        { 0, 0, 0, 0, 0 }, //4
    };
*/
  bool ans = hasCycle(G);
  cout << "cycle? " << ans << endl;

    //cout << "isEmpty: " << isEmpty(G) << endl;
    //cout << "hasSelfLoops: " << hasSelfLoops(G) << endl;
    //cout << "isDigraph: " << isDigraph(G) << endl;
    //cout << "hasCycle: " << hasCycle(G) << endl;
    
  //cout << "{" << G[5][0] << "} ";
/*
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << "{" << G[i][j] << "} ";
        }
        cout << endl;
    }
 */
    //cout << G[0][1] << endl;

    return 0;
}
