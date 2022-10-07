import 'dart:math';

import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:snake_game/game_state.dart';
import 'constants.dart';

class GameBoard extends StatelessWidget {
  List<Widget> _getChildren(GameState state){
    List<Widget> children = [];
    for(int i =0; i< NUM_COL * NUM_ROW; ++i){
      if(state.cellValue[i] ==0)
        children.add(EmptyCell());
      else if(state.cellValue[i] == 1)
        children.add(TailCell());
      else if (state.cellValue[i] == state.length)
        children.add(HeadCell());
      else if(state.cellValue[i]<0)
        children.add(FruitCell());
      else
        children.add(BodyCell());
    }
    return children;
  }

  @override
  Widget build(BuildContext context) {
    final state = Provider.of<GameState>(context);
    return Stack(
      children: [Align(
        child: AspectRatio(
          aspectRatio: NUM_COL/NUM_ROW,
          child: Container(color: Colors.white,
            child: GridView.count(
              physics: NeverScrollableScrollPhysics(),
              crossAxisCount: NUM_COL,
              children: _getChildren(state),
            ),
          ),
        ),
      ),
        state.isGameOver ? GameOver() :Container(),
      ],
    );
  }
}

class EmptyCell extends StatelessWidget {
  const EmptyCell({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container();
  }
}

class FruitCell extends StatelessWidget {
  const FruitCell({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return FittedBox(
      child: Icon(Icons.adb, color: Colors.red,),
    );
  }
}

class TailCell extends StatelessWidget {
  const TailCell({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      margin: EdgeInsets.all(5),
      decoration: BoxDecoration(
        shape: BoxShape.circle,
        color: Colors.green,
      ),
    );
  }
}

class BodyCell extends StatelessWidget {
  const BodyCell({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
    decoration: BoxDecoration(
      shape: BoxShape.circle,
      color: Colors.green,
    ),
    );
  }
}

class HeadCell extends StatelessWidget {
  const HeadCell({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final state = Provider.of<GameState>(context);
    return FittedBox(
        child: Transform.rotate(
          angle: getRotationAngle(state.currentDir) + pi * 0.5,
            child: Icon(
                Icons.android,
                color: Colors.green,
            ),
        ),
    );
  }
}

class GameOver extends StatelessWidget {
  const GameOver({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final state = Provider.of<GameState>(context);
    return Center(
      child: GestureDetector(
        onTap: ()=>state.startGame(),
        child: Text(
          'Game Over',
          style: TextStyle(
            fontSize: 36,
            color: Colors.red,
            backgroundColor: Colors.grey,
          ),
        ),
      ),
    );
  }
}





