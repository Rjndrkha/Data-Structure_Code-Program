package com.example.randomaitictactoe.component

import androidx.compose.foundation.BorderStroke
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.material.Button
import androidx.compose.material.ButtonDefaults
import androidx.compose.material.MaterialTheme
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.RectangleShape
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp

//the square composable is a button that is used in the board component. OnClicking it, the onClick parameter which the screen receives as an argument is invoked.
@Composable
fun Square(selection: String, isBoardEnabled: Boolean, onClick: () -> Unit) {
    Button(
        modifier = Modifier
            .fillMaxWidth()
            .height(128.dp),
        border = BorderStroke(1.dp, Color.Black),
        shape = RectangleShape,
        enabled = isBoardEnabled && selection.isBlank(),
        onClick = onClick,
        colors = ButtonDefaults.buttonColors(
            disabledBackgroundColor = Color.Cyan
        )
    ) {
        Text(
            text = selection,
            color = Color.Black,
            style = MaterialTheme.typography.h3,
            fontWeight = FontWeight.Bold
        )
    }
}