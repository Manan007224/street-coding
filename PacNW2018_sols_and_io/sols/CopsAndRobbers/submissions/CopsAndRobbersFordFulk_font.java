
import java.util.*;
import java.io.*;

public class CopsAndRobbersFordFulk_font
{
   public static void main(String[] args) throws Exception
   {
      PrintWriter out = new PrintWriter(System.out);
      new CopsAndRobbersFordFulk_font(new FastScanner(System.in), out);
      out.close();
   }

   int N, M, C, oo = 987654321;
   char[][] grid;
   int[] dr = {0, 1, 0, -1};
   int[] dc = {1, 0, -1, 0};


   int getID(int s, int i, int j)
   {
      return 2 * (i * M + j) + s; 
   }

   public CopsAndRobbersFordFulk_font(FastScanner in, PrintWriter out)
   {
      M = in.nextInt();
      N = in.nextInt();
      C = in.nextInt();
      grid = new char[N][];
      for (int i=0; i<N; i++)
         grid[i] = in.next().toCharArray();
      int[] costs = new int[C];
      for (int i=0; i<C; i++)
         costs[i] = in.nextInt();
      
      FordFulkerson solver = new FordFulkerson(N*M*2);
      for (int i=0; i<N; i++)
      {
         for (int j=0; j<M; j++)
         {
            int cost = oo;
            if (grid[i][j] == 'B')
            {
               solver.addEdge(solver.source, getID(0, i, j), oo);
            }
            else if (grid[i][j] != '.')
            {
               int pos = grid[i][j] - 'a';
               cost = costs[pos];
            }
            solver.addEdge(getID(0, i, j), getID(1, i, j), cost);

            for (int u=0; u<4; u++)
            {
               int ni = i+dr[u];
               int nj = j+dc[u];

               if (0 <= ni && ni < N &&
                   0 <= nj && nj < M)
               {
                  solver.addEdge(getID(1, i, j), getID(0, ni, nj), oo);
               }
               else
               {
                  solver.addEdge(getID(1, i, j), solver.sink, oo);
               }
            }
         }
      }

      int result = solver.run();
      out.println(result >= oo ? -1 : result);
   }

   class Edge
   {
      int i, j;
      boolean matchedEdge;

      Edge(int i, int j, boolean matchedEdge)
      {
         this.i = i;
         this.j = j;
         this.matchedEdge = matchedEdge;
      }
   }
}

class FordFulkerson
{
   int numNodes, source, sink; 
   ArrayList<Edge>[] adj;
   boolean[] seen;

   public FordFulkerson(int numNodes)
   {
      this.numNodes = numNodes;
      this.source = numNodes++;
      this.sink = numNodes++;
      seen = new boolean[numNodes];
      adj = new ArrayList[numNodes];
      for (int i=0; i<numNodes; i++)
      {
         adj[i] = new ArrayList<>();
      }
   }

   void addEdge(int i, int j, int cap)
   {
      Edge fwd = new Edge(i, j, cap);
      Edge rev = new Edge(j, i, 0);
      fwd.rev = rev;
      rev.rev = fwd;
      adj[i].add(fwd);
      adj[j].add(rev);
   }

   int dfs(int curNode, int flowCap)
   {
      if (seen[curNode] || flowCap == 0)
         return 0;
      seen[curNode] = true;
      if (curNode == sink)
         return flowCap;

      for (Edge e : adj[curNode])
      {
         int amtSent = dfs(e.j, Math.min(e.cap, flowCap));
         if (amtSent > 0)
         {
            e.cap -= amtSent;
            e.rev.cap += amtSent;
            return amtSent;
         }
      }

      return 0;
   }

   int run()
   {
      int totalFlow = 0;
      int flowSent = -1;
      while (flowSent != 0)
      {
         Arrays.fill(seen, false);
         flowSent = dfs(source, Integer.MAX_VALUE); 
         totalFlow += flowSent;
      }
      return totalFlow;
   }
}

class Edge
{
   int i, j, cap;
   Edge rev;

   public Edge(int i, int j, int cap)
   {
      this.i = i;
      this.j = j;
      this.cap = cap;
      this.rev = null;
   }
}

class FastScanner
{
   private InputStream stream;
   private byte[] buf = new byte[1024];
   private int curChar;
   private int numChars;
    
   public FastScanner(InputStream stream)
   {
      this.stream = stream;
   }
    
   int read()
   {
      if (numChars == -1)
         throw new InputMismatchException();
      if (curChar >= numChars)
      {
         curChar = 0;
         try
         {
            numChars = stream.read(buf);
         } 
         catch (IOException e) 
         {
            throw new InputMismatchException();
         }
         
         if (numChars <= 0)
            return -1;
      }
      return buf[curChar++];
   }
    
   boolean isSpaceChar(int c)
   {
      return c==' '||c=='\n'||c=='\r'||c=='\t'||c==-1;
   }
   
   boolean isEndline(int c)
   {
      return c=='\n'||c=='\r'||c==-1;
   }
   
   int nextInt()
   {
      return Integer.parseInt(next());
   }
   
   long nextLong()
   {
      return Long.parseLong(next());
   }
   
   double nextDouble()
   {
      return Double.parseDouble(next());
   }
   
   String next()
   {
      int c = read();
      while (isSpaceChar(c))
         c = read();
      StringBuilder res = new StringBuilder();
      do
      {
         res.appendCodePoint(c);
         c = read();
      } while(!isSpaceChar(c));
      return res.toString();
   }
   
   String nextLine()
   {
      int c = read();
      while (isEndline(c))
         c = read();
      
      StringBuilder res = new StringBuilder();
      do
      {
         res.appendCodePoint(c);
         c = read();
      } while(!isEndline(c));
      return res.toString();
   }
}
