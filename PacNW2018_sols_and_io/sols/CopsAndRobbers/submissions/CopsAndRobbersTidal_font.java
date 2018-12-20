
import java.util.*;
import java.io.*;

public class CopsAndRobbersTidal_font
{
   public static void main(String[] args) throws Exception
   {
      PrintWriter out = new PrintWriter(System.out);
      new CopsAndRobbersTidal_font(new FastScanner(System.in), out);
      out.close();
   }

   int N, M, C, oo = 98765432;
   char[][] grid;
   int[] dr = {0, 1, 0, -1};
   int[] dc = {1, 0, -1, 0};


   int getID(int s, int i, int j)
   {
      return 2 * (i * M + j) + s; 
   }

   public CopsAndRobbersTidal_font(FastScanner in, PrintWriter out)
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
      
      TidalFlow solver = new TidalFlow(N*M*2);
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

class TidalFlow
{
   int numNodes, source, sink; 
   ArrayList<Edge>[] adj;
   
   ArrayDeque<Integer> q;
   boolean[] blocked;
   int[] level, lo, hi;

   int numEdges;
   Edge[] levelGraph;

   public TidalFlow(int numNodes)
   {
      this.source = numNodes++;
      this.sink = numNodes++;
      this.numNodes = numNodes;
      adj = new ArrayList[numNodes];
      for (int i=0; i<numNodes; i++)
      {
         adj[i] = new ArrayList<>();
      }
      
      q = new ArrayDeque<>();
      blocked = new boolean[numNodes];
      level = new int[numNodes];
      lo = new int[numNodes];
      hi = new int[numNodes];
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

   boolean bfs()
   {
      Arrays.fill(level, Integer.MAX_VALUE);
      level[sink] = 0;
      q.clear();
      q.add(sink);

      while (!q.isEmpty())
      {
         int i = q.poll();
         if (i == source)
         {
            q.clear();
            q.add(source);
            Arrays.fill(hi, 0);
            hi[source] = 1;
            numEdges = 0;

            while (!q.isEmpty())
            {
               i = q.poll();
               for (Edge e : adj[i])
               {
                  if (e.cap > 0 && level[i] > level[e.j])
                  {
                     levelGraph[numEdges] = e;
                     numEdges++;

                     if (hi[e.j] == 0)
                     {
                        q.add(e.j); 
                        hi[e.j] = 1;
                     }
                  }
               }
            }

            return true;
         }

         for (Edge e : adj[i])
         {
            if (e.rev.cap > 0 && level[e.j] == Integer.MAX_VALUE)
            {
               level[e.j] = level[i] + 1;
               q.add(e.j);
            }
         }
      }
   
      return false;
   }

   int tidalPhase()
   {
      // Tide in
      Arrays.fill(hi, 0);
      hi[source] = Integer.MAX_VALUE;
      for (int curEdge=0; curEdge<numEdges; curEdge++)
      {
         Edge e = levelGraph[curEdge];
         e.promised = Math.min(e.cap, hi[e.i]);
         hi[e.j] += e.promised;
      }

      if (hi[sink] == 0)
         return 0;

      // Tide out
      Arrays.fill(lo, 0);
      lo[sink] = hi[sink];
      for (int curEdge=numEdges-1; curEdge>=0; curEdge--)
      {
         Edge e = levelGraph[curEdge];
         int amt = Math.min(hi[e.i]-lo[e.i], lo[e.j]);
         e.promised = Math.min(amt, e.promised);
         lo[e.i] += e.promised;
         lo[e.j] -= e.promised;
      }

      // Augment level graph
      Arrays.fill(hi, 0);
      hi[source] = lo[source];
      for (int curEdge=0; curEdge<numEdges; curEdge++)
      {
         Edge e = levelGraph[curEdge];
         int f = Math.min(e.promised, hi[e.i]);
         hi[e.i] -= f;
         hi[e.j] += f;
         e.cap -= f;
         e.rev.cap += f;
      }

      return hi[sink];
   }

   int run()
   {
      numEdges = 0;
      for (int i=0; i<numNodes; i++)
         numEdges += adj[i].size();
      numEdges /= 2;
      levelGraph = new Edge[numEdges];

      int totalFlow = 0;
      while (bfs())
      {
         int flowSent = -1;
         while (flowSent != 0)
         {
            flowSent = tidalPhase();
            totalFlow += flowSent;
         }
      }
      return totalFlow;
   }
}

class State
{
   int i, flowCap; 

   public State(int i, int flowCap)
   {
      this.i = i;
      this.flowCap = flowCap;
   }
}

class Edge
{
   int i, j, cap, promised;
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

