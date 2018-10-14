class Solution:
	def isValidSudoku(self, board):
		ll = len(board)

		## row checker
		for i in range(ll):
			rr = 0
			row = set()
			for j in range(ll):
				if board[i][j] != ".":
					rr=rr+1
					row.add(board[i][j])
			if len(row) != rr:
				return False

		print("passed row check")		
		## column checker
		for i in range(ll):
			rc = 0
			col = set()
			for j in range(ll):
				if board[j][i] != ".":
					rc=rc+1
					col.add(board[j][i])
			if len(col) != rc:
				return False

		print("passed col check")

		## 3*3 Grid checker
		for i in range(ll):
			print("i: ", i)
			rg = 0
			grid = set()
			r = int(i/3)
			c = i%3
			c1 = (3*c)+3
			c2 = (3*r)+3
			while(r<c2):
				while(c<c1):
					print(r, " ", c)
					if board[c][r] != ".":
						rg=rg+1
						grid.add(board[c][r])
					c=c+1
				r=r+1
			if len(grid) != rg:
				return False	 

		return True

sudoku =[
	[".",".",".",".","5",".",".","1","."],
	[".","4",".","3",".",".",".",".","."],
	[".",".",".",".",".","3",".",".","1"],
	["8",".",".",".",".",".",".","2","."],
	[".",".","2",".","7",".",".",".","."],
	[".","1","5",".",".",".",".",".","."],
	[".",".",".",".",".","2",".",".","."],
	[".","2",".","9",".",".",".",".","."],
	[".",".","4",".",".",".",".",".","."]
]

sln = Solution()
print(sln.isValidSudoku(sudoku))