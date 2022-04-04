import requests
from bs4 import BeautifulSoup
import re
import sys
import os

atCoderUrlPrefix="https://atcoder.jp"

#形式エラー
if len(sys.argv) != 3:
    print("you shoud retry below forms")
    print("python get-test.py contestName mondaiName")
    print("------------ for example ---------------")
    print("python get-test.py abc165 e")
    sys.exit()

def zerotuika(contestName,n):
    flag=False
    if "abc" in contestName:
        flag=True
    if "arc" in contestName:
        flag=True
    if "agc" in contestName:
        flag=True
    if flag:
        #abc,arc,agc
        prefix=contestName[0:3]
        num=contestName[3:]
        # 9 -> 009, 35 -> 035 0を n桁になるまで追加する
        while len(num) < n:
            num=str(0)+num
        return prefix+num
    return contestName

# コマンドライン引数設定
contestName = zerotuika(sys.argv[1],3)
mondaiName=sys.argv[2]

#httpステータス確認
def httpStatusCheck(response,url):
    if not "200" in str(response):
        print(response)
        print("your specified URL is " + url)
        print("try again")
        sys.exit()

mondaiUrlList=[]
if not os.path.exists("mondaiUrl.txt"):
    #問題一覧画面から個別問題へのリンクを取得し、ファイルに書き込んでおく
    atCoderListUrl=atCoderUrlPrefix+"/contests/"+contestName+"/tasks"
    response = requests.get(atCoderListUrl)
    httpStatusCheck(response,atCoderListUrl)

    #パーサー
    soup = BeautifulSoup(response.content, "html.parser")
    pretags = soup.find_all("a")

    def duplicateDeletion(mondaiUrlList,url):
        for v in mondaiUrlList:
            if v == url:
                return mondaiUrlList
        mondaiUrlList.append(url)
        return mondaiUrlList

    for p in pretags:
        if "/contests/"+contestName+"/tasks/" in str(p.get("href")):
            mondaiUrlList = duplicateDeletion(mondaiUrlList,atCoderUrlPrefix+p.get("href")+"\n")

    mondaiUrlFile=open("mondaiUrl.txt",mode="w")
    for v in mondaiUrlList:
        mondaiUrlFile.write(v)
    mondaiUrlFile.close()

if(not os.path.exists(mondaiName+"in")) and (not os.path.exists(mondaiName+"out")):
    os.mkdir(mondaiName+"in")
    os.mkdir(mondaiName+"out")

#tesstcase を取得済みの場合は testcase 数だけ print して終了する
if os.path.exists(mondaiName+"in/"+mondaiName+"in0.txt") or os.path.exists(mondaiName+"out/"+mondaiName+"out0.txt"):
    j = 0
    while os.path.exists(mondaiName+"in/"+mondaiName+"in"+str(j)+".txt") or os.path.exists(mondaiName+"out/"+mondaiName+"out"+str(j)+".txt"):
        j+=1
    print(j)
    sys.exit()

#mondaiUrlLisr が空なら　url を file から読み込み
if len(mondaiUrlList) == 0:
    mondaiFile=open("mondaiUrl.txt",mode="r")
    mondaiUrlList = mondaiFile.readlines()
    mondaiFile.close()

moziListString="abcdefghijklmnopqrstuvwxyz"
alphabetDict={}
k=0
for s in moziListString:
    alphabetDict[s]=k
    k+=1

#接続URL作成 html取得
atCoderUrl=mondaiUrlList[alphabetDict[mondaiName]].strip()
url = requests.get(atCoderUrl)
httpStatusCheck(url,atCoderUrl)

#パーサー
soup = BeautifulSoup(url.content, "html.parser")

pretags = soup.find_all("pre")
i=0
#同じデータが来たときにbreakする用
inSaisyo = True
eigoKaihiIn="eigoKaihiIn"
ini = 0
for p in pretags:
    if p.string != None and i % 2 == 0:
        if eigoKaihiIn == p.string.replace("\n",""):
            break
        if inSaisyo:
            eigoKaihiIn = p.string.replace("\n","")
            inSaisyo = False
        inFile=open(mondaiName+"in/"+mondaiName+"in"+ str(ini) + ".txt",mode="w")
        inFile.write(p.string.replace("\n",""))
        ini+=1
        i+=1
        inFile.close()
    elif p.string != None and i % 2 == 1:
        outFile=open(mondaiName+"out/"+mondaiName+"out"+ str(ini-1) + ".txt",mode="w")
        outFile.write(p.string.replace("\n",""))
        i+=1
        outFile.close()
print(ini)
