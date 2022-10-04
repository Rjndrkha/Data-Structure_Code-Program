package com.example.randomaitictactoe.presentation.state

//ViewState is the state that handles the turn and square chosen by the player and the computer. It also notifies who has won.
//It also uses an enum class to maintain the turn sequence.
data class ViewState(
    val info: String = "Next player: X",
    private var turn: Turn = Turn.X_PLAYER,
    val isFinished: Boolean = false,
    val squares: List<String> = List(9) { "" },
) {
    fun selectSquare(index: Int): ViewState {
        val updatedSquares = squares.toMutableList()
        updatedSquares[index] = turn.label

        val updatedTurn = when (turn) {
            Turn.X_PLAYER -> Turn.O_PLAYER
            Turn.O_PLAYER -> Turn.X_PLAYER
        }

        val winner = calculateWinner(updatedSquares)

        val updatedInfo = if (winner == null) {
            "Next player: ${updatedTurn.label}"
        }
        else if(winner=="none"){
            "Draw"
        }
        else {
            "Winner: $winner"
        }
        return ViewState(
            info = updatedInfo,
            turn = updatedTurn,
            isFinished = winner != null,
            squares = updatedSquares,
        )
    }

    private fun calculateWinner(squares: List<String>): String? {
        val winningLines = listOf(
            listOf(0, 1, 2),
            listOf(3, 4, 5),
            listOf(6, 7, 8),
            listOf(0, 3, 6),
            listOf(1, 4, 7),
            listOf(2, 5, 8),
            listOf(0, 4, 8),
            listOf(2, 4, 6),
        )
        winningLines.forEach { lines ->
            if (squares[lines[0]].isNotBlank() &&
                squares[lines[0]] == squares[lines[1]] &&
                squares[lines[0]] == squares[lines[2]]
            ) {
                return squares[lines[0]]
            }
        }
        if ((squares[0] == "X" || squares[0] == "O") &&
            (squares[1] == "X" || squares[1] == "O") &&
            (squares[2] == "X" || squares[2] == "O") &&
            (squares[3] == "X" || squares[3] == "O") &&
            (squares[4] == "X" || squares[4] == "O") &&
            (squares[5] == "X" || squares[5] == "O") &&
            (squares[6] == "X" || squares[6] == "O") &&
            (squares[7] == "X" || squares[7] == "O") &&
            (squares[8] == "X" || squares[8] == "O")) {
            return "none"
        }
        return null
    }
}
//this enum class is responsible to help the viewState handle the turn.
enum class Turn(val label: String) {
    X_PLAYER("X"),
    O_PLAYER("O")
}