class Solution:
	def isValidSudoku(self, board):
		ll = len(board)
		
		for i in range(ll):
			rr = 0
			rc = 0
			row = set()
			col = set()
			for j in range(ll):
				if board[i][j] != ".":
					rr=rr+1
					row.add(board[i][j])
				if board[j][i] != ".":
					rc=rc+1
					col.add(board[j][i])
			if len(row) != rr or len(col) != rc:
				return False

		for i in range(ll):
			rg = 0
			grid = set()
			for j in range(3*int(i/3),3*int(i/3)+3):
				for k in range(3*int(i%3),3*int(i%3)+3):
					if board[k][j] != ".":
						rg=rg+1
						grid.add(board[k][j])
			if len(grid) != rg:
				return False	 

		return True

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
print(sln.isValidSudoku(sudoku))
