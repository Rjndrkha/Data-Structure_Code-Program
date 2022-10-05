from turtle import Turtle
import random as r


class Food(Turtle):
    
    def __init__(self):
        super().__init__()
        self.shape("circle")
        self.penup()
        self.shapesize(0.5, 0.5)
        self.color("dodger blue")
        self.speed("fastest")
        
        
    def refresh(self):
        rand_x = r.randint(-270, 270)
        rand_y = r.randint(-270, 270)

        self.goto(rand_x, rand_y)
    