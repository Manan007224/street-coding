class Solution:
	def runner(self, board):
		ll = len(board)
		row = [set() for _ in range(ll)]
		col = [set() for _ in range(ll)]
		grid = [set() for _ in range(ll)]

		# Filling all the cells in row and column

		for i in range(ll):
			for j in range(ll):
				if board[i][j]!= ".":
					row[i].add(board[i][j])
				if board[j][i]!= ".":
					col[j].add(board[j][i])

		# Filling all the cells in the 3*3 grid

		for i in range(ll):
			for j in range(3*int(i/3),3*int(i/3)+3):
				for k in range(3*int(i%3),3*int(i%3)+3):
					if board[k][j]!= ".":
						grid[i].add(board[k][j])


		# Checking the validity of sudoku board
						
		def valid_sudoku(board, val, r, c):
			return val not in row[r] and val not in col[c] and val not in grid[int(r/3)+int(c%3)*3] 

		# Backtracking Function
			
		def backtrack(r, c):
			ll = len(board)

			if r+1 >= ll and c+1 >= ll:
				return True

			for i in range(r,ll):
				for j in range(c,ll):
					if board[i][j] == ".":
						for temp in range(1, 10):	
							if valid_sudoku(board, temp, i, j):
								board[i][j] = str(temp)
								row[i].add(temp)
								col[j].add(temp)
								grid[int(i/3)+int(j%3)*3].add(temp)
								if backtrack(i, j):
									return True
								row[i].remove(temp)
								col[j].remove(temp)
								grid[int(i/3)+int(j%3)*3].remove(temp)
								board[i][j] = "."			
			return False

		backtrack(0,0)	
							

sudoku = [
[".",".",".",".",".",".","5",".","."],
[".",".",".",".",".",".",".",".","."],
[".",".",".",".",".",".",".",".","."],
["9","3",".",".","2",".","4",".","."],
[".",".","7",".",".",".","3",".","."],
[".",".",".",".",".",".",".",".","."],
[".",".",".","3","4",".",".",".","."],
[".",".",".",".",".","3",".",".","."],
[".",".",".",".",".","5","2",".","."]
]

sln = Solution()
sln.runner(sudoku)
print(sudoku)
