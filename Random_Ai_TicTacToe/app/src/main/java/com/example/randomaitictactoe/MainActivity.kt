package com.example.randomaitictactoe

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material.MaterialTheme
import androidx.compose.material.Surface
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import androidx.lifecycle.ViewModelProvider
import com.example.randomaitictactoe.presentation.GamePlay
import com.example.randomaitictactoe.presentation.PlayerViewModel
import com.example.randomaitictactoe.presentation.PlayerViewModelFactory
import com.example.randomaitictactoe.presentation.state.ViewState
import com.example.randomaitictactoe.ui.theme.RandomAITicTacToeTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val viewModelFactory = PlayerViewModelFactory(ViewState())
        //the vieModelProvider takes in the viewModelFactory and gets the PlayerViewModel with an initial viewState
        val viewModel = ViewModelProvider(this,viewModelFactory).get(PlayerViewModel::class.java)
        setContent {
            RandomAITicTacToeTheme {
                // A surface container using the 'background' color from the theme
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colors.background
                ) {
                    GamePlay(viewModel = viewModel)
                }
            }
        }
    }
}
