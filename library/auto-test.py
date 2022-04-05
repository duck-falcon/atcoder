import sys
import os

#形式エラー
if len(sys.argv) != 2 and len(sys.argv) !=3:
    print("you shoud retry below forms(ALL_TESTCASE)")
    print("python auto-test.py mondaiName")
    print("------------ for example ---------------")
    print("python auto-test.py f\n\n")

    print("you shoud retry below forms(UNIT_TESTCASE)")
    print("python auto-test.py mondaiName testCaseName")
    print("------------ for example ---------------")
    print("python auto-test.py f 0")
    sys.exit()

mondaiName=sys.argv[1]

#i番目のテストケースのチェック
def check(i):
    outPutFilePath=mondaiName+"out/"+mondaiName+"out"+str(i)+".txt"
    myAnswerFilePath=mondaiName+"myans/"+mondaiName+"myans"+str(i)+".txt"
    outPutFile = open(outPutFilePath,"r")
    myAnswerFile = open(myAnswerFilePath,"r")
    outPut = outPutFile.read()
    myAnswer = myAnswerFile.read()
    print("-----sample" + str(i)+"-----")
    if outPut.strip() == myAnswer.strip():
        print("AC")
    else:
        print("WA")
        print("expect answer")
        print(outPut)
        print("-------------")
        print("your answer")
        print(myAnswer)

if len(sys.argv) == 3:
    check(sys.argv[2])
else:
    i = 0
    while os.path.exists(mondaiName+"out/"+mondaiName+"out"+str(i)+".txt") and os.path.exists(mondaiName+"myans/"+mondaiName+"myans"+str(i)+".txt"):
        check(i)
        i += 1
