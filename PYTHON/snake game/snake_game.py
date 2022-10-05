from turtle import Turtle, Screen, color, width
import time
from snake import Snake
from food import Food
from scoreboard import ScoreBoard
from border import Border


screen = Screen()
screen.setup(600, 600)
screen.title("Snake Game")
screen.bgcolor("black")
screen.tracer(0)
screen.title("Snake Game")

screen.listen()

border = Border()

food = Food()

snake = Snake()

score = ScoreBoard()

screen.onkeypress(fun=snake.up, key="w")
screen.onkeypress(fun=snake.left, key="a")
screen.onkeypress(fun=snake.down, key="s")
screen.onkeypress(fun=snake.right, key="d")


game_on = True

while game_on:

    screen.update()
    time.sleep(0.1)
    snake.move()

    if snake.all_turtle[0].distance(food) < 15:
        food.refresh()
        score.clear()
        score.count += 1
        score.score_count()
        snake.extend()

    if snake.all_turtle[0].xcor() > 280 or snake.all_turtle[0].xcor() < -280 or snake.all_turtle[0].ycor() > 280 or snake.all_turtle[0].ycor() < -280:
        # game_on = False
        score.reset()
        snake.reset()
        
        


    for turts in snake.all_turtle[1:]:
        
        if snake.all_turtle[0].distance(turts) < 9:
            # game_on = False
            score.reset()
            snake.reset()
            
            




screen.exitonclick()
