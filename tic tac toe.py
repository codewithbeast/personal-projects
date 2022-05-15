import sys

a = [
    ['N','N','N'],
    ['N','N','N'],
    ['N','N','N']
]

First3Vertically = []
First3Horizontally = []

GameOver = False
Row = None
Colum = None

Turn = "O"
Winner = None




def FindFirst3Vertically(row):
    for i in range(3):
        First3Vertically.append(a[row][i])
        if len(First3Vertically) == 3:

            if First3Vertically[0] == First3Vertically[1] == First3Vertically[2]:
                if "N" not in First3Vertically:
                    print(First3Vertically[0][0],"Is Winner")
                    sys.exit()
                    return True


            First3Vertically.clear()

def FindFirst3Horizontally(item):
   for i in range(3):
        First3Horizontally.append(a[i][item])

        if len(First3Horizontally) == 3:

            if First3Horizontally[0] == First3Horizontally[1] == First3Horizontally[2]:
                if "N" not in First3Horizontally:
                    print(First3Horizontally[0][0],"Is winner")
                    sys.exit()
                    return True


            First3Horizontally.clear()


def CheckDiagnoally():

    if a[2][0] != "N" and a[1][1] != "N" and a[0][2] != "N":
        if a[2][0] == a[1][1] == a[0][2]:
            print(a[1][1],"is the winner")
            sys.exit()

    if a[0][0] != "N" and a[1][1] != "N" and a[2][2] != "N":
        if a[0][0] == a[1][1] == a[2][2]:
            print(a[1][1],"is the winner")
            sys.exit()




def CheckWinner():
    # print("running")
    for i in range(3):
        VerticalTestResult = FindFirst3Vertically(i)

    for i in range(3):
        HorizontalTestResult = FindFirst3Horizontally(i)
        # print(HorizontalTestResult)

    c = CheckDiagnoally()

    if not HorizontalTestResult  or not VerticalTestResult or not c :
        if "N" not in a[0] and a[1] and a[2]:
            print("Draw")
            sys.exit()




def DrawBoard():
    for i in range(len(a)):
        print(a[i])



DrawBoard()
print("Quick Note : Indexing Starts From 0\n")
while not GameOver:

    CheckWinner()

    if Turn == "O":
        print(Turn,"'s","Turn\n")
        Row = int(input("Row: "))
        Colum = int(input("Colum: "))
        if a[Row][Colum] == "N":
            a[Row][Colum] = "O"
            Turn = "X"

        else:
            print("That Square Is Occupied")
            Turn = "O"

        DrawBoard()


    CheckWinner()

    if Turn == "X":
        print(Turn,"'s","Turn\n")
        Row = int(input("Row: "))
        Colum = int(input("Colum: "))
        Turn = "O"
        if a[Row][Colum] == "N":
            a[Row][Colum] = "X"
            Turn = "O"

        else:
            print("That Square is Occupied")
            Turn = "X"

        DrawBoard()

    CheckWinner()
