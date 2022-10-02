import random

rock = '''
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
'''

paper = '''
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''

scissors = '''
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''

# Write your code below this line 👇

choices = [rock, paper, scissors]
user = int(input("What do you choose? Enter 0 for Rock, 1 for Paper, or 2 for Scissors.\n"))
if user > 2 or user < 0:
  print("You typed an invalid number, you lose!")
else:
  print(choices[user])
  computer = random.randint(0, 2)
  if computer == 0:
    print(f"Computer chose:\n{choices[computer]}")
  elif computer == 1:
    print(f"Computer chose:\n{choices[computer]}")
  else:
    print(f"Computer chose:\n{choices[computer]}")
  if user == 0 and computer == 2:
    print("You win!")
  elif computer == 0 and user == 2:
    print("You lose!")
  elif user > computer:
    print("You win!")
  elif computer > user:
    print("You lose!")
  elif computer == user:
    print("It's a draw.")
