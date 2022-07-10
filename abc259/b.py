import numpy as np
from sys import stdin

# ここにcoordinate()を実装
# ここにvisual_vector()を実装

# ベクトル回転関数
# deg=Falseならばラジアンで角度を指定
# deg=Trueならば度数単位で角度を指定
def rotation_o(u, t):

    t = np.deg2rad(t)

    # 回転行列
    R = np.array([[np.cos(t), -np.sin(t)],
                  [np.sin(t),  np.cos(t)]])

    return  np.dot(R, u)

a,b,t = input().split()
a = int(a)
b = int(b)
t = int(t)
# 単位ベクトル
u = (a, b)

# uを45°回転させる
Ru = rotation_o(u, t)
print(Ru[0], Ru[1])
