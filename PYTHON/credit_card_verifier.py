
def main():
    # get credit card from input
    credit = get_string("Number: ")

    # Luhn's algorithm
    luhn = 0

    # start from second last character
    for i in range(-2, -len(credit) - 1, -2):
        t = str(int(credit[i]) * 2)
        # Add each digit
        for n in range(len(t)):
            luhn += int(t[n])

    # start from last character
    for i in range(-1, -len(credit) - 1, -2):
        luhn += int(credit[i])

    # say what card is used
    if (luhn % 10) == 0:

        # determine lenght and first-second digits
        lenght = len(credit)
        firsts = int(credit[0]) * 10 + int(credit[1])
        first = int(credit[0])

        # assign credit card company
        # AMEX
        if lenght == 15 and (firsts == 34 or firsts == 37):
            print("AMEX")

        # MASTERCARD
        elif lenght == 16 and (firsts == 51 or firsts == 52 or firsts == 53 or firsts == 54 or firsts == 55):
            print("MASTERCARD")

        # VISA
        elif (lenght == 13 or lenght == 16) and first == 4:
            print("VISA")

        # INVALID
        else:
            print("INVALID")

    else:
        print("INVALID")

def get_string(prompt):
    """
    Read a line of text from standard input and return it as a string,
    sans trailing line ending. Supports CR (\r), LF (\n), and CRLF (\r\n)
    as line endings. If user inputs only a line ending, returns "", not None.
    Returns None upon error or no input whatsoever (i.e., just EOF).
    """
    if type(prompt) is not str:
        raise TypeError("prompt must be of type str")
    try:
        return input(prompt)
    except EOFError:
        return None

if __name__ == "__main__":
    main()
