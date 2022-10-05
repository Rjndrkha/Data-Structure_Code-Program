from turtle import Turtle 

SPEED = 20
UP = 90
DOWN = 270
LEFT = 180
RIGHT = 0

class Snake:

    def __init__(self):
        self.all_turtle = []
        self.create_snake()


    def create_snake(self):
        

        for i in range(0,3):
            self.add_segment()

    
    def reset(self):
        for turt in self.all_turtle:
            turt.goto(1000, 1000)
        self.all_turtle.clear()
        self.create_snake()
            
            
    
    def add_segment(self):
        x = 0

        timmy = Turtle(shape = "square")
        timmy.penup()
        timmy.color("white")
        timmy.goto(x,0)
        x -= 20
        self.all_turtle.append(timmy)

    
    def extend(self):
        timmy = Turtle(shape = "square")
        timmy.penup()
        timmy.color("white")
        timmy.goto(self.all_turtle[-1].position())
        self.all_turtle.append(timmy)

    

    def move(self):
        
        for turts in range(len(self.all_turtle) - 1, 0, -1):
            new_x = self.all_turtle[turts-1].xcor()
            new_y = self.all_turtle[turts-1].ycor()

            self.all_turtle[turts].goto(new_x, new_y)
        
        self.all_turtle[0].forward(20)

    def up(self):
        if self.all_turtle[0].heading() != DOWN:
            self.all_turtle[0].setheading(UP)

    def left(self):
        if self.all_turtle[0].heading() != RIGHT:
            self.all_turtle[0].setheading(LEFT)

    def down(self):
        if self.all_turtle[0].heading() != UP:
            self.all_turtle[0].setheading(DOWN)

    def right(self):
        if self.all_turtle[0].heading() != LEFT:
            self.all_turtle[0].setheading(RIGHT)
