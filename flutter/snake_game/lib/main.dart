import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:snake_game/snake_game.dart';

import 'game_state.dart';

void main() {
  runApp(MaterialApp(
    debugShowCheckedModeBanner: false,
    home: Scaffold(
      backgroundColor: Colors.grey,
      body: SafeArea(
        child: ChangeNotifierProvider(
          child: SnakeGame(),
          create: (context) => GameState(),
        ),
      ),
    ),
  ));
}

