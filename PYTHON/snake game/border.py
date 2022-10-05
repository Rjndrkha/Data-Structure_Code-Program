from turtle import Turtle

CORDS = [(280, 280), (-280, 280), (-280, -280), (280, -280)]

class Border(Turtle):
    def __init__(self):
        super().__init__()
        self.penup()
        self.hideturtle()
        self.draw()

    
    def draw(self):
        for i in CORDS:
            self.goto(i)
            self.pendown()
        
        
            
        
