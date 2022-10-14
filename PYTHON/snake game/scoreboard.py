from turtle import Turtle, mode



class ScoreBoard(Turtle):
    
    def __init__(self):
        super().__init__()
        self.count = 0
        self.high_score = 0
        self.penup()
        self.hideturtle()
        self.goto(0, 270)
        self.color("white")
        self.score_count()


    def score_count(self):
        with open("data.txt", mode= "r") as file:
            score_high = file.read()
        self.clear()
        self.write(f"Score = {self.count}    High Score = {score_high}", False, align = "center", font= ("Courier", 12, "bold"))
        
    
    def reset(self):
        if self.count > self.high_score:
            self.high_score = self.count
            self.count = 0
        
        with open("data.txt" , mode= "w") as file:
            file.write(f"{self.high_score}")
        
        self.score_count()
        
        
        