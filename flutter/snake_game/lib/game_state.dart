import 'dart:async';
import 'dart:math';

import 'package:flutter/material.dart';
import 'package:snake_game/constants.dart';

enum Direction{
  RIGHT, UP, LEFT, DOWN,
}

double getRotationAngle(Direction dir){
  double angle = 0;
  switch(dir){

    case Direction.RIGHT:
      // TODO: Handle this case.
      break;
    case Direction.UP:
      angle -= pi * 0.5;
      break;
    case Direction.LEFT:
      angle += pi;
      break;
    case Direction.DOWN:
      angle += pi * 0.5;
      break;
  }
  return angle;
}

class GameState with ChangeNotifier{
  GameState(){
    startGame();
}
  bool isGameOver = true;

  final rg = Random();
  void _generateFruit(){
    int fruitPos = -1;
    do{
      fruitPos = rg.nextInt(NUM_COL * NUM_ROW);
    }while(cellValue[fruitPos] !=0);
    cellValue[fruitPos] =-1;
  }
  void startGame(){
    isGameOver= false;
    cellValue = List.filled(NUM_ROW * NUM_COL, 0);
    headPos = rg.nextInt(NUM_ROW*NUM_COL);
    final dirIdx = rg.nextInt(Direction.values.length);
    currentDir = nextDir = Direction.values[dirIdx];
    final tailPos = _neighbor(headPos, opposite(currentDir));

    length = 2;
    cellValue[headPos] = length;
    cellValue[tailPos] = 1;

    _generateFruit();

    bestScore = max(bestScore, currentScore);
    currentScore=0;
    notifyListeners();

    gameLoop = Timer.periodic(Duration(milliseconds: DELTA_T_MS), (timer){
      _update();
    });
  }

  void _update(){
    currentDir = nextDir;

    headPos = _neighbor(headPos, currentDir);
    if(cellValue[headPos] == -1){
      ++currentScore;
      ++length;
      cellValue[headPos] = length;
      _generateFruit();
    } else if(cellValue[headPos]> 1){
      isGameOver = true;
      gameLoop.cancel();
      notifyListeners();
  }
    else{
      for(int i =0;i<NUM_COL * NUM_ROW; ++i){
        if(cellValue[i]<=0) continue;
        --cellValue[i];
      }
      cellValue[headPos] = length;
    }
    notifyListeners();
  }
  Direction opposite(Direction dir){
    switch (dir){

      case Direction.RIGHT:
        return Direction.LEFT;
        break;
      case Direction.UP:
        return Direction.DOWN;
        break;
      case Direction.LEFT:
        return Direction.RIGHT;
        break;
      case Direction.DOWN:
        return Direction.UP;
        break;
    }
  }

  int _neighbor(int pos, Direction dir){
    switch(dir){

      case Direction.RIGHT:
        if(pos % NUM_COL == NUM_COL - 1)
          pos -= NUM_COL;
        ++pos;
        break;
      case Direction.UP:
        if(pos ~/ NUM_COL == 0)
          pos += NUM_COL * NUM_ROW;
        pos -= NUM_COL;
        break;
      case Direction.LEFT:
        if(pos % NUM_COL == 0)
          pos += NUM_COL;
        --pos;
        break;
      case Direction.DOWN:
        if(pos ~/ NUM_COL == NUM_ROW -1 )
          pos -= NUM_COL * NUM_ROW;
        pos += NUM_COL;
        break;
    }
    return pos;
  }

  int currentScore = 0;
  int bestScore = 0;

  late Direction currentDir;
  late Direction nextDir;

  late List<int> cellValue;

  late int headPos;
  late int length;

  late Timer gameLoop;

}