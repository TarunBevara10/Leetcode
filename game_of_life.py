class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        m, n = len(board), len(board[0])

        # Directions for 8 neighbors
        dirs = [
            (1, 0), (-1, 0), (0, 1), (0, -1),
            (1, 1), (1, -1), (-1, 1), (-1, -1)
        ]

        def count_live_neighbors(r, c):
            live = 0
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                # Check boundaries, treat encoded 1->0 (2) as live
                if 0 <= nr < m and 0 <= nc < n and (board[nr][nc] == 1 or board[nr][nc] == 2):
                    live += 1
            return live

        # First pass: apply rules using encoded transitions
        for r in range(m):
            for c in range(n):
                live_neighbors = count_live_neighbors(r, c)

                # Rule for live cell
                if board[r][c] == 1:
                    if live_neighbors < 2 or live_neighbors > 3:
                        board[r][c] = 2   # live -> dead

                # Rule for dead cell
                else:
                    if live_neighbors == 3:
                        board[r][c] = 3   # dead -> live

        # Second pass: decode new states (2->0, 3->1)
        for r in range(m):
            for c in range(n):
                if board[r][c] == 2:
                    board[r][c] = 0
                elif board[r][c] == 3:
                    board[r][c] = 1
