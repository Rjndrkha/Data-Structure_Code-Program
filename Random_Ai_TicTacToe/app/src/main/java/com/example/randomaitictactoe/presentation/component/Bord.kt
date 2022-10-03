package com.example.randomaitictactoe.presentation.component

import androidx.compose.foundation.ExperimentalFoundationApi
import androidx.compose.foundation.lazy.GridCells
import androidx.compose.foundation.lazy.LazyVerticalGrid
import androidx.compose.runtime.Composable

//the board component uses Grid. Where the squares are the cells. Once the square is clicked it gets the index and passes the onclick function to the square.
@ExperimentalFoundationApi
@Composable
fun Board(squares: List<String>, isBoardEnabled: Boolean, onClick: (Int) -> Unit) {
    LazyVerticalGrid(
        cells = GridCells.Fixed(3),
    ) {
        items(squares.size) { index ->
            Square(squares[index], isBoardEnabled) { onClick(index) }
        }
    }
}