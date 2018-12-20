
import java.util.*;
import java.io.*;

public class CopsAndRobbers_font
{
   public static void main(String[] args) throws Exception
   {
      PrintWriter out = new PrintWriter(System.out);
      new CopsAndRobbers_font(new FastScanner(System.in), out);
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

   public CopsAndRobbers_font(FastScanner in, PrintWriter out)
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
      
      ISAP solver = new ISAP(N*M*2);
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

class ISAP
{
   int numNodes, source, sink; 
   ArrayList<Edge>[] adj;
   
   ArrayDeque<Integer> q;
   ArrayDeque<Edge> path;
   int[] level;
   int[] curEdge;
   int[] count;

   public ISAP(int numNodes)
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
      path = new ArrayDeque<>();
      level = new int[numNodes];
      curEdge = new int[numNodes];
      count = new int[numNodes+1];
   }

   public void addEdge(int i, int j, int cap)
   {
      Edge fwd = new Edge(i, j, cap);
      Edge rev = new Edge(j, i, 0);
      fwd.rev = rev;
      rev.rev = fwd;
      adj[i].add(fwd);
      adj[j].add(rev);
   }

   void bfs()
   {
      Arrays.fill(level, numNodes);
      level[sink] = 0;
      q.clear();
      q.add(sink);

      while (!q.isEmpty())
      {
         int i = q.poll();
         for (Edge e : adj[i])
         {
            if (e.rev.cap > 0 && level[e.j] == numNodes)
            {
               level[e.j] = level[i] + 1;
               q.add(e.j);
            }
         }
      }
   }

   public int run()
   {
      bfs();
      for (int i=0; i<numNodes; i++)
         count[level[i]]++;

      int last = 0;
      int i = source;
      int totalFlow = 0;
      while (level[source] < numNodes)
      {
         Edge admissibleEdge = null;
         while (curEdge[i] < adj[i].size())
         {
            Edge e = adj[i].get(curEdge[i]);
            if (level[i] == level[e.j] + 1 && e.cap > 0)
            {
               admissibleEdge = e;
               break;
            }

            curEdge[i]++;
         }

         if (admissibleEdge == null)
         {
            // Relabel & Retreat
            count[level[i]]--;
            if (count[level[i]] == 0)
               break;
            level[i] = numNodes;
            for (Edge e : adj[i])
               if (e.cap > 0)
                  level[i] = Math.min(level[i], 1+level[e.j]);
            count[level[i]]++;
            curEdge[i] = 0;
            if (i != source)
            {
               Edge e = path.pop();
               i = e.i;
            }
         }
         else
         {
            path.push(admissibleEdge);
            i = admissibleEdge.j;
            if (i == sink)
            {
               int bottleneck = Integer.MAX_VALUE;
               for (Edge e : path)
                  bottleneck = Math.min(bottleneck, e.cap);
               totalFlow += bottleneck;

               Edge firstZero = null;
               for (Edge e : path)
               {
                  e.cap -= bottleneck;
                  e.rev.cap += bottleneck;
                  if (firstZero == null && e.cap == 0)
                     firstZero = e;
               }
            
               while (!path.isEmpty())
               {
                  Edge e = path.pop();
                  i = e.i;
                  if (e == firstZero)
                     break;
               }
               if (level[source] != last)
               {
                  last = level[source];
               }
            }
         }
      }
      return totalFlow;
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
