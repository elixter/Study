# Floyd's Algorithm for shortest paths

## 1. Weght graph
- For using dynamic programming, we use weight matrix W. if W[$i$][$j$] has value, there is an edge from $v_i$ to $v_j$.
This array called the $\boldsymbol{adjacency\ matrix.}$

$$
\mathrm{W}[i][j] = \begin{cases}
    weight\ on\ edge & \text{if there is an edge from $v_i$ to $v_j$} \\
    \infty & \text{if there is no edge from $v_i$ to $v_j$} \\
    0 & \text{if ${i}$ = ${j}$.}
\end{cases}
$$

## 2. Directed graph
$$
\mathrm{D}[i][j] = \text{length of a shortest path from $v_i$ to $v_j$ using only vertices in the set \{$v_1$, $v_2$, ... , $v_k$\} as intermediate vertices.}
$$

## 3. Floyd's algorithm.
- ### Floyd's algorithm has two cases.
    - #### Case 1
      - At least one shortest path from $v_i$ to $v_j$, using only vertices in {$v_1$, $v_2$, ... ,$v_k$} as intermediate vertices, does not use $v_k$. Then

          $$\Rightarrow D^{(k)}[i][j] = D^{(k-1)}[i][j].$$

    - #### Case 2
      - All shortest paths from $v_i$ to $v_j$, using only vertices in {$v_1$, $v_2$, ... ,$v_k$} as intermediate vertices, do use $v_k$. $v_k$ can't be an intermediate vertex on the subpath from $v_i$ to $v_k$, that subpath uses only vertices in {$v_1$, $v_2$, ... ,$v_{k-1}$} as intermdediates. This implies that $\boldsymbol{the\ subpath's\ length\ must\ be equal\ to\ {D^{(k-1)}[i][k]}. }$
      - Here is reasons why subpath's length must be equal to ${D^{(k-1)}[i][k]}$
        1. ${D^{(k-1)}[i][l]}$ is the length of a shortest path from $v_i$ to $v_k$ using only vertices in {$v_1$, $v_2$, ... ,$v_k$} as intermediates.
        2. The subpath's length cannot be longer.

          $$\Rightarrow D^{(k)}[i][j] = D^{(k-1)}[i][k] + D^{(k-1)}[k][j].$$
- ### Result
    - $$D^{(k)}[i][j] = minimum(D^{(k-1)}[i][j],\ D^{(k-1)}[i][k] + D^{(k-1)}[k][j])$$

## 4. Code
~~~c++
void floyd (int n, const int W[][], const int D[][]) {
  int i, j, k;
  D = W;
  for (k = 1; k <= n; k++) {
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
      }
    }
  }
}
~~~

## 5. Worst time complexity
- Basic operation : The instruction in the for-j loop.
- Input size : n, the number of vertices in the graph.
$$\Rightarrow T(n) = n \times n \times n = n^3 \in \Theta(n^3)$$

## - Appendix A
- ### Path tracker
  - Additional ouput : Array P, which has both its rows and columns indexed from 1 to n, where

  $$
  \mathrm{P}[i][j] = \begin{cases}
  highest\ index\ of\ an\ intermediate\ vertex\ on\ the\ shortest\ path\\ from\ v_i\ to\ v_j,\ if\ at\ least\ one\ intermediate\ vertex\ exists. \\
  0,\ if\ no\ intermediate\ vertex\ exists.
  \end{cases}
  $$

  - ### Code

    ~~~c++
    // Make shortest path.
    void floyd (int n, const int W[][], int D[][], int P[][]) {
      int i, j, k;

      for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
          P[i][j] = 0;
        }
      }
      D = W;
      for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
          for (j = 1; j <= n; j++)
            if (D[i][k] + D[k][j] < D[i][j]) {
              P[i][j] = k;
              D[i][j] = D[i][k] + D[k][j];
            }
    }

    // Print shortest path.
    void path (int q/*start*/, int r/*end*/) {
      if (P[q][r] != 0) {
        path(q, P[q][r])
        std::cout << "v" << P[q][r];
        path(P[q][r], r);
      }
    }
    ~~~
