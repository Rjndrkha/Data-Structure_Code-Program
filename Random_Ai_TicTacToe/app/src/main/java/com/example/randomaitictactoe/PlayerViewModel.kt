package com.example.randomaitictactoe


import android.util.Log
import androidx.lifecycle.*
import com.example.randomaitictactoe.state.ViewState
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch

//This is the PlayerViewModel and it takes in state as an argument. And with the state the functions are performed and reflected in the ui.
class PlayerViewModel(
    state : ViewState
):ViewModel() {

    private val state1 = MutableLiveData(state)
    val state2 : LiveData<ViewState> = state1

    //this is the randomComputerPlayer. This is responsible to choose the board after the human player turn.
    private fun randomComputerPlayer() {
        val indexValues = state1.value?.squares
        val listIndexes = ArrayList<Int>()
        indexValues?.forEachIndexed { index, s ->
            if (s == "") {
                listIndexes.add(index)
            }
        }
        onSquareSelected(listIndexes.random())
    }

    //This function checks checks checks whether human player has selected the square and updates it. And then updates the state value.
    fun onSquareSelected(index:Int){
        state1.value = state1.value?.selectSquare(index)
        viewModelScope.launch(Dispatchers.Main) {
            if (state2.value?.info == "Next player: O"){
                Log.v("working","super")
                randomComputerPlayer()
            }
        }
    }

    //This function flushes the state value. And restarts the game.
    fun onPlayAgainClicked(){
        state1.value = ViewState()
    }

}

//This is the PlayerViewModelFactory. It returns the viewmodel with an initial state value from the argument state.
class PlayerViewModelFactory(private val state : ViewState) : ViewModelProvider.Factory{
    override fun <T : ViewModel> create(modelClass: Class<T>): T {
        if (modelClass.isAssignableFrom(PlayerViewModel::class.java)){
            return PlayerViewModel(state) as T
        }
        throw  IllegalArgumentException("Sorry man couldn't access viewModel")
    }

}