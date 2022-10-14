import 'package:flutter/material.dart';

class Scores extends StatelessWidget {
  final int currentScore, bestScore;

  Scores(this.currentScore,this.bestScore);

  Widget _score(String  text, int score){
    final style = TextStyle(
      fontSize: 24,
      fontWeight: FontWeight.bold,
    );
    return Column(
      mainAxisAlignment: MainAxisAlignment.spaceEvenly,
      children: [
        Text(
            text,
          style: style,
        ),
        Text(
            score.toString(),
          style: style,
        ),
      ],
    );
  }
  @override
  Widget build(BuildContext context) {
    return Row(
      mainAxisAlignment: MainAxisAlignment.spaceEvenly,
      children: [
        _score('SCORE', currentScore),
        _score('BEST', bestScore),
      ],
    );
  }
}
