import 'package:flutter/cupertino.dart';
import 'package:provider/provider.dart';
import 'package:snake_game/game_state.dart';
import 'package:snake_game/scores.dart';

import 'controls.dart';
import 'game_board.dart';

class SnakeGame extends StatelessWidget {

  @override
  Widget build(BuildContext context) {
    final state = Provider.of<GameState>(context);
    return Column(
      children: [
        Expanded(
            child: GameBoard(),
          flex: 3,
        ),
        Expanded(
            child: Controls(),
          flex: 2,
        ),
        Expanded(
          child: Scores(state.currentScore, state.bestScore),
          flex: 1,
        ),
      ],
    );
  }
}
